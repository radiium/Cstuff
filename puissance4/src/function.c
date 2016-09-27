#include "function.h"


//-----------------------------------------------------------------------------
//  Description : displays the grid
//  Argument    : 2d array, 
void put_grid(char grid[6][7])
{
    int i, k;
    
    printf("\n\n\t");

    // rows 
    for (i=0; i<6; i++)
    {
        //interrows
        for(k=0; k<7; k++)
            printf("----");
        printf("-\n\t|");

        //boucle columns
        //si case vide affiche espace plutot que 0
        for(k=0; k<7; k++)
        {
            if(grid[i][k]==0)
                printf("   ");

            //couleur de fond rouge
            else if(grid[i][k]=='X')
            {
                color("41");
                printf(" %1c ", grid[i][k]);
                color("0");
            }
            //couleur de fond jaune
            else if(grid[i][k]=='O')
            {
                color("43");
                printf(" %1c ", grid[i][k]);
                color("0");
            }
            printf("|");
        }
        //numérotation rows
        printf(" %d\n\t", i+1);
    }

    //interrow de fin
    for(k=0; k<7; k++)
        printf("----");
    printf("-\n\t");

    //numerotation colone
    for(k=0; k<7; k++)
        printf("  %d ", k+1);
    printf("\n\n\n\n");
}

//-----------------------------------------------------------------------------
//  Description : write in the grid
//  Argument    : 2d array, 
void get_grid(char grid[6][7],int column, int player, int * row)
{
    int i;

    //rempli case player 1
    if(player==1)
        for(i=5; i>=0; i--)
        {
            if(grid[i][column]==0)
            {
                grid[i][column] = 'X';
                *row = i;
                i=0;
            }
        }
    //rempli case player 2
    else if(player==2)
        for(i=5; i>=0; i--)
        {
            if(grid[i][column]==0)
            {
                grid[i][column] = 'O';
                *row = i;
                i=0;
            }
        }
}

//-----------------------------------------------------------------------------
//  Description : check if current player wins
//  Argument    : 2d array, row and column position
int check(char grid[6][7], int row, int column)
{
    int li = row;
    int co = column;
    int pion = 0;

    ////////////////////////////////////////////////////////////
    //              verification of X (player 1)              //
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////horizontal verification
    co = column;
    while(grid[li][co] == 'X' && co < 7) {
        pion++;
        co++;
    }
    if (pion==4)
        return 1;

    co = column-1;
    while(grid[li][co] == 'X' && co >= 0) {
        pion++;
        co--;
    }
    if (pion==4)
        return 1;
    pion = 0;//------------pion 0

    //////////////////////////////////////vertical verification
    li = row;
    co = column;
    while(grid[li][co] == 'X' && li >= 0) {
        pion++;
        li++;
    }
    if (pion==4)
        return 1;
    pion = 0;//------------pion 0

    //////////////////////////////////////diagonal verification
    //                                  (de droite à gauche)
    li = row;
    co = column;
    while(grid[li][co] == 'X' && co < 7 && li < 6) {
        pion++;
        li++;
        co++;
    }
    if (pion==4)
        return 1;

    li = row;
    co = column;
    while(grid[li][co] == 'X' && co > 0 && li > 0) {
        pion++;
        li--;
        co--;
    }
    if (pion==4)
        return 1;
    pion = 0;//------------pion 0

    //////////////////////////////////////diagonal verification
    //                                  (de gauche à droite)
    li = row;
    co = column;
    while(grid[li][co] == 'X' && co < 7 && li < 6) {
        pion++;
        li++;
        co--;
    }
    if (pion==4)
        return 1;

    li = row;
    co = column;
    while(grid[li][co] == 'X' && co > 0 && li > 0) {
        pion++;
        li--;
        co++;
    }
    if (pion==4)
        return 1;
    pion = 0;//------------pion 0

    ////////////////////////////////////////////////////////////
    //              verification of O (player 2)              //
    ////////////////////////////////////////////////////////////

    ////////////////////////////////////horizontal verification
    li = row;
    co = column;

    while(grid[li][co] == 'O' && co < 7) {
        pion++;
        co++;
    }
    if (pion==4)
        return 2;

    li = row;
    co = column-1;
    while(grid[li][co] == 'O' && co >= 0) {
        pion++;
        co--;
    }
    if (pion==4)
        return 2;
    pion = 0;

    //////////////////////////////////////vertical verification
    li = row;
    co = column;
    while(grid[li][co] == 'O' && li >= 0) {
        pion++;
        li++;
    }
    if (pion==4)
        return 2;
    pion = 0;//------------pion 0

    //////////////////////////////////////diagonal verification
    //                                    (de droite à gauche)
    li = row;
    co = column;
    while(grid[li][co] == 'O' && co < 7 && li < 6) {
        pion++;
        li++;
        co++;
    }
    if (pion==4)
        return 2;

    li = row;
    co = column;
    while(grid[li][co] == 'O' && co > 0 && li > 0) {
        pion++;
        li--;
        co--;
    }
    if (pion==4)
        return 2;
    pion = 0;//------------pion 0

    //////////////////////////////////////diagonal verification
    //                                    (de gauche à droite)
    li = row;
    co = column;
    while(grid[li][co] == 'X' && co < 7 && li < 6) {
        pion++;
        li++;
        co--;
    }
    if (pion==4)
        return 2;

    li = row;
    co = column;
    while(grid[li][co] == 'X' && co > 0 && li > 0) {
        pion++;
        li--;
        co++;
    }
    if (pion==4)
        return 2;
    pion = 0;//------------pion 0

    return 0;
}

