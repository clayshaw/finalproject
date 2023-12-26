#include"finalproject.h"
#include"2048.h"

enum direction_2048{STOP_2048 = 0,UP_2048,LEFT_2048,DOWN_2048,RIGHT_2048};
enum direction_2048 dir_2048 = STOP_2048;

void setup_2048() {
	i = -1, j = 1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			tmp[i][j] = board[i][j] = 0;
		}
	}
	gameOver_2048 = 0;
	ctr=0;
}


void printBoard() {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) {
				printf("|    ");
			}
			else {
				printf("|%4d", board[i][j]);
			}
		}
		printf("|\n");
	}
	printf("WASD : control direction\n");
}

void addTile() {  //尋找值為0的陣列，並隨機在其中一個填入2或4
	int emptyTiles[SIZE * SIZE][2];
	int count = 0;

	for (int i = 0; i < SIZE; ++i) {  //找值為0的陣列
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == 0) {
				emptyTiles[count][0] = i;
				emptyTiles[count][1] = j;
				count++;
			}
		}
	}

	if (count > 0) {
		int index = rand() % count;
		int value = (rand() % 2 + 1) * 2; // 抽 2 or 4
		int row = emptyTiles[index][0];
		int col = emptyTiles[index][1];
		board[row][col] = value;
	}
}

void shift(int row[]) { // 從陣列最前端往開始，每個格都往前移，直到遇到0以外的數字
	int i, j;

	for (i = 0; i < SIZE - 1; ++i) {
		for (j = 0; j < SIZE - 1; ++j) {
			if (row[j] == 0) {
				row[j] = row[j + 1];
				row[j + 1] = 0;
			}
		}
	}
}

void merge(int row[]) {  // 前端和後端一樣，前端值x2，後端 = 0
	for (int i = 0; i < SIZE - 1; ++i) {
		if (row[i] == row[i + 1] && row[i] != 0) {
			row[i] *= 2;
			row[i + 1] = 0;
		}
	}
}

void moveLeft() {
	for (int i = 0; i < SIZE; ++i) {
		shift(board[i]);
		merge(board[i]);
		shift(board[i]);
	}
}

void moveRight() {
	for (int i = 0; i < SIZE; ++i) {
		int row[SIZE];
		for (int j = 0; j < SIZE; ++j) { // 把陣列倒過來
			row[j] = board[i][SIZE - 1 - j];
		}
		shift(row);
		merge(row);
		shift(row);
		for (int j = 0; j < SIZE; ++j) {
			board[i][SIZE - 1 - j] = row[j];
		}
	}
}

void moveUp() {
	for (int j = 0; j < SIZE; ++j) {
		int col[SIZE];
		for (int i = 0; i < SIZE; ++i) {
			col[i] = board[i][j];
		}
		shift(col);
		merge(col);
		shift(col);
		for (int i = 0; i < SIZE; ++i) {
			board[i][j] = col[i];
		}
	}
}

void moveDown() {
	for (int j = 0; j < SIZE; ++j) {
		int col[SIZE];
		for (int i = 0; i < SIZE; ++i) {
			col[i] = board[SIZE - 1 - i][j];
		}
		shift(col);
		merge(col);
		shift(col);
		for (int i = 0; i < SIZE; ++i) {
			board[SIZE - 1 - i][j] = col[i];
		}
	}
}

int checkGameOver() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == 0) {
				return 0;
			}
			if ((j + 1 < SIZE) && (board[i][j] == board[i][j + 1])) {
				return 0;
			}
			if ((i + 1 < SIZE) && (board[i][j] == board[i + 1][j])) {
				return 0;
			}
		}
	}
	return 1;
}

void Input_2048() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': case 'A':
			dir_2048 = LEFT_2048;
			break;
		case 'd': case 'D':
			dir_2048 = RIGHT_2048;
			break;
		case 'w': case 'W':
			dir_2048 = UP_2048;
			break;
		case 's': case 'S':
			dir_2048 = DOWN_2048;
			break;
		case 'x': case 'X':
			gameOver_2048 = 1;
			break;
		}
	}
}


void Start_2048() {
	system("cls");
	
	setup_2048();
	srand(time(NULL));

	addTile();
	addTile();
	printBoard();

	

	while (!gameOver_2048) {

		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++)
				tmp[i][j] = board[i][j];
		}
		ctr = 0;
		Input_2048();

		switch (dir_2048) {
		case UP_2048:
			moveUp();
			dir_2048 = STOP_2048;
			break;
		case LEFT_2048:
			moveLeft();
			dir_2048 = STOP_2048;
			break;
		case DOWN_2048:
			moveDown();
			dir_2048 = STOP_2048;
			break;
		case RIGHT_2048:
			moveRight();
			dir_2048 = STOP_2048;
			break;
		default:
			continue;
		}

		if (!gameOver_2048) {
			system("cls");

			for (i = 0; i < SIZE; i++) {  // 如果陣列沒變，不加入新數字
				for (j = 0; j < SIZE; j++) {
					if (tmp[i][j] == board[i][j])
						ctr++;
				}

			}
			if (ctr < 16)
				addTile();

			printBoard();
			if (checkGameOver()) {
				printf("\nGame over!\n");
				gameOver_2048 = 1;
			}
		}
	}
	system("pause");
}
