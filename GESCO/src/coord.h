/*******************************************************
    Nom        : coord.h

    Desription : D�finition des structures et des fonctions associ�es  �
                 la gestion des coordonn�es.

    Auteur     : T.C

********************************************************/

#include "annexe.h"
#include "definition.h"

#ifndef COORD_H
#define COORD_H

typedef struct coord
{
    char num[4];
    char rue[MAX_CHAR];
    char postal[6];
    char ville[MAX_CHAR];
    char tel[11];
}coord_t;

///-----------------------------------------------------------------------------
/// Fonction : Affichage des coordonn�es
/// param�tre entr�e : coord
void ft_afficherCoord (coord_t coord);


///-----------------------------------------------------------------------------
/// Fonction : Saisie des informations des coordonn�es
/// param�tre en mise � jour : coord
void ft_saisirCoord (coord_t *coord);


///-----------------------------------------------------------------------------
/// Fonction : Modifications des champs de la structure coord
/// param�tre en mise � jour : coord
void ft_modifierCoord (coord_t *coord);

#endif // COORD_H

