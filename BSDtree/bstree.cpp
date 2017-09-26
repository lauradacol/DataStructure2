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

node * getSuccessor(node * nodo){
   node* aux = nodo;
 	
 	//Acha o nodo mais à esquerda (menor)
    while (aux->left != NULL)
        aux = aux->left;
 
    return aux;
}


node * deleteV(node * root, int key){

	//Se a arvore está vazia
	if(root == NULL){
		return root;
	}

	//Se key for maior, vai para direita
	if(key > root->key){
		
		root->right = deleteV(root->right, key);

	//Se key for menor, vai para esquerda
	}else if(key < root->key){
		
		root->left = deleteV(root->left, key);

	//Se achar a chave
	}else{
		
		//Se o nodo tem filhos
		if(root->left == NULL){
			
			node *temp = root->right;
			return temp;

		}else if(root->right == NULL){

			node *temp = root->left;
			return temp;

		}
		
		//Encontrar o sucessor da sub-árvore a direita
		node * successor = getSuccessor(root->right);		
		root->key = successor->key;
		root->right = deleteV(root->right, successor->key);
	}

	return root;

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
	root = insert(root, 20);	
	
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

	int x = 10;
	deleteV(root, x);
	
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









