#include<cstdio>

int a[17];
int b[17];
char map[17][17];

int main() {
	int n;

	scanf("%d", &n);

	for (int i(0); i < n; ++i)
		scanf("%d", a + i);

	for (int i(0); i < n; ++i)
		scanf("%d", b + i);

	for (int i(0); i < n; ++i) {
		int m = a[i] | b[i];
		int j(0);

		while (m > 0) {
			int x = m % 2;
			m /= 2;

			if (x)
				map[i][n - j - 1] = '#';
			else
				map[i][n - j - 1] = ' ';

			++j;
		}
	}

	for (int i(0); i < n; ++i) 
		printf("%s\n", map[i]);
	

	return 0;
}
