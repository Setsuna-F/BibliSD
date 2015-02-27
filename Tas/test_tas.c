/**
 * \file test_tas.c
 * \author Zevio.S et Benharchache.S
 * \brief Fichier de test sur les fonction de tas
 * \date 18 decembre 2014
 */

#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

int main(){
	Heap h=NULL;
	h = Tas_creer(0);
/*	afficherTas(h);

	printf("%s  :   le pointeur est de %p\n", __FUNCTION__, h);
	FREE(h)
	printf("%s  :   le pointeur est de %p\n", __FUNCTION__, h);
*/
	printf("\n");

	printf("%s\n", "=======  ajouter_valeur  ========");
	Tas_ajouter_valeur(h, (void*)42);
	Tas_ajouter_valeur(h, (void*)23);
	Tas_ajouter_valeur(h, (void*)07);
	Tas_afficher(h);


	printf("%s\n", "\n=======  concatener  ========");
	Heap h2=NULL;
	h2=Tas_concatener(h2, h);
	h2=Tas_concatener(h2, h);
	Tas_afficher(h2);



	printf("%s\n", "\n=======  estVide  ========");
	if(Tas_estVide(h2))
		printf("h2 est vide !!!\n");
	else
		printf("h2 n'est pas vide !!!\n");


	printf("%s\n", "\n=======  ajouter variable  ========");
	int j=666;
	int*val=(int*)malloc(sizeof(int));
	val=(void *)(intptr_t)j;
	Tas_ajouter_valeur(h2, val);
	Tas_afficher(h2);

	printf("%s\n", "\n=======  creer tas par copie  ========");
	Heap h3 = Tas_creerTasParCopie(h2);
	Tas_afficher(h3);


	printf("%s\n", "\n=======  enlever element du tas  ========");
	h3 = Tas_enlever_valeur(3, h3);
	h3 = Tas_enlever_valeur(3, h3);
	h3 = Tas_enlever_valeur(3, h3);
	h3 = Tas_enlever_valeur(3, h3);
	h3 = Tas_enlever_valeur(3, h3);
	Tas_afficher(h3);


	printf("%s\n", "\n=======   supprimer un tas  ========");
	Tas_afficher(h);
	h=Tas_detruire(h);
	Tas_afficher(h);
	return 0;
}





