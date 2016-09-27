/*******************************************************
    Nom        : demo.h

    Desription : Programme de démarrage
                 proposant d'essayer GESCO
                 avec une ecole fictive
                 ou vide

    Auteur     : R.P

********************************************************/

#include "annexe.h"
#include "definition.h"
#include "menu.h"

#ifndef DEMO_H
#define DEMO_H

//-----------------------------------------------------------------------------
//    Description : menu de demonstration :
//                  1 tester le programme avec une ecole deja creer
//                  2 creer votre ecole
//    parametre   : * su struct ecole_t
void menuDemo(ecole_t *ecole);

#endif// DEMO_H

