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
	node * min;
	if(r->right != NULL){
		min = r->right;	
	}
	
	else{
		min = r;
	}
	
	while(min->left !=NULL){
		min = min->left;
	}
	
	return min;
}

/*Troca dois ponteiros de lugar*/
void swap(node ** a, node ** b){
	node * aux1 = *a;
	node * aux2 = *b;
	*a = aux2;
	*b = aux1;	
	
}

/*Retorna o ponteiro para o pai*/
node ** getParent(node * v){
		if(v->parent->left == v){	
			return &(v->parent->left);
		}
		else{
			return &(v->parent->right);	
		}
}

/*Trasplanta dois nodos*/
void transplant(node * v, node * minV){
	swap(&(minV->left), &(v->left));
	swap(&(minV->right), &(v->right));
	
	swap(getParent(v),getParent(minV));
	
	swap(&(minV->parent), &(v->parent));
	
}

/*Deleta um nodo se ele é uma folha*/
void deleteFolha(node * v){
	node ** pai = getParent(v);
	*pai = NULL;	

/*		
	if(v->parent->left == v){
		v->parent->left = NULL;
	}	
	else{
		v->parent->right = NULL;
	}
	*/		
}	


/*Deleta o nodo*/
void * deleteNode(node * r, int key){
	node * v = search(r, key);
	
	//se v é uma folha
	if(v->left == NULL && v->right == NULL){
		deleteFolha(v);
	}

	//se v tem só um filho à esquerda
	if(v->left != NULL && v->right == NULL){
		v->left->parent = v->parent;
		
		//se v for filho à esquerdagit commit --amend --reset-author

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
		deleteFolha(v);
		
	}
	free(v);
}

int main(void){
	
	int n;
	node * root = NULL;

	/*Inserindo chaves na árvore*/
	root = insert(root,10);
	root = insert(root,8);
	root = insert(root,16);
	root = insert(root,3);
	root = insert(root,2);
	root = insert(root,6);
	root = insert(root,1);
	root = insert(root,5);
	root = insert(root,7);	
	
	printf("PERCURSO IN ORDER ANTES DA DELEÇÃO\n");
	inOrder(root);
	
	printf("\n\nPERCURSO PRE ORDER ANTES DA DELEÇÃO\n");
	preOrder(root);	
	
	printf("\n\nPERCURSO POS ORDER ANTES DA DELEÇÃO\n");
	posOrder(root);		
	
	printf("\n\nDESENHO DA ÁRVORE ANTES DA DELEÇÃO\n");	
	drawTree(root, 0);	
	
	printf("\n#########################################\n");
	printf("############ DELETANDO O 3 ##############\n");
	printf("#########################################\n\n");	

	int x = 3;
	deleteNode(root, x);
	
	printf("PERCURSO IN ORDER APÓS DA DELEÇÃO\n");
	inOrder(root);

	printf("\n\nPERCURSO PRE ORDER APÓS DA DELEÇÃO\n");
	preOrder(root);	
	
	printf("\n\nPERCURSO POS ORDER APÓS DA DELEÇÃO\n");
	posOrder(root);
	
	printf("\n\nDESENHO DA ÁRVORE APÓS DA DELEÇÃO\n");	
	drawTree(root, 0);
	
	return 0;
}









