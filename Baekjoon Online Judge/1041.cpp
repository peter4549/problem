#define MIN(A, B) (A < B ? A : B)
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long long N, sum(0);
	int dice[6];
	
	scanf("%d", &N);
	scanf("%d %d %d %d %d %d", dice, &dice[1], &dice[2], &dice[3], &dice[4], &dice[5]);

	if (N == 1) {
		sort(dice, dice + 6);

		for (int i = 0; i < 5; ++i)
			sum += dice[i];

		printf("%d", sum);

		return 0;
	}

	dice[0] = MIN(dice[0], dice[5]);
	dice[1] = MIN(dice[1], dice[4]);
	dice[2] = MIN(dice[2], dice[3]);

	sort(dice, dice + 3);

	long long n1 = (5 * N * N - 8 * N + 4) * dice[0];
	long long n2 = (8 * N - 8) * dice[1];
	long long n3 = 4 * dice[2];

	sum = n1 + n2 + n3;

	printf("%lld", sum);

	return 0;
}
