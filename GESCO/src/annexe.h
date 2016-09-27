/*******************************************************
    Nom        : annexe.h

    Desription : Fonctions annexes

    Auteur     : R.P
                 C.H.L
                 T.C

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

#include "definition.h"

#ifndef ANNEXE_H
#define ANNEXE_H

////////////////////////////////////////////////////////
// Fonctions de R.P
////////////////////////////////////////////////////////

/*******************************************************
 Description .. : attend une entrée au clavier pour
                  passer à l'affichage suivant

********************************************************/
void attenteRetour();
/*******************************************************
 Description .. : Vide le buffer de l'entrée standard

********************************************************/
void viderBuffer();
/*******************************************************
 Description .. : Saisi chaine et place '\0' a la fin
 Parametre .... : Chaine + longueur chaine
 Retour ....... : Renvoie : 1 si chaine termine par '\0'
                            (chaine bien saisi et terminé)
                            0 si chaine est NULL
                            (chaine vide)
********************************************************/
int  lireChaine(char *chaine, int longueur);

////////////////////////////////////////////////////////
// Fonctions de C.H.L
////////////////////////////////////////////////////////

/*******************************************************
 Description .. : Controler la saisie d'un numero de telephone
 Paramètre en entrée : t
********************************************************/
int Controle_Telephone(char *t);


/*******************************************************
 Fonction réalisée par C.H.L qui permet de controler si 
 une saisie n'est composée que de chiffres
 paramètre en entrée : s, t
 paramètre en sortie : saisie (1 si la saisie est un 
 entier 0 sinon)
*********************************************************/
int Controle_IntSaisie(char *s,int t);


/*******************************************************
 Fonction réalisée par C.H.L qui permet de controler si  
 un caractère saisie est égal à l'une ou l'autre des 
 deux lettres transmises en entrée
 paramètre en entrée : c, l1 et l2
 paramètre en sortie : saisie (1 si la saisie est égale 
 à l'une ou l'autre des deux lettres transmises 0 sinon)
*********************************************************/
int Controle_Saisie(char c,char l1,char l2);


/********************************************************
 Fonction réalisée par T.C qui permet d'afficher un numero 
 de telephone dans le format 06.21.21.36.35
 paramètre en entrée : 	t
**********************************************************/
void ft_affichageTel(char tel[11]);

#endif // ANNEXE_H

