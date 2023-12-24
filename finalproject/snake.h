#pragma once

#ifndef SNAKE
#define SNAKE

#define WIDTH 60
#define HEIGHT 30

static int gameOver;
static int score;
static int tailLength;
static int tailX[100], tailY[100];
static int headX, headY;
static int fruitX, fruitY;
static int SPEED = 100;

static enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
static enum Direction dir;

void Setup_snake();
void Draw_snake();
void Input_snake();
void Logic_snake();
void snake();

#endif // !SNAKE


