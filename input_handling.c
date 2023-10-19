#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "functions.h"
#include "STD_TYPES.h"
#include "array.h"
#include <Windows.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

extern uint8 x;
extern uint8 y;
extern uint8 option;
extern uint8 continu;
extern char first_player_name[20];
extern char second_player_name[20];

/*
 * Function: TicTacToeGame_VStart_Fun
 * ----------------------
 * This function shows the available modes to the user to choose between them.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VStart_Fun()
{
    printf("1 - Multi player mode\n\n");
    printf("2 - Single player mode\n");
    printf("\nNote: Anytime you want to quite just enter 'q' or 'Q'\n");
    printf("\nChoose between these  two modes: ");
}

/*
 * Function: TicTacToeGame_VOption_Handling
 * ----------------------
 * This function handles the input cases of "option" variable.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VOption_Handling()
{
    scanf(" %c",&option);
    fflush(stdin);
    while(option!=49&&option!=50&&option!=81&&option!=113)
    {
        printf("\nInvalid input please enter between modes or 'Q' to quite: ");
        scanf(" %c",&option);
        fflush(stdin);
    }
    if(option=='Q'||option=='q')
    {
        //will not enter the modes and while loop will exit the game
    }
    else
    {
        if(option==49)
        {
            system(CLEAR);
            printf("Welcome to Multi player mode\n\n");
            TicTacToeGame_VMultiPlayer_Mode();
        }
        else if(option==50)
        {
            system(CLEAR);
            printf("Welcome to Single player mode\n\n");
            TicTacToeGame_VSinglePlayer_Mode();
        }
    }
}
/*
 * Function: TicTacToeGame_VTaking_X_Axis
 * ----------------------
 * This function takes X axis from user.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VTaking_X_Axis()
{
    printf("\nEnter X axis: ");
    scanf(" %c",&x);
    fflush(stdin);
    while(x!=48&&x!=49&&x!=50&&x!=81&&x!=113)//input must be 0 or 1 or 2 or q or Q
    {
        printf("\nInvalid input please enter positive number between 0 and 2: ");
        scanf(" %c",&x);
        fflush(stdin);
    }
}

/*
 * Function: TicTacToeGame_VTaking_Y_Axis
 * ----------------------
 * This function takes Y axis from user.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VTaking_Y_Axis()
{
    printf("Enter Y axis: ");
    scanf(" %c",&y);
    fflush(stdin);
    while(y!=48&&y!=49&&y!=50&&y!=81&&y!=113)//input must be 0 or 1 or 2 or q or Q
    {
        printf("\nInvalid input please enter positive number between 0 and 2: ");
        scanf(" %c",&y);
        fflush(stdin);
    }
}

/*
 * Function: TicTacToeGame_VTaking_Names
 * ----------------------
 * This function takes names of the players.
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Void
 */
void TicTacToeGame_VTaking_Names()
{
    printf("\nEnter first player name: ");
    scanf("%s",first_player_name);
    printf("\nEnter second player name: ");
    scanf("%s",second_player_name);
    printf("\n");
}

/*
 * Function: TicTocToeGame_VAfter_Finishing
 * ----------------------
 * This function checks after finishing the game if user wants to play again or exit the game.
 *
 * Parameters:
 *   Avoid
 *
 * Returns:
 *   Avoid
 */
void TicTocToeGame_VAfter_Finishing()
{
    printf("\n");
    printf("1 - Play again\n");
    printf("\n2 - Quit\n");
    printf("\nChoose between these options: ");
    scanf(" %c",&continu);
    while(continu!=49&&continu!=50)//input must be 1 or 2
    {
        printf("\nInvalid option please choose between 1 or 2: ");
        scanf(" %c",&continu);
    }
    if(continu==49)
    {
        //blanking all positions to be ready for new round
        for(uint8 i=0; i<3; i++)
        {
            for(uint8 j=0; j<3; j++)
            {
                xx[i][j]=' ';
            }
        }
    }
}
