#include <cstdio>

int main() {
	int N, milk, previous_milk, count(0);
	bool ate_strawberry_milk(false);

	scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		scanf("%d", &milk);

		if (!ate_strawberry_milk) {
			if (milk == 0) {
				ate_strawberry_milk = true;
				previous_milk = milk;
				++count;
			}

			continue;
		}

		if (previous_milk == 0 && milk == 1 ||
			previous_milk == 1 && milk == 2 ||
			previous_milk == 2 && milk == 0)
			++count, previous_milk = milk;
	}

	printf("%d", count);

	return 0;
}
