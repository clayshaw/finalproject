#pragma once
#ifndef GOMOKU
#define GOMOKU

#define SIZE 15
#define INIT 0
#define X 1 
#define O 2 

bool isGameOver(int panel[][15], int x, int y, int character);
char Symbol(int n);
void print(int panel[][SIZE], int current[], int turn);
void gomoku();

#endif // !GOMOKU

