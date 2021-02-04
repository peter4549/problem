int matrix[n][n];

void rotate() {
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			int k = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = k;
		}
	}
}

int intlen(int n) {
	int m(0);
	
	do {
		n = int(n / 10);
		++m;
	} while (n > 0);

	return m;
}
