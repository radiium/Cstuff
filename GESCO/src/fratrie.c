/*******************************************************
    Nom        : fraterie.c

    Desription : Définition des fonctions associées  à
                 la gestion des frere(s) et soeur(s) de eleve.

    Auteur     : C.H.L

********************************************************/

#include "fratrie.h"
#include "date.h"

// fonction qui permet de saisir les informations d'un frere ou une soeur
void Saisir_Fratrie(fratrie_t *f,int i)
{   
	printf("\t\t   - nom frère ou soeur %d         : ",i+1);
    lireChaine(f->nom,MAX_CHAR);
    
	printf("\t\t   - prenom frère ou soeur %d      : ",i+1);
    lireChaine(f->prenom,MAX_CHAR);
    
// Controle saisie scolarisation ('o' ou 'n')
    printf("\t\t   - scolarise dans l'ecole (O/N) : ");
	lireChaine(&f->scolarise_ec,2);
    while (Controle_Saisie(f->scolarise_ec,'O','N')==0)  
    {
        printf("\n\t\t=> information scolarisation invalide, la ressaisir svp ");
        printf("\n\t\t   - scolarise dans l'ecole (O/N) : ");
		lireChaine(&f->scolarise_ec,2);
	}  
	
// Saisie da date de naissance
	printf("\t\t   - date de naissance            : ");
	f->date_nais=ft_saisieDate();
}

// fonction qui affiche les frères et soeurs de l'élève
void Afficher_Fratrie(fratrie_t f,int i)
{
	printf("\n\t|%02d|  Nom : %-10s Prenom : %-10s Age : %2d     Inscrit ecole : %c  |\n",
			i+1,
            f.nom,
            f.prenom,
            ft_calculAgeEleve(f.date_nais),
            f.scolarise_ec);
            printf("\t|--|-----------------------------------------------------------------------|\n");
}

// fonction qui permet de modifier le nom d'un frère ou une soeur de l'élève
void Modifier_NomFratrie(fratrie_t *f,int i)
{
    printf("\n\n\t=> veuillez entrer le nom du frere ou de la soeur %d : ",i+1);
    lireChaine(f->nom,MAX_CHAR);
}

void Modifier_PrenomFratrie(fratrie_t *f,int i)
{
	printf("\n\n\t=> veuillez entrer le prenom du frere ou de la soeur %d : ",i+1);
    lireChaine(f->prenom,MAX_CHAR);
}

// fonction qui permet de modifier le prenom d'un frère ou une soeur de l'élève
void Modifier_AgeFratrie(fratrie_t *f,int i)
{
	printf("\n\n\t=> veuillez entrer la date de naissance du frere ou de la soeur %d : ",i+1);		
	f->date_nais=ft_saisieDate();
}

// fonction qui permet de modifier si un frère ou une soeur de l'élève est scolarisé(e) ou non dans l'école
void Modifier_ScolFratrie(fratrie_t *f,int i)
{
	printf("\n\n\t=> veuillez entrer 'O' ou 'N' si le frere ou la soeur %d frequente l'etablissement  : ",i+1);
	lireChaine(&f->scolarise_ec,2);
    while (Controle_Saisie(f->scolarise_ec,'O','N')==0)  
    {
        printf("\n\t=> information scolarisation invalide, la ressaisir svp ");
        printf("\n\tscolarise dans l'ecole (O/N) : ");
		lireChaine(&f->scolarise_ec,2);
	}  
}

// fonction qui permet de modifier les informations d'une personne de la fratrie
void Modifier_Fratrie(fratrie_t *f,int i)
{   
	int choix;    // Variable pour le choix du switch

//Menu avec choix et test d'entrée valide
        printf("\n\n");
        printf("\t\t MODIFICATION DE LA FRATRIE :");
        printf("\n\t\t==============================");
        printf("\n\n\t\t1 *  Nom");
        printf("\n\n\t\t2 *  Prenom");
        printf("\n\n\t\t3 *  Age");
        printf("\n\n\t\t4 *  Scolarisation dans l'etablissement");
        printf("\n\n\n\t\t5 *  Toutes les informations");
        printf("\n\n\n\n\t\t0 *  RETOUR\n\n\n\n\n\t\t  >> ");
        scanf("%d",&choix);
        getchar();
    while((choix>5) || (choix<0))
    {
        printf("\n\t\t=> choix invalide, le resaisir svp ");
        scanf("%d",&choix);
        getchar();
    }
    
//Modification des informations du frère ou de la soeur sélectionné en fonction du choix de l'utilisateur
    switch(choix)
    {
    case 0:
        break;
    case 1:
        Modifier_NomFratrie(f,i);
        break;
	case 2:
        Modifier_PrenomFratrie(f,i);
        break;
    case 3:
        Modifier_AgeFratrie(f,i);
        break;
    case 4:
        Modifier_ScolFratrie(f,i);
        break;
    case 5:
		Saisir_Fratrie(f,i);
        break;
    }
}

