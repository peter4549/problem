#include <stdio.h>

int N, B, C;
int A[1000000];

int main() {
	int i;
	long long count(0);

	scanf("%d", &N);
	
	for (i = 0; i < N; ++i)
		scanf("%d", &A[i]);

	scanf("%d %d", &B, &C);

	for (i = 0; i < N; ++i) {
		A[i] -= B;
		++count;

		if (A[i] > 0) {
			count += A[i] / C;

			if (A[i] % C)
				++count;
		}
	}

	printf("%lld", count);

	return 0;
}
