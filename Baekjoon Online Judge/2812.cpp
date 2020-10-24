#include <stdio.h>
#include <queue>

using namespace std;

int N, K;
char number[500000];
deque<char> dq;

int main() {
	int i;

	scanf("%d %d", &N, &K);
	scanf("%s", number);

	for (i = 0; i < N; ++i) {
		while (K && !dq.empty() && dq.back() < number[i]) {
			dq.pop_back();
			K--;
		}

		dq.push_back(number[i]);
	}

	for (i = 0; i < dq.size() - K; ++i)
		printf("%c", dq[i]);

	return 0;
}
