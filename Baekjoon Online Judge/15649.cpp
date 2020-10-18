#include <stdio.h>

int N, M;
int naturalNumbers[8];
bool isUsed[8];

void printSequences(int k) {
	int i;

	if (k == M) {
		for (i = 0; i < M; ++i)
			printf("%d ", naturalNumbers[i]);
		
		puts("");
		return;
	}

	for (i = 1; i <= N; ++i) {
		if (!isUsed[i]) {
			naturalNumbers[k] = i;
			isUsed[i] = true;
			printSequences(k + 1);
			isUsed[i] = false;
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);
	printSequences(0);

	return 0;
}
