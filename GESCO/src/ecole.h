/*******************************************************
    Nom        : ecole.h

    Desription : Définition d'une structure ecole
                 et des fonctions associées

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
#include "classe.h"
#include "date.h"

#ifndef ECOLE_H
#define ECOLE_H

typedef struct ecole_t
{
    char     nom[MAX_CHAR];         // Nom de l'école
    char     directeur[MAX_CHAR];   // Nom du directeur
    time_t   date;                  // Date en cours
    coord_t  adresse;               // Coordonnée de l'école
    int      nombreClasse;          // Nombre de classe total dans l'ecole
    classe_t *tab_cp[MAX_CLASSE];   // Tableau de pointeur sur les classes
    classe_t *tab_ce1[MAX_CLASSE];
    classe_t *tab_ce2[MAX_CLASSE];
    classe_t *tab_cm1[MAX_CLASSE];
    classe_t *tab_cm2[MAX_CLASSE];
}ecole_t;

// Prototypes fonctions
///////////////////////////////////////////////////////////////////////////////ENTETE
//-----------------------------------------------------------------------------
//  Description : affiche une entete
//  parametre   : structure ecole_t
void ft_afficheEntete(ecole_t ecole);

///////////////////////////////////////////////////////////////////////////////RELATIF A ECOLE (AFFICHER, SAISIR, MODIFIER)
//-----------------------------------------------------------------------------
// Description : Afficher le contenu de l'ecole
// parametre   : struct ecole_t
void ft_afficherEcole(ecole_t ecole);

//-----------------------------------------------------------------------------
// Description : Saisir le contenu de l'ecole
// parametre   : * sur struct ecole_t
void ft_saisirEcole(ecole_t *ecole);

//-----------------------------------------------------------------------------
// Description : Modiffier le contenu de l'ecole
// parametre   : * sur struct ecole_t
void ft_modifierEcole(ecole_t *ecole);

///////////////////////////////////////////////////////////////////////////////RELATIF A RECHERCHE ELEVE DANS ECOLE
//-----------------------------------------------------------------------------
// Description : Recherche eleve dans struct classe_t dans struct ecole_t
// parametre   : struct ecole_t
//               * sur struct eleve_t
int ft_rechercheEleveEcole(ecole_t ecole, eleve_t **eleveChercher, classe_t **teteClasse);
///////////////////////////////////////////////////////////////////////////////RELATIF A SUPPRESSION D'UNE CLASSE
//-----------------------------------------------------------------------------
// Description : Modiffier le contenu de struct ecole_t
//               appelle ft_viderListe
// parametre   : * sur struct ecole_t
void ft_supprimerClasse(ecole_t *ecole);

//-----------------------------------------------------------------------------
// Description : Vide une liste d'eleve
// parametre   : double * sur struct ecole_t
void ft_viderListe(eleve_t **eleve);

///////////////////////////////////////////////////////////////////////////////RELATIF A INSCRIPTION D'UN ELEVE
//-----------------------------------------------------------------------------
// Description : Affecte eleve à un niveau selon son age
//               Appelle ft_affecterEleveClasse
// parametre   : pointeur sur struct ecole_t
//               pointeur sur struct eleve_t
void ft_affecterEleveNiveau(ecole_t *ecole, eleve_t **eleve);

//-----------------------------------------------------------------------------
// Description : Affecte eleve à une classe selon effectif
//               appelle ft_insererEleveClasse
//               et appelle ft_creerNouvelleClasse (si besoin)
// parametre   : * sur struct classe_t (classe1)
//               * sur struct classe_t (classe2)
void ft_affecterEleveClasse(classe_t **classe1, classe_t **classe2, eleve_t **eleve);

//-----------------------------------------------------------------------------
// Description : Inserre eleve dans une classe selon ordre alphabétique
// parametre   : * sur struct classe_t
//               * sur struct eleve_t
void ft_insererEleveClasse(classe_t *classe, eleve_t **eleve);

//-----------------------------------------------------------------------------
// Description : Coupe une classe pleine en 2 classes
// parametre   : * sur struct classe_t (classe pleine)
//               * sur struct classe_t (classe a creer)
void ft_creerNouvelleClasse(classe_t *classePleine, classe_t *classeNouvelle);


void ft_creerClasse(classe_t **classe);






#endif // ECOLE_H

