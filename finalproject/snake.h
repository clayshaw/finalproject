#pragma once

#ifndef SNAKE
#define SNAKE

#define WIDTH 60
#define HEIGHT 30

int gameOver;
int score;
int tailLength;
int tailX[100], tailY[100];
int headX, headY;
int fruitX, fruitY;
int SPEED = 100;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

void Setup_snake();
void Draw_snake();
void Input_snake();
void Logic_snake();
void snake();

#endif // !SNAKE


