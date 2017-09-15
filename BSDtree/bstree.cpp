#include<stdio.h>
#include<stdlib.h>

struct node{
	int key; //chave de identificação do nodo
	node * left, * right, *parent; //ponteiro para os filhos e para o pai
};

node * insert(node * r, int key){
	node * aux = r;	
	
	//inicializa o nodo
	node * n = (node*)malloc(sizeof(node));
	n->key = key;
	n->left = n->right = n->parent = NULL;
	
	//se a raiz é nula, insere n na raiz e retorna n
	if(r == NULL){
		return n;
	}
		
	while(1){
		//se a chave é menor, vai para esquerda
		if(key < aux->key){
			if(aux->left == NULL){
				n->parent = aux;
				aux->left = n;
				return r;
			}
			
			else{				
				aux = aux->left;
				
			}
		}
		
		//se a chave é maior, vai para direita
		else{
			if(aux->right == NULL){
				n->parent = aux;
				aux->right = n;
				return r;
			}

			else{
				aux = aux->right;
			}			
		}		
	}		
}

void imp(node * n, int h){
	
	if(n->left != NULL){
		imp(n->left, h+1);	
	}

	int i;
	for(i=0; i<h; i++){
		printf("  ");
	}
	printf("%d\n", n->key);
	
	if(n->right != NULL){
		imp(n->right, h+1);
	}
}


/*busca por uma chave k na árvore com raiz r
caso a chave não estiver na árvore retorna NULL*/
node * search(node * r, int key){
	if(!r || r->key == key){
		return r;
	}
	if(key <= r->key){
		return search(r->left, key);	
	}
	
	return search(r->right, key);
}

/*Procura o menor nodo de uma sub-arvore*/
node * minTree(node * r){
	node * min = r->right;
	
	while(min->left !=NULL){
		min = min->left;
	}
	
	return min;
}

//in Order
int inOrder(node * t){
	if(t!=NULL){
		inOrder(t->left);
		
		printf("%d ", t->key);
		
		inOrder(t->right);
	}	
}

void swap(node ** a, node ** b){
	//printf("a = %d, b = %d\n", *a, *b);
	node * aux1 = *a;
	node * aux2 = *b;
	*a = aux2;
	*b = aux1;	
	
}

void transplant(node * v, node * minV){
	swap(&(minV->left), &(v->left));
	swap(&(minV->right), &(v->right));
	
	if(v->parent->left == v){
		if(minV->parent->left == v){	
			swap(&(v->parent->left), &(minV->parent->left));
		}
		else{
			swap(&(v->parent->left), &(minV->parent->right));		
		}
	}
				
	else{
		if(minV->parent->right == v){	
			swap(&(v->parent->right), &(minV->parent->left));
		}
		else{
			swap(&(v->parent->right), &(minV->parent->right));		
		}	
	}
	
	swap(&(minV->parent), &(v->parent));
	
}

void * deleteNode(node * r, int key){
	node * v = search(r, key);
	
	//se v é uma folha
	if(v->left == NULL && v->right == NULL){
		if(v->parent->left == v){
			v->parent->left = NULL;
		}	
		else{
			v->parent->right = NULL;
		}
		
	}	
	
	//se v tem só um filho à esquerda
	else if(v->left != NULL && v->right == NULL){
		v->left->parent = v->parent;
		
		//se v for filho à esquerda
		if(v->parent->left == v){
			v->parent->left = v->left;
		}
				
		//se v for filho à direita
		else{
			v->parent->right = v->left;
		}	
	}
	
	//se v tem só um filho à direita
	else if(v->right != NULL && v->right == NULL){
		v->right->parent = v->parent;

		//se v for filho à esquerda
		if(v->parent->left == v){
			v->parent->left = v->right;
		}
				
		//se v for filho à direita
		else{
			v->parent->right = v->right;
		}		
	}
	
	else{
		//procura o menor nodo da sub-arvore cuja v é a raiz
		node * minV = minTree(v);
		transplant(v, minV);

	}

	free(v);
}




/*Procura o pai de um nodo*/
node * findParent(node * r, int key){
	node * p = NULL;
	node * n = r;
	
	while(1){
		if(n->key == key){
			return p;
			break;
		}
		
		else if(key > n->key){
			p = n;
			n = n->right;
		}
		
		else if(key < n->key){
			p = n;
			n = n->left;
		}		
	}
}

//mostra todas as chaves da árvore
void * print(node * r){
	node * aux = r;
	
	for(aux = r; aux!=NULL; aux = aux->left){
		printf("%d ",aux->key); 
	}
	
	for(aux = r->right; aux!=NULL; aux = aux->right){
		printf("%d ", aux->key);
	}
}

void * printOrdenado(node * r){
	node * aux = r;
	
	
}



//remove o nodo da árvore com raiz r que possui chave igual a key
//(lembra que tem que dar free no nodo)
void remove(node * r, int key);

int main(void){
	
	int n;
	node * root = NULL;
	
	while(scanf("%d", &n)){
		root = insert(root,n);
	}
	
	int x = 3;

	//printf("minimo da sub 3 %d\n", minTree(search(root, 3))->key);
		
	imp(root, 0);
//	deleteNode(root, x);
	printf("\n\n");
	//imp(root,0);
	
	transplant(search(root, 3), search(root, 7));
	imp(root,0);
	
	return 0;
}









