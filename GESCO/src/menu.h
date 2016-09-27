/*******************************************************
    Nom        : menu.h

    Desription : Définition des fonctions de
                 menus et des sous menus associées

    Auteur     : R.P

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

#include "annexe.h"
#include "definition.h"
#include "ecole.h"
#include "date.h"

#ifndef MENU_H
#define MENU_H

///////////////////////////////////////////////////////////////////////////////MENU PRINCIPALE
//-----------------------------------------------------------------------------
//  Description : menu principale
//  parametre   : * sur  struct ecole_t
void ft_menuPrincipale(ecole_t *ecole);

///////////////////////////////////////////////////////////////////////////////SOUS-MENU INSCRIRE (UN ELEVE)
//-----------------------------------------------------------------------------
//  Description : Sous-menu Inscrire (un eleve)
//  parametre   : * sur  struct ecole_t
void ft_menuInscrire(ecole_t *ecole);

///////////////////////////////////////////////////////////////////////////////SOUS-MENU CONSULTER
//-----------------------------------------------------------------------------
//  Description : Sous-menu consulter (eleve, classe, ecole)
//  parametre   : struct ecole_t
void ft_menuConsulter(ecole_t ecole);

//-----------------------------------------------------------------------------
//    Description : sous-menu affiche les informations d'un eleve recherche
//    parametre   : struct ecole_t
void ft_consulterEleve(ecole_t ecole);

//-----------------------------------------------------------------------------
//  Description : Sous-menu affiche les informations d'une classe
//  parametre   : struct ecole_t
void ft_consulterClasse(ecole_t ecole);
// AfficherEcole dans ecole.h

//-----------------------------------------------------------------------------
// Consulter ecole est ft_afficherEcole dans ecole.h

///////////////////////////////////////////////////////////////////////////////SOUS-MENU GERER
//-----------------------------------------------------------------------------
//  Description : Sous-menu gerer (modifier champs ecole, classe ou eleve)
//  parametre   : * sur struct ecole_t
void ft_menuGerer(ecole_t *ecole);

void ft_menuGererEleve(ecole_t *ecole);

void ft_menuGererClasse(ecole_t *ecole);

//-----------------------------------------------------------------------------
// Modifier ecole est ft_modifierEcole dans ecole.h

#endif // MENU_H

