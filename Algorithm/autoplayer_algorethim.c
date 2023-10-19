#include "functions.h"
#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include "array.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
/*
 * Function: TicTacToeGame_VFirstTwo_Moves_User
 * ----------------------
 * This functions is related to the algorithm of playing against the program in single mode and it is responsible
   of making the first two moves of the program (if the user starts) as a reaction to the user first two moves.
 *
 * Parameters:
 *   param1: move number (first move or second move)
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VFirstTwo_Moves_User(uint8 count)
{
    if(count==1) //first move
    {
        if(xx[2][0]==' ')
        {
            xx[2][0]='x';
            TicTacToeGame_VBoard_After_Update('x',50,48);
        }
        else
        {
            xx[2][2]='x';
            TicTacToeGame_VBoard_After_Update('x',50,50);
        }
    }
    else if(count==3)  //second move
    {
        uint8 val;
        val=TicTacToeGame_uint8Avoid_Loss();
        if(!val)
        {
            if((xx[0][0]=='o')&&(xx[2][0]=='o'))
            {
                xx[0][2]='x';
                TicTacToeGame_VBoard_After_Update('x',48,50);
            }
            else if((xx[0][0]=='o')&&(xx[0][2]=='o'))
            {
                xx[2][0]='x';
                TicTacToeGame_VBoard_After_Update('x',50,48);
            }
            else if((xx[0][2]=='o')&&(xx[2][0]=='o'))
            {
                xx[0][0]='x';
                TicTacToeGame_VBoard_After_Update('x',48,48);
            }else if(xx[0][2]==' '){
                xx[0][2]='x';
                TicTacToeGame_VBoard_After_Update('x',48,50);
            }else if(xx[0][0]=' '){
                xx[0][0]='x';
                TicTacToeGame_VBoard_After_Update('x',48,48);
            }
        }
    }
}

/*
 * Function: TicTacToeGame_VFirstTwo_Moves_Prog
 * ----------------------
 * This functions is related to the algorithm of playing against the program in single mode and it is responsible
   of making the first two moves of the program (if the program starts) as a reaction to the user first move.
 *
 * Parameters:
 *   param1: move number (first move or second move)
 *
 * Returns:
 *   Void.
 */
void TicTacToeGame_VFirstTwo_Moves_Prog(uint8 count)
{
    if(count==0) //first move
    {
        xx[2][0]='x';
        TicTacToeGame_VBoard_After_Update('x',50,48);
    }
    else if(count==2)  //second move
    {
        if(xx[1][1]=='o')
        {
            xx[0][0]='x';
            TicTacToeGame_VBoard_After_Update('x',48,48);
        }
        else if((xx[1][1]==' ')&&(xx[0][2]==' '))
        {
            xx[0][2]='x';
            TicTacToeGame_VBoard_After_Update('x',48,50);
        }
        else
        {
            xx[0][0]='x';
            TicTacToeGame_VBoard_After_Update('x',48,48);
        }
    }
}

/*
 * Function: TicTacToeGame_uint8Avoid_Loss
 * ----------------------
 * This function checks after every move if there is any chance to loose and makes a move to avoid loss.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Function returns 1 if making a move to avoid loss and 0 if no need
 */
uint8 TicTacToeGame_uint8Avoid_Loss()
{

    uint8 ret_state=0;
//first row-------------------------------------
    if(((xx[0][0]=='o')&&(xx[0][1]=='o')&&(xx[0][2]==' '))||((xx[0][0]=='o')&&(xx[0][2]=='o')&&(xx[0][1]==' '))||((xx[0][0]==' ')&&(xx[0][1]=='o')&&(xx[0][2]=='o')))
    {
        for(uint8 i=0; i<1; i++)
        {
            for(uint8 j=0; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//second row-------------------------------------
    else if(((xx[1][0]=='o')&&(xx[1][1]=='o')&&(xx[1][2]==' '))||((xx[1][0]=='o')&&(xx[1][2]=='o')&&(xx[1][1]==' '))||((xx[1][0]==' ')&&(xx[1][1]=='o')&&(xx[1][2]=='o')))
    {
        for(uint8 i=1; i<2; i++)
        {
            for(uint8 j=0; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//third row-------------------------------------
    else if(((xx[2][0]=='o')&&(xx[2][1]=='o')&&(xx[2][2]==' '))||((xx[2][0]=='o')&&(xx[2][2]=='o')&&(xx[2][1]==' '))||((xx[2][0]==' ')&&(xx[2][1]=='o')&&(xx[2][2]=='o')))
    {
        for(uint8 i=2; i<3; i++)
        {
            for(uint8 j=0; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//first column------------------------------------
    else if(((xx[0][0]=='o')&&(xx[1][0]=='o')&&(xx[2][0]==' '))||((xx[0][0]=='o')&&(xx[1][0]==' ')&&(xx[2][0]=='o'))||((xx[0][0]==' ')&&(xx[1][0]=='o')&&(xx[2][0]=='o')))
    {
        for(uint8 i=0; i<3; i++)
        {
            for(uint8 j=0; j<1; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//second column-----------------------------------
    else if(((xx[0][1]=='o')&&(xx[1][1]=='o')&&(xx[2][1]==' '))||((xx[0][1]=='o')&&(xx[1][1]==' ')&&(xx[2][1]=='o'))||((xx[0][1]==' ')&&(xx[1][1]=='o')&&(xx[2][1]=='o')))
    {
        for(uint8 i=0; i<3; i++)
        {
            for(uint8 j=1; j<2; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//third column------------------------------------
    else if(((xx[0][2]=='o')&&(xx[1][2]=='o')&&(xx[2][2]==' '))||((xx[0][2]=='o')&&(xx[1][2]==' ')&&(xx[2][2]=='o'))||((xx[0][2]==' ')&&(xx[1][2]=='o')&&(xx[2][2]=='o')))
    {
        for(uint8 i=0; i<3; i++)
        {
            for(uint8 j=2; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//first diagonal------------------------------------
    else if((xx[0][0]=='o')&&(xx[1][1]=='o')&&(xx[2][2]==' '))
    {
        xx[2][2]='x';
        TicTacToeGame_VBoard_After_Update('x',50,50);
        ret_state=1;
    }
    else if((xx[0][0]=='o')&&(xx[1][1]==' ')&&(xx[2][2]=='o'))
    {
        xx[1][1]='x';
        TicTacToeGame_VBoard_After_Update('x',49,49);
        ret_state=1;
    }
    else if((xx[0][0]==' ')&&(xx[1][1]=='o')&&(xx[2][2]=='o'))
    {
        xx[0][0]='x';
        TicTacToeGame_VBoard_After_Update('x',48,48);
        ret_state=1;
    }
//second diagonal------------------------------------
    else if((xx[0][2]=='o')&&(xx[1][1]=='o')&&(xx[2][0]==' '))
    {
        xx[2][0]='x';
        TicTacToeGame_VBoard_After_Update('x',50,48);
        ret_state=1;
    }
    else if((xx[0][2]=='o')&&(xx[1][1]==' ')&&(xx[2][0]=='o'))
    {
        xx[1][1]='x';
        TicTacToeGame_VBoard_After_Update('x',49,49);
        ret_state=1;
    }
    else if((xx[0][2]==' ')&&(xx[1][1]=='o')&&(xx[2][0]=='o'))
    {
        xx[0][2]='x';
        TicTacToeGame_VBoard_After_Update('x',48,50);
        ret_state=1;
    }
    return ret_state;
}
/*
 * Function: TicTcToeGame_uint8Chance_To_Win
 * ----------------------
 * This function checks if there is any chance to win the gamed and make this move .
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Function returns 1 if making a move to win and 0 if no need.
 */
uint8 TicTcToeGame_uint8Chance_To_Win()
{
    uint8 ret_state=0;
//first row-------------------------------------
    if(((xx[0][0]=='x')&&(xx[0][1]=='x')&&(xx[0][2]==' '))||((xx[0][0]=='x')&&(xx[0][2]=='x')&&(xx[0][1]==' '))||((xx[0][0]==' ')&&(xx[0][1]=='x')&&(xx[0][2]=='o')))
    {
        for(uint8 i=0; i<1; i++)
        {
            for(uint8 j=0; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//second row-------------------------------------
    else if(((xx[1][0]=='x')&&(xx[1][1]=='x')&&(xx[1][2]==' '))||((xx[1][0]=='x')&&(xx[1][2]=='x')&&(xx[1][1]==' '))||((xx[1][0]==' ')&&(xx[1][1]=='x')&&(xx[1][2]=='x')))
    {
        for(uint8 i=1; i<2; i++)
        {
            for(uint8 j=0; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//third row-------------------------------------
    else if(((xx[2][0]=='x')&&(xx[2][1]=='x')&&(xx[2][2]==' '))||((xx[2][0]=='x')&&(xx[2][2]=='x')&&(xx[2][1]==' '))||((xx[2][0]==' ')&&(xx[2][1]=='x')&&(xx[2][2]=='x')))
    {
        for(uint8 i=2; i<3; i++)
        {
            for(uint8 j=0; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//first column------------------------------------
    else if(((xx[0][0]=='x')&&(xx[1][0]=='x')&&(xx[2][0]==' '))||((xx[0][0]=='x')&&(xx[1][0]==' ')&&(xx[2][0]=='x'))||((xx[0][0]==' ')&&(xx[1][0]=='x')&&(xx[2][0]=='x')))
    {
        for(uint8 i=0; i<3; i++)
        {
            for(uint8 j=0; j<1; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//second column-----------------------------------
    else if(((xx[0][1]=='x')&&(xx[1][1]=='x')&&(xx[2][1]==' '))||((xx[0][1]=='x')&&(xx[1][1]==' ')&&(xx[2][1]=='x'))||((xx[0][1]==' ')&&(xx[1][1]=='x')&&(xx[2][1]=='x')))
    {
        for(uint8 i=0; i<3; i++)
        {
            for(uint8 j=1; j<2; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//third column------------------------------------
    else if(((xx[0][2]=='x')&&(xx[1][2]=='x')&&(xx[2][2]==' '))||((xx[0][2]=='x')&&(xx[1][2]==' ')&&(xx[2][2]=='x'))||((xx[0][2]==' ')&&(xx[1][2]=='x')&&(xx[2][2]=='x')))
    {
        for(uint8 i=0; i<3; i++)
        {
            for(uint8 j=2; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    ret_state=1;
                }
            }
        }
    }
//first diagonal------------------------------------
    else if((xx[0][0]=='x')&&(xx[1][1]=='x')&&(xx[2][2]==' '))
    {
        xx[2][2]='x';
        TicTacToeGame_VBoard_After_Update('x',50,50);
        ret_state=1;
    }
    else if((xx[0][0]=='x')&&(xx[1][1]==' ')&&(xx[2][2]=='x'))
    {
        xx[1][1]='x';
        TicTacToeGame_VBoard_After_Update('x',49,49);
        ret_state=1;
    }
    else if((xx[0][0]==' ')&&(xx[1][1]=='x')&&(xx[2][2]=='x'))
    {
        xx[0][0]='x';
        TicTacToeGame_VBoard_After_Update('x',48,48);
        ret_state=1;
    }
//second diagonal------------------------------------
    else if((xx[0][2]=='x')&&(xx[1][1]=='x')&&(xx[2][0]==' '))
    {
        xx[2][0]='x';
        TicTacToeGame_VBoard_After_Update('x',50,48);
        ret_state=1;
    }
    else if((xx[0][2]=='x')&&(xx[1][1]==' ')&&(xx[2][0]=='x'))
    {
        xx[1][1]='x';
        TicTacToeGame_VBoard_After_Update('x',49,49);
        ret_state=1;
    }
    else if((xx[0][2]==' ')&&(xx[1][1]=='x')&&(xx[2][0]=='x'))
    {
        xx[0][2]='x';
        TicTacToeGame_VBoard_After_Update('x',48,50);
        ret_state=1;
    }
    return ret_state;
}

/*
 * Function: TicTacToeGame_VNormal_Moves
 * ----------------------
 * After checking loss and winning odds this function searches for a position which will increase winning percentage
   and if not found it makes a normal move to any empty position.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VNormal_Moves()
{
//first row--------------------------------------------
    if(((xx[0][0]=='x')&&(xx[0][1]==' ')&&(xx[0][2]==' '))||((xx[0][0]==' ')&&(xx[0][2]==' ')&&(xx[0][1]=='x'))||((xx[0][0]==' ')&&(xx[0][1]==' ')&&(xx[0][2]=='x')))
    {
        if(xx[0][1]==' ')
        {
            xx[0][1]='x';
            TicTacToeGame_VBoard_After_Update('x',48,49);
        }
        else
        {
            xx[0][0]='x';
            TicTacToeGame_VBoard_After_Update('x',48,48);
        }
    }
//second row--------------------------------------------
    else if(((xx[1][0]=='x')&&(xx[1][1]==' ')&&(xx[1][2]==' '))||((xx[1][0]==' ')&&(xx[1][2]==' ')&&(xx[1][1]=='x'))||((xx[1][0]==' ')&&(xx[1][1]==' ')&&(xx[1][2]=='x')))
    {
        if(xx[1][1]==' ')
        {
            xx[1][1]='x';
            TicTacToeGame_VBoard_After_Update('x',49,49);
        }
        else
        {
            xx[1][0]='x';
            TicTacToeGame_VBoard_After_Update('x',49,48);
        }
    }
//third row---------------------------------------------
    else if(((xx[2][0]=='x')&&(xx[2][1]==' ')&&(xx[2][2]==' '))||((xx[2][0]==' ')&&(xx[2][2]==' ')&&(xx[2][1]=='x'))||((xx[2][0]==' ')&&(xx[2][1]==' ')&&(xx[2][2]=='x')))
    {
        if(xx[2][1]==' ')
        {
            xx[2][1]='x';
            TicTacToeGame_VBoard_After_Update('x',50,49);
        }
        else
        {
            xx[2][0]='x';
            TicTacToeGame_VBoard_After_Update('x',50,48);
        }
    }
//first column------------------------------------------
    else if(((xx[0][0]=='x')&&(xx[1][0]==' ')&&(xx[2][0]==' '))||((xx[0][0]==' ')&&(xx[1][0]=='x')&&(xx[2][0]==' '))||((xx[0][0]==' ')&&(xx[1][0]==' ')&&(xx[2][0]=='x')))
    {
        if(xx[1][0]==' ')
        {
            xx[1][0]='x';
            TicTacToeGame_VBoard_After_Update('x',49,48);
        }
        else
        {
            xx[0][0]='x';
            TicTacToeGame_VBoard_After_Update('x',48,48);
        }
    }
//second column------------------------------------------
    else if(((xx[0][1]=='x')&&(xx[1][1]==' ')&&(xx[2][1]==' '))||((xx[0][1]==' ')&&(xx[1][1]=='x')&&(xx[2][1]==' '))||((xx[0][1]==' ')&&(xx[1][1]==' ')&&(xx[2][1]=='x')))
    {
        if(xx[1][1]==' ')
        {
            xx[1][1]='x';
            TicTacToeGame_VBoard_After_Update('x',49,49);
        }
        else
        {
            xx[0][1]='x';
            TicTacToeGame_VBoard_After_Update('x',48,49);
        }
    }
//third column-------------------------------------------
    else if(((xx[0][2]=='x')&&(xx[1][2]==' ')&&(xx[2][2]==' '))||((xx[0][2]==' ')&&(xx[1][2]='x')&&(xx[2][2]==' '))||((xx[0][2]==' ')&&(xx[1][2]==' ')&&(xx[2][2]=='x')))
    {
        if(xx[1][2]==' ')
        {
            xx[1][2]='x';
            TicTacToeGame_VBoard_After_Update('x',49,50);
        }
        else
        {
            xx[0][2]='x';
            TicTacToeGame_VBoard_After_Update('x',48,50);
        }
    }
//first diagonal------------------------------------------
    else if((xx[0][0]=='x')&&(xx[1][1]==' ')&&(xx[2][2]==' '))
    {
        xx[1][1]='x';
        TicTacToeGame_VBoard_After_Update('x',49,49);
    }
    else if((xx[0][0]==' ')&&(xx[1][1]=='x')&&(xx[2][2]==' '))
    {
        xx[0][0]='x';
        TicTacToeGame_VBoard_After_Update('x',48,48);
    }
    else if((xx[0][0]==' ')&&(xx[1][1]==' ')&&(xx[2][2]=='x'))
    {
        xx[1][1]='x';
        TicTacToeGame_VBoard_After_Update('x',49,49);
    }
//second diagonal-----------------------------------------
    else if((xx[0][2]=='x')&&(xx[1][1]==' ')&&(xx[2][0]==' '))
    {
        xx[1][1]='x';
        TicTacToeGame_VBoard_After_Update('x',49,48);
    }
    else if((xx[0][2]==' ')&&(xx[1][1]=='x')&&(xx[2][0]==' '))
    {
        xx[0][2]='x';
        TicTacToeGame_VBoard_After_Update('x',48,50);
    }
    else if((xx[0][2]==' ')&&(xx[1][1]==' ')&&(xx[2][0]=='x'))
    {
        xx[0][2]='x';
        TicTacToeGame_VBoard_After_Update('x',48,50);
    }
    else
    {
        for(uint8 i=0; i<3; i++)
        {
            uint8 flag=0;
            for(uint8 j=0; j<3; j++)
            {
                if(xx[i][j]==' ')
                {
                    xx[i][j]='x';
                    TicTacToeGame_VBoard_After_Update('x',i+48,j+48);
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
    }
}
//-----------------------------------------------------------------------------
/*
 * Function: TicTacToeGame_uint8Stone_Rock_Scissor
 * ----------------------
 * this function decides who will start first, the user or the program in single-player mode by playing stone rock scissor.
 *
 * Parameters:
 *   Param1: choice of the user
 *   Param2: choice of the program
 *
 * Returns:
 *   function returns 1 if the user wins and 0 if the program win
 */
uint8 TicTacToeGame_uint8Stone_Rock_Scissor(char you, char computer)
{

    // If user's choice is stone and
    // computer's choice is paper
    if (you == 's' && computer == 'p')
        return 0;

    // If user's choice is paper and
    // computer's choice is stone
    else if (you == 'p' && computer == 's') return 1;

    // If user's choice is stone and
    // computer's choice is scissor
    if (you == 's' && computer == 'z')
        return 1;

    // If user's choice is scissor and
    // computer's choice is stone
    else if (you == 'z' && computer == 's')
        return 0;

    // If user's choice is paper and
    // computer's choice is scissor
    if (you == 'p' && computer == 'z')
        return 0;

    // If user's choice is scissor and
    // computer's choice is paper
    else if (you == 'z' && computer == 'p')
        return 1;
}
