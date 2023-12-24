
#include"finalproject.h"
#include"GoMoku.h"
#include"snake.h"
#include"plane.h"


#define WINDOW_SIZE 20

int data[WINDOW_SIZE][WINDOW_SIZE];
enum CHOICE{SNAKE_C ,GOMOKU_C, PLANE_C ,EXIT_C};
CHOICE choice = SNAKE_C;




int main() {

	int ch = '0';
	bool isbreak = false;
	do {
		if (choice == SNAKE_C && (ch == 's' || ch == 'S')) { choice = GOMOKU_C; ch = '0'; }
		if (choice == GOMOKU_C && (ch == 's' || ch == 'S')) { choice = PLANE_C; ch = '0'; }
		if (choice == PLANE_C && (ch == 's' || ch == 'S')) { choice = EXIT_C; ch = '0'; }
		if (choice == EXIT_C && (ch == 's' || ch == 'S')) {choice = SNAKE_C;ch = '0'; }
		
		if (choice == SNAKE_C && (ch == 'w' || ch == 'W')) {choice = EXIT_C; ch = '0'; }
		if (choice == GOMOKU_C && (ch == 'w' || ch == 'W')) {choice = SNAKE_C; ch = '0'; }
		if (choice == PLANE_C && (ch == 'w' || ch == 'W')) { choice = GOMOKU_C; ch = '0'; }
		if (choice == EXIT_C && (ch == 'w' || ch == 'W')) {choice = PLANE_C; ch = '0'; }
		
		system("cls");
		switch (choice)
		{
		case SNAKE_C:
			printf("==============================================================\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("|                     === Game Menu ===                      |\n");
			printf("|                     ->  Snake Game                         |\n");
			printf("|                         Gomoku Game                        |\n");
			printf("|                         Plane Game                         |\n");
			printf("|                         Exit                               |\n");
			printf("|                 W:UP  S:DOWN  ENTER:SELECT                 |\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("==============================================================\n");
			break;
		case GOMOKU_C:
			printf("==============================================================\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("|                     === Game Menu ===                      |\n");
			printf("|                         Snake Game                         |\n");
			printf("|                     ->  Gomoku Game                        |\n");
			printf("|                         Plane Game                         |\n");
			printf("|                         Exit                               |\n");
			printf("|                 W:UP  S:DOWN  ENTER:SELECT                 |\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("==============================================================\n");
			break;
		case PLANE_C:
			printf("==============================================================\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("|                     === Game Menu ===                      |\n");
			printf("|                         Snake Game                         |\n");
			printf("|                         Gomoku Game                        |\n");
			printf("|                     ->  Plane Game                         |\n");
			printf("|                         Exit                               |\n");
			printf("|                 W:UP  S:DOWN  ENTER:SELECT                 |\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("==============================================================\n");
			break;
		case EXIT_C:
			printf("==============================================================\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("|                     === Game Menu ===                      |\n");
			printf("|                         Snake Game                         |\n");
			printf("|                         Gomoku Game                        |\n");
			printf("|                         Plane Game                         |\n");
			printf("|                     ->  Exit                               |\n");
			printf("|                 W:UP  S:DOWN  ENTER:SELECT                 |\n");
			printf("|                                                            |\n");
			printf("|                                                            |\n");
			printf("==============================================================\n");
			break;
		default:
			break;
		}
		ch = _getch();
		if (ch == '\r') {
			switch (choice)
			{
			case SNAKE_C:
				snake();
				break;
			case GOMOKU_C:
				gomoku();
				break;
			case PLANE_C:
				Plane();
				break;
			case EXIT_C:
				isbreak = true;
				break;
			default:
				break;
			}
		}
		fflush(stdin);

	} while (!isbreak);
    return 0;
	
}

