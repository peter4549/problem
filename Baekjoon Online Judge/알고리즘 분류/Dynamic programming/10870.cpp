#include <cstdio>

int F[21];

int fibonacci(int n) {
	if (n <= 1)
		return n;

	if (n <= 3)
		return n - 1;

	if (F[n] != 0)
		return F[n];

	return F[n] = fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
	int n;

	scanf("%d", &n);

	printf("%d \n", fibonacci(n));

	return 0;
}
