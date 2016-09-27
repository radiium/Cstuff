/*******************************************************
    Nom        : coord.c

    Desription : Définition des structures et des fonctions associées  à
                 la gestion des coordonnées.

    Auteur     : T.C

********************************************************/

#include "coord.h"

///-----------------------------------------------------------------------------
/// Fonction : Affichage des coordonnées
/// paramètre entrée : coord
void ft_afficherCoord(coord_t coord)
{
    printf("%s %s %s %s",coord.num,coord.rue,coord.postal,coord.ville);

    ft_affichageTel(coord.tel);
}

///------------------------------------------------------------------------------------------------
/// Fonction : Permet de modifier une structure de type coordonnées
/// paramètre en mise à jour : coord
void ft_modifierCoord(coord_t *coord)
{
    int choix;   //Variable pour le choix du switch

    //Menu avec choix et test d'entrée valide
    do
    {
        printf("\n\n");
        printf("\t\t MODIFICATION DES COORDONNES :");
        printf("\n\t\t===============================");
        printf("\n\n\t\t1 *  Numero de voie");
        printf("\n\n\t\t2 *  Nom de voie");
        printf("\n\n\t\t3 *  Code postal");
        printf("\n\n\t\t4 *  Ville");
        printf("\n\n\t\t5 *  Numero de telephone");
        printf("\n\n\n\t\t6 *  Toutes les informations");
        printf("\n\n\n\n\t\t0 *  RETOUR\n\n\n\n\n\t\t  >> ");
        scanf("%d",&choix);
        viderBuffer();
    }
    while((choix>6) && (choix<0));

    //Modification de A en fonction du choix de l'utilisateur
    switch(choix)
    {
    case 0:
        break;
    case 1:
        printf("\n\t=> veuillez entrer le numero de voie      : ");
		lireChaine(coord->num,4);
		while (Controle_IntSaisie(coord->num,strlen(coord->num))==0)
		{
			printf("\n\t=> numero invalide, le ressaisir svp ");
			printf("\n\tnumero      : ");
			lireChaine(coord->num,4);
		}
        break;

    case 2:
        printf("\n\t=> veuillez entrer le nom de la voie      : ");
        lireChaine(coord->rue,MAX_CHAR);
        break;

    case 3:
		printf("\n\t=> veuillez entrer le code postal         : ");
		lireChaine(coord->postal,6);
		while (Controle_IntSaisie(coord->postal,5)==0)
		{
			printf("\n\t=> code postal invalide, le ressaisir svp ");       
			printf("\n\tcode postal : ");
			lireChaine(coord->postal,6);
		}
        break;

    case 4:
        printf("\n\t=> veuillez entrer le nom de la ville     : ");
        lireChaine(coord->ville,MAX_CHAR);
        break;

    case 5:
		printf("\n\t=> veuillez saisir le numero de telephone (ex : 0626542110) : ");
		lireChaine(coord->tel,11);
		while (!Controle_Telephone(coord->tel))
		{
			printf("\n\t=> numero de telephone invalide, le ressaisir svp ");       
			printf("\n\tnumero de telephone des parents (ex : 0626542110) : ");
			lireChaine(coord->tel,11);
		}
        break;

    case 6:
        ft_saisirCoord(coord);
        break;
    }
}

///-----------------------------------------------------------------------------
/// Fonction : Saisie des informations des coordonnées
/// paramètre en mise à jour : coord
void ft_saisirCoord(coord_t *coord)
{
    printf("\t\t   - numero      : ");
    lireChaine(coord->num,4);
    while (Controle_IntSaisie(coord->num,strlen(coord->num))==0)
    {
        printf("\n\t\t=> numero invalide, le ressaisir svp ");
        printf("\n\t\t   - numero      : ");
        lireChaine(coord->num,4);
    }

    printf("\t\t   - voie        : ");
    lireChaine(coord->rue,MAX_CHAR);

    printf("\t\t   - code postal : ");
    lireChaine(coord->postal,6);
    while (Controle_IntSaisie(coord->postal,5)==0)
    {
        printf("\n\t\t=> code postal invalide, le ressaisir svp ");       
        printf("\n\t\t   - code postal : ");
        lireChaine(coord->postal,6);
    }

    printf("\t\t   - ville       : ");
    lireChaine(coord->ville,MAX_CHAR);

    printf("\n\t\t- numero de telephone des parents (ex : 0626542110) : ");
    lireChaine(coord->tel,11);
    while (!Controle_Telephone(coord->tel))
    {
        printf("\n\t\t=> numero de telephone invalide, le ressaisir svp ");       
        printf("\n\t\t- numero de telephone des parents (ex : 0626542110) : ");
        lireChaine(coord->tel,11);
    }
}

