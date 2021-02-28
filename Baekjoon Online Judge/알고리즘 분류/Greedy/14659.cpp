#include <cstdio>

#define MAX(a, b) (a > b ? a : b)

int A[30001];

int main() {
	int N, max(0);

	scanf("%d", &N);

	for (int i(0); i < N; ++i)
		scanf("%d", &A[i]);

	for (int i(0); i < N - 1; ++i) {
		int k(0);

		for (int j(i + 1); j < N; ++j) {
			if (A[i] >= A[j])
				++k;
			else
				break;
		}

		max = MAX(max, k);
	}

	printf("%d \n", max);
  
  return 0;
}
