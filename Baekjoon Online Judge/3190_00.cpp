#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

const int APPLE = 2;

const int LEFT = 0;
const int DOWN = 1;
const int RIGHT = 2;
const int UP = 3;

int N, K, L;
int board[101][101];

struct Snake {
	pair<int, int> head;
	pair<int, int> tail;
	pair<int, int> body[10000];
	int d = RIGHT, length = 1;

	bool move() {
		switch (d)
		{
		case LEFT:
			--head.second;
			break;
		case RIGHT:
			++head.second;
			break;
		case DOWN:
			++head.first;
			break;
		case UP:
			--head.first;
			break;
		default:
			return false;
			break;
		}

		if (0 >= head.first || head.first > N)
			return false;
		if (0 >= head.second || head.second > N)
			return false;

		if (board[head.first][head.second] == 1)
			return false;
		if (board[head.first][head.second] == APPLE)
			++length;
		else
			board[tail.first][tail.second] = 0;

		memmove(body + 1, body, sizeof(pair<int, int>) * (length - 1));
		body[0] = head;
		tail = body[length - 1];

		for (int i(0); i < length; ++i)
			board[body[i].first][body[i].second] = 1;

		return true;
	}

	void turn(int d) {
		if (d == LEFT)
			this->d = (this->d + 1) % 4;
		else if (d == RIGHT) 
			this->d = (this->d + 3) % 4;
	}
};

int main() {
	scanf("%d", &N);
	scanf("%d", &K);

	for (int i(0); i < K; ++i) {
		int y, x;
		scanf("%d %d", &y, &x);
		board[y][x] = APPLE;
	}

	int XC[10001];
	for (int i(1); i < 10001; ++i)
		XC[i] = -1;

	scanf("%d", &L);

	for (int i(0); i < L; ++i) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		if (c == 'L')
			XC[x] = LEFT;
		else
			XC[x] = RIGHT;
	}

	Snake snake;
	snake.head.first = 1;
	snake.head.second = 1;
	snake.tail.first = 1;
	snake.tail.second = 1;
	snake.body[0] = snake.head;
	board[1][1] = 1;
	
	for (int i(1); i < 10001; ++i) {
		if (!snake.move()) {
			printf("%d", i);
			return 0;
		}

		snake.turn(XC[i]);
	}

	return 0;
}
