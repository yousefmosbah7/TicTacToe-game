#include "functions.h"
#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
#include "array.h"
extern char first_player_name[20];
extern char second_player_name[20];
extern uint8 option,who;


/*
 * Function: TicTacToeGame_uin8Check_Winner
 * ----------------------
 * This function checks if anyone wins after every move
 *
 * Parameters:
 *   Void
 *
 * Returns:
 *   Function returns 1 if there is a winner and 0 if not
 */
uint8 TicTacToeGame_uin8Check_Winner()
{

    /*----------------------------------------------------------------------------
    ------------check player who plays with x status in multiple mode-------------
    -----------------------------------------------------------------------------*/
   if(option==49)
   {
    if((xx[0][0]=='x')&&(xx[0][1]=='x')&&(xx[0][2]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    else if((xx[1][0]=='x')&&(xx[1][1]=='x')&&(xx[1][2]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    else if((xx[2][0]=='x')&&(xx[2][1]=='x')&&(xx[2][2]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    else if((xx[0][0]=='x')&&(xx[1][0]=='x')&&(xx[2][0]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    else if((xx[0][1]=='x')&&(xx[1][1]=='x')&&(xx[2][1]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    else if((xx[0][2]=='x')&&(xx[1][2]=='x')&&(xx[2][2]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    else if((xx[0][0]=='x')&&(xx[1][1]=='x')&&(xx[2][2]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    else if((xx[0][2]=='x')&&(xx[1][1]=='x')&&(xx[2][0]=='x'))
    {
        printf("\n%s is the winner\n",first_player_name);
        return 1;
    }
    /*----------------------------------------------------------------------------
    ------------check player who plays with o status in multiple mode-------------
    -----------------------------------------------------------------------------*/
    else if((xx[0][0]=='o')&&(xx[0][1]=='o')&&(xx[0][2]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else if((xx[1][0]=='o')&&(xx[1][1]=='o')&&(xx[1][2]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else if((xx[2][0]=='o')&&(xx[2][1]=='o')&&(xx[2][2]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else if((xx[0][0]=='o')&&(xx[1][0]=='o')&&(xx[2][0]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else if((xx[0][1]=='o')&&(xx[1][1]=='o')&&(xx[2][1]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else if((xx[0][2]=='o')&&(xx[1][2]=='o')&&(xx[2][2]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else if((xx[0][0]=='o')&&(xx[1][1]=='o')&&(xx[2][2]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else if((xx[0][2]=='o')&&(xx[1][1]=='o')&&(xx[2][0]=='o'))
    {
        printf("\n%s is the winner\n",second_player_name);
        return 1;
    }
    else
    {
        return 0;
    }
  }

else{

    if(who==49){
    /*----------------------------------------------------------------------------
    ---check player who plays with x status in single mode when program starts----
    -----------------------------------------------------------------------------*/
        if((xx[0][0]=='x')&&(xx[0][1]=='x')&&(xx[0][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[1][0]=='x')&&(xx[1][1]=='x')&&(xx[1][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[2][0]=='x')&&(xx[2][1]=='x')&&(xx[2][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][0]=='x')&&(xx[1][0]=='x')&&(xx[2][0]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][1]=='x')&&(xx[1][1]=='x')&&(xx[2][1]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][2]=='x')&&(xx[1][2]=='x')&&(xx[2][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][0]=='x')&&(xx[1][1]=='x')&&(xx[2][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][2]=='x')&&(xx[1][1]=='x')&&(xx[2][0]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
    /*----------------------------------------------------------------------------
    ---check player who plays with o status in single mode when program starts----
    -----------------------------------------------------------------------------*/
        else if((xx[0][0]=='o')&&(xx[0][1]=='o')&&(xx[0][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[1][0]=='o')&&(xx[1][1]=='o')&&(xx[1][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[2][0]=='o')&&(xx[2][1]=='o')&&(xx[2][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][0]=='o')&&(xx[1][0]=='o')&&(xx[2][0]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][1]=='o')&&(xx[1][1]=='o')&&(xx[2][1]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][2]=='o')&&(xx[1][2]=='o')&&(xx[2][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][0]=='o')&&(xx[1][1]=='o')&&(xx[2][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][2]=='o')&&(xx[1][1]=='o')&&(xx[2][0]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else{
    /*----------------------------------------------------------------------------
    ---check player who plays with x status in single mode when user starts----
    -----------------------------------------------------------------------------*/

        if((xx[0][0]=='x')&&(xx[0][1]=='x')&&(xx[0][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[1][0]=='x')&&(xx[1][1]=='x')&&(xx[1][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[2][0]=='x')&&(xx[2][1]=='x')&&(xx[2][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][0]=='x')&&(xx[1][0]=='x')&&(xx[2][0]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][1]=='x')&&(xx[1][1]=='x')&&(xx[2][1]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][2]=='x')&&(xx[1][2]=='x')&&(xx[2][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][0]=='x')&&(xx[1][1]=='x')&&(xx[2][2]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        else if((xx[0][2]=='x')&&(xx[1][1]=='x')&&(xx[2][0]=='x'))
        {
            printf("\nProgram is the winner\n");
            return 1;
        }
        /*----------------------------------------------------------------------------
        -----check player who plays with o status in single mode when user starts-----
        -----------------------------------------------------------------------------*/
        else if((xx[0][0]=='o')&&(xx[0][1]=='o')&&(xx[0][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[1][0]=='o')&&(xx[1][1]=='o')&&(xx[1][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[2][0]=='o')&&(xx[2][1]=='o')&&(xx[2][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][0]=='o')&&(xx[1][0]=='o')&&(xx[2][0]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][1]=='o')&&(xx[1][1]=='o')&&(xx[2][1]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][2]=='o')&&(xx[1][2]=='o')&&(xx[2][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][0]=='o')&&(xx[1][1]=='o')&&(xx[2][2]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else if((xx[0][2]=='o')&&(xx[1][1]=='o')&&(xx[2][0]=='o'))
        {
            printf("\n%s is the winner\n",first_player_name);
            return 1;
        }
        else
        {
            return 0;
        }
    }


}
}
