#include<stdio.h>
#include<stdlib.h>

#define RED false
#define BLACK true

struct node{
	int key;
	node *left, *right, *p;
	bool c;
};

struct rbtree{
	node * root;
	node * nill; //a cor do nill é preta
};

rbtree * start(){
	rbtree * t = (rbtree *)malloc(sizeof(rbtree));
	t->nill = (node *)malloc(sizeof(node));
	
	/* Inicializa o nill da newT tudo para null */
	t->nill->p = NULL;
	t->nill->left = NULL;
	t->nill->right = NULL;
	
	/*Aponta a raiz da nova arvore para o nil*/
	t->root = t->nill;
	
	return t;
}

void insert(rbtree * t, int k){
	node * n = (node *)malloc(sizeof(node));
	n->key = k;
	n->right = n->left = t->nill;
	n->c = RED;
	
	//auxiliares para guardar o nodo (y) e o pai do nodo (x)
	node * y;
	node * x;
	
	y = t->nill;
	x = t->root;
	
	/*Procura o lugar do nodo, guardando o pai deste na variável y.*/
	while(x != t->nill){
		y = x;
		
		if(k < x->key){
			x = x->left;
		}
		
		else{
			x = x->right;
		}		
	}
	
	n->p = y;
	
	//Se a arvore for vazia
	if(y = t->nill){
		t->root = n;
	}
	
	/*O y é o pai do nodo a ser inserido, que foi guardado no while. 
	Agora se verifica se o nodo vai a direita ou esquerda do y*/
	if(k < y->key){
		y->left = n;
	}
	else{
		y->right = n;
	}
		
}

void rotateLeft(rbtree * t, node * x){
	node * y = x->right;
	x->right = y->left;
	
	if(y->left != t->nill){
		y->left->p = x;
	}
	
	y->p = x->p;
	
	//se x é a raiz
	if(x->p == t->nill){
		t->root = y;
	}
	
	else{
		if(x == x->p->left){
			x->p->left = y;
		}
		else{
			x->p->right = y;
		}
	
	y->left = x;
	x->p = y;	
	}
}

void rotateRight(rbtree * t, node * x){
	node * y = x->left;
	x->left = y->right;
	
	if(y->right != t->nill){
		y->right->p = x;
	}
	
	y->p = x->p;
	
	//se x é a raiz
	if(x->p == t->nill){
		t->root = y;
	}
	
	else{
		if(x == x->p->right){
			x->p->right = y;
		}
		else{
			x->p->left = y;
		}
	
	y->right = x;
	x->p = y;	
	}
}

void arrange(rbtree * t, node * z){
	while(z->p->c == RED){
		if(z->p == z->p->p->left){
			y = z->p->p->right;
			
			if(y->c == RED){
				y->c = BLACK;
				z->pai = BLACK;
				z->p->p = RED;
				z = z->p->p;
			}			
			else{
				if(z == z->p->right){
					z = z->pai;
					rotateLeft(t,z);
				}
				
				z->p->c = BLACK;
				z->p->p->c = RED;
				rotateRight(t, z->p->p);							
			}
		}
		
		else{
			y = z->p->p->left;
			
			if(y->c == RED){
				y->c = BLACK;
				z->pai = BLACK;
				z->p->p = RED;
				z = z->p->p;
			}			
			else{
				if(z == z->p->left){
					z = z->pai;
					rotateRight(t,z);
				}
				
				z->p->c = BLACK;
				z->p->p->c = RED;
				rotateLeft(t, z->p->p);								
			}
		}			
	}
		
//		z->root->left
}


/*Imprime a árvore bonitinha*/
void drawTree(node * n, int h){
	if(n->left != NULL){
		drawTree(n->left, h+1);	
	}

	int i;
	for(i=0; i<h; i++){
		printf("  ");
	}
	printf("%d\n", n->key);
	
	if(n->right != NULL){
		drawTree(n->right, h+1);
	}
}

//Percurso in Order
void inOrder(node * r){
	if(r!=NULL){
		inOrder(r->left);
		
		printf("%d ", r->key);
		
		inOrder(r->right);
	}	
}

//Percurso pre Order
void preOrder(node * r){
	if(r!=NULL){
		printf("%d ", r->key);		
		preOrder(r->left);				
		preOrder(r->right);
	}	
}

//Percurso Pos Order
void posOrder(node * r){
	if(r!=NULL){
		posOrder(r->left);
		posOrder(r->right);
		printf("%d ", r->key);
		
	}
}

int main(){

	rbtree * t = start();
	insert(t, 10);
	insert(t, 8);
	insert(t, 15);
	insert(t, 5);
	insert(t, 9);
	insert(t, 20);
	insert(t, 17);
	insert(t, 16);
	insert(t, 11);
	insert(t, 19);

	//drawTree(t->root, 0);
	inOrder(t->root);

return 0;
}










