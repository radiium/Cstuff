/*******************************************************
    Name       : main.c

    Desription : main of simple game (puissance4)

    Autor      : Rémi PONCET

********************************************************/
#include "menu.h"
#include "function.h"

int main ()
{
    char grid[6][7] = {{0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0}};

    int column = 0;
    int row    = 0;
    int winner = 0;
    int test   = 0;

    menu();
    title();
    put_grid(grid);

    do{
        do{
            color("31");
            printf("\tPlayer 1\n\n\t>>");
            color("0");
            scanf("%d", &column);
            printf("\n\n\n\n\n\n\n\n\n\n");
            if((column<1) || (column>7) || (grid[0][column-1]=='X') || (grid[0][column-1]=='O'))
            {
                printf("\n\tYou are out of the grid...\n\tTry again!\n\n");
            }
            else
            {
                get_grid(grid, column-1, 1, &row);
                winner = check(grid, row, column-1);
                column = 0;
                title();
                put_grid(grid);
                test = 1;
            }
        }while(test==0);
        test = 0;

        if(winner==0)
        {
            do{
                color("33");
                printf("\tPlayer 2\n\n\t>>");
                color("0");
                scanf("%d", &column);
                printf("\n\n\n\n\n\n\n\n\n\n");
                if((column<1) || (column>7) || (grid[0][column-1]=='X') || (grid[0][column-1]=='O'))
                {
                    printf("\n\tYou are out of the grid...\n\tTry again!\n\n");
                }
                else
                {
                    get_grid(grid, column-1, 2, &row);
                    winner = check(grid, row, column-1);
                    column = 0;
                    title();
                    put_grid(grid);
                    test = 1;
                }
            }while(test==0);
            test = 0;
        }

    }while(winner==0);
    win(winner);
    put_grid(grid);

    return 0;
}

