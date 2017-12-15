#include <stdio.h>
#include <stdlib.h>
#include <iostream>      
#include <queue>         

int main(){
	
	/*Fiz duas heaps, vou dando pop em uma conforme o caixa pega um cliente
	 * e adicionando para que este caixa atenda outro cliente se restar na fila
	 */
	std::priority_queue<int> cashier;
	std::priority_queue<int> cashier2;
		
	/*Variávies com a quantidade de caixas e clientes*/	
	int cash, cli;
		
	std::cin >> cash;
	std::cin >> cli;
	
	/*Os clientes podem ser um vetor*/
	int cliVector[cli];
	
	/*Adiciona os caixas na primeira heap (cashier)*/
	int i;
	for(i=0; i<cash; i++){
		int v;
		std::cin >> v;
		cashier.push(v*(-1));		
	}
	
	/*Adiciona os clientes no vetor*/
	for(i=0; i<cli; i++){		
		std::cin >> cliVector[i];	
	}
	
	int result1 = 0, result2 = 0;
	for(i=0; i<cli; i++){
	
		/*Se minha heap cashier não está vazia, calculo o tempo com o 
		 * caixa e o cliente da vez, adiciono este caixa na cashier2 e 
		 * removo da cashier*/
		if(!cashier.empty()){
			int time = cliVector[i]*(cashier.top()*-1);				
			if(time>result1){
				result1 = time;
			}
			cashier2.push(cashier.top());
			cashier.pop();		
		}

		/*Se minha heap cashier2 não está vazia, calculo o tempo com o 
		 * caixa e o cliente da vez, adiciono este caixa na cashier e 
		 * removo da cashier2*/		
		else if(!cashier2.empty()){			
			int time = cliVector[i]*(cashier2.top()*-1);			
			if(time>result2){
				result2=time;
			}
			cashier.push(cashier2.top());
			cashier2.pop();	
		}
	}
	
	/*Teoricamente o resultado é a soma dos tempos calculados, mas não 
	 * tá bem certo essa lógica*/
	std::cout << result1+result2 << '\n';
	
}
