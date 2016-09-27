/*******************************************************
    Nom        : coord.h

    Desription : Définition des structures et des fonctions associées  à
                 la gestion des coordonnées.

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
/// Fonction : Affichage des coordonnées
/// paramètre entrée : coord
void ft_afficherCoord (coord_t coord);


///-----------------------------------------------------------------------------
/// Fonction : Saisie des informations des coordonnées
/// paramètre en mise à jour : coord
void ft_saisirCoord (coord_t *coord);


///-----------------------------------------------------------------------------
/// Fonction : Modifications des champs de la structure coord
/// paramètre en mise à jour : coord
void ft_modifierCoord (coord_t *coord);

#endif // COORD_H

