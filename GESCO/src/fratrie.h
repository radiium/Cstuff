/*******************************************************
    Nom        : fraterie.h

    Desription : Définition des structures et des fonctions associées  à
                 la gestion des frere(s) et soeur(s) de eleve.

    Auteur     : C.H.L

********************************************************/

#include "annexe.h"
#include "definition.h"

#ifndef FRATRIE_H
#define FRATRIE_H

// ce fichier contient la définition de la variable fratrie

// définition de la structure
typedef struct fratrie
{
	char nom[MAX_CHAR];
	char prenom[MAX_CHAR];
	time_t date_nais;
	char scolarise_ec;
} fratrie_t;

// fonction qui permet de saisir les informations d'un frere ou une soeur
void Saisir_Fratrie(fratrie_t *f,int i);

// fonction qui affiche les frères et soeurs de l'élève
void Afficher_Fratrie(fratrie_t f,int i);

// fonction qui permet de modifier les informations d'une personne de la fratrie
void Modifier_Fratrie(fratrie_t *f,int i);

// fonction qui permet de modifier le nom d'un frère ou une soeur de l'élève
void Modifier_NomFratrie(fratrie_t *f,int i);

// fonction qui permet de modifier le prenom d'un frère ou une soeur de l'élève
void Modifier_PrenomFratrie(fratrie_t *f,int i);


// fonction qui permet de modifier l'age d'un frère ou une soeur de l'élève
void Modifier_AgeFratrie(fratrie_t *f,int i);

// fonction qui permet de modifier si un frère ou une soeur de l'élève est scolarisé(e) ou non dans l'école
void Modifier_ScolFratrie(fratrie_t *f,int i);

#endif// FRATRIE_H

