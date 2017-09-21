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
	
	y = t->nill; //pai do meu nodo
	x = t->root; //meu nodo
	
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
	if(y == t->nill){
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

/*busca por uma chave k na árvore com raiz r
caso a chave não estiver na árvore retorna NULL*/
node * search(rbtree * t, node * r, int key){
	
	if(r == t->nill || r->key == key){
		return r;
	}
	if(key <= r->key){
		return search(t, r->left, key);	
	}
	
	return search(t, r->right, key);
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
	node * y;
	
	while(z->p->c == RED){
		if(z->p == z->p->p->left){
			y = z->p->p->right; //tio
			
			if(y->c == RED){
				y->c = BLACK;
				z->c = BLACK;
				z->p->c = RED;
				z = z->p->p;
			}			
			else{
				if(z == z->p->right){
					z = z->p;
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
				z->c = BLACK;
				z->p->c = RED;
				z = z->p->p;
			}			
			else{
				if(z == z->p->left){
					z = z->p;
					rotateRight(t,z);
				}
				
				z->p->c = BLACK;
				z->p->p->c = RED;
				rotateLeft(t, z->p->p);								
			}
		}
		
		z->c = BLACK;
		z = z->p;						
	}
		
	
}


/*Imprime a árvore bonitinha*/
void drawTree(rbtree * t, node * n, int h){
	if(n->left != t->nill){
		drawTree(t, n->left, h+1);	
	}

	int i;
	for(i=0; i<h; i++){
		printf("    ");
	}
	
	if(n->c == RED){
		printf("R-%d\n", n->key);	
	}
	else{
		printf("R-%d\n", n->key);		
	}
	
	if(n->right != t->nill){
		drawTree(t, n->right, h+1);
	}
}

//Percurso in Order
void inOrder(rbtree * t, node * r){
	if(r!=t->nill){
		inOrder(t, r->left);
		
		printf("%d ", r->key);
		
		inOrder(t, r->right);
	}	
}

//Percurso pre Order
void preOrder(rbtree * t, node * r){
	if(r!=t->nill){
		printf("%d ", r->key);		
		preOrder(t, r->left);				
		preOrder(t, r->right);
	}	
}

//Percurso Pos Order
void posOrder(rbtree * t, node * r){
	if(r!=t->nill){
		posOrder(t, r->left);
		posOrder(t, r->right);
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
	insert(t, 11);

	
	node * i = t->root;
	
	drawTree(t, t->root, 0);
	printf("\n\n");

	arrange(t, search(t, t->root, 17));
	drawTree(t, t->root, 0);

return 0;
}










