/*******************************************************
    Nom        : contact.c

    Desription : Définition des structures et des fonctions associées  à
                 la gestion des coordonnées

    Auteur     : C.H.L

********************************************************/

#include "contact.h"

// fonction qui permet de saisir les informations d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Saisir_Contact(contact_t *c,int i)
{
	printf("\t\t   - nom %d    : ",i+1);				
	lireChaine(c->nom,MAX_CHAR);
		
	printf("\t\t   - prenom %d : ",i+1);
	lireChaine(c->prenom,MAX_CHAR);
	
	printf("\t\t   - numero de telephone %d (ex : 0626542110) : ",i+1);
	lireChaine(c->tel,11);
	while (!Controle_Telephone(c->tel))
	{
		printf("\n\t\t=> numero de telephone invalide, le ressaisir svp ");
		printf("\n\t\t   - numero de telephone %d (ex : 0626542110) : ",i+1);
		lireChaine(c->tel,11);
	}
}

// fonction qui affiche un contact de l'élève
// paramètre en entrée : c,i
void Afficher_Contact(contact_t c,int i)
{		
	printf("\n\t|%02d|  Nom : %-10s Prenom : %-10s Telephone : ",i+1,c.nom,c.prenom);
    ft_affichageTel(c.tel);
    printf("      |\n");
    printf("\t|--|-----------------------------------------------------------------------|\n");
}

// fonction qui permet de modifier les informations d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_Contact(contact_t *c,int i)
{
	int choix;  //Variable pour le choix du switch

    //Menu avec choix et test d'entrée valide
    printf("\n\n");
    printf("\t\t MODIFICATION DU CONTACT : ");
    printf("\n\t\t===========================");
    printf("\n\n\t\t1 *  Nom");
    printf("\n\n\t\t2 *  Prenom");
    printf("\n\n\t\t3 *  Numero de telephone");
    printf("\n\n\n\t\t4 *  Toutes les informations");
    printf("\n\n\n\n\t\t0 *  RETOUR\n\n\n\n\n\t\t  >> ");
    scanf("%d",&choix);
    getchar();
    while((choix>4) || (choix<0))
    {
        printf("\n\t\t=> choix invalide, le ressaisir svp ");
        scanf("%d",&choix);
        getchar();
    }
    

    //Modification de des informations du contact sélectionné en fonction du choix de l'utilisateur
    switch(choix)
    {
    case 0:
        break;
        
    case 1:
        Modifier_NomContact(c,i);
        break;

    case 2:
        Modifier_PrenomContact(c,i);
        break;

    case 3:
        Modifier_TelContact(c,i);
        break;

    case 4:
		Saisir_Contact(c,i);
        break;
    }
}

// fonction qui permet de modifier le nom d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_NomContact(contact_t *c,int i)
{
	printf("\n\tveuillez entrer le nom du contact %d : ",i+1);
	lireChaine(c->nom,MAX_CHAR);
}

//fonction qui permet de modifier le prenom d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_PrenomContact(contact_t *c,int i)
{
	printf("\n\tveuillez entrer le prenom du contact %d : ",i+1);
	lireChaine(c->prenom,MAX_CHAR);
}

// fonction qui permet de modifier le numero de telephone d'un contact de l'élève
// paramètre en mise à jour : c 
// paramètre en entrée : i
void Modifier_TelContact(contact_t *c,int i)
{
	printf("\n\tveuillez entrer le numero de telephone du contact %d : ",i+1);
	lireChaine(c->tel,11);
	while (!Controle_Telephone(c->tel))
	{
		printf("\n\t=> numero de telephone invalide, le ressaisir svp ");
		printf("\n\tnumero de telephone %d (ex : 0626542110) : ",i+1);
		lireChaine(c->tel,11);
	}
}

