#include <cstdio>
using namespace std;

//Grau da árvore
const int T = 3;

struct Node {
	long my_pos;
	int size = 0;
	int values[2*T] = {0};
	long sons[2*T+1];

	//Retorna true se não há filhos (se o valor é -1)
	bool leaf() {return sons[0] == -1;}

	//Preenche o vetor de filhos com -1 para indicar que está vazio
	Node() {
		for(int i = 0; i < 2*T; ++i) sons[i] = -1;
	}

	//Retorna true se o nodo está vazio
	bool isEmpty() {return size == 0;}

	//Se o nodo estiver vazio, retorna false. Se não, insere a chave e retorna true
	int insertLeaf(int key){
		int i=0;
		for(i=0; i<size && (values[i] < key); i++);
				
		for(int j=size; j>=i; j--){
			values[j+1] = values[j];
		}
		
		values[i] = key;
		size++;
	}
	
	void printNodo(){
		for(int i=0; i<2*T; i++){
			printf("%d ", values[i]);
		}
		printf("\n");
	}	
  
};

struct Tree{
	Node * r;
	long position;
};

/*
Tree * initTree(){
	Tree * t = malloc(sizeof(Tree));
	t->r = malloc(sizeof(Node));	
	
	return t;	
}*/

int main(){
	Node n;
	
	n.insertLeaf(3);
	n.printNodo();	
	n.insertLeaf(5);
	n.printNodo();	
	n.insertLeaf(4);
	n.printNodo();			
	n.insertLeaf(1);
	n.insertLeaf(5);
	n.printNodo();
	
	
			
}

