/*******************************************************
    Name       : function.h

    Desription : function relative to the grid

    Autor      : Rémi PONCET

********************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define color(param) printf("\033[%sm",param)

#ifndef _FUNCTION_H
#define _FUNCTION_H

//-----------------------------------------------------------------------------
//  Description : displays the grid
//  Argument    : 2d array, 
void put_grid(char grid[6][7]);

//-----------------------------------------------------------------------------
//  Description : write in the grid
//  Argument    : 2d array, 
void get_grid(char grid[6][7],int column, int player, int * row);

//-----------------------------------------------------------------------------
//  Description : check if current player wins
//  Argument    : 2d array, row and column position
int  check(char grid[6][7], int row, int culumn);

#endif // _FUNCTION_H
