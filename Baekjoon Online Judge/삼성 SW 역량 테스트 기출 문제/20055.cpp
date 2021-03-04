#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

int N, K, length;
pair<int, bool> A[201];

void rotate() {
	pair<int, bool> a(A[length - 1]);

	A[N - 1].second = false;
	memmove(A + 1, A, sizeof(pair<int, bool>) * (length - 1));
	A[0] = a;
}

void move() {
	A[N - 1].second = false;

	for (int i(N - 2); i >= 0; --i) {
		if (A[i].second) {
			if (A[i + 1].first > 0 && !A[i + 1].second) {
				--A[i + 1].first;
				A[i + 1].second = true;
				A[i].second = false;
			}
		}
	}
}

void put() {
	if (A[0].first > 0 && !A[0].second) {
		--A[0].first;
		A[0].second = true;
	}
}

bool check() {
	int k(0);

	for (int i(0); i < length; ++i) {
		if (A[i].first == 0)
			++k;
	}
	
	return k >= K;
}

int main() {
	int step(0);

	scanf("%d %d", &N, &K);

	length = 2 * N;

	for (int n(0); n < length; ++n) {
		int i;

		scanf("%d", &i);

		A[n] = { i, false };
	}

	while (!check()) {
		rotate();
		move();
		put();
		++step;
	}

	printf("%d \n", step);

	return 0;
}
