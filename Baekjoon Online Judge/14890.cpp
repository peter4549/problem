#include <cstdio>

int N, L;
int map[100][100];

int main() {
	int i, j, count(0);
	scanf("%d %d", &N, &L);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			scanf("%d", &map[i][j]);

	for (i = 0; i < N; ++i) {
		int l(1);
		
		for (j = 0; j < N - 1; ++j) {
			if (map[i][j] - map[i][j + 1] == 1 && l >= 0)
				l = 1 - L;
			else if (map[i][j] == map[i][j + 1])
				++l;
			else if (map[i][j] - map[i][j + 1] == -1 && l >= L)
				l = 1;
			else
				break;
		}

		if (j >= N - 1 && l >= 0)
			++count;
	}

	for (i = 0; i < N; ++i) {
		int l(1);

		for (j = 0; j < N - 1; ++j) {
			if (map[j][i] - map[j + 1][i] == 1 && l >= 0)
				l = 1 - L;
			else if (map[j][i] == map[j + 1][i])
				++l;
			else if (map[j][i] - map[j + 1][i] == -1 && l >= L)
				l = 1;
			else
				break;
		}

		if (j >= N - 1 && l >= 0) {
			++count;
		}
	}
	
	printf("%d", count);

	return 0;
}
