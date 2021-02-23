#include <cstdio>

#define MIN(a, b) (a < b ? a : b)

using namespace std;

int main() {

	int D[1000001] = { 0, }, N;

	scanf("%d", &N);

	D[1] = 0;
	for (int i(2); i <= N; i++) {
		D[i] = D[i - 1] + 1;
		
		if (i % 2 == 0) 
			D[i] = MIN(D[i], D[i / 2] + 1);

		if (i % 3 == 0) 
			D[i] = MIN(D[i], D[i / 3] + 1);
	}

	printf("%d \n", D[N]);

	return 0;
}
