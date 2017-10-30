#include <cstdio>
#include <iostream>
using namespace std;

//Grau da árvore
const int T = 2;

//Posição do split
const int S = ((2*T)/2)-1;

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
	
	//Encontra o nodo folha para a chave
	Node * findNode(int key){
		if(isLeaf()){
			return this;
		}
		else{
			int i;
			//Encontra a posição no vetor de filhos de parentNode 			
			for(i=0; i<size && this->values[i] < key; i++);
			return(this->sons[i]->findNode(key));
		}
	}
	
	//Insere a chave no nodo certo
	Node * insert(int key){
		this->findNode(key)->insertLeaf(key);
	}
	
	//Dar split no nodo, se ele tá cheio
	Node * split(){
		//Se está cheio, splitar
		if(this->isFull()){
			Node parent = new Node;
			Node rightSon = new Node;
			
			parent->values[0] = this.values[S];
			
			//Copia os valores para o rightSon
			j = 0;
			for(int i=S+1; i<size; i++){
				rightSon->values[j] = this.values[i];
				j++;
			}
			
			//Apaga os valores do nodo original
			for(int i=S; i<size; i++){
				this.values[i] = 0;
			}
			size = S;
			
			//Arruma os filhos
			parent->sons[0] = this;
			parent->sons[1] = rightSon;
			
			return parent;			
		}
		
		//Se o nodo não está cheio
		else{
			return this;
		}
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
	
	//Construtor		
	Tree(){
		root = new Node;
	}		
			
	//Retorna true se a árvore está vazia
	bool isEmpty() {return root == NULL;}

	//Achar o nodo folha correto para a chave
	Node * findNode(int key){
		return this->root->findNode(key);
	}	
	
	//Função de inserir	
	Node * insert(int key){
		return this->root->insert(key);
	}
};

int main(){
	
	Tree * t = new Tree();
		
	t->insert(6);
	t->insert(4);
	t->insert(8);
	t->insert(10);
	
	//cout << (t->root->isFull() ? "Cheia\n" : "Não cheia\n");
	
	/*
	
	Node * n1 = new Node();
	n1->insertLeaf(4);
	t->root->sons[0] = n1;
	
	Node * n2 = new Node();
	n2->insertLeaf(8);
	n2->insertLeaf(20);
	t->root->sons[1] = n2;
		*/
				
	
	t->root->printNodo();
	t->root->printFilho();	
				
}



