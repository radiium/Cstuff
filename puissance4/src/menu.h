/*******************************************************
    Name       : menu.h

    Desription : function relative to the display

    Autor      : Rémi PONCET

********************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef _MENU_H
#define _MENU_H

//-----------------------------------------------------------------------------
//  Description : Display title game
void title();

//-----------------------------------------------------------------------------
//  Description : Display menu game
void menu();

//-----------------------------------------------------------------------------
//  Description : Display credit
void credit();

//-----------------------------------------------------------------------------
//  Description : Display winner
//  Argument    : player
void win(int winner);

//-----------------------------------------------------------------------------
//  Description : pause display
void waitingBack();

#endif // _MENU_H
