#include <cstdio>

#define MIN(a, b) (a < b ? a : b)

long long A, B, min;

void dfs(long long a, long long b, long long n) {
	if (n == B) {
		min = MIN(min, a + b);
		return;
	}

	if (n > B)
		return;

	dfs(a + 1, b, n * 2);
	dfs(a, b + 1, n * 10 + 1);
}

int main() {
	min = 1000000001;
	scanf("%lld %lld", &A, &B);

	dfs(0, 0, A);

	if (min == 1000000001)
		printf("-1");
	else
    	printf("%lld", min + 1);

	return 0;
}
