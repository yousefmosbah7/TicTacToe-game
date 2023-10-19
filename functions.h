#include "STD_TYPES.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void TicTacToeGame_VMultiPlayer_Mode();

void TicTacToeGame_VSinglePlayer_Mode();

void TicTacToeGame_VUpdate_Board(uint8 choice,uint8 x,uint8 y);

void TicTacToeGame_VStart_Fun();

uint8 TicTacToeGame_uin8Check_Winner();

uint8 TicTacToeGame_uint8Available_Position(uint8 x,uint8 y);

void TicTacToeGame_VFirstTwo_Moves_Prog(uint8 count);

void TicTacToeGame_VFirstTwo_Moves_User(uint8 count);

uint8 TicTacToeGame_uint8Avoid_Loss();

uint8 TicTcToeGame_uint8Chance_To_Win();

void TicTacToeGame_VNormal_Moves();

void TicTacToeGame_VBoard_After_Update();

void TicTocToeGame_VAfter_Finishing();

void TicTacToeGame_VOption_Handling();

void TicTacToeGame_VTaking_Names();

void TicTacToeGame_VTaking_X_Axis();

void TicTacToeGame_VTaking_Y_Axis();

uint8 TicTacToeGame_uint8Stone_Rock_Scissor(char you, char computer);

#endif
