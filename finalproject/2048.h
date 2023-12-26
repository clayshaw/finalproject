#pragma once
#define SIZE 4

int board[SIZE][SIZE];
int gameOver_2048 = 0;
int tmp[SIZE][SIZE];
int i, j;
int ctr;

void setup_2048();
void printBoard();
void addTile();
void shift(int row[]);
void merge(int row[]);
void moveLeft();
void moveRight();
void moveUp();
void moveDown();
int checkGameOver();
void Input_2048();
void Start_2048();
