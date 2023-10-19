#include "functions.h"
#include <stdio.h>
#include "STD_TYPES.h"
#include "array.h"
#include <stdlib.h>
#include <Windows.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/*
 * Function: TicTacToeGame_VUpdate_Board
 * ----------------------
 * This function updates the board after every move.
 *
 * Parameters:
 *   param1: Player choose x or o.
 *   param2: X axis.
 *   param3: Y axis.
 *
 * Returns:
 *   Description of the return value.
 */
void TicTacToeGame_VUpdate_Board(uint8 choice,uint8 x,uint8 y){
if(x==48&&y==48)
        {
            xx[0][0]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==48&&y==49)
        {
            xx[0][1]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==48&&y==50)
        {
            xx[0][2]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==49&&y==48)
        {
            xx[1][0]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==49&&y==49)
        {
            xx[1][1]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==49&&y==50)
        {
            xx[1][2]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==50&&y==48)
        {
            xx[2][0]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==50&&y==49)
        {
            xx[2][1]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
else if(x==50&&y==50)
        {
            xx[2][2]=choice;
            TicTacToeGame_VBoard_After_Update();
        }
}

/*
 * Function: TicTacToeGame_VBoard_After_Update
 * ----------------------
 * This function draws the updated board after every move.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VBoard_After_Update(){
    printf("\t\t\t\t\t| %c | %c | %c |\n\t\t\t\t\t| %c | %c | %c |\n\t\t\t\t\t| %c | %c | %c |",xx[0][0],xx[0][1],xx[0][2],xx[1][0],xx[1][1],xx[1][2],xx[2][0],xx[2][1],xx[2][2]);

}
