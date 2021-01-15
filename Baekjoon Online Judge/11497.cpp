#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

bool compare(int i, int j) {
	return j < i;
}

int logs[10001];

int main() {
	int T, N, difficulty;

	scanf("%d", &T);

	for (int t(0); t < T; ++t) {
		scanf("%d", &N);

		for (int n(0); n < N; ++n)
			scanf("%d", &logs[n]);

		sort(logs, logs + N, compare);

		difficulty = MAX(logs[0] - logs[1], logs[N - 2] - logs[N - 1]);

		for (int i(0); i < N - 2; ++i)
			difficulty = MAX(difficulty, logs[i] - logs[i + 2]);

		printf("%d \n", difficulty);
	}

	return 0;
}
