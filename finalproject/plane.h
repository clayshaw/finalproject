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

bool gameOver_Plane;
point plane;
point enemy;
point bullet;
int score_Plane;
double enemy_speed;
short level;

enum Direction_Plane { STOP_PLANE = 0, LEFT_PLANE, RIGHT_PLANE, SHUT };
enum BulletState { NO_BULLET, HAVE_BULLET };
enum Direction_Plane dir_plane;
enum BulletState bull;

void Plane();
void Logic_plane();
void Input_plane();
void Draw_plane();
void Setup_plane();

#endif // !PLANE