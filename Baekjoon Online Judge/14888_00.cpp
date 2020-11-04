#include <cstdio>

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

using namespace std;

int N;
int A[11];
int operators[4];
long long maximumResult(-1E9), mininumResult(1E9);

void dfs(int result, int depth) {
	if (depth == N - 1) {
		maximumResult = MAX(maximumResult, result);
		mininumResult = MIN(mininumResult, result);

		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (operators[i] != 0) {
			--operators[i];

			if (i == 0) {
				dfs(result + A[depth + 1], depth + 1);
			}
			else if (i == 1) {
				dfs(result - A[depth + 1], depth + 1);
			}
			else if (i == 2) {
				dfs(result * A[depth + 1], depth + 1);
			}
			else if (i == 3) {
				dfs(result / A[depth + 1], depth + 1);
			}

			++operators[i];
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &A[i]);

	for (int i = 0; i < 4; ++i)
		scanf("%d", &operators[i]);

	dfs(A[0], 0);

	printf("%lld \n%lld", maximumResult, mininumResult);

	return 0;
}
