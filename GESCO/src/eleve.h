/*******************************************************
    Nom        : eleve.h

    Desription : Définition des structures et des fonctions
                 associées  à la gestion d'un eleve.

    Auteur     : K.Z

********************************************************/

#include "fratrie.h"
#include "contact.h"
#include "date.h"
#include "coord.h"
#include "definition.h"
#include "annexe.h"

#ifndef ELEVE_H
#define ELEVE_H

typedef struct eleve
{
	char nom[MAX_CHAR ];		// Nom de l'élève
	char prenom[MAX_CHAR ];		// Prenom de l'élève
	char redoublement;			// Si l'eleve est redoublant
	char restauration;			// Si l'eleve est 1/2 pensionnaire
	char genre;                 // Si fille ou garçon
	int nb_fratrie;				// Nombre de personnes dans la fratrie
	time_t date_naissance;		// Date de naissance de l'élève
	fratrie_t tab_fratrie[9];	// Les frere(s)/soeur(s) de l'élève
	contact_t tab_contact[2];	// Les personnes à contacter 
	coord_t adresse;			// Adresse de l'élève
	struct eleve *suivant;      // Pointeur sur eleve suivant
}eleve_t;

///-----------------------------------------------------------------------------
/// Fonction  : Affichage des informations d'un élève
/// paramètre : struct eleve_t
void Afficher_Eleve(eleve_t el);

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Saisie des informations d'un élève
/// paramètre : * sur struct eleve_t 
void Saisir_Eleve(eleve_t *el);

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier le nom de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Nom(eleve_t *el);

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier le prénom de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Prenom(eleve_t *el);

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier la donnée "redoublement" 
/// paramètre : * sur struct eleve_t 
void Modifier_Redoublement(eleve_t *el);

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier la donnée "restauration" 
/// paramètre : * sur struct eleve_t 
void Modifier_Restauration(eleve_t *el);

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier le genre de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Genre(eleve_t *el);

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier la date de naissance de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Date(eleve_t *el);

#endif// ELEVE_H

