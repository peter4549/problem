#include <cstdio>
#include <cmath>

inline void swap(int &a, int& b) {
	int t(a);
	a = b;
	b = t;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i(0); i < T; ++i) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		if (r1 > r2)
			swap(r1, r2);
		
		double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		if (d > r2) {
			if (r1 + r2 == d)
				printf("1\n");
			else if (r1 + r2 > d)
				printf("2\n");
			else if (r1 + r2 < d)
				printf("0\n");
		}
		else {
			if (x1 == x2 && y1 == y2 && r1 == r2)
				printf("-1\n");
			else if (d + r1 == r2)
				printf("1\n");
			else if (d + r1 > r2)
				printf("2\n");
			else if (d + r1 < r2)
				printf("0\n");
		}
	}

	return 0;
}
