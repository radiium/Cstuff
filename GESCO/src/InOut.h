/*******************************************************
    Nom        : InOut.h

    Desription : D�finition des structures et des fonctions associ�es  �
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
/// param�tre en lecture : eleve
void ft_imprimerEleve(eleve_t el,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Impression informations classe
/// param�tre en lecture : classe
void ft_imprimerClasse(classe_t cl,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Impression informations ecole
/// param�tre en lecture : ecole
void ft_imprimerEcole(ecole_t ec,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Exportation informations ecole
/// param�tre en lecture : ecole
void ft_exporterEcole(ecole_t ec,char n_f[MAX_CHAR]);

///-----------------------------------------------------------------------------
/// Fonction : Importation informations ecole
/// param�tre en mise � jour : ecole
void ft_importerEcole(ecole_t ec,char n_f[MAX_CHAR]);

#endif // INOUT_H

