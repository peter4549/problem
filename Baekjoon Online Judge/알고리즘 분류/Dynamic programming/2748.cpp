#include <cstdio>

long long F[91];

long long fibonacci_number(int n) {
	if (n <= 2)
		return 1;

	if (F[n])
		return F[n];

	return F[n] = fibonacci_number(n - 1) + fibonacci_number(n - 2);
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%lld", fibonacci_number(n));

	return 0;
}
