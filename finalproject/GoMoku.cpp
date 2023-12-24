
#include"finalproject.h"
#include"GoMoku.h"


bool isGameOver(int panel[][15], int x, int y, int character) {


    for (int i = x - 4, count = 0; i <= x + 4; i++) {
        if (panel[y][i] == character) {
            count++;
            if (count == 5) return true;
        }
        else count = 0;
    }

    for (int i = y - 4, count = 0; i <= y + 4; i++) {
        if (panel[i][x] == character) {
            count++;
            if (count == 5) return true;
        }
        else count = 0;
    }

    for (int i = y - 4, j = x - 4, count = 0; i <= y + 4; i++, j++) {
        if (panel[i][j] == character) {
            count++;
            if (count == 5) return true;
        }
        else count = 0;
    }

    for (int i = y + 4, j = x - 4, count = 0; i >= y - 4; i--, j++) {
        if (panel[i][j] == character) {
            count++;
            if (count == 5) return true;
        }
        else count = 0;
    }

    return false;
}

char Symbol(int n) {
    switch (n)
    {
    case INIT:
        return '.';
        break;
    case X:
        return 'X';
        break;
    case O:
        return 'O';
        break;
    default:
        break;
    }
}

void print(int panel[][SIZE], int current[], int turn) {
    system("cls");

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (i == current[0] && j == current[1]) {
                printf("->.<-");
            }
            else {
                printf("  %c  ", Symbol(panel[i][j]));
            }
        }
        printf("\n\n");
    }
    printf("It is %c turn now\n\n",Symbol(turn));
    printf("WASD:control position\n");
    printf("W:up  A:left  S:down  D:right ENTER:select\n");
}

void gomoku()
{
    int panel[SIZE][SIZE] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };


    int turn = X;
    int current[] = { 0,0 };
    int winner = INIT;


    while (true) {
        print(panel, current, turn);

        if (winner != INIT) {
            break;
        }

        int key = _getch();

        switch (key)
        {
        case 'w':case'W':
            if (current[0] <= 0) current[0] = 14;
            else current[0]--;
            break;
        case 'a':case'A':
            if (current[1] <= 0) current[1] = 14;
            else current[1]--;
            break;
        case 's':case'S':
            if (current[0] >= 14) current[0] = 0;
            else current[0]++;
            break;
        case 'd':case'D':
            if (current[1] >= 14) current[1] = 0;
            else current[1]++;
            break;
        case ' ':case '\r':

            if (panel[current[0]][current[1]] != INIT) {
                printf("Invalid!");
                break;
            }
            else {
                panel[current[0]][current[1]] = turn;
            }
            if (isGameOver(panel, current[1], current[0], turn)) {
                winner = turn;
                break;
            }
            turn = (turn == X ? O : X);
            break;
        case 'x':
            goto label;
        default:
            break;
        }
    }
    label:{
        
    }
    printf("GameOver!\n");
    printf("Winner is %c\n", Symbol(winner));
    system("pause");
    system("cls");
}
