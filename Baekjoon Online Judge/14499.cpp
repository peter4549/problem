#include <cstdio>
#include <utility>

using namespace std;

int N, M, x, y, K;
int map[20][20];

enum Directions {
	East = 1,
	West,
	North,
	South
};

enum Side {
	Top = 0,
	Back,
	Right,
	Left,
	Front,
	Bottom
};

struct Dice {
	int y, x;
	int numbers[6] = { 0, };

	bool rotate(int command) {
		int number;

		switch (command)
		{
		case East:
			if (x + 1 >= M)
				return false;
			++x;

			number = numbers[Top];
			numbers[Top] = numbers[Left];
			numbers[Left] = numbers[Bottom];
			numbers[Bottom] = numbers[Right];
			numbers[Right] = number;
			break;
		case West:
			if (x - 1 < 0)
				return false;
			--x;

			number = numbers[Top];
			numbers[Top] = numbers[Right];
			numbers[Right] = numbers[Bottom];
			numbers[Bottom] = numbers[Left];
			numbers[Left] = number;
			break;
		case North:
			if (y - 1 < 0)
				return false;
			--y;

			number = numbers[Top];
			numbers[Top] = numbers[Front];
			numbers[Front] = numbers[Bottom];
			numbers[Bottom] = numbers[Back];
			numbers[Back] = number;
			break;
		case South:
			if (y + 1 >= N)
				return false;
			++y;

			number = numbers[Top];
			numbers[Top] = numbers[Back];
			numbers[Back] = numbers[Bottom];
			numbers[Bottom] = numbers[Front];
			numbers[Front] = number;
			break;
		default:
			break;
		}

		return true;
	}
};

int main() {
	Dice dice;
	
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i(0); i < N; ++i)
		for (int j(0); j < M; ++j)
			scanf("%d", &map[i][j]);

	dice.y = y;
	dice.x = x;

	for (int i(0); i < K; ++i) {
		int command;
		scanf("%d", &command);
		
		if (dice.rotate(command)) {
			if (map[dice.y][dice.x]) {
				dice.numbers[Bottom] = map[dice.y][dice.x];
				map[dice.y][dice.x] = 0;
			}
			else 
				map[dice.y][dice.x] = dice.numbers[Bottom];

			printf("%d \n", dice.numbers[Top]);
		}
	}

	return 0;
}
