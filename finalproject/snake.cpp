
#include"finalproject.h"
#include"snake.h"


void Setup_snake() {
    gameOver = 0;
    score = 0;
    tailLength = 0;
    dir = STOP;
    headX = WIDTH / 2;
    headY = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
}

void Draw_snake() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                putchar('|');
            if (i == headY && j == headX)
                putchar('O');
            else if (i == fruitY && j == fruitX)
                putchar('*');
            else {
                int isTail = 0;
                for (int k = 0; k < tailLength; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        putchar('o');
                        isTail = 1;
                    }
                }

                if (!isTail)
                    putchar(' ');
            }

            if (j == WIDTH - 1)
                putchar('|');
        }
        putchar('\n');
    }

    for (int i = 0; i < WIDTH + 2; i++)
        putchar('-');
    putchar('\n');

    printf("Score: %d\n", score);
    printf("WASD:control direction\n");
    printf("W:up  A:left  S:down  D:right  X:exit\n");
}

void Input_snake() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': case 'A':
            if (dir == RIGHT) break;
            dir = LEFT;
            break;
        case 'd': case 'D':
            if (dir == LEFT) break;
            dir = RIGHT;
            break;
        case 'w': case 'W':
            if (dir == DOWN) break;
            dir = UP;
            break;
        case 's': case 'S':
            if (dir == UP) break;
            dir = DOWN;
            break;
        case 'x': case 'X':
            gameOver = 1;
            break;
        }
    }
}

void Logic_snake() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = headX;
    tailY[0] = headY;

    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    default:
        break;
    }

    if (headX < 0 || headX >= WIDTH || headY < 0 || headY >= HEIGHT)
        gameOver = 1;

    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == headX && tailY[i] == headY)
            gameOver = 1;
    }

    if (headX == fruitX && headY == fruitY) {
        score += 10;
        tailLength++;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
}

void snake() {
    Setup_snake();
    
    while (!gameOver) {
        Draw_snake();
        Input_snake();
        Logic_snake();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(SPEED)); // Add a small delay
    }

    system("pause");
}