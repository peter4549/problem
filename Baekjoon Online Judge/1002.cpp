#include <cstdio>
#include <cmath>

inline void swap(int &a, int& b) {
	int t(a);
	a = b;
	b = t;
}

int main()
{
	int T, x1, y1, r1, x2, y2, r2;
	long long dx, dy, sum, difference, d;

	scanf("%d", &T);

	for (int t = 0; t < T; ++t) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		dx = x2 - x1;
		dy = y2 - y1;

		sum = pow(r1 + r2, 2);
		difference = pow(r2 - r1, 2);
        d = dx * dx + dy * dy;

		if (r1 > r2)
			swap(r1, r2);
		
		if (d < sum && d > difference)
			printf("2\n");
		else if (d == sum || (d == difference && d > 0))
			printf("1\n");
		else if (d < difference || d > sum)
			printf("0\n");
		else if (d == 0) {
			if (r1 == r2)
				printf("-1\n");
			else 
				printf("0\n");
		}
	}

	return 0;
}
