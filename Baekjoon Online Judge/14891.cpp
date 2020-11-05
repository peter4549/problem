#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

pair<int, int> compareAdjacentPoles(int number);
void rotateAdjacentGears(int number, int clockwise);

int K;
int A[100], B[100];
bool rotated[5];

struct Gear {
	int number;
	int poles[8];

	void rotate(int clockwise) {
		rotated[number] = true;
		pair<int, int> nextGears = compareAdjacentPoles(number);

		if (clockwise == 1) {
			int pole = poles[7];
			memmove(poles + 1, poles, sizeof(int) * 7);
			poles[0] = pole;
		}
		else {
			int pole = poles[0];
			memmove(poles, poles + 1, sizeof(int) * 7);
			poles[7] = pole;
		}

		if (nextGears.first)
			rotateAdjacentGears(nextGears.first, -clockwise);

		if (nextGears.second)
			rotateAdjacentGears(nextGears.second, -clockwise);

		rotated[number] = false;
	}
};

Gear gear1, gear2, gear3, gear4;

pair<int, int> compareAdjacentPoles(int number) {
	int a(0), b(0);

	if (number == 1) {
		if (!rotated[2] && gear1.poles[2] != gear2.poles[6])
			a = 2;
	}
	else if (number == 2) {
		if (!rotated[1] && gear2.poles[6] != gear1.poles[2])
			a = 1;

		if (!rotated[3] && gear2.poles[2] != gear3.poles[6])
			b = 3;
	}
	else if (number == 3) {
		if (!rotated[2] && gear3.poles[6] != gear2.poles[2])
			a = 2;

		if (!rotated[4] && gear3.poles[2] != gear4.poles[6])
			b = 4;
	}
	else if (number == 4)
		if (!rotated[3] && gear4.poles[6] != gear3.poles[2])
			a = 3;

	return make_pair(a, b);
}

void rotateAdjacentGears(int number, int clockwise) {
	if (number == 1)
		gear1.rotate(clockwise);

	if (number == 2)
		gear2.rotate(clockwise);

	if (number == 3) 
		gear3.rotate(clockwise);

	if (number == 4) 
		gear4.rotate(clockwise);
}

int main() {
	int i;

	gear1.number = 1;
	gear2.number = 2;
	gear3.number = 3;
	gear4.number = 4;

	for (i = 0; i < 8; ++i)
		scanf("%1d", &gear1.poles[i]);

	for (i = 0; i < 8; ++i)
		scanf("%1d", &gear2.poles[i]);

	for (i = 0; i < 8; ++i)
		scanf("%1d", &gear3.poles[i]);

	for (i = 0; i < 8; ++i)
		scanf("%1d", &gear4.poles[i]);

	scanf("%d", &K);

	for (i = 0; i < K; ++i)
		scanf("%d %d", &A[i], &B[i]);

	for (i = 0; i < K; ++i) {
		if (A[i] == 1)
			gear1.rotate(B[i]);
		if (A[i] == 2)
			gear2.rotate(B[i]);
		if (A[i] == 3)
			gear3.rotate(B[i]);
		if (A[i] == 4)
			gear4.rotate(B[i]);
	}

	int score(0);

	score += gear1.poles[0];
	score += 2 * gear2.poles[0];
	score += 4 * gear3.poles[0];
	score += 8 * gear4.poles[0];

	printf("%d", score);

	return 0;
}
