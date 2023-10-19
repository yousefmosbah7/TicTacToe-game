#include "functions.h"
#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
#include "array.h"

/*
 * Function: TicTacToeGame_uint8Available_Position
 * ----------------------
 * This function checks if the position which user choose is available to play in (empty) or not.
 *
 * Parameters:
 *   param1: X axis.
 *   param2: Y axis.
 *
 * Returns:
 *   Function returns 1 if the position is empty and 0 if not.
 */
uint8 TicTacToeGame_uint8Available_Position(uint8 x,uint8 y)
{
    if(x==48&&y==48)
    {
        if(xx[0][0]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==48&&y==49)
    {
        if(xx[0][1]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==48&&y==50)
    {
        if(xx[0][2]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==49&&y==48)
    {
        if(xx[1][0]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==49&&y==49)
    {
        if(xx[1][1]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==49&&y==50)
    {
        if(xx[1][2]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==50&&y==48)
    {
        if(xx[2][0]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==50&&y==49)
    {
        if(xx[2][1]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(x==50&&y==50)
    {
        if(xx[2][2]==' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}
