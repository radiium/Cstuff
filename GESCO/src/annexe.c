/*******************************************************
    Nom        : annexe.c

    Desription : Fonctions annexes

    Auteur     : R.P
                 C.H.L
                 T.C

********************************************************/

#include "annexe.h"

////////////////////////////////////////////////////////
// Fonctions de R.P
////////////////////////////////////////////////////////

/*******************************************************
 Description .. : attend une entrée au clavier pour
                  passer à l'affichage suivant

********************************************************/
void attenteRetour()
{
    int retour;

    while(retour!=0)
    {
        printf("\n\n\n\n\t\tAppuyer sur la touche 0 pour revenir au menu ");
        scanf("%d", &retour);
    }
}
/*******************************************************
 Description .. : Vide le buffer de l'entrée standard

********************************************************/
void viderBuffer()
{
    int c = 0;

    do
    {
        c = getchar();
    }while (c != '\n' && c != EOF);
}
/*******************************************************
 Description .. : Saisi chaine et place '\0' a la fin

 Parametre .... : Chaine + longueur chaine

 Retour ....... : Renvoie : 1 si chaine termine par '\0'
                            (chaine bien saisi et terminé)
                            0 si chaine est NULL
                            (chaine vide)

********************************************************/
int lireChaine(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');

        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}

////////////////////////////////////////////////////////
// Fonctions de C.H.L
////////////////////////////////////////////////////////

/**************************************************************
 Description .. : Controler la saisie d'un numero de telephone
 Paramètre en entrée : t
***************************************************************/
int Controle_Telephone(char *t)
{
    int i=0;
    int saisie=1;

// contrôle que le nombre saisi contient 10 numéros
	if (strlen(t)!=10)
	{
		saisie=0;
		return saisie;
	}

// contrôle que le nombre saisi commence par le chiffre 0
	if (t[0]!='0')
	{
		saisie=0;
		return saisie;
	}

// contrôle que le nombre saisi contient uniquement des chiffres
    do
    {
        saisie=isdigit(t[i]);
        i++;
    } while ((i<10) && (saisie!=0));
    return saisie;
}

/**************************************************************************************************
 Fonction réalisée par C.H.L qui permet de controler si une saisie n'est composée que de chiffres
 paramètre en entrée : s, t
 paramètre en sortie : saisie (1 si la saisie est un entier 0 sinon)
*************************************************************************************************/
int Controle_IntSaisie(char *s,int t)
{
    int i=0;
    int saisie=1;

    do
    {
        saisie=isdigit(s[i]);
        i++;
    } while ((i<t) && (saisie!=0));
    return saisie;
}


/*******************************************************************************************************************************************
 Fonction réalisée par C.H.L qui permet de controler si un caractère saisie est égal à l'une ou l'autre des deux lettres transmises en entrée
 paramètre en entrée : c, l1 et l2
 paramètre en sortie : saisie (1 si la saisie est égale à l'une ou l'autre des deux lettres transmises 0 sinon)
********************************************************************************************************************************************/
int Controle_Saisie(char c,char l1,char l2)
{
    int saisie=1;

    if ((c!=toupper(l1)) && (c!=tolower(l1)) && (c!=toupper(l2)) & (c!=tolower(l2))) saisie=0;
        return saisie;
}

/*******************************************************************************************************************************************
 Fonction réalisée par C.H.L qui permet d'afficher un numero de telephone dans le format 06.21.21.36.35
 paramètre en entrée : 	t
********************************************************************************************************************************************/

void ft_affichageTel(char *tel)
{
    int i;

    printf("%1c%1c", tel[0], tel[1]);
    for (i=2; i<10; i=i+2)
    printf(".%1c%1c", tel[i], tel[i+1]);
}

