#include <cstdio>
#include <cstring>
#include <utility>

#define APPLE 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5
#define UP 6

using namespace std;

int N, K, L;
int board[101][101];
int X[10001];

struct Snake {
	int direction, length;
	pair<int, int> head, tail;
	pair<int, int> body[10000];

	bool move() {
		tail = body[length - 1];

		if (direction == DOWN)
			head.first += 1;
		else if (direction == LEFT)
			head.second -= 1;
		else if (direction == RIGHT)
			head.second += 1;
		else if (direction == UP)
			head.first -= 1;

		if (board[head.first][head.second] == 1)
			return false;

		if (board[head.first][head.second] == APPLE)
			++length;
		else
			board[tail.first][tail.second] = 0;

		memmove(body + 1, body, sizeof(pair<int, int>) * (length - 1));
		body[0] = head;

		for (int i = 0; i < length; ++i)
			board[body[i].first][body[i].second] = 1;

		return true;
	}

	void changeDirection(int x) {
		if (x == RIGHT) {
			if (direction == DOWN)
				direction = LEFT;
			else if (direction == LEFT)
				direction = UP;
			else if (direction == RIGHT)
				direction = DOWN;
			else if (direction == UP)
				direction = RIGHT;
		}
		else if (x == LEFT) {
			if (direction == DOWN)
				direction = RIGHT;
			else if (direction == LEFT)
				direction = DOWN;
			else if (direction == RIGHT)
				direction = UP;
			else if (direction == UP)
				direction = LEFT;
		}
	}
};

int main() {
	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 0; i < K; ++i) {
		int y, x;
		scanf("%d %d", &y, &x);
		board[y][x] = APPLE;
	}

	scanf("%d", &L);

	for (int i = 0; i < L; ++i) {
		int x;
		char c;

		scanf("%d %c", &x, &c);
		
		if (c == 'D')
			X[x] = RIGHT;
		else if (c == 'L')
			X[x] = LEFT;
	}

	Snake snake;
	snake.head = make_pair(1, 1);
	snake.direction = RIGHT;
	snake.length = 1;
	snake.body[0] = snake.head;

	board[1][1] = 1;

	int x(0);

	while (true) {
		++x;
		if (!snake.move()) {
			printf("%d", x);
			return 0;
		}

		if (X[x])
			snake.changeDirection(X[x]);

		int hy = snake.head.first;
		int hx = snake.head.second;

		if (hy <= 0 || hy > N || hx <= 0 || hx > N) {
			printf("%d", x);
			return 0;
		}
	}

	return 0;
}
