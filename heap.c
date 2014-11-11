/*
	Autor: Samuel Toyoshi Ishida
*/

#include "heapVet.h"

int main() {
	Heap *h;
	int i;
	
	h = malloc(sizeof(Heap));
	(*h).tam = 10;
	
	for(i=0; i<(*h).tam; i++)
		scanf("%d",&((*h).vetor[i]));
		
	/*ConstroeHeapSubindo(h);*/
	/*ConstroeHeapDescendo(h);*/
	HeapSort(h);
	
	for(i=0; i<(*h).tam; i++)
		printf("%d ",(*h).vetor[i]);
	
	free(h);
	
	return 0;
}