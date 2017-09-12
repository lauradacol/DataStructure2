#include<stdio.h>
#include<stdlib.h>

struct node{
	int key; //chave de identificação do nodo
	node * left, * right; //ponteiro para os filhos
};

node * insert2(node * r, int key){
	node * aux = r;	
	
	node * n = (node*)malloc(sizeof(node));
	n->key = key;
	n->left = n->right = NULL;
	
	if(r == NULL){
		return n;
	}
	
	while(1){
		if(key < aux->key){
			if(aux->left == NULL){
				aux->left = n;
				return r;
			}
			else{
				aux = aux->left;
			}
		}
		
		else{
			if(aux->right == NULL){
				aux->right = n;
				return r;
			}
			else{
				aux = aux->right;
			}			
		}
		
	}		
	
}

//busca por uma chave k na árvore com raiz r
//caso a chave não estiver na árvore retorna NULL
node * search(node * r, int key){
	if(!r || r->key == key){
		return r;
	}
	if(key <= r->key){
		return search(r->left, key);	
	}
	
	return search(r->right, key);
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

//in Order
int inOrder(node * t){
	if(t!=NULL){
		inOrder(t->left);
		
		printf("%d ", t->key);
		
		inOrder(t->right);
	}	
}

//insere um nodo com chave key na árvore com raiz r
//retorna um ponteiro para a raiz da árvore
node * insert(node * r, int key){
	node * it = r;
	
	node * n = (node *)malloc(sizeof(node)); //cria um novo nodo
	n->left = n->right = NULL;
	n->key = key;
	
	if(!r){
		return n; //se a árvore estiver vazia
	}
	
	while(1){
		if(key < it->key){
			if(!it->left){
				it->left = n; //atualiza o filho da esquerda de r
				return r;
			}
			it = it->left;
		}
		else{
			if(!it->right){
				it->right = n;
				break;
			}
			it = it->right;
		}
	}
	
	return r;
}

//remove o nodo da árvore com raiz r que possui chave igual a key
//(lembra que tem que dar free no nodo)
void remove(node * r, int key);

int main(void){
	
	int n;
	node * root = NULL;
	
	while(scanf("%d", &n)){
		root = insert2(root,n);
	}
	
	if(search(root, 7)){
		printf("achou\n");
		}
	else{
		printf("nao achou\n");
	}
	
	inOrder(root);
	
	return 0;
}









