#include <cstdio>
#include <deque>

#define APPLE 1

using namespace std;

const int dy[4] = { 1, 0, 0, -1 };
const int dx[4] = { 0, -1, 1, 0 };

typedef struct Position {
	int y, x;
} position;

char C[10001];
int board[101][101], N;

enum Direction {
	Down = 0,
	Left,
	Right,
	Up
};

struct Snake {
	deque<position> body;
	int direction = Right;

	bool move() {
        position head(body.front());
	    int y(head.y + dy[direction]);
		int x(head.x + dx[direction]);

		if (y < 1 || y > N || x < 1 || x > N)
			return false;

		for (auto& it : body)
			if (y == it.y && x == it.x)
				return false;

		position p;
		p.y = y;
		p.x = x;

		body.push_front(p);

		if (board[y][x] != APPLE)
			body.pop_back();
		else
			board[y][x] = 0;

		return true;
	}

	void turn(char direction) {
		if (direction == 'D') {
			switch (this->direction)
			{
			case Down:
				this->direction = Left;
				break;
			case Left:
				this->direction = Up;
				break;
			case Right:
				this->direction = Down;
				break;
			case Up:
				this->direction = Right;
				break;
			default:
				break;
			}
		}
		else if (direction == 'L') {
			switch (this->direction)
			{
			case Down:
				this->direction = Right;
				break;
			case Left:
				this->direction = Down;
				break;
			case Right:
				this->direction = Up;
				break;
			case Up:
				this->direction = Left;
				break;
			default:
				break;
			}
		}
	}
};

int main() {
	int K, L;

	scanf("%d", &N);
	scanf("%d", &K);

	for (int i(0); i < K; ++i) {
		int r, c;
		scanf("%d %d", &r, &c);
		board[r][c] = APPLE;
	}

	scanf("%d", &L);

	for (int i(0); i < L; ++i) {
		char c;
		int x;
		scanf("%d %c", &x, &c);
		C[x] = c;
	}

	Snake snake;
	position p;
	p.y = 1;
	p.x = 1;
	snake.body.push_front(p);

	int t(1);

	while (true) {
		if (!snake.move())
			break;

		if (C[t])
			snake.turn(C[t]);

		++t;
	}

	printf("%d", t);

	return 0;
}
