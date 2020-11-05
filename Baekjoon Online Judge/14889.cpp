#include <cstdio>
#include <cstring>
#include <algorithm>

#define MIN(a, b) a > b ? b : a

using namespace std;

int N, d(2000);
int S[20][20];
bool start[20];
bool link[20];

void dfs(int n, int level) {
	if (level == N / 2) {
		int a(0), b(0), i, j;
		
		for (i = 0; i < N; ++i) {
			if (start[i]) {
				for (j = i + 1; j < N; ++j) {
					if (start[j])
						a += S[i][j] + S[j][i];
				}
			}
		}

		for (i = 0; i < N; ++i) {
			if (link [i]) {
				for (j = i + 1; j < N; ++j) {
					if (link[j])
						b += S[i][j] + S[j][i];
				}
			}
		}

		for (int k = 0; k < N; ++k) {
			printf("%d ", start[k]);
		}
		puts("");
		for (int k = 0; k < N; ++k) {
			printf("%d ", link[k]);
		}
		puts("");

		d = MIN(d, abs(a - b));

		return;
	}

	for (int i = n; i < N; ++i) {
		start[i] = false;
		link[i] = true;
		dfs(i + 1, level + 1);
		link[i] = false;
		start[i] = true;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &S[i][j]);

	memset(start, true, sizeof(start));

	for (int i = 0; i < N; ++i)
		dfs(i, 0);

	
	printf("%d", d);

	return 0;
}
