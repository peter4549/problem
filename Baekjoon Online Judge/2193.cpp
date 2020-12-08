#include <cstdio>

long long A[91];

int main() {
	int N;

	scanf("%d", &N);

	A[1] = 1;
	A[2] = 1;

	for (int i(3); i <= N; ++i)
		A[i] = A[i - 2] + A[i - 1];

	printf("%lld", A[N]);

    return 0;
}
