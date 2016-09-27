#include "menu.h"

//-----------------------------------------------------------------------------
//  Description : Display title game
void title()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("             _                            ___ \n");
    printf("     ___ _ _|_|___ ___ ___ ___ ___ ___   | | |\n");
    printf("    | . | | | |_ -|_ -| .'|   |  _| -_|  |_  |\n");
    printf("    |  _|___|_|___|___|__,|_|_|___|___|    |_|\n");
    printf("    |_|\n\n\n\n\n\n\n");
}
//-----------------------------------------------------------------------------
//  Description : Display menu game
void menu()
{
    int menu = 0;

    while(menu!=1)
    {
        title();
        //printf("\t1-Partie simple\n");
        printf("\t1-Two player\n");
        printf("\t2-Credit\n\n\n\n\n\t>> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
                menu = 1;
                break;
            case 2:
                credit();
                break;
            default:
                title();
                printf("\n\tWrong way...\n\tTry again!\n\n");
                waitingBack();
                break;
        }
    }
}
//-----------------------------------------------------------------------------
//  Description : Display credit
void credit()
{
    title();
    printf("\t========================\n");
    printf("\t* game made by radiium *\n");
    printf("\t========================\n");    

    waitingBack();
}

//-----------------------------------------------------------------------------
//  Description : Display winner
//  Argument    : player
void win(int winner)
{
    if(winner==1)
    {
        printf("\t _ | _    _ _   /|     . _   | \n");
        printf("\t|_)|(_|\\/(-|     |  \\)/|| )  . \n");
        printf("\t|      /                 \n\n\n\n\n");
    }
    if(winner==2)
    {
        printf("\t                 _\n");
        printf("\t _ | _    _ _    _)     . _   | \n");
        printf("\t|_)|(_|\\/(-|    /__  \\)/|| )  . \n");
        printf("\t|      /                  \n\n\n\n\n");
    }
}

//-----------------------------------------------------------------------------
//  Description : pause display
void waitingBack()
{
    int retour = 1;

    do {
        printf("\n\n\n    Press 0 to return to the menu ");
        scanf("%d", &retour);
    }while(retour!=0);
}

