#include <cstdio>
#include <queue>

using namespace std;

int N;
bool cup_holders[101];
queue<int> seats;

int main() {
	bool couple(false);
	char seat;
	int k(1);

	scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		scanf("%1c", &seat);

		if (couple) {
			couple = false;
			continue;
		}

		if (seat == 'S') {
			seats.push(k);
			cup_holders[k - 1] = true;
			cup_holders[k + 1] = true;
			k += 2;
		}
		else if (seat == 'L') {
			seats.push(k);
			seats.push(k + 1);
			cup_holders[k - 1] = true;
			cup_holders[k + 2] = true;
			k += 3;
			couple = true;
		}
	}

	while (!seats.empty()) {
		int seat = seats.front();
		seats.pop();

		if (cup_holders[seat - 1]) {
			cup_holders[seat - 1] = false;
			continue;
		}

		if (cup_holders[seat + 1]) {
			cup_holders[seat + 1] = false;
			continue;
		}

		--N;
	}

	printf("%d", N);
		
	return 0;
}
