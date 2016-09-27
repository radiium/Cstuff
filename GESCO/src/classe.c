/*******************************************************
    Nom        : classe.c

    Desription : Définition des structures et des fonctions associées  à
                 la gestion d'une classe.

    Auteur     : T.C

********************************************************/

#include "classe.h"

///-----------------------------------------------------------------------------
/// Fonction : Affichage d'une classe d'élèves
/// paramètre entrée : classe
void ft_afficherClasse (classe_t *classe)
{
    eleve_t *courant;
    courant=classe->ptr_eleve;
    int i=0;

    if (courant==NULL)
    {
        printf("\n\n\t\t La classe est vide.\n\n\n");
    }
    else
    {
        //Entete  nom de la classe et nom prof
        printf("\t|-------------------------------|\n");
        printf("\t| Classe       : %-15s|\n", classe->nom);
        printf("\t| Professeur   : %-15s|\n", classe->prof);
        printf("\t|-------------------------------|\n\n");

        //Affichage d'un eleve par ligne
        //nom, prenom, date de naissance, genre, restauration et redoublement
        printf("\t  n  Nom              Prenom           Date Nais     Genre    1/2Pension  redouble\n");
        printf("\t|--|----------------|----------------|------------|----------|----------|----------|\n");

        while(courant != NULL)
        {
            printf("\t|%02d| %-14s | %-14s |",
            i+1,
            courant->nom,
            courant->prenom);
            ft_afficherDate(courant->date_naissance);
            printf(" |     %c    |    %3s   |    %3s   |\n",
            courant->genre,
            (courant->redoublement) ? "Oui":"Non",
            (courant->restauration) ? "Oui":"Non");
            printf("\t|--|----------------|----------------|------------|----------|----------|----------|\n");
            i++;
            courant=courant->suivant;
        }
    }
}



///-----------------------------------------------------------------------------
/// Fonction : Saisie des informations de la classe(nom et prof de la classe)
/// paramètre en mise à jour : classe
void ft_saisirClasse(classe_t *classe)
{
        printf("\n\t=> veuillez entrer le nom de la classe :");
        lireChaine(classe->nom,MAX_CHAR);
        printf("\n\t=> veuillez entrer le nom du professeur :");
        lireChaine(classe->prof,MAX_CHAR);
}


///-----------------------------------------------------------------------------
/// Fonction : Modifications des champs de la structure classe (nom et prof)
/// paramètre en mise à jour : classe
void ft_modifierClasse(classe_t *classe)
{
    int choix;    //Variable pour le choix du switch

    //Menu avec choix et test d'entrée valide
    do
    {
        printf("\n\n");
        printf("\t\t MODIFICATION DE LA CLASSE :");
        printf("\n\t\t=============================");
        printf("\n\n\t\t1 *  Nom de la classe");
        printf("\n\n\t\t2 *  Nom du professeur");
        printf("\n\n\n\t\t3 *  Toutes les informations");
        printf("\n\n\n\n\t\t0 *  RETOUR\n\n\n\n\n\t\t  >> ");
        scanf("%d",&choix);
    }
    while((choix>3) && (choix<0));
    viderBuffer();

    //Modification de A en fonction du choix de l'utilisateur
    switch(choix)
    {
    case 0:
        break;
    case 1:
        printf("\n\t=> veuillez entrer le nom de la classe :");
        lireChaine(classe->nom,MAX_CHAR);
        break;

    case 2:
        printf("\n\t=> veuillez entrer le nom du professeur :");
        lireChaine(classe->prof,MAX_CHAR);
        break;

    case 3:
        printf("\n\t=> veuillez entrer le nom de la classe :");
        lireChaine(classe->nom,MAX_CHAR);
        printf("\n\t=> veuillez entrer le nom du professeur :");
        lireChaine(classe->prof,MAX_CHAR);
        break;
    }
}


///-----------------------------------------------------------------------------
/// Fonction : Rechercher un élève dans la classe
/// paramètre en mise à jour : classe
int ft_rechercherEleve(classe_t *classe,eleve_t **retour)
{
    eleve_t *courant;
    int test=0;
    courant=classe->ptr_eleve;

    while((courant != NULL))
    {
        if((strcmp((*retour)->nom,courant->nom) == 0) && (strcmp((*retour)->prenom,courant->prenom)==0))
        {
            (*retour)=courant;
            test=1;
        }
        courant=courant->suivant;
    }
    if (test == 0)
    {
        (*retour)=NULL;
    }
    return test;
}

///-----------------------------------------------------------------------------
/// Fonction : Suppresion d'un élève de la classe
/// paramètre en mise à jour : classe
void ft_supprimerEleve(classe_t *classe,eleve_t **supprime)
{

    int i=1; // nombre d'élèves dans la classe
    int j=0; // position de l'élève à supprimer
    int k;   // compteur de boucle
    eleve_t *courant;
    courant=classe->ptr_eleve;

    while (courant != NULL) //Recherche de la position de l'élève a supprimer
    {
        if (courant == (*supprime))
            j=i;

        courant=courant->suivant;
        i++;
    }
    i--;

    if(j==1)
    {
        classe->ptr_eleve=(*supprime)->suivant;
        free(supprime);

    }
    else
    {
        courant=classe->ptr_eleve;
        for(k=1;k<j-1;k++)                // Récuperation de l'adresse precedente dans courant
            courant=courant->suivant;

        if(j==i)
            courant->suivant=NULL;
        else
            courant->suivant=(*supprime)->suivant;

        free(supprime);
    }

}


