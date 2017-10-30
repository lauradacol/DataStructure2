#include <cstdio>
#include <iostream>
using namespace std;

//Grau da árvore
const int T = 3;

struct Node {
	long my_pos;
	int size = 0;
	int values[2*T] = {0};
	Node * sons[2*T+1];

	//Retorna true se não há filhos
	bool isLeaf() {return sons[0] == NULL;}

	//Preenche o vetor de filhos com -1 para indicar que está vazio
	/*
	Node() {
		for(int i = 0; i < 2*T; ++i) sons[i] = -1;
	}*/

	//Retorna true se o nodo está vazio
	bool isEmpty() {return size == 0;}

	//Retorna true se o nodo está cheio
	bool isFull() {return size >= 2*T;}

	//Procura a posição da chave, desloca as outras chaves para frente e insere
	void insertLeaf(int key){
		int i=0;
		for(i=0; i<size && (values[i] < key); i++);
				
		for(int j=size; j>=i; j--){
			values[j+1] = values[j];
		}
		
		values[i] = key;
		size++;
	}
	
	//Imprime o nodo
	void printNodo(){
		printf("Nodo: ");
		for(int i=0; i<size; i++){
			printf("%d ", values[i]);
		}
		printf("\n");
	}
	
	void printFilho(){
		printf("Filhos:\n");
		if(sons[0] != NULL){
			for(int i=0; sons[i] != NULL; i++){			
				sons[i]->printNodo();
			}	
			printf("\n");
		}
		else{
			printf("Sem filhos\n");
		}		
		
	}	
  
};

struct Tree{
	Node * root;
	long position;
	
	//Retorna true se a árvore está vazia
	bool isEmpty() {return root == NULL;}
	
	//Insere na raiz
	void insertRoot(int key){		
		this->root = new Node();
		root->insertLeaf(key);
		//return this->root;
	}
	
	//Achar o nodo folha correto para a chave
	Node * findNode(Node * parentNode, int key){

		//Enquanto o nodo não for folha
		while(!(parentNode->isLeaf())){
			int i;
			//Encontra a posição no vetor de filhos de parentNode 			
			for(i=0; (i<parentNode->size && key>parentNode->values[i]); i++);
			
			//Chama recursivamente a função para o nodo filho
			findNode(parentNode->sons[i], key);						
		}
		
		parentNode->insertLeaf(key);
		//parentNode.split();		
		return parentNode;			
	}
	
	//Função de inserir
	void * insert(int key){
		if(this->isEmpty()){
			insertRoot(key);
		}
		else{
			findNode(root,key)->insertLeaf(key);
		}
		
		//this->isEmpty() ? insertRoot(key) : findNode(root, key);
	}
};

int main(){
	
	Tree * t = new Tree();
		
	t->insert(6);
	
	Node * n1 = new Node();
	n1->insertLeaf(4);
	t->root->sons[0] = n1;
	
	Node * n2 = new Node();
	n2->insertLeaf(8);
	n2->insertLeaf(20);
	t->root->sons[1] = n2;
	
	//cout << (t->root->isLeaf() ? "É folha" : "Não é folha");
	
	t->insert(10);			
	t->root->printNodo();
	t->root->printFilho();	
				
}



