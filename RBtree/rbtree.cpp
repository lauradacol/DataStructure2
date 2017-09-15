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

int main(){

return 0;
}










