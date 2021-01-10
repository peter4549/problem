#include <cstdio>

int N, B, C;
int A[1000001];

int main() {
	int count(0);

	scanf("%d", &N);

	for (int i(0); i < N; ++i)
		scanf("%d", A + i);

	scanf("%d %d", &B, &C);

	for (int i(0); i < N; ++i) {
		A[i] -= B;
		++count;

		if (A[i] <= 0)
			continue;

		if (A[i] <= C) {
			++count;
			continue;
		}

		int a = A[i] / C;
		int b = C * a;
		if (A[i] <= b)
			count += a;
		else
			count += a + 1;
	}

	printf("%d", count);

	return 0;
}
