#pragma once
#ifndef PLANE
#define PLANE

typedef struct point
{
	int x;
	int y;
}point;

#define WIDTH_PALEN 20
#define HEIGHT_PLANE 20
#define ENEMY 5

static bool gameOver_Plane;
static point plane;
static point enemy;
static point bullet;
static int score_Plane;
static double enemy_speed;
static short level;

static enum Direction_Plane { STOP_PLANE = 0, LEFT_PLANE, RIGHT_PLANE, SHUT };
static enum BulletState { NO_BULLET, HAVE_BULLET };
static enum Direction_Plane dir_plane;
static enum BulletState bull;

void Plane();
void Logic_plane();
void Input_plane();
void Draw_plane();
void Setup_plane();

#endif // !PLANE