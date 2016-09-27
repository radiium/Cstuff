/*******************************************************
    Nom        : eleve.h

    Desription : Définition des structures et des fonctions
                 associées  à la gestion d'un eleve.

    Auteur     : K.Z

********************************************************/

#include "eleve.h"

///-----------------------------------------------------------------------------
/// Fonction  : Affichage des informations d'un élève
/// paramètre : struct eleve_t
void Afficher_Eleve(eleve_t el)
{
	int i;
 
 //Affiche les informations d'un Eleve
    printf("\n\t  ELEVE                                  ADRESSE\n");
    printf("\t|--------------------------------------|-----------------------------------|\n");
    // Ligne 1 nom et numero de rue
    printf("\t| Nom              : %-18s| N            : %-19s|\n",
    el.nom,
    el.adresse.num);
    // Ligne 2 prenom et nom rue
    printf("\t| Prenom           : %-18s| Rue          : %-19s|\n",
    el.prenom,
    el.adresse.rue);

    // Ligne 3 date naissance et code postal
    printf("\t| Date naissance   :");
    ft_afficherDate(el.date_naissance);
    printf("| Code Postal  : %-19s|\n", el.adresse.postal);

    // Ligne 4 genre et nom ville
    printf("\t| Genre            : %-18c| Ville        : %-19s|\n",
    el.genre,
    el.adresse.ville);
    
    // Ligne 5 restauration et num de telephone
    printf("\t| Restauration     : %-18c| Telephone    : ",el.restauration);
    ft_affichageTel(el.adresse.tel);
    printf("     |\n");
    
    // Ligne 6
    printf("\t| Redoublement     : %-18c|                                   |\n",
    el.redoublement);
    printf("\t|--------------------------------------|-----------------------------------|\n\n");

    // Affichage des 2 contacts de l'élève (1 par ligne)
    printf("\t  n  Contact\n");
    printf("\t|--|-----------------------------------------------------------------------|\n");
    for (i=0; i<2; i++)
    {
        Afficher_Contact(el.tab_contact[i],i);
    }

    // Affichage de la fratrie de l'élève
    if (el.tab_fratrie[0].nom!='\0')
    {
        printf("\n\n\t  n  Fratrie\n");
        printf("\t|--|-----------------------------------------------------------------------|\n");
        for (i=0; el.tab_fratrie[i].nom!='\0' ; i++)
        {
			Afficher_Fratrie(el.tab_fratrie[i],i);
        }
    }
}
 
///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Saisie des informations d'un élève
/// paramètre : * sur struct eleve_t 
void Saisir_Eleve(eleve_t *el)
{
	int i;
	int j;
	int saisie=1;
	char c_nb_fratrie;
 
    printf("\n\t\t- date de naissance de l'eleve : ");
    el->date_naissance = ft_saisieDate();//--------------------------- saisie de la date de naissance de l'élève


    printf("\n\n\t\t- redoublement (O/N) : ");
	lireChaine(&el->redoublement,2);
	while (Controle_Saisie(el->redoublement,'O','N')==0)
    {
        printf("\n\t\t=> information redoublement invalide,la resaisir svp "); 
        printf("\n\t\t- redoublement (O/N) : ");
		lireChaine(&el->redoublement,2);
	}

	printf("\n\n\t\t- restauration (O/N) : ");
	lireChaine(&el->restauration,2);
    while (Controle_Saisie(el->restauration,'O','N')==0)
    {	
        printf("\n\t\t=> information restauration invalide,la resaisir svp "); 
		printf("\n\t\t- restauration (O/N) : ");
		lireChaine(&el->restauration,2);
	}

	printf("\n\n\t\t- genre (G/F)        : ");
    lireChaine(&el->genre,2);//-----  
    while (Controle_Saisie(el->genre,'G','F')==0)
    {	
        printf("\n\t\t=> information genre invalide,la resaisir svp "); 
		printf("\n\t\t- genre (G/F)        : ");
        lireChaine(&el->genre,2);//---------------------------------- saisie de la donnée genre (F = fille, G = garcon)
    } 

 
     printf("\n\n\t\t- adresse            :\n");
     ft_saisirCoord(&el->adresse);//----------------------------------- saisie de l'adresse de l'élève
 
  
     printf("\n\n\t\t- nombre de personne(s) dans la fratrie : ");
     scanf("%c",&c_nb_fratrie);
     saisie=isdigit(c_nb_fratrie);
     el->nb_fratrie=c_nb_fratrie-48;
     getchar();
     while (!(((el->nb_fratrie)>-1) && ((el->nb_fratrie)<9) && (saisie!=0)))
     {
        printf("\n\t\t=> nombre invalide,le resaisir svp "); 
        printf("\n\t\t- nombre de personne(s) dans la fratrie : ");
        scanf("%c",&c_nb_fratrie);
        saisie=isdigit(c_nb_fratrie);
        el->nb_fratrie=c_nb_fratrie-48;
        getchar();
     } 
    for(i=0; i <el->nb_fratrie; i++) 
    {   
        Saisir_Fratrie(&el->tab_fratrie[i],i);//---------------------- saisie de la fratrie de l'élève
    }

   
    printf("\n\n\t\t- 2 contacts à saisir en cas de probleme : \n");
    for(j=0;j<2;j++)
    {
		Saisir_Contact(&el->tab_contact[j], j);//---------------------- saisie des personnes à contacter en cas de problème
		printf("\n");
     }
}

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier le nom de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Nom(eleve_t *el)
{
	printf("\nveuillez entrer le nom de l'eleve :");
    lireChaine(el->nom,MAX_CHAR);
}

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier le prénom de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Prenom(eleve_t *el)
{
	printf("\nveuillez entrer le prenom de l'eleve :");
    lireChaine(el->prenom,MAX_CHAR);
}

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier la donnée "redoublement" 
/// paramètre : * sur struct eleve_t 
void Modifier_Redoublement(eleve_t *el)
{
	printf("\nveuillez entrer 'O' si l'eleve est redoublant sinon 'N' : ");
	lireChaine(&el->redoublement,2);
	while (Controle_Saisie(el->redoublement,'O','N')==0)
    {
        printf("\n\t\t=> information redoublement invalide,la resaisir svp "); 
        printf("\n\t\tredoublement (O/N) : ");
		lireChaine(&el->redoublement,2);
	}
}

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier la donnée "restauration" 
/// paramètre : * sur struct eleve_t 
void Modifier_Restauration(eleve_t *el)
{
	printf("\nveuillez entrer le regime de l'eleve : ");
	lireChaine(&el->restauration,2);
    while (Controle_Saisie(el->restauration,'O','N')==0)
    {	
        printf("\n\t\t=> information restauration invalide,la resaisir svp "); 
		printf("\n\t\trestauration (O/N) : ");
		lireChaine(&el->restauration,2);
	}
}

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier le genre de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Genre(eleve_t *el)
{
	printf("\nveuillez entrer le genre de l'eleve : ");
    lireChaine(&el->genre,2);//-----  
    while (Controle_Saisie(el->genre,'G','F')==0)
    {	
        printf("\n\t\t=> information genre invalide,la resaisir svp "); 
		printf("\n\t\tgenre (G/F)        : ");
        lireChaine(&el->genre,2);//---------------------------------- saisie de la donnée genre (F = fille, G = garcon)
    } 
}

///--------------------------------------------------------------------------------------------------------------------------------------
/// Fonction  : Modifier la date de naissance de l'élève
/// paramètre : * sur struct eleve_t 
void Modifier_Date(eleve_t *el)
{
	printf("\nveuillez entrer la date de naissance de l'eleve : ");
	el->date_naissance = ft_saisieDate();
}
 

