#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "functions.h"
#include "array.h"
#include "STD_TYPES.h"
#include <Windows.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

uint8 option;
uint8 continu;

int main()
{
    do
    {
        system(CLEAR);
        TicTacToeGame_VStart_Fun();
        TicTacToeGame_VOption_Handling();
        TicTocToeGame_VAfter_Finishing();
    }
    while(continu!=50);
    printf("\nWe hope to see you soon\n");
}
