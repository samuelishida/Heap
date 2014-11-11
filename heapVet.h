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

void swap (int *x, int *y) {
     if (x != y) {
         *x ^= *y;
         *y ^= *x;
         *x ^= *y;
     }
 }

void Sobe(Heap *h, int m){
	int j = (m-1)/2;/*pai*/
	
	/*enquanto nao chegar na raiz vai subindo no heap*/
	while(m > 0 && (*h).vetor[j] < (*h).vetor[m]){
		swap(&(*h).vetor[m] , &(*h).vetor[j]);
		m = j;
		j = (j-1)/2;/*vai para o pai*/
	}
	
}

void Desce(Heap *h, int m){
	int k = 2*m+1;/*filho da esquerda*/
	
	while(k < (*h).tam){
		if(k < (*h).tam-1 && (*h).vetor[k] < (*h).vetor[k+1])
			k++;/*seleciona o filho maior*/
		if((*h).vetor[m] < (*h).vetor[k]){
			swap(&(*h).vetor[m] , &(*h).vetor[k]);
			m = k;
			k = 2*k+1;/*vai para o filho*/
		}
		else
			break;
	}

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

void InsereHeap(Heap *h, int x) {
	(*h).vetor[(*h).tam] = x ; /* insere no final do vetor */
	((*h).tam)++ ;
	Sobe(h, ((*h).tam-1)); /* coloca x na posicao correta */
}

int RemoveHeap (Heap *h) {
	int x = (*h).vetor[0] ; /* remove a raiz */
	((*h).tam)-- ;
	(*h).vetor[0] = (*h).vetor[(*h).tam] ;
	Desce(h,0) ; /* força a raiz nova */
	return x;
}

void HeapSort(Heap *h)
{
	int i;
	int n = (*h).tam;
	
	/*ConstroeHeapSubindo(h);*/
	ConstroeHeapDescendo(h);
	
	/*ordena*/
	for(i=n-1; i >= 0; i--)
	{
		swap(&((*h).vetor[0]),&((*h).vetor[i]));
		((*h).tam)--;
		Desce(h,0);
	}
	
	(*h).tam = n;
}


