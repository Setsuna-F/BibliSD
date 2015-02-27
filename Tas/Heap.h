/**
 * \file Heap.h
 * \author Zevio.S et Benharchache.S
 * \brief Fichier d'en-tete du tas (heap)
 * \date 18 decembre 2014
 */

#ifndef SOFIEN_STELLA__HEAP_H__
#define SOFIEN_STELLA__HEAP_H__


/**
 * \struct heap_struct
 * \brief Une structure de tas
 *
 * Struct_heap est une structure pour manipuler les tas.
 * On a une taille qui correspond a la taille visuel (par l'utilisateur) 
 * et la taille reel qui a ete allouee a la machine.
 *
 */
struct heap_struct{
	size_t size;		/*!< Taille (manipulable) visible par l'utilisateur. */
	size_t capacite;	/*!< Taille reel qui a ete allouee (elle est egale a deux ois taille de size). */
	void ** heap;		/*!< Tableau dynamique qui constitu notre tas. */
};

typedef struct heap_struct* Heap;




/**
 * \fn Heap creerTas(size_t nb)
 * \brief Fonction constructeur pour creer un tas
 *
 * \param nb Taille du tableau a allouer.
 * \return Un pointeur sur la structure tas.
 */
Heap Tas_creer(size_t nb);


/**
 * \fn Heap creerTasParCopie(Heap h)
 * \brief Fonction constructeur par copie pour creer un tas
 *
 * \param h Le tas a copier.
 * \return un pointeur sur la structure tas qui sera une copie de h.
 */
Heap Tas_creerTasParCopie(Heap h);


/**
 * \fn Heap Tas_detruire(Heap h)
 * \brief Fonction destructeur de la structure tas.
 *
 * \param h Le tas a detruire.
 * \return un pointeur sur la structure tas qui sera desalouee.
 */
Heap Tas_detruire(Heap h);


/**
 * \fn void afficherTas(Heap h);
 * \brief Fonction qui affiche le tas sous forme d'un tableau.
 *
 * \param h Le tas a afficher.
 */
void Tas_afficher(Heap h);


/**
 * \fn size_t taille(const Heap h);
 * \brief Fonction retourne la taille du tableau de tas
 *
 * \param h Le tas qui nous donnnera la taille.
 * \return La taille du tas.
 */
size_t Tas_taille(const Heap h);


/**
 * \fn void ajouter_valeur(Heap h, void* val)
 * \brief Fonction qui ajoute une valeur dans le tas.
 * 
 * \param h Le tas auquel on va lui ajouter une valeur.
 * \param val La valeur a ajouter.
 * \return Le tas avec la valeur ajoute.
 */
void Tas_ajouter_valeur(Heap h, void* val);

/**
 * \fn Heap concatener_heap(Heap h, const Heap h2)
 * \brief Fonction qui concatener deux tas.
 * 
 * \param h Le tas auqeuel on ajoute h2.
 * \param h2 Le tas qui sera ajoute a h.
 * \return h La concatenation de h et h2 */
Heap Tas_concatener(Heap h, const Heap h2);


/**
 * \fn int estVide_heap(Heap h)
 * \brief Fonction dit si le tas est vide ou non.
 * 
 * \param h Le tas dont on va verifier s'il est vide.
 * \return 1 Si le tas est vide.
 * \return 0 Sinon
 */
int Tas_estVide(Heap h);


/**
 * \fn Heap enlever_valeur(size_t i, Heap h)
 * \brief Fonction qui enleve l'element qui se trouve a la position i dans le tas
 *
 * \param i L'indice de la valeur a supprimer.
 * \param h Le tas ou l'on va supprimer la valeur.
 * \return le tas h avec la valeur enleve si elle est bien inferieur la taille du tas
 */
Heap Tas_enlever_valeur(size_t i, Heap h);



#endif




