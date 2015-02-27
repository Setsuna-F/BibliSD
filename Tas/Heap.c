/**
 * \file Heap.c
 * \author Zevio.S et Benharchache.S
 * \brief Fichier source
 * \date 18 decembre 2014
 */

#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

Heap Tas_detruire(Heap h){//ALGO POUR LES FREE()
	if(h != NULL){
		if(h->heap != NULL){
			free(h->heap);
			h->heap = NULL;
		}
		free(h);
		h = NULL;
	}
	return h;
}


// Constructeur 
Heap Tas_creer(size_t nb){
	Heap h;

	if((h = malloc(sizeof(struct heap_struct))) == NULL){
		fprintf(stderr, "errueut lors de l'allocation de memoir de la structure");
		exit(1);
	}
	h->size=nb;
	if(nb < 1)
		h->capacite=1;
	else
		h->capacite=h->size*2;
	if((h->heap = malloc(h->capacite*sizeof(void*))) == NULL){
		fprintf(stderr, "errueut lors de l'allocation de memoir du tas");
		h=Tas_detruire(h);
		exit(1);
	}
//	printf("%s  :   le pointeur est de %p\n", __FUNCTION__, h);
	return h;
}


// Constructeur par copie des elements de h2 dans h1.
Heap Tas_creerTasParCopie(Heap h2){
	Heap h;
	if((h = malloc(sizeof(struct heap_struct))) == NULL){
		fprintf(stderr, "errueut lors de l'allocation de memoir de la structure");
		exit(1);
	}
	if(h2){

		h->size = h2->size;
		h->capacite = h2->capacite;

		if((h->heap = malloc(h->capacite*sizeof(void*))) == NULL){
			fprintf(stderr, "errueut lors de l'allocation de memoir du tas");
			h=Tas_detruire(h);
			exit(1);
		}

		for(size_t i=0; i<h->size; i++)
			h->heap[i] = h2->heap[i];
	}
	return h;
}


void Tas_afficher(Heap h){ 
	//printf("%s  :   le pointeur est de %p\n", __FUNCTION__, h);
	if(h != NULL){
		//printf("size a une valeur de %zu\nLa capacite est de %zu\nLes valeur sont: \n", h->size, h->capacite);
		for(size_t i = 0; i<h->size; i++)
			printf("%d ", (int)h->heap[i]);
		printf("\n");
	}
}

size_t Tas_taille(const Heap h){
	return h->size;
}

void Tas_ajouter_valeur(Heap h, void* val){
	if(h){
		if(h->size == h->capacite){
			h->capacite*=2; //On  double la capacite
			h->heap = realloc(h->heap, h->capacite * sizeof(void*));
		}
	}
	else{
		h = Tas_creer(0);
	}
	h->size++;
	h->heap[h->size-1] = val;
}

Heap Tas_concatener(Heap h, const Heap h2){
	if(!h){
		h=Tas_creer(h2->size);
		h->capacite = h2->capacite;
		for (size_t i = 0; i < h2->size; i++){
			h->heap[i] = h2->heap[i];
		}
	}
	else{
		h->size += h2->size; 
		h->capacite += h2->capacite;
		h->heap = realloc(h->heap, (h->size + h2->size) * sizeof(void*));
		for(size_t i = (h->size - h2->size), j=0 ; i<h->size; i++, j++){
			h->heap[i] = h2->heap[j];
		}
	}
	return h;
}

int Tas_estVide(Heap h){
	return h->size==0;
}

Heap Tas_enlever_valeur(size_t position, Heap h){
	if(h->size <position){
		fprintf(stderr, "l'indice est trop eleve %zu %zu\n", h->size, position);
		exit(1);
	}
	Heap htemp;
	htemp = Tas_creer(h->size-1);

	size_t j=0;
	for (size_t i = 0; i < h->size; ++i){
		if(i == position)
			continue;
		else
			htemp->heap[j++]=h->heap[i];
	}
	return htemp;
}


