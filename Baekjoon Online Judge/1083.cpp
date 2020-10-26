#include <cstdio>

int main() {
	int N, S, i, j, max, maxIndex;
	int A[50];

	scanf("%d", &N);

	for (i = 0; i < N; ++i)
		scanf("%d", &A[i]);

	scanf("%d", &S);

	for (i = 0; i < N && S; ++i) {
		int max = A[i];
		int maxIndex = i;

		for (j = i + 1; j < N && j <= i + S; ++j) {
			if (max < A[j]) {
				max = A[j];
				maxIndex = j;
			}
		}

		S -= maxIndex - i;

		while (maxIndex > i) {
			A[maxIndex] = A[maxIndex - 1];
			--maxIndex;
		}

		A[i] = max;
	}

	for (i = 0; i < N; ++i)
		printf("%d ", A[i]);

	return 0;
}
