#include <cstdio>

int A[1000001];

int main() {	
	int N, B, C;
	scanf("%d", &N);

	for (int i(0); i < N; ++i)
		scanf("%d", A + i);

	scanf("%d %d", &B, &C);

	long long min(N);

	for (int i(0); i < N; ++i) {
		A[i] -= B;

		if (A[i] <= 0)
			continue;

		if (A[i] <= C)
			++min;
		else {
			min += A[i] / C;

			if (A[i] % C != 0)
				++min;
		}
	}

	printf("%lld", min);
	
	return 0;
}
