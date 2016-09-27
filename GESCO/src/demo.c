/*******************************************************
    Nom        : demo.h

    Desription : Programme de démarrage
                 proposant d'essayer GESCO
                 avec une ecole fictive
                 ou vide

    Auteur     : R.P

********************************************************/

#include "demo.h"

//-----------------------------------------------------------------------------
//    Description : menu de demonstration :
//                  1 tester le programme avec une ecole deja creer
//                  2 creer votre ecole
//    parametre   : * su struct ecole_t
void menuDemo(ecole_t *ecole)
{
    int choix = 0;

    do
    {
        printf("\n\n");
        printf("\t\t Bienvenu dans gesco v2\n");
        printf("\t\t========================\n\n");
        printf("\t\t1 *  Demo (ecole deja creer)\n\n");
        printf("\t\t2 *  1ere utilisation\n\n\n\n");
        printf("\t\t0 *  Quitter\n\n\n\n\n\t\t  >>");
        scanf("%d", &choix);
        viderBuffer();
        printf("\n\n");
    }while ((choix<0) && (choix>2));

    switch(choix)
    {
    case 1:
        //initialiser une ecole = ecoleInitialiser
        //ft_menuPrincipale(ecoleInitialiser);
        break;
    case 2:
        ft_saisirEcole(ecole);
        ft_menuPrincipale(ecole);
        break;
    default:
        printf("\n\n\n\n");
        printf("Ce n'est pas un choix valide, recommencez la saisie\n");
        break;
    }
}

