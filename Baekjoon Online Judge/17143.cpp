#include <cstdio>
#include <queue>

using namespace std;

int R, C, M;
long long sum;

struct Shark {
	int r, c, s, d, z;

	void move() {
		if (d == 1) {
			if (s < r)
				r -= s;
			else if (s < R + r - 1) {
				r = s - r + 2;
				d = 2;
			}
			else
				r += 2 * R - s - 2;
		}
		else if (d == 2) {
			if (s < R - r)
				r += s;
			else if (s < 2 * R - r) {
				r = 2 * R - r - s;
				d = 1;
			}
			else
				r += s - 2 * R + 2;
			
		}
		else if (d == 3) {
			if (s < C - c)
				c += s;
			else if (s < 2 * C - c) {
				c = 2 * C - c - s;
				d = 4;
			}
			else
				c += s - 2 * C + 2;
		}
		else if (d == 4) {
			if (s < c)
				c -= s;
			else if (s < C + c - 1) {
				c = s - c + 2;
				d = 3;
			}
			else
				c += 2 * C - s - 2;
		}
	}
};

struct compare {
	bool operator() (Shark a, Shark b) {
		if (a.r == b.r)
			return a.z < b.z;

		return a.r > b.r;
	}
};

priority_queue<Shark, vector<Shark>, compare> sharks;

void catch_shark(int c) {
	queue<Shark> q;
	
	while (!sharks.empty()) {
		Shark shark = sharks.top();
		sharks.pop();
		
		if (shark.c == c) {
			sum += shark.z;
			break;
		}
		
		q.push(shark);
	}

	while (!q.empty()) {
		Shark shark = q.front();
		q.pop();
		sharks.push(shark);
	}
}

void move_shark() {
	int A[101][101] = { 0, };
	queue<Shark> q;

	while(!sharks.empty()) {
		Shark shark = sharks.top();
		sharks.pop();

		shark.move();
		
		if (A[shark.r][shark.c] < shark.z) {
			q.push(shark);
			A[shark.r][shark.c] = shark.z;
		}
	}
	
	while (!q.empty()) {
		Shark shark = q.front();

		q.pop();
		if (A[shark.r][shark.c] == shark.z)
		    sharks.push(shark);
	}
}

int main() {
	int r, c, s, d, z, i;

	scanf("%d %d %d", &R, &C, &M);

	for (i = 0; i < M; ++i) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		
		if (d == 1 || d == 2)
			s %= ((R - 1) * 2);
		else
			s %= ((C - 1) * 2);

		Shark shark;
		shark.r = r, shark.c = c, shark.s = s, shark.d = d, shark.z = z;
		sharks.push(shark);
	}

	for (c = 1; c <= C; ++c) {
		catch_shark(c);
		move_shark();
	}

	printf("%lld", sum);

	return 0;
}
