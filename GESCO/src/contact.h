/*******************************************************
    Nom        : contact.c

    Desription : Définition des structures et des fonctions associées  à
                 la gestion des coordonnées

    Auteur     : C.H.L

********************************************************/

#include "annexe.h"
#include "definition.h"

#ifndef CONTACT_H
#define CONTACT_H

// définition de la structure contact_t
typedef struct
{
	char nom[MAX_CHAR];
	char prenom[MAX_CHAR];
	char tel[11];
} contact_t;


// fonction qui permet de saisir les informations d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Saisir_Contact(contact_t *c,int i);


// fonction qui affiche un contact de l'élève
// paramètre en entrée : c,i
void Afficher_Contact(contact_t c,int i);


// fonction qui permet de modifier les informations d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_Contact(contact_t *c,int i);


// fonction qui permet de modifier le nom d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_NomContact(contact_t *c,int i);


//fonction qui permet de modifier le prenom d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_PrenomContact(contact_t *c,int i);


// fonction qui permet de modifier le numero de telephone d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_TelContact(contact_t *c,int i);

#endif // CONTACT_H
