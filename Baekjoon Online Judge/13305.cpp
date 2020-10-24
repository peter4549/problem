#include <stdio.h>

int N;
long roads[99999];
long cities[100000];

int main() {
	int i;
	long cost(0), city, length(0);

	scanf("%d", &N);

	for (i = 0; i < N - 1; ++i)
		scanf("%d", &roads[i]);

	for (i = 0; i < N; ++i)
		scanf("%d", &cities[i]);

	if (city > cities[1]) {
		i = 1;
		cost = roads[0] * cities[0];
		city = cities[1];
	}
	else {
		i = 0;
		cities[N - 1] = 0;
		city = cities[0];
	}
	
	while (i < N - 1) {
		length += roads[i];
		if (city > cities[i + 1]) {
			cost += length * city;
			city = cities[i + 1];
			length = 0;
		}

		++i;
	}

	printf("%ld", cost);

	return 0;
}
