/*******************************************************
    Nom        : InOut.h

    Desription : Définition des structures et des fonctions associées  à
                 la gestion d'une classe.

    Auteur     : T.C
                 C.H.L

********************************************************/

#include "annexe.h"
#include "definition.h"
#include "ecole.h"
#include "date.h"

#ifndef INOUT_H
#define INOUT_H

///-----------------------------------------------------------------------------
/// Fonction : Impression informations eleve
/// paramètre en lecture : eleve
void ft_imprimerEleve(eleve_t el,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Impression informations classe
/// paramètre en lecture : classe
void ft_imprimerClasse(classe_t cl,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Impression informations ecole
/// paramètre en lecture : ecole
void ft_imprimerEcole(ecole_t ec,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Exportation informations ecole
/// paramètre en lecture : ecole
void ft_exporterEcole(ecole_t ec,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Importation informations ecole
/// paramètre en mise à jour : ecole
void ft_importerEcole(ecole_t ec,char n_f[MAX_CHAR]);

#endif // INOUT_H

