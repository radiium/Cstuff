/*******************************************************
    Nom        : date.c

    Desription : Définition des fonctions associées  à
                 la gestion des dates.

    Auteur     : T.C
                 R.P

********************************************************/

#include "date.h"

//-----------------------------------------------------------------------------
//  Description : Affichage formaté (jj/mm/aaaa) d'une date
//  parametre   : date au format time_t
void ft_afficherDate(time_t date)
{
    char chaine[11];

    // place le message dans la chaÃ®ne
    strftime(chaine,11,"%d/%m/%Y", localtime(&date));

    //affiche la chaÃ®ne en console
    printf(" %10s",chaine);
}

//-----------------------------------------------------------------------------
//  Description : calcul age de l'eleve
//  parametre   : date au format time_t
int ft_calculAgeEleve(time_t dateNaissance)
{
    time_t tempsactuel;
    time_t age;

    tempsactuel=time(NULL);

    age=difftime(tempsactuel,dateNaissance);

    age=age/(365.25*24*60*60);

    return (int)age;
}

//-----------------------------------------------------------------------------
//  Description : calcul si année de date est bisextile
//  parametre   : année au format int
int ft_bissextile (int aaaa)
{
    if (aaaa % 4 == 0 && (aaaa % 100 != 0 || aaaa % 400 == 0))
        return 1;
    else
        return 0;
}

//-----------------------------------------------------------------------------
//  Description : Verification de saisi de date
//  parametre   : 3 int (jour, mois, année)
int ft_dateCorrecte (int jj, int mm, int aaaa)
{
    int jj_valide;
    if(mm>0 && mm<13)
    {
        switch (mm)
        {
            case 1: jj_valide = 31;
                break;
            case 2: if (ft_bissextile (aaaa))
                        jj_valide = 29;
                    else
                        jj_valide = 28;
                break;
            case 3: jj_valide = 31;
                break;
            case 4: jj_valide = 30;
                break;
            case 5: jj_valide = 31;
                break;
            case 6: jj_valide = 30;
                break;
            case 7: jj_valide = 31;
                break;
            case 8: jj_valide = 31;
                break;
            case 9: jj_valide = 30;
                break;
            case 10: jj_valide = 31;
                break;
            case 11: jj_valide = 30;
                break;
            case 12 : jj_valide = 31;
                break;
            default : return 0;
        }
        if (jj <= 0 || jj > jj_valide || aaaa  < 0)
        {
            printf("\n\t\t=> date invalide, la resaisir svp ");
            return 0;
        }
        else
            return 1;
    }
    else
    {
        printf("\n\t\t=> date invalide, la resaisir svp ");
        return 0;
    }
}

//-----------------------------------------------------------------------------
//  Description : Saisi d'une date au format jj/mm/aaaa
//  retour      : date au format time_t
time_t ft_saisieDate()
{
    time_t A;
    struct tm B;
    memset(&B,0,sizeof(struct tm));

    do
    {
    printf("\n\t\t     - jour  : ");
    scanf("%d",&B.tm_mday);
    viderBuffer();
    printf("\t\t     - mois  : ");
    scanf("%d",&B.tm_mon);
    viderBuffer();
    printf("\t\t     - annee : ");
    scanf("%d",&B.tm_year);
    viderBuffer();
    }
    while (ft_dateCorrecte(B.tm_mday,B.tm_mon,B.tm_year) != 1);
    B.tm_mon  -= 1;
    B.tm_year -= 1900;

    A=mktime(&B);

    return A;
}

