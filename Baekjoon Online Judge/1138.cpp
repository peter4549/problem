#include <cstdio>

int main() {
	int N, L;
	int A[10] = { 0, };
	
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &L);

		for (int j = 0; j < N; ++j) {
			if (!L && !A[j]) {
				A[j] = i + 1;
				break;
			}
			else if (!A[j])
				--L;
		}
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", A[i]);

	return 0;
}
