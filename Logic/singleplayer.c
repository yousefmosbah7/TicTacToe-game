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

uint8 who;
extern char first_player_name[20];

/*
 * Function: TicTacToeGame_VSinglePlayer_Mode
 * ----------------------
 * This function handles single-player mode(where only single player is playing against the program).
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VSinglePlayer_Mode()
{
    printf("\t\t\t\t      Y0      Y1      Y2\n\t\t\t\tX0 | (0,0) | (0,1) | (0,2) |\n\t\t\t\tX1 | (1,0) | (1,1) | (1,2) |\n\t\t\t\tX2 | (2,0) | (2,1) | (2,2) |");
    printf("\n\n\n");
    uint8 count=0;
//-----------------------------------
    int n;
    char you, computer, result;

    printf("\nEnter your name: ");
    scanf("%s",first_player_name);

    printf("\n\nEnter s for STONE, p for PAPER and z for SCISSOR: ");
    scanf(" %c", &you);
    while((you!='s')&&(you!='p')&&(you!='z'))
    {
        printf("\nInvalid input, You must enter s or p or z: ");
        scanf(" %c",&you);
        fflush(stdin);
    }
    srand(time(NULL));
    n = rand() % 100;

    if (n < 33)
        computer = 's';
    else if (n > 33 && n < 66)
        computer = 'p';
    else
        computer = 'z';

    if(computer==you&&you=='p')
    {
        computer='s';
    }
    if(computer==you&&you=='s')
    {
        computer='z';
    }
    if(computer==you&&you=='z')
    {
        computer='p';
    }

    result = TicTacToeGame_uint8Stone_Rock_Scissor(you, computer);

    printf("\n%s chooses : %c and Computer chooses : %c\n",first_player_name,you, computer);

    if (result == 1)
    {
        printf("\nWow! %s have won the game! He will start\n\n",first_player_name);
        who=50;

    }
    else
    {
        printf("\nOh! %s have lost the game! Program will start\n\n",first_player_name);
        who=49;
    }
//-----------------------------------
    if(who!=113&&who!=81)//user does not want to quite
    {
        do
        {
            if(who==49)//program starts first

            {

                if(count%2==0)//program turns when program is the starter
                {
                    if(count==0||count==2)
                    {
                        TicTacToeGame_VFirstTwo_Moves_Prog(count);
                    }
                    else
                    {
                        uint8 ret_val;
                        ret_val=TicTcToeGame_uint8Chance_To_Win();
                        if(!ret_val)
                        {
                            ret_val=TicTacToeGame_uint8Avoid_Loss();
                        }
                        if(!ret_val)
                        {
                            TicTacToeGame_VNormal_Moves();
                        }
                    }
                    count++;
                    printf("\n");
                }
//------------------------------------------------
//------------------------------------------------
                else//user turns when program is the starter
                {
                    uint8 x,y,empty_position;
                    uint8 flag=0;
                    do
                    {
                        printf("\nEnter X axis: ");
                        scanf(" %c",&x);
                        fflush(stdin);
                        while(x!=48&&x!=49&&x!=50&&x!=81&&x!=113)
                        {
                            printf("\nInvalid input please enter positive number between 0 and 2: ");
                            scanf(" %c",&x);
                        }
                        if(x==113||x==81)
                        {
                            flag=1;
                            break;
                        }
                        printf("Enter Y axis: ");
                        scanf(" %c",&y);
                        fflush(stdin);
                        while(y!=48&&y!=49&&y!=50&&y!=81&&y!=113)
                        {
                            printf("\nInvalid input please enter positive number between 0 and 2: ");
                            scanf(" %c",&y);
                            fflush(stdin);
                        }
                        if(y==113||y==81)
                        {
                            flag=1;
                            break;
                        }
                        empty_position = TicTacToeGame_uint8Available_Position(x,y);
                        if(empty_position!=1)
                        {
                            printf("\nNot empty position\n");
                        }
                    }
                    while(empty_position!=1);
                    if(flag==1)
                    {
                        break;
                    }

                    /*-------------------------------------------------------------------------------------------------------------------------------------------
                    starting of the game
                    --------------------------------------------------------------------------------------------------------------------------------------------*/

                    system(CLEAR);
                    printf("\t\t\t\t      Y0      Y1      Y2\n\t\t\t\tX0 | (0,0) | (0,1) | (0,2) |\n\t\t\t\tX1 | (1,0) | (1,1) | (1,2) |\n\t\t\t\tX2 | (2,0) | (2,1) | (2,2) |");
                    printf("\n\n\n");
                    if(x==48)
                    {
                        if(y==48)
                        {
                            xx[0][0]='o';
                        }
                        else if(y==49)
                        {
                            xx[0][1]='o';
                        }
                        else if(y==50)
                        {
                            xx[0][2]='o';
                        }
                        count++;
                        printf("\n");
                    }
                    else if(x==49)
                    {
                        if(y==48)
                        {
                            xx[1][0]='o';
                        }
                        else if(y==49)
                        {
                            xx[1][1]='o';
                        }
                        else if(y==50)
                        {
                            xx[1][2]='o';
                        }
                        count++;
                        printf("\n");
                    }
                    else if(x==50)
                    {
                        if(y==48)
                        {
                            xx[2][0]='o';
                        }
                        else if(y==49)
                        {
                            xx[2][1]='o';
                        }
                        else if(y==50)
                        {
                            xx[2][2]='o';
                        }
                        count++;
                        printf("\n");
                    }
                }
            }
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
            else if(who==50)//user starts first

            {

                if(count%2==0)//user turns when user is the starter
                {
                    uint8 x,y,empty_position;
                    uint8 flag=0;
                    do
                    {
                        printf("\nEnter X axis: ");
                        scanf(" %c",&x);
                        fflush(stdin);
                        while(x!=48&&x!=49&&x!=50&&x!=81&&x!=113)
                        {
                            printf("\nInvalid input please enter positive number between 0 and 2: ");
                            scanf(" %c",&x);
                            fflush(stdin);
                        }
                        if(x==113||x==81)
                        {
                            flag=1;
                            break;
                        }
                        printf("Enter Y axis: ");
                        scanf(" %c",&y);
                        fflush(stdin);
                        while(y!=48&&y!=49&&y!=50&&y!=81&&y!=113)
                        {
                            printf("\nInvalid input please enter positive number between 0 and 2: ");
                            scanf(" %c",&y);
                            fflush(stdin);
                        }
                        if(y==113||y==81)
                        {
                            flag=1;
                            break;
                        }
                        empty_position = TicTacToeGame_uint8Available_Position(x,y);
                        if(empty_position!=1)
                        {
                            printf("\nNot empty position\n");
                        }
                    }
                    while(empty_position!=1);
                    if(flag==1)
                    {
                        break;
                    }

                    /*-------------------------------------------------------------------------------------------------------------------------------------------
                    starting of the game
                    --------------------------------------------------------------------------------------------------------------------------------------------*/

                    system(CLEAR);
                    printf("\t\t\t\t      Y0      Y1      Y2\n\t\t\t\tX0 | (0,0) | (0,1) | (0,2) |\n\t\t\t\tX1 | (1,0) | (1,1) | (1,2) |\n\t\t\t\tX2 | (2,0) | (2,1) | (2,2) |");
                    printf("\n\n\n");
                    if(x==48)
                    {
                        if(y==48)
                        {
                            xx[0][0]='o';
                            TicTacToeGame_VBoard_After_Update('o',48,48);
                            printf("\n\n\n");
                        }
                        else if(y==49)
                        {
                            xx[0][1]='o';
                            TicTacToeGame_VBoard_After_Update('o',48,49);
                            printf("\n\n\n");
                        }
                        else if(y==50)
                        {
                            xx[0][2]='o';
                            TicTacToeGame_VBoard_After_Update('o',48,50);
                            printf("\n\n\n");
                        }
                        count++;
                        printf("\n");
                    }
                    else if(x==49)
                    {
                        if(y==48)
                        {
                            xx[1][0]='o';
                            TicTacToeGame_VUpdate_Board('o',49,48);
                            printf("\n\n\n");
                        }
                        else if(y==49)
                        {
                            xx[1][1]='o';
                            TicTacToeGame_VUpdate_Board('o',49,49);
                            printf("\n\n\n");
                        }
                        else if(y==50)
                        {
                            xx[1][2]='o';
                            TicTacToeGame_VUpdate_Board('o',49,50);
                            printf("\n\n\n");
                        }
                        count++;
                        printf("\n");
                    }
                    else if(x==50)
                    {
                        if(y==48)
                        {
                            xx[2][0]='o';
                            TicTacToeGame_VUpdate_Board('o',50,48);
                            printf("\n\n\n");
                        }
                        else if(y==49)
                        {
                            xx[2][1]='o';
                            TicTacToeGame_VUpdate_Board('o',50,49);
                            printf("\n\n\n");
                        }
                        else if(y==50)
                        {
                            xx[2][2]='o';
                            TicTacToeGame_VUpdate_Board('o',50,50);
                            printf("\n\n\n");
                        }
                        count++;
                        printf("\n");
                    }
                }
                else//program turns when user is the starter
                {
                    if(count==1||count==3)
                    {
                        TicTacToeGame_VFirstTwo_Moves_User(count);
                    }
                    else
                    {
                        uint8 ret_val;
                        ret_val=TicTcToeGame_uint8Chance_To_Win();
                        if(!ret_val)
                        {
                            ret_val=TicTacToeGame_uint8Avoid_Loss();
                        }
                        if(!ret_val)
                        {
                            TicTacToeGame_VNormal_Moves();
                        }
                    }
                    count++;
                    printf("\n");
                }
            }
            if(count>=5)
            {
                uint8 check_win=0;
                check_win=TicTacToeGame_uin8Check_Winner();
                if(check_win)
                {
                    break;
                }
            }
            if(count==9)
            {
                printf("\nNo one wins!\n");
                break;
            }
        }
        while(count!=9);
    }
}
