#include <stdio.h>
#include <stdlib.h>

#include "listegmp.h"

/*! \file      listegmp.c
 *  \brief     Fichier contenant les différentes fonctions de listes necessaires
 *  \author    ROBIN JORAN
 *  \author    BOUDO IBRAHIM
 *  \author    SLIMANI AREZKI
 *  \version   1.00
 *  \date      24 fevrier 2019
 */

/*! \fn listegmp creer_listegmp()
 *  \brief Fonction qui créer une liste vide
 *  \return retourne la liste vide
 */
listegmp creer_listegmp()
{
	return NULL;
}

/*! \fn listegmp ajoute_elem_debutgmp(listegmp l,mpz_t i,int p)
 *  \brief Fonction qui ajoute au début un élément dans la liste
 *  \param l : liste l
 *  \param i : valeur i à ajouter
 *  \param p : entier p représenant la primalité
 *  \return retourne la liste vide
 */
listegmp ajoute_elem_debutgmp(listegmp l,mpz_t i,int p)
{
	listegmp new = malloc(sizeof(struct elemgmp));
	
	mpz_init(new->val);
	mpz_set(new->val,i);
	
	new->primalite = p;
	new->suiv = l;
	
	return new;
}

/*! \fn int est_videgmp(listegmp l)
 *  \brief Fonction qui permet de savoir si une liste est vide ou non
 *  \param l : liste l
 *  \return retourne 1 si la liste est vide ,sinon 0
 */
int est_videgmp(listegmp l)
{
	if(l == NULL)
		return 1;
	return 0;
}

/*! \fn void affiche_listegmp(listegmp l)
 *  \brief Fonction qui permet d'afficher le contenu de la liste
 *  \param l : liste l
 */
void affiche_listegmp(listegmp l)
{
	if(est_videgmp(l))
	{
		gmp_printf("La liste est vide \n");
		return;
	}
	while(l)
	{
		gmp_printf("%Zd(%d) ",l->val,l->primalite);
		l = l->suiv;
	}
	gmp_printf("\n");
}

/*! \fn listegmp libere_listegmp(listegmp l)
 *  \brief Fonction qui permet de liberer la liste
 *  \param l : liste l
 *  \return retourne NULL quand la liste est vide
 */
listegmp libere_listegmp(listegmp l)
{
	listegmp tmp;
	
	while(l)
	{
		tmp = l->suiv;

		mpz_clears(l->val,NULL);
		free(l);
		l = tmp;
	}
	return NULL;
}
