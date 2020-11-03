#include <cstdio>

#define MAX(a, b) a > b ? a : b

using namespace std;

int N, price, maxPrice;
int T[15], P[15];
bool inConsultation[20];

void startConsultation(int day) {
	for (int i = day; i < day + T[day]; ++i)
		inConsultation[i] = true;
}

void endConsultation(int day) {
	for (int i = day; i < day + T[day]; ++i)
		inConsultation[i] = false;
}

void backtrack(int day) {
	if (day == N)
		return;

	for (int i = day; i < N; ++i) {
		if (!inConsultation[i] && i + T[i] - 1 < N) {
			startConsultation(i);
			price += P[i];
			maxPrice = MAX(maxPrice, price);
			backtrack(i + T[i]);
			price -= P[i];
			endConsultation(i);
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d %d", &T[i], &P[i]);

	backtrack(0);

	printf("%d", maxPrice);

	return 0;
}
