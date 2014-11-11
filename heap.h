/*
	Autor: Samuel Toyoshi Ishida
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
	int vetor[MAX];
	int tam;
} Heap;

void Sobe(Heap *h, int m){
	int j = (m-1)/2;/*pai*/
	int x = (*h).vetor[m];/*salva o valor atual*/
	
	/*enquanto nao chegar na raiz vai subindo no heap*/
	while(m > 0 && (*h).vetor[j] < x){
		(*h).vetor[m] = (*h).vetor[j];
		m = j;
		j = (j-1)/2;
	}
	
	(*h).vetor[m] = x;
}

void Desce(Heap *h, int m){
	int k = 2*m+1;/*filho da esquerda*/
	int x = (*h).vetor[m];/*salva o valor atual*/
	
	while(k < (*h).tam){
		if(k < (*h).tam-1 && (*h).vetor[k] < (*h).vetor[k+1])
			k++;/*seleciona o filho maior*/
		if(x < (*h).vetor[k]){
			(*h).vetor[m] = (*h).vetor[k];
			m = k;
			k = 2*k+1;
		}
		else
			break;
	}
	
	(*h).vetor[m] = x;
}

void ConstroeHeapSubindo(Heap *h){
	int i;
	
	for(i=1; i<(*h).tam; i++)
		Sobe(h,i);
}


void ConstroeHeapDescendo(Heap *h){
	int i;
	
	for(i=((*h).tam-2)/2; i>=0; i--)
		Desce(h,i);
}

void InsereHeap(Heap *h, T x) {
	vetor[(*h).tam] = x ; /* insere no final do vetor */
	((*h).tam)++ ;
	Sobe(h, ((*h).tam-1) ; /* coloca x na posicao correta */
} /* InsereHeap */

