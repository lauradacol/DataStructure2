#include <stdio.h>
#include <stdlib.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct Funcionario{
    int time, prioridade, id;
    
    Funcionario(int time, int prioridade, int id){
		time = time;
		prioridade = prioridade;
		id = id;
	}
	    
}Funcionario;

typedef struct BHeap{
    int size;
    int count = 0;    
    Funcionario * funcionarios[size];
    
    BHeap(int size){
		size = size;		
	}
       
    Funcionario * insertFunc(int time, int prioridade, int id){
		funcionarios[count] = new Funcionario(time, prioridade, id);
		return funcionarios[count];
		count++;
	}
	
	void swapFunc(Funcionario * f1, Funcionario * f2){
		Funcionario aux = *f1;
		*f1 = *f2;
		*f2 = *aux;
	}
	
	int findPosition(Funcionario * f){
		int position = -1;
		for(int i=0; i<size; i++){
			if(funcionarios[i] == f){
				position = i;
				break;
			}
		}
	}
	
	Funcionario * heapify(Funcionario * f){
		int x = findPosition(f);
		
		//se não tem pai
		if((int((x-1)/2)) == 0){
			return f;
		}	
		
		else{
			Funcionario * pai = funcionarios[int((x-1)/2)];
			
			//se a prioridade do pai for menor
			if(f->prioridade >= pai->prioridade){
				return f;
			}
			
			//se a prioridade do pai for maior
			else{
				swapFunc(f, pai);
				heapify(f);
			}
		}
	}
	
	void insertBHeap(int data, int time, int id){
		Funcionario f = heapify(insertFunc(time, prioridade, id));
	}

	void printHeap(){
		for(int i=0; i<size; i++){
			printf("%d ", funcionarios->time[i]);			
			printf("%d ", funcionarios->prioridade[i]);
			printf("%d\n", funcionarios->id[i]);			
		}
	}
	    
}BHeap;

int main(){

 
}


//https://robin-thomas.github.io/max-heap/
