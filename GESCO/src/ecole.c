/*******************************************************
    Nom        : ecole.h

    Desription : Définition d'une structure ecole
                 et des fonctions associées

    Auteur     : R.P

********************************************************/

#include "ecole.h"

//-----------------------------------------------------------------------------
//  Description : affiche une entete
//  parametre   : structure ecole_t
void ft_afficheEntete(ecole_t ecole)
{
    time_t date = time (NULL);
    char chaineDate[5];
    int annee;

    strftime(chaineDate, 5, "%Y", localtime (&date));
    annee = atoi(chaineDate);

    //Entete composé de du nom d'ecole et année scolaire en cour 
    printf("\n\n\t*************************** Ecole Primaire v2 *********************************************\n");
    printf("\t*                                                                                         *\n");
    printf("\t*         Ecole       : %-16s            Annee Scolaire : %4d/%4d            *\n", ecole.nom, annee-1, annee);
    printf("\t*                                                                                         *\n");
    printf("\t*******************************************************************************************\n\n");
}

//-----------------------------------------------------------------------------
// Description : Afficher le contenu l'ecole
// parametre   : struct ecole_t
void ft_afficherEcole(ecole_t ecole)
{
    int i;
    int totalEcole = 0;// Compteur total d'eleve dans l'ecole

    ft_afficheEntete(ecole);

    // Tableau avec information de l'ecole'
    printf("\n\n\t\t|-----------------------------------------------|\n");
    printf("\t\t| Directrice     : %-16s             |\n", ecole.directeur);
    printf("\t\t|-----------------------------------------------|\n");
    printf("\t\t| Adresse        :");
    printf("  Num   : %-5s               |\n", ecole.adresse.num);
    printf("\t\t|                   Rue   : %-12s        |\n", ecole.adresse.rue);
    printf("\t\t|                   CP    : %-5s               |\n",ecole.adresse.postal);
    printf("\t\t|                   Ville : %-12s        |\n", ecole.adresse.ville);
    printf("\t\t|                   Tel   : %c%c", ecole.adresse.tel[0], ecole.adresse.tel[1]);
    for (i=2; i<10; i=i+2)
        printf(".%c%c", ecole.adresse.tel[i], ecole.adresse.tel[i+1]);
    printf("      |\n\t\t|-----------------------------------------------|");

    // Vérifie si une classe de CP existe (si oui affiche la classe)
    if (ecole.tab_cp[0]!=NULL)
    {
        printf("\n\n\n");
        printf("\t\tCP :");
        printf("\t\t  n   Professeur       Nm Eleve\n");
        printf("\t\t|---|----------------|----------|\n");
        printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_cp[0]->prof, ecole.tab_cp[0]->nbeleve);


        totalEcole = totalEcole + ecole.tab_cp[0]->nbeleve;
        // Vérifie si une deuxieme classe de CP existe (si oui affiche la classe)
        if (ecole.tab_cp[1]!=NULL)
        {
            printf("\t\t|---|----------------|----------|\n");
            printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_cp[1]->prof, ecole.tab_cp[1]->nbeleve);
            totalEcole = totalEcole + ecole.tab_cp[1]->nbeleve;
        }
        printf("\t\t|---|----------------|----------|\n");
    }

    // Vérifie si une classe de CE1 existe (si oui affiche la classe)
    if (ecole.tab_ce1[0]!=NULL)
    {
        printf("\n");
        printf("\t\tCE1 :");
        printf("\t\t  n  Professeur       Nm Eleve\n");
        printf("\t\t|--|----------------|----------|\n");
        printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_ce1[0]->prof, ecole.tab_ce1[0]->nbeleve);
        totalEcole = totalEcole + ecole.tab_ce1[0]->nbeleve;
        // Vérifie si une deuxieme classe de CE1 existe (si oui affiche la classe)
        if (ecole.tab_ce1[1]!=NULL)
        {
            printf("\t\t|---|----------------|----------|\n");
            printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_ce1[1]->prof, ecole.tab_ce1[1]->nbeleve);
            totalEcole = totalEcole + ecole.tab_ce1[1]->nbeleve;
        }
        printf("\t\t|---|----------------|----------|\n");
    }

    // Vérifie si une classe de CE2 existe (si oui affiche la classe)
    if (ecole.tab_ce2[0]!=NULL)
    {
        printf("\n");
        printf("\t\tCE2 :");
        printf("\t\t  n  Professeur       Nm Eleve\n");
        printf("\t\t|--|----------------|----------|\n");
        printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_ce2[0]->prof, ecole.tab_ce2[0]->nbeleve);
        totalEcole = totalEcole + ecole.tab_ce2[0]->nbeleve;
        // Vérifie si une deuxieme classe de CE2 existe (si oui affiche la classe)
        if (ecole.tab_ce2[1]!=NULL)
        {
            printf("\t\t|---|----------------|----------|\n");
            printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_ce2[1]->prof, ecole.tab_ce2[1]->nbeleve);
            totalEcole = totalEcole + ecole.tab_ce2[1]->nbeleve;
        }
        printf("\t\t|---|----------------|----------|\n");
    }

    // Vérifie si une classe de CM1 existe (si oui affiche la classe)
    if (ecole.tab_cm1[0]!=NULL)
    {
        printf("\n");
        printf("\t\tCM1 :");
        printf("\t\t  n  Professeur       Nm Eleve\n");
        printf("\t\t|--|----------------|----------|\n");
        printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_cm1[0]->prof, ecole.tab_cm1[0]->nbeleve);
        totalEcole = totalEcole + ecole.tab_cm1[0]->nbeleve;
        // Vérifie si une deuxieme classe de CM1 existe (si oui affiche la classe)
        if (ecole.tab_cm1[1]!=NULL)
        {
            printf("\t\t|---|----------------|----------|\n");
            printf("\t\t| 1|  %-14s|    %-2d    |\n", ecole.tab_cm1[1]->prof, ecole.tab_cm1[1]->nbeleve);
            totalEcole = totalEcole + ecole.tab_cm1[1]->nbeleve;
        }
        printf("\t\t|---|----------------|----------|\n");
    }

    // Vérifie si une classe de CM2 existe (si oui affiche la classe)
    if (ecole.tab_cm2[0]!=NULL)
    {
        printf("\n");
        printf("\t\tCM2 :");
        printf("\t\t  n  Professeur       Nm Eleve\n");
        printf("\t\t|---|----------------|----------|\n");
        printf("\t\t| 1 |  %-14s|    %-2d    |\n", ecole.tab_cm2[0]->prof, ecole.tab_cm2[0]->nbeleve);
        totalEcole = totalEcole + ecole.tab_cm2[0]->nbeleve;
        // Vérifie si une deuxieme classe de CM2 existe (si oui affiche la classe)
        if (ecole.tab_cm2[1]!=NULL)
        {
            printf("\t\t|---|----------------|----------|\n");
            printf("\t\t| 1 |  %-14s|    %-2d    |\n", ecole.tab_cm2[1]->prof, ecole.tab_cm2[1]->nbeleve);
            totalEcole = totalEcole + ecole.tab_cm2[1]->nbeleve;
        }
        printf("\t\t|---|----------------|----------|\n");
    }

    printf("\n\n\t\tIl y a %d eleves dans l'ecole.", totalEcole);

}

//-----------------------------------------------------------------------------
// Description : Saisir le contenu l'ecole
// parametre   : * sur struct ecole_t
void ft_saisirEcole(ecole_t *ecole)
{
    printf("\t\tSaisi des informations de votre ecole : \n\n");
    printf("\t\tVeuillez saisir le nom de l'ecole   : ");
    lireChaine(ecole->nom, MAX_CHAR);
    printf("\n\t\tVeuillez saisir le nom du directeur : ");
    lireChaine(ecole->directeur, MAX_CHAR);
    printf("\n\n\t\tSaisir l'adresse de l'ecole :\n\n");
    ft_saisirCoord(&ecole->adresse);
}

//-----------------------------------------------------------------------------
// Description : Modiffier le contenu de l'ecole
// parametre   : * sur struct ecole_t
void ft_modifierEcole(ecole_t *ecole)
{
    int choix;      //Variable pour le choix du switch

    //Menu avec choix et test d'entrée valide
    do
    {
        ft_afficheEntete(*ecole);
        printf("\n\n");
        printf("\t\t MODIFICATION DE L'ECOLE :\n");
        printf("\t\t===========================");
        printf("\n\n\t\t1 *  Nom de l'ecole");
        printf("\n\n\t\t2 *  Nom du directeur");
        printf("\n\n\t\t3 *  Coordonnees de l'ecole");
        printf("\n\n\n\t\t4 *  Toutes les informations");
        printf("\n\n\n\n\t\t0 *  RETOUR\n\n\n\n\n\t\t  >>");
        scanf("%d",&choix);
        viderBuffer();
    }while((choix>4) && (choix<0));

    //Modification de ecole en fonction du choix de l'utilisateur
    switch(choix)
    {
    case 0:
        // Retour menu parent
        break;
    case 1:
        printf("\nVeuillez entrer le nom de l'ecole :");
        lireChaine(ecole->nom, MAX_CHAR);
        break;
    case 2:
        printf("\nVeuillez entrer le nom du directeur :");
        lireChaine(ecole->directeur, MAX_CHAR);
        break;
    case 3:
        ft_modifierCoord(&ecole->adresse);
        break;
    case 4:
        printf("\nVeuillez entrer le nom de l'ecole :");
        lireChaine(ecole->nom, MAX_CHAR);
        printf("\nVeuillez entrer le nom du directeur :");
        lireChaine(ecole->directeur, MAX_CHAR);
        ft_modifierCoord (&ecole->adresse);
        break;
    }
}

//-----------------------------------------------------------------------------
// Description : Recherche eleve dans struct classe_t dans struct ecole_t
// parametre   : struct ecole_t
//               * sur struct eleve_t
int ft_rechercheEleveEcole(ecole_t ecole, eleve_t **eleveChercher, classe_t **teteClasse)
{
    int trouver = 0;

    // Recherche si un eleve est présent dans une des classe
    // Si présent : met a jour l'entier 'touver' et arrete de chercher
    if (ecole.tab_cp[0]!=NULL)
    {
        trouver = ft_rechercherEleve(ecole.tab_cp[0], eleveChercher);
        if (trouver==1)
            (*teteClasse) = ecole.tab_cp[0];
        if (ecole.tab_cp[1]!=NULL && trouver==0)
        {
            trouver = ft_rechercherEleve(ecole.tab_cp[0], eleveChercher);
            if (trouver==1)
                (*teteClasse) = ecole.tab_cp[1];
        }
    }
    // CE1
    if (ecole.tab_ce1[0]!=NULL && trouver==0)
    {
        ft_afficherClasse(ecole.tab_ce1[0]);
        trouver = ft_rechercherEleve(ecole.tab_ce1[0], eleveChercher);
        if (trouver==1)
            (*teteClasse) = ecole.tab_ce1[0];
        if (ecole.tab_ce1[1]!=NULL && trouver==0)
        {
            trouver = ft_rechercherEleve(ecole.tab_ce1[1], eleveChercher);
            if (trouver==1)
                (*teteClasse) = ecole.tab_ce1[1];
        }
    }
    // CE2
    if (ecole.tab_ce2[0]!=NULL && trouver==0)
    {
        trouver = ft_rechercherEleve(ecole.tab_ce2[0], eleveChercher);
        if (trouver==1)
            (*teteClasse) = ecole.tab_ce2[0];
        if (ecole.tab_ce2[1]!=NULL && trouver==0)
        {
            trouver = ft_rechercherEleve(ecole.tab_ce2[1], eleveChercher);
            if (trouver==1)
                (*teteClasse) = ecole.tab_ce2[1];
        }
    }
    // CM1
    if (ecole.tab_cm1[0]!=NULL && trouver==0)
    {
        trouver = ft_rechercherEleve(ecole.tab_cm1[0], eleveChercher);
        if (trouver==1)
            (*teteClasse) = ecole.tab_cm1[0];
        if (ecole.tab_cm1[1]!=NULL && trouver==0)
        {
            trouver = ft_rechercherEleve(ecole.tab_cm1[1], eleveChercher);
            if (trouver==1)
                (*teteClasse) = ecole.tab_cm1[1];
        }
    }
    // CM2
    if (ecole.tab_cm2[0]!=NULL && trouver==0)
    {
        trouver = ft_rechercherEleve(ecole.tab_cm2[0], eleveChercher);
        if (trouver==1)
            (*teteClasse) = ecole.tab_cm2[0];
        if (ecole.tab_cm2[1]!=NULL && trouver==0)
        {
            trouver = ft_rechercherEleve(ecole.tab_cm2[1], eleveChercher);
            if (trouver==1)
                (*teteClasse) = ecole.tab_cm2[1];
        }
    }
    if (trouver==0)
    {
        (*teteClasse) = NULL;
    }

    return trouver;
}

//-----------------------------------------------------------------------------
// Description : Modiffier le contenu de struct ecole_t
//               appelle ft_viderListe
// parametre   : * sur struct ecole_t
void ft_supprimerClasse(ecole_t *ecole)
{
    int choix  = 0;         // Choix du menu
    int souxchoix  = 0;     // Choix sous menu

    //menu liste des classes
    //(pour le moment les 5 classes doivent etre existante sous peine d'erreur)
    do {
        ft_afficheEntete(*ecole);
        printf("\n\n");
        printf("\t\tQuel classe souhaitez-vous Supprimer :\n\n");
        printf("\t\t1 *  CP\n\n");
        printf("\t\t2 *  CE1\n\n");
        printf("\t\t3 *  CE2\n\n");
        printf("\t\t4 *  CM1\n\n");
        printf("\t\t5 *  CM2\n\n");
        printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
        scanf("%d", &choix);
        viderBuffer();
    } while ((choix<0) && (choix>5));

    switch(choix)
    {
        case 1:
            if (ecole->tab_cp[0]!=NULL && ecole->tab_cp[1]!=NULL)
            {
                do {
                    ft_afficheEntete(*ecole);
                    printf("\n\n\t\tIl y a deux classe de CP\n");
                    printf("\t\tLaquelle voulez vous supprimer :\n\n");
                    printf("\t\t1 *  CP_1\n\n");
                    printf("\t\t2 *  CP_2\n\n\n\n");
                    printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
                    scanf("%d", &souxchoix);
                    viderBuffer();
                } while ((souxchoix<0) && (souxchoix>2));
                if (souxchoix==1)
                    ft_viderListe(&ecole->tab_cp[0]->ptr_eleve);
                if (souxchoix==2)
                    ft_viderListe(&ecole->tab_cp[1]->ptr_eleve);
            }
            if (ecole->tab_cp[0]!=NULL && ecole->tab_cp[1]==NULL)
                ft_viderListe(&ecole->tab_cp[0]->ptr_eleve);
            if (ecole->tab_cp[0]==NULL && ecole->tab_cp[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CP\n\n");
            break;
        case 2:
            if (ecole->tab_ce1[0]!=NULL && ecole->tab_ce1[1]!=NULL)
            {
                do {
                    ft_afficheEntete(*ecole);
                    printf("\n\n\t\tIl y a deux classe de CE1\n");
                    printf("\t\tLaquelle voulez vous supprimer :\n\n");
                    printf("\t\t1 *  CE1_1\n\n");
                    printf("\t\t2 *  CE1_2\n\n\n\n");
                    printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
                    scanf("%d", &souxchoix);
                    viderBuffer();
                } while ((souxchoix<0) && (souxchoix>2));
                if (souxchoix==1)
                    ft_viderListe(&ecole->tab_ce1[0]->ptr_eleve);
                if (souxchoix==2)
                    ft_viderListe(&ecole->tab_ce1[1]->ptr_eleve);
            }
            if (ecole->tab_ce1[0]!=NULL && ecole->tab_ce1[1]==NULL)
                ft_viderListe(&ecole->tab_ce1[0]->ptr_eleve);
            if (ecole->tab_ce1[0]==NULL && ecole->tab_ce1[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CE1\n\n");
            break;
        case 3:
            if (ecole->tab_ce2[0]!=NULL && ecole->tab_ce2[1]!=NULL)
            {
                do {
                    ft_afficheEntete(*ecole);
                    printf("\n\n\t\tIl y a deux classe de CE2\n");
                    printf("\t\tLaquelle voulez vous supprimer :\n\n");
                    printf("\t\t1 *  CE2_1\n\n");
                    printf("\t\t2 *  CE2_2\n\n\n\n");
                    printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
                    scanf("%d", &souxchoix);
                    viderBuffer();
                } while ((souxchoix<0) && (souxchoix>2));
                if (souxchoix==1)
                    ft_viderListe(&ecole->tab_ce2[0]->ptr_eleve);
                if (souxchoix==2)
                    ft_viderListe(&ecole->tab_ce2[1]->ptr_eleve);
            }
            if (ecole->tab_ce2[0]!=NULL && ecole->tab_ce2[1]==NULL)
                ft_viderListe(&ecole->tab_ce2[0]->ptr_eleve);
            if (ecole->tab_cm2[0]==NULL && ecole->tab_cm2[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CE2\n\n");
            break;
        case 4:
            if (ecole->tab_cm1[0]!=NULL && ecole->tab_cm1[1]!=NULL)
            {
                do {
                    ft_afficheEntete(*ecole);
                    printf("\n\n\t\tIl y a deux classe de CM1\n");
                    printf("\t\tLaquelle voulez vous supprimer :\n\n");
                    printf("\t\t1 *  CM1_1\n\n");
                    printf("\t\t2 *  CM1_2\n\n\n\n");
                    printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
                    scanf("%d", &souxchoix);
                    viderBuffer();
                } while ((souxchoix<0) && (souxchoix>2));
                if (souxchoix==1)
                    ft_viderListe(&ecole->tab_cm1[0]->ptr_eleve);
                if (souxchoix==2)
                    ft_viderListe(&ecole->tab_cm1[1]->ptr_eleve);
            }
            if (ecole->tab_cm1[0]!=NULL && ecole->tab_cm1[1]==NULL)
                ft_viderListe(&ecole->tab_cm1[0]->ptr_eleve);
            if (ecole->tab_cm1[0]==NULL && ecole->tab_cm1[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CM1\n\n");
            break;
        case 5:
            if (ecole->tab_cm2[0]!=NULL && ecole->tab_cm2[1]!=NULL)
            {
                do {
                    ft_afficheEntete(*ecole);
                    printf("\n\n\t\tIl y a deux classe de CM2\n");
                    printf("\t\tLaquelle voulez vous supprimer :\n\n");
                    printf("\t\t1 *  CM2_1\n\n");
                    printf("\t\t2 *  CM2_2\n\n\n\n");
                    printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
                    scanf("%d", &souxchoix);
                    viderBuffer();
                } while ((souxchoix<0) && (souxchoix>2));
                if (souxchoix==1)
                    ft_viderListe(&ecole->tab_cm2[0]->ptr_eleve);
                if (souxchoix==2)
                    ft_viderListe(&ecole->tab_cm2[1]->ptr_eleve);
            }
            if (ecole->tab_cm2[0]!=NULL && ecole->tab_cm2[1]==NULL)
                ft_viderListe(&ecole->tab_cm2[0]->ptr_eleve);
            if (ecole->tab_cm2[0]==NULL && ecole->tab_cm2[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CM2\n\n");
            break;
        default:
            printf("\n\n\t\tCe choix n'est pas valide, recommencez\n\n");
            break;
    }
}

//-----------------------------------------------------------------------------
// Description : Vide une liste d'eleve
// parametre   : double * sur struct ecole_t
void ft_viderListe(eleve_t **eleve)
{
   eleve_t *eleveAsupprimer = *eleve;
   while (eleve != NULL)
   {
      eleve_t *eleveTemp = eleveAsupprimer;
      eleveAsupprimer = eleveAsupprimer->suivant;
      free (eleveTemp);
   }
   *eleve = NULL;
   printf("\n\n\t\tLa classe a été supprimé.\n\n");
}

//-----------------------------------------------------------------------------
// Description : Affecte eleve à un niveau selon son age
//               Appelle ft_affecterEleveClasse
// parametre   : pointeur sur struct ecole_t
//               pointeur sur struct eleve_t
void ft_affecterEleveNiveau(ecole_t *ecole, eleve_t **eleve)
{
    int ageEleve;


    // Envoie un time_t, retourne un age
    ageEleve = ft_calculAgeEleve((*eleve)->date_naissance);

    // Affectation selon age
    switch(ageEleve)
    {
        case 6:// CP
            ft_affecterEleveClasse(&ecole->tab_cp[0], &ecole->tab_cp[1], eleve);
            break;
        case 7:// CE1
            ft_affecterEleveClasse(&ecole->tab_ce1[0], &ecole->tab_ce1[1], eleve);
            break;
        case 8:// CE2
            ft_affecterEleveClasse(&ecole->tab_ce2[0], &ecole->tab_ce2[1], eleve);
            break;
        case 9:// CM1
            ft_affecterEleveClasse(&ecole->tab_cm1[0], &ecole->tab_cm1[1], eleve);
            break;
        case 10:// CM2
            ft_affecterEleveClasse(&ecole->tab_cm2[0], &ecole->tab_cm2[1], eleve);
            break;
        default:// Si age eleve ne correspond a aucune classe
            if (ageEleve<6)
                printf("Leleve est trop jeune\n");
            if (ageEleve>10)
                printf("Leleve est trop vieux\n");
            break;
    }
}

//-----------------------------------------------------------------------------
// Description : Affecte eleve à une classe selon effectif
//               appelle ft_insererEleveClasse
//               et appelle ft_creerNouvelleClasse (si besoin)
// parametre   : * sur struct classe_t (classe1)
//               * sur struct classe_t (classe2)
void ft_affecterEleveClasse(classe_t **classe1, classe_t **classe2, eleve_t **eleve)
{
    // Si classe1 existe et classe2 existe
    if ((*classe1)!=NULL && (*classe2)!=NULL)
    {
        // Si les 2 classes sont pleine
        if ((*classe1)->nbeleve==25 && (*classe2)->nbeleve==25)
            printf("Il n'y a plus de place dans s classe dans cette école\n");
        // si il y a de la place dans la classe2 seulement
        else if ((*classe1)->nbeleve==25 && (*classe2)->nbeleve<25)
            ft_insererEleveClasse((*classe2), eleve);
        // si il y a de la place dans la classe1 seulement
        else if ((*classe1)->nbeleve<25 && (*classe2)->nbeleve==25)
            ft_insererEleveClasse((*classe1), eleve);
        // si il y a de la place dans les 2 classe
        else if ((*classe1)->nbeleve<25 && (*classe2)->nbeleve<25)
        {
            // si il y a plus de place dans la classe2
            if ((*classe1)->nbeleve > (*classe2)->nbeleve)
                ft_insererEleveClasse((*classe2), eleve);
            // si il y a plus de place dans la classe1
            else if ((*classe1)->nbeleve < (*classe2)->nbeleve)
                ft_insererEleveClasse((*classe1), eleve);
            // si il y a autant de place dans la classe1 qu dans la classe2
            else
                ft_insererEleveClasse((*classe1), eleve);
        }
    }
    // Si classe1 existe et classe 2 n'existe pas
    else if ((*classe1)!=NULL && (*classe2)==NULL)
    {
        // Si la classe1 est pleine
        if ((*classe1)->nbeleve==25)
        {
            ft_creerClasse(classe2);
            ft_creerNouvelleClasse((*classe1), (*classe2));
            ft_affecterEleveClasse(classe1, classe2, eleve);
        }
        // si la classe1 a de la place
        else
            ft_insererEleveClasse((*classe1), eleve);
    }
    // Si classe1 n'existe pas et classe 2 existe
    else if ((*classe1)==NULL && (*classe2)!=NULL)
    {
        // Si la classe2 est pleine
        if ((*classe2)->nbeleve==25)
        {
            ft_creerClasse(classe1);
            ft_creerNouvelleClasse((*classe2), (*classe1));
            ft_affecterEleveClasse(classe1, classe2, eleve);
        }
        // si la classe2 a de la place
        else
            ft_insererEleveClasse((*classe2), eleve);
    }
    // Si aucune classe
    else if ((*classe1)==NULL && (*classe2)==NULL)
    {
        ft_creerClasse(classe1);
        ft_insererEleveClasse((*classe1), eleve);
    }
}

//----------------------------------------------------------------------------
// Description : Inserre eleve dans une classe selon ordre alphabétique
// parametre   : * sur struct classe_t
//               * sur struct eleve_t
void ft_insererEleveClasse(classe_t *classe, eleve_t **eleve)
{
    int i=1;
    int j=0;

    eleve_t *eleveCourant  = classe->ptr_eleve;
    eleve_t *eleveCourant2 = classe->ptr_eleve;

    if (classe->ptr_eleve==NULL)
    {
         classe->ptr_eleve = (*eleve);
         classe->nbeleve = classe->nbeleve + 1;
    }
    else
    {
        while (strcmp(eleveCourant->nom, (*eleve)->nom)>0)
        {
            eleveCourant = eleveCourant->suivant;
            i++;
        }
        while (strcmp(eleveCourant->nom, (*eleve)->nom)==0 && strcmp(eleveCourant->prenom, (*eleve)->prenom)>0)
        {
            eleveCourant = eleveCourant->suivant;
            i++;
        }
        classe->nbeleve = classe->nbeleve + 1;
    }
    i--;

    if (i==classe->nbeleve)
    {
        eleveCourant = (*eleve);
        (*eleve)->suivant = NULL;
    }
    else
    {
        eleveCourant = classe->ptr_eleve;
        for (j=0; j<i-1; j++)
        {
            eleveCourant = eleveCourant->suivant;
        }
        eleveCourant2 = eleveCourant->suivant;
        eleveCourant->suivant = (*eleve);
        (*eleve)->suivant = eleveCourant2;
    }
}

//-----------------------------------------------------------------------------
// Description : Coupe une classe pleine en 2 classes
// parametre   : * sur struct classe_t (classe pleine)
//               * sur struct classe_t (classe a creer)
void ft_creerNouvelleClasse(classe_t *classePleine, classe_t *classeNouvelle)
{
    eleve_t *element = classePleine->ptr_eleve;
    int i;

    for (i=1; i<12; i++)
    {
        element = element->suivant;
    }
    if (i==12)
    {
        classeNouvelle->ptr_eleve = element->suivant;
        element->suivant = NULL;
    }
}
void ft_creerClasse(classe_t **classe)
{
    (*classe) = (classe_t*)malloc(sizeof(classe_t));
    memset((*classe), 0, sizeof(classe_t));
}

