/*******************************************************
 Nom .......... : main.c

 Description .. : Programme de gestion d'école primaire

 Auteur ....... : C.H.L
                  K.Z
                  T.C
                  R.P

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

#include "demo.h"

int main (int argc, char *argv[])
{
    ecole_t ecole;
    memset(&ecole, 0, sizeof(ecole_t));
    classe_t *classeCp = malloc(sizeof(classe_t));
    ecole.tab_cp[0] = classeCp;
    ecole.tab_cp[1] = NULL;
    ecole.tab_ce1[0] = NULL;
    ecole.tab_ce1[1] = NULL;
    ecole.tab_ce2[0] = NULL;
    ecole.tab_ce2[1] = NULL;
    ecole.tab_cm1[0] = NULL;
    ecole.tab_cm1[1] = NULL;
    ecole.tab_cm2[0] = NULL;
    ecole.tab_cm2[1] = NULL;

    menuDemo(&ecole);

    return 0;
}

