/*******************************************************
    Nom        : classe.h

    Desription : D�finition des structures et des fonctions associ�es  �
                 la gestion d'une classe.

    Auteur     : T.C

********************************************************/

#include "annexe.h"
#include "definition.h"
#include "eleve.h"
#include "date.h"

#ifndef CLASSE_H
#define CLASSE_H

typedef struct classe
{
    char   nom[MAX_CHAR];    // Nom de la classe
    char   prof[MAX_CHAR];   // Nom du professeur de la classe
    int nbeleve;
    eleve_t  *ptr_eleve;   // Pointeur sur le premier �l�ve de la classe
}classe_t;


///-----------------------------------------------------------------------------
/// Fonction : Affichage d'une classe d'�l�ves
/// param�tre entr�e : classe
void ft_afficherClasse (classe_t *classe);


///-----------------------------------------------------------------------------
/// Fonction : Saisie des informations de la classe(nom et prof de la classe)
/// param�tre en mise � jour : classe
void ft_saisirClasse(classe_t *classe);


///-----------------------------------------------------------------------------
/// Fonction : Modifications des champs de la structure classe (nom et prof)
/// param�tre en mise � jour : classe
void ft_modifierClasse(classe_t *classe);


///-----------------------------------------------------------------------------
/// Fonction : Rechercher un �l�ve dans la classe
/// param�tre en mise � jour : classe
int ft_rechercherEleve(classe_t *classe,eleve_t **retour);


///-----------------------------------------------------------------------------
/// Fonction : Suppresion d'un �l�ve de la classe
/// param�tre en mise � jour : classe
void ft_supprimerEleve(classe_t *classe,eleve_t **supprime);





#endif // CLASSE_H
