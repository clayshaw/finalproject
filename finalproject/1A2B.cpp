#include"finalproject.h"
#include"1A2B.h"

void generateRandomNumber(int answer[]) {  // 生成隨機數字

	srand(time(NULL));
	for (int i = 0; i < DIGITS; ++i) {
		answer[i] = rand() % 10;
		for (int j = 0; j < i; j++) { // 確保數字不重複
			if (answer[i] == answer[j]) {
				i--;
			}
		}
	}
}


void checkGuess(int guess[], int answer[], int* A, int* B) {  // 檢查
	*A = *B = 0;

	for (int i = 0; i < DIGITS; i++) {
		if (guess[i] == answer[i]) {
			(*A)++;
		}
		else {
			for (int j = 0; j < DIGITS; j++) {
				if (guess[i] == answer[j])
					(*B)++;
			}
		}
	}
}

void Start_1A2B() {
	system("cls");
	int answer[DIGITS];
	int guess[DIGITS];
	int A=-1, B=-1;
	int ctr = 0;

	generateRandomNumber(answer);

	printf("Welcome to 1A2B game!\n");
	printf("Please guess a %d digit integer\n", DIGITS);

	do {
		printf("Please enter your guess :");
		std::string check;
		std::cin >> check;
		if (check == "X" || check == "x") {
			return ;
		}
		if (check.length() == 4 && (check[0] <= '9' && check[0] >= '0') && (check[1] <= '9' && check[1] >= '0') && (check[2] <= '9' && check[2] >= '0') && (check[3] <= '9' && check[3] >= '0')) {
			guess[0] = check[0] - '0';
			guess[1] = check[1] - '0';
			guess[2] = check[2] - '0';
			guess[3] = check[3] - '0';
			checkGuess(guess, answer, &A, &B); // 檢查猜測結果
			printf("%dA%dB\n", A, B); // 輸出結果
			ctr++;
		}
		else {
			printf("Please enter correct integer\n");
		}

		

	} while (A != DIGITS); // 一直循環直到猜中答案

	printf("Congratulations!Anwser is %d%d%d%d\n", answer[0], answer[1], answer[2], answer[3]);
	printf("You guess %d times。\n", ctr);
	system("pause");
}
