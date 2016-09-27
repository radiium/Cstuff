/*******************************************************
    Nom        : menu.C

    Desription : Définition des fonctions de
                 menus et des sous menus associées

    Auteur     : R.P

********************************************************/

#include "menu.h"

//-----------------------------------------------------------------------------
//  Description : menu principale
//  parametre   : * sur  struct ecole_t
void ft_menuPrincipale(ecole_t *ecole)
{
    int choix   = 0;    //Choix du menu
    int quitter = 0;    //Quitter le programme

    while (quitter!=1) {

        //Affiche entete et menu principal
        ft_afficheEntete(*ecole);
        printf("\n\n");
        printf("\t\t MENU PRINCIPAL:\n");
        printf("\t\t==================\n\n");
        printf("\t\t1 *  Inscrire\n\n");
        printf("\t\t2 *  Consulter\n\n");
        printf("\t\t3 *  Gerer\n\n\n\n");
        printf("\t\t0 *  Quitter\n\n\n\n\n\t\t  >>");
        scanf("%d", &choix);
        viderBuffer();
        printf("\n\n");


        switch(choix) {
            case 0:
                //Quitte le programme (et te dit au revoir)
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t=======================\n\n");
                printf("\t\t   Au revoir et merci\n\n");
                printf("\t\t=======================\n\n\n\n\n\n\n\n");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                quitter = 1;
                break;
            case 1:
                // Sous-menu inscrire (un eleve)
                ft_menuInscrire(ecole);
                break;
            case 2:
                // Sous-menu consulter(ecole, classe ou eleve)
                ft_menuConsulter(*ecole);
                break;
            case 3:
                // Sous-menu gerer (modifier champs des structure ecole, classe ou eleve)
                ft_menuGerer(ecole);
                break;
            default:
                printf("\n\n\n\n");
                printf("Ce n'est pas un choix valide, recommencez la saisie\n");
        }
    }
}

//-----------------------------------------------------------------------------NE FONCTIONNE PAS (GDB >> SIGSEGV)
//                                                                             eleve a inscrire ecrase eleve deja inscrit
//  Description : Sous-menu Inscrire (un eleve)
//  parametre   : * sur  struct ecole_t
void ft_menuInscrire(ecole_t *ecole)
{
    eleve_t *eleveAinscrire = malloc(sizeof(eleve_t));  // Declaration et allocation memoire d'un eleve a inscrire
    if (!eleveAinscrire)
    {
        exit(EXIT_FAILURE);
    }
    memset(eleveAinscrire, 0, sizeof(eleve_t));
    classe_t *classeEleveChercher = NULL;
    int eleveExiste = 0;                                // Test si eleve est deja inscrit

    // Saisi nom et prenom de l'eleve a inscrire
    printf("\n\n\t\tVeuillez saisir le nom d'un eleve :");
    printf("\n\n\t\t  Nom :");
    lireChaine(eleveAinscrire->nom, MAX_CHAR);
    printf("\n\n\t\tVeuillez saisir le prenom d'un eleve :");
    printf("\n\n\t\t  Prenom :");
    lireChaine(eleveAinscrire->prenom, MAX_CHAR);

    // Recherche si eleve existe dans l'ecole
    // eleveExiste = ft_rechercheEleveEcole(*ecole, &eleveAinscrire, &classeEleveChercher);
    if (eleveExiste==0)
    {
        printf("eleve nexiste pas alors classe = NULL\n");
    }
    // Si eleve existe ne fait rien
    if (eleveExiste==1)
    {
        printf("Leleve est deja inscrit dans cette ecole\n");
    }
    // Si eleve n'existe pas, saisi et affecte eleve
    if (eleveExiste==0)
    {
        Saisir_Eleve(eleveAinscrire);
        ft_affecterEleveNiveau(ecole, &eleveAinscrire);
    }
    free(eleveAinscrire);
    eleveAinscrire = NULL;
    printf("nom = %s", eleveAinscrire->nom);
}

//-----------------------------------------------------------------------------
//  Description : Sous-menu consulter (eleve, classe, ecole)
//  parametre   : struct ecole_t
void ft_menuConsulter(ecole_t ecole)
{
    int choix  = 0;//Choix du menu

    do {
        //Affichage entete et menu
        ft_afficheEntete(ecole);
        printf("\n\n");
        printf("\t\t CONSULTATION:\n");
        printf("\t\t==================\n\n");
        printf("\t\t1 *  Les informations d'un eleve\n\n");
        printf("\t\t2 *  Les eleves d'une classe\n\n");
        printf("\t\t3 *  Les informations de l'ecole\n\n\n\n");
        printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
        scanf("%d",&choix);
        viderBuffer();

        switch(choix)
        {
            case 0:
                //Retour menu parent
                break;
            case 1:
                //Rechercher et afficher infos eleve
                ft_consulterEleve(ecole);
                break;
            case 2:
                //Choisir et afficher classe
                ft_consulterClasse(ecole);
                break;
            case 3:
                //Afficher infos ecole
                ft_afficherEcole(ecole);
                //Mise en pause de l'affichage jusqu'a saisie de 0
                attenteRetour();
                break;
            default:
                printf("\n\n\n\n");
                printf("Ce n'est pas un choix valide, recommencez la saisie\n");
                break;
        }
    }while ((choix<0) && (choix>3));
}

//-----------------------------------------------------------------------------
//    Description : sous-menu affiche les informations d'un eleve recherche
//    parametre   : struct ecole_t
void ft_consulterEleve(ecole_t ecole)
{

    int trouver   = 0;                                  // Resultat de la recherche (= 1 si trouvé, sinon 0)
    eleve_t *eleveChercher = malloc(sizeof(eleve_t));   // Declaration et allocation memoire d'un eleve
    classe_t * classeEleveChercher = NULL;

    // Saisie de nom et prenon de l'eleve a rechercher
    ft_afficheEntete(ecole);
    printf("\n\n\t\tVeuillez saisir le nom d'un eleve :");
    printf("\n\n\t\t  Nom :");
    lireChaine(eleveChercher->nom, MAX_CHAR);
    printf("\n\n\t\tVeuillez saisir le prenom d'un eleve :");
    printf("\n\n\t\t  Prenom :");
    lireChaine(eleveChercher->prenom, MAX_CHAR);

    // Recherche eleve dans l'ecole (si trouvé renvoie 1 et fait pointer l'eleve sur eleveChercher)
    trouver = ft_rechercheEleveEcole(ecole, &eleveChercher, &classeEleveChercher);

    // Si eleve existe affiche ses informations et attend retour menu
    if(trouver==1)
    {
        ft_afficheEntete(ecole);
        Afficher_Eleve(*eleveChercher);
        attenteRetour();
    }
    //sinon message d'erreur
    else
    {
        printf("\n\n\n\n\t\tCet eleve n'est pas inscrit dans l'ecole\n");
        //Mise en pause de l'affichage jusqu'a saisie de 0
        attenteRetour();
    }
}

//-----------------------------------------------------------------------------
//  Description : Sous-menu affiche les informations d'une classe
//  parametre   : struct ecole_t
void ft_consulterClasse(ecole_t ecole)
{
    int choix  = 0;     // Choix du menu

    //menu liste des classes
    do {
        ft_afficheEntete(ecole);
        printf("\n\n");
        printf("\t\tQuel classe souhaitez-vous consulter :\n\n");
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
            if (ecole.tab_cp[0]!=NULL && ecole.tab_cp[1]!=NULL)
            {
                ft_afficherClasse(ecole.tab_cp[0]);
                ft_afficherClasse(ecole.tab_cp[1]);
            }
            if (ecole.tab_cp[0]!=NULL && ecole.tab_cp[1]==NULL)
                ft_afficherClasse(ecole.tab_cp[0]);
            if (ecole.tab_cp[0]==NULL && ecole.tab_cp[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CP\n\n");
            break;
        case 2:
            if (ecole.tab_ce1[0]!=NULL && ecole.tab_ce1[1]!=NULL)
            {
                ft_afficherClasse(ecole.tab_ce1[0]);
                ft_afficherClasse(ecole.tab_ce1[1]);
            }
            if (ecole.tab_ce1[0]!=NULL && ecole.tab_ce1[1]==NULL)
                ft_afficherClasse(ecole.tab_ce1[0]);
            if (ecole.tab_ce1[0]==NULL && ecole.tab_ce1[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CE1\n\n");
            break;
        case 3:
            if (ecole.tab_ce2[0]!=NULL && ecole.tab_ce2[1]!=NULL)
            {
                ft_afficherClasse(ecole.tab_ce2[0]);
                ft_afficherClasse(ecole.tab_ce2[1]);
            }
            if (ecole.tab_ce2[0]!=NULL && ecole.tab_ce2[1]==NULL)
                ft_afficherClasse(ecole.tab_ce2[0]);
            if (ecole.tab_cm2[0]==NULL && ecole.tab_cm2[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CE2\n\n");
            break;
        case 4:
            if (ecole.tab_cm1[0]!=NULL && ecole.tab_cm1[1]!=NULL)
            {
                ft_afficherClasse(ecole.tab_cm1[0]);
                ft_afficherClasse(ecole.tab_cm1[1]);
            }
            if (ecole.tab_cm1[0]!=NULL && ecole.tab_cm1[1]==NULL)
                ft_afficherClasse(ecole.tab_cm1[0]);
            if (ecole.tab_cm1[0]==NULL && ecole.tab_cm1[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CM1\n\n");
            break;
        case 5:
            if (ecole.tab_cm2[0]!=NULL && ecole.tab_cm2[1]!=NULL)
            {
                ft_afficherClasse(ecole.tab_cm2[0]);
                ft_afficherClasse(ecole.tab_cm2[1]);
            }
            if (ecole.tab_cm2[0]!=NULL && ecole.tab_cm2[1]==NULL)
                ft_afficherClasse(ecole.tab_cm2[0]);
            if (ecole.tab_cm2[0]==NULL && ecole.tab_cm2[1]==NULL)
                printf("\n\n\t\tIl n'a pas de classe de CM2\n\n");
            break;
        default:
            printf("\n\n\t\tCe choix n'est pas valide, recommencez\n\n");
            break;
    }
}

//-----------------------------------------------------------------------------
//  Description : Sous-menu gerer (modifier champs ecole, classe ou eleve)
//  parametre   : * sur struct ecole_t
void ft_menuGerer(ecole_t *ecole)
{
    int choix  = 0;     //Choix du menu

    do {
        ft_afficheEntete(*ecole);
        printf("\n\n");
        printf("\t\t GESTION:\n");
        printf("\t\t=========\n\n");
        printf("\t\t1 *  Modification d'un eleve\n\n");
        printf("\t\t2 *  Modification de la classe\n\n");
        printf("\t\t3 *  Modification de l'ecole \n\n\n\n");
        printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
        scanf("%d",&choix);
        viderBuffer();

        switch(choix)
        {
            case 0:
                break;
            case 1:
                // Modifier les informations d'un eleve
                ft_menuGererEleve(ecole);
                break;
            case 2:
                // Modifier les informations d'une classe
                ft_menuGererClasse(ecole);
                break;
            case 3:
                // Modifier les informations de l'ecole
                ft_modifierEcole(ecole);
                break;
            default:
                printf("\n\n\n\n");
                printf("Ce n'est pas un choix valide, recommencez la saisie\n");
                break;
        }
    }while ((choix<0) && (choix>3));
}

void ft_menuGererEleve(ecole_t *ecole)
{
    int choix  = 0;     //Choix du menu

    eleve_t *elevemodif;
    elevemodif=(eleve_t *)malloc(sizeof(eleve_t));
    memset(elevemodif,0,sizeof(eleve_t));
    classe_t *tete = NULL;

    do {
        ft_afficheEntete(*ecole);
        printf("\n\n");
        printf("\t\t GERER ELEVE:\n");
        printf("\t\t=============\n\n");
        printf("\t\t1 *  Modification d'un eleve\n\n");
        printf("\t\t2 *  Suppression d'un eleve\n\n");
        printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
        scanf("%d",&choix);
        viderBuffer();

        switch(choix)
        {
            case 0:
                break;
            case 1:
                Modifier_Nom(elevemodif);
                Modifier_Prenom(elevemodif);
                ft_rechercheEleveEcole(*ecole,&elevemodif,&tete); //Ajouter modif classe etc...
                Saisir_Eleve(elevemodif);
                break;
            case 2:
                Modifier_Nom(elevemodif);
                Modifier_Prenom(elevemodif);
                ft_rechercheEleveEcole(*ecole,&elevemodif,&tete);
                ft_supprimerEleve(tete,&elevemodif);
                break;
            default:
                printf("\n\n\n\n");
                printf("Ce n'est pas un choix valide, recommencez la saisie\n");
                break;
        }
    }while ((choix<0) && (choix>2));
}

void ft_menuGererClasse(ecole_t *ecole)
{
    int choix  = 0;     //Choix du menu

    classe_t *classemodif;
    classemodif=(classe_t *)malloc(sizeof(classe_t));
    memset(classemodif,0,sizeof(classe_t));

    do {
        ft_afficheEntete(*ecole);
        printf("\n\n");
        printf("\t\t GERER CLASSE:\n");
        printf("\t\t=============\n\n");
        printf("\t\t1 *  Modification d'une classe\n\n");
        printf("\t\t2 *  Suppression d'une classe\n\n");
        printf("\t\t0 *  Retour\n\n\n\n\n\t\t  >>");
        scanf("%d",&choix);
        viderBuffer();

        switch(choix)
        {
            case 0:
                break;
            case 1:
                //afficher les classes
                ft_modifierClasse(classemodif);
                break;
            case 2:
                ft_supprimerClasse(ecole);
                break;
            default:
                printf("\n\n\n\n");
                printf("Ce n'est pas un choix valide, recommencez la saisie\n");
                break;
        }
    }while ((choix<0) && (choix>2));
}

