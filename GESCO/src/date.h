/*******************************************************
    Nom        : date.c

    Desription : Définition des fonctions associées  à
                 la gestion des dates.

    Auteur     : T.C
                 R.P

********************************************************/

#include "annexe.h"
#include "definition.h"

#ifndef DATE_H
#define DATE_H

//-----------------------------------------------------------------------------
//  Description : Affichage formaté (jj/mm/aaaa) d'une date
//  parametre   : date au format time_t
void ft_afficherDate(time_t date);

//-----------------------------------------------------------------------------
//  Description : calcul age de l'eleve
//  parametre   : date au format time_t
int ft_calculAgeEleve(time_t dateNaissance);

//-----------------------------------------------------------------------------
//  Description : calcul si année de date est bisextile
//  parametre   : année au format int
int ft_bissextile (int aaaa);

//-----------------------------------------------------------------------------
//  Description : Verification de saisi de date
//  parametre   : 3 int (jour, mois, année)
int ft_dateCorrecte (int jj, int mm, int aaaa);

//-----------------------------------------------------------------------------
//  Description : Saisi d'une date au format jj/mm/aaaa
//  retour      : date au format time_t
time_t ft_saisieDate();

#endif// DATE_H

