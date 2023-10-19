#include "functions.h"
#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
#include <Windows.h>
#include "array.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

uint8 x,y;
char first_player_name[20];
char second_player_name[20];


/*
 * Function: TicTacToeGame_VMultiPlayer_Mode
 * ----------------------
 * This function handles multi-player mode(where two players are playing against each other).
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VMultiPlayer_Mode()
{
    printf("\t\t\t\t      Y0      Y1      Y2\n\t\t\t\tX0 | (0,0) | (0,1) | (0,2) |\n\t\t\t\tX1 | (1,0) | (1,1) | (1,2) |\n\t\t\t\tX2 | (2,0) | (2,1) | (2,2) |");
    printf("\n");
    uint8 count=0;//counting moves of two players
    uint8 choice;
    TicTacToeGame_VTaking_Names();
    do
    {

        /*-------------------------------------------------------------------------------------------------------------------------------------------
        Taking position from user
        --------------------------------------------------------------------------------------------------------------------------------------------*/
        uint8 empty_position;
        uint8 flag=0;//to check if user enter q or Q
        do
        {
            if(count%2==0)
            {
                printf("%s's turn:\n",first_player_name);
            }
            else
            {
                printf("%s's turn:\n",second_player_name);
            }
            TicTacToeGame_VTaking_X_Axis();
            //if user input q or Q he will quite
            if(x==113||x==81)
            {
                flag=1;
                break;
            }
            TicTacToeGame_VTaking_Y_Axis();
            //if user input q or Q he will quite
            if(y==113||y==81)
            {
                flag=1;
                break;
            }
            //check if the user choose an empty position
            empty_position = TicTacToeGame_uint8Available_Position(x,y);
            if(empty_position!=1)
            {
                printf("\nNot empty position\n");
            }
        }
        while(empty_position!=1);
        if(flag==1)//user want to quite
        {
            break;
        }

        if(count%2==0)//player one turns
        {
            choice='x';
        }
        else//player two turns
        {
            choice='o';
        }
        if(choice=='Q'||choice=='q')
        {
            break;
        }

        /*-------------------------------------------------------------------------------------------------------------------------------------------
        update the position where the user choose
        --------------------------------------------------------------------------------------------------------------------------------------------*/

        system(CLEAR);
        printf("\t\t\t\t      Y0      Y1      Y2\n\t\t\t\tX0 | (0,0) | (0,1) | (0,2) |\n\t\t\t\tX1 | (1,0) | (1,1) | (1,2) |\n\t\t\t\tX2 | (2,0) | (2,1) | (2,2) |");
        printf("\n\n\n");
        if(x==48)//first row
        {
            if(y==48)
            {
                xx[0][0]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            else if(y==49)
            {
                xx[0][1]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            else if(y==50)
            {
                xx[0][2]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            count++;
            printf("\n");
        }
        else if(x==49)//second row
        {
            if(y==48)
            {
                xx[1][0]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            else if(y==49)
            {
                xx[1][1]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            else if(y==50)
            {
                xx[1][2]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            count++;
            printf("\n");
        }
        else if(x==50)//third row
        {
            if(y==48)
            {
                xx[2][0]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            else if(y==49)
            {
                xx[2][1]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            else if(y==50)
            {
                xx[2][2]=choice;
                TicTacToeGame_VUpdate_Board(choice,x,y);
            }
            count++;
            printf("\n");
        }

        if(count>=5)//no one can win before a player does three moves and the other makes two moves so count can't be less than 5
        {
            uint8 check_win=0;
            check_win=TicTacToeGame_uin8Check_Winner();
            if(check_win)
            {
                break;
            }
        }
        if(count==9)//draw state no one wins
        {
            printf("No one wins!\n");
            break;
        }
    }
    while(choice!='Q'||choice!='q');
}

