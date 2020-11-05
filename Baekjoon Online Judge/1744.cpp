#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int A[10000];
long long sum;

int main() {
	int i, j;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &A[i]);

	sort(A, A + N);

	for (i = 0; i < N - 1 && A[i + 1] < 1; i += 2)
		sum += A[i] * A[i + 1];

	for (j = N - 1; j && A[j - 1] > 1; j -= 2)
		sum += A[j] * A[j - 1];

	for (; i <= j; ++i)
		sum += A[i];

	printf("%d", sum);

	return 0;
}
