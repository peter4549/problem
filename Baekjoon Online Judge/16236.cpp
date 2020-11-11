#include <cstdio>
#include <queue>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

struct BabyShark {
	int y, x, size;
	int size_count = 0;

	void eat() {
		if (++size_count == size) {
			++size;
			size_count = 0;
		}
	}
};

struct Fish {
	int y, x, distance;
};

struct compare {
	bool operator() (Fish& a, Fish& b) {
		if (a.distance == b.distance) {
			if (a.y == b.y)
				return a.x > b.x;
			else
				return a.y > b.y;
		}
		else
			return a.distance > b.distance;
	}
};

int N;
int space[20][20];

int bfs(BabyShark baby_shark) {
	int sum(0);
	queue<BabyShark> baby_sharks;
	baby_sharks.push(baby_shark);

	while (!baby_sharks.empty()) {
		int time[20][20] = { 0, };
		BabyShark baby_shark = baby_sharks.front();
		baby_sharks.pop();

		queue<pair<int, int>> q;
		q.push(make_pair(baby_shark.y, baby_shark.x));

		time[baby_shark.y][baby_shark.x] = 1;

		priority_queue<Fish, vector<Fish>, compare> pq;

		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();

			for (int i(0); i < 4; ++i) {
				int y = p.first + dy[i];
				int x = p.second + dx[i];

				if (x < 0 || x >= N || y < 0 || y >= N || time[y][x] || (space[y][x] > baby_shark.size))
					continue;

				q.push(make_pair(y, x));
				time[y][x] = time[p.first][p.second] + 1;

				if (space[y][x] && (space[y][x] < baby_shark.size)) {
					Fish fish;
					fish.y = y, fish.x = x, fish.distance = time[y][x];
					pq.push(fish);
				}
			}
		}

		if (!pq.empty()) {
			Fish fish = pq.top();
			space[fish.y][fish.x] = 9;
			space[baby_shark.y][baby_shark.x] = 0;
			
			sum += fish.distance - 1;
			baby_shark.y = fish.y, baby_shark.x = fish.x;
			baby_shark.eat();
			baby_sharks.push(baby_shark);
		}
	}

	return sum;
}

int main() {
	int i, j;
	BabyShark baby_shark;
	
	scanf("%d", &N);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			scanf("%d", &space[i][j]);

			if (space[i][j] == 9)
				baby_shark.y = i, baby_shark.x = j, baby_shark.size = 2;
		}
	
	printf("%d", bfs(baby_shark));

	return 0;
}
