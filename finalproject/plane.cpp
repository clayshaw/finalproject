#include"finalproject.h"
#include"plane.h"



void Setup_plane() {
	srand(time(NULL));
	gameOver_Plane = false;
	plane.x = WIDTH_PALEN / 2;
	plane.y = HEIGHT_PLANE - 2;
	bull = NO_BULLET;
	bullet.x = bullet.y = -1;
	score_Plane = 0;
	enemy.y = 0;
	enemy.x = rand() % WIDTH_PALEN;
	enemy_speed = 0.12;
	level = 1;
}
void Draw_plane() {
	system("cls");

	for (int i = 0; i < HEIGHT_PLANE -1; i++) {
		for (int j = 0; j <= WIDTH_PALEN; j++) {
			if (j == WIDTH_PALEN) {
				putchar('$');
			} else if (j == plane.x && i == plane.y) {
				putchar('^');
			} else if (j == bullet.x && i == bullet.y) {
				putchar('|');
			} else if (i == enemy.y && j == enemy.x) {
					putchar('&');
			} else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
	printf("Score : %d\n", score_Plane);
	printf("Current Level : %d\n", level);
	printf("A: Left  S: Right  X: Exit\n");
	printf("Space/Enter: Attack\n");
}


void Input_plane() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': case 'A':
			dir_plane = LEFT_PLANE;
			break;
		case 'd': case 'D':
			dir_plane = RIGHT_PLANE;
			break;
		case ' ':case '\r':
			dir_plane = SHUT;
			break;
		case 'x': case 'X':
			gameOver_Plane = 1;
			break;
		}
	}
}


void Logic_plane() {

	static double the = 0;

	switch (dir_plane)
	{
	case LEFT_PLANE:
		if (plane.x > 0) {
			plane.x--;
		}
		dir_plane = STOP_PLANE;
		break;
	case RIGHT_PLANE:
		if (plane.x < WIDTH_PALEN -1) {
			plane.x++;
		}
		dir_plane = STOP_PLANE;
		break;
	case SHUT:
		if (bull == NO_BULLET) {
			bullet.x = plane.x;
			bullet.y = plane.y - 1;
			bull = HAVE_BULLET;
		}
		dir_plane = STOP_PLANE;
		break;
	default:
		break;
	}
	
	

	if (bull == HAVE_BULLET && bullet.y > 0) {
		bullet.y--;
	}
	else if (bull == HAVE_BULLET) {
		bullet.y = bullet.x = -1;
		bull = NO_BULLET;
	}

	if (enemy.x == bullet.x && enemy.y == bullet.y) {
		enemy.x = rand() % WIDTH_PALEN;
		enemy.y = 0;
		bullet.y = bullet.x = -1;
		bull = NO_BULLET;
		score_Plane += 10;
		if (score_Plane % 50 == 0) {
			enemy_speed += 0.05;
			level++;
		}
	}
	
	
	if ((enemy.x == plane.x && enemy.y == plane.y) || enemy.y >= HEIGHT_PLANE) {
		gameOver_Plane = true;
	} else {
		enemy.y += the;
	}
	if (the >= 1.0) the = 0.0;
	the += enemy_speed;
	
	if (enemy.x == bullet.x && enemy.y == bullet.y) {
		enemy.x = rand() % WIDTH_PALEN;
		enemy.y = 0;
		bullet.y = bullet.x = -1;
		bull = NO_BULLET;
		score_Plane += 10;
		if (score_Plane % 50 == 0) {
			enemy_speed += 0.03;
			level++;
		}
	}
}

void Plane() {
	Setup_plane();

	while (!gameOver_Plane) {
		Draw_plane();
		Input_plane();
		Logic_plane();

		std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Add a small delay
	}

	system("pause");
}



