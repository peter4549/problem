#include <cstdio>
#include <algorithm>

#define MIN(A, B) (A < B ? A : B)

using namespace std;

void print(long long n, int* dice) {
	long long n2(n * n), sum(0);

	if (n == 1) {
		sort(dice, dice + 6);
		
		for (int i(0); i < 5; ++i)
			sum += dice[i];

		printf("%lld", sum);
		return;
	}

	dice[0] = MIN(dice[0], dice[5]);
	dice[1] = MIN(dice[1], dice[4]);
	dice[2] = MIN(dice[2], dice[3]);

	sort(dice, dice + 3);

	sum += dice[0] * (5 * n2 - 8 * n + 4);
	sum += dice[1] * (8 * n - 8);
	sum += dice[2] * 4;

	printf("%lld", sum);
	return;
}

int main() {
	int dice[6];
	long long N;
	scanf("%lld", &N);

	for (int i(0); i < 6; ++i)
		scanf("%d", dice + i);

	print(N, dice);

	return 0;
}
