#include <cstdio>

char seats[51];
int N;

int main() {
	scanf("%d\n%s", &N, seats);
	int couple(0);

	for (int i(0); i < N; ++i)
		if (seats[i] == 'L')
			++couple;

	if (couple == 0)
		printf("%d", N);
	else
		printf("%d", N - (couple >> 1) + 1);

	return 0;
}
