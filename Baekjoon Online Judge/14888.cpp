#include <cstdio>
#include <cstring>
#include <vector>

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

using namespace std;

int N;
long long A[11], temporaryA[11];
int B[10];
bool used[10];
vector<int> v;
long long maximumResult(-1E9), mininumResult(1E9);

int swit = 0;

void dfs(int n, int depth) {
	if (depth == N - 1) {
		int i(1);
		vector<int> temporaryV = v;
		
		memcpy(temporaryA, A, sizeof(A));

		while (!temporaryV.empty()) {
			int b = temporaryV.back();
			temporaryV.pop_back();

			if (b == 1)
				temporaryA[i] = temporaryA[i - 1] + temporaryA[i];
			else if (b == 2)
				temporaryA[i] = temporaryA[i - 1] - temporaryA[i];
			else if (b == 3)
				temporaryA[i] = temporaryA[i - 1] * temporaryA[i];
			else if (b == 4)
				temporaryA[i] = temporaryA[i - 1] / temporaryA[i];

			++i;
		}

		maximumResult = MAX(maximumResult, temporaryA[i - 1]);
		mininumResult = MIN(mininumResult, temporaryA[i - 1]);

		return;
	}
	
	for (int i = 0; i < N - 1; ++i) {
		if (!used[i]) {
			v.push_back(B[i]);
			used[i] = true;
			dfs(i, depth + 1);
			v.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	int addition, subtraction, multiplication, division, i;

	scanf("%d", &N);

	for (i = 0; i < N; ++i)
		scanf("%d", &A[i]);

	scanf("%d %d %d %d", &addition, &subtraction, &multiplication, &division);

	for (i = 0; i < addition; ++i)
		B[i] = 1;
	for (i; i < addition + subtraction; ++i)
		B[i] = 2;
	for (i; i < addition + subtraction + multiplication; ++i)
		B[i] = 3;
	for (i; i < addition + subtraction + multiplication + division; ++i)
		B[i] = 4;

	for (i = 0; i < N - 1; ++i) {
		if (!used[i]) {
			v.push_back(B[i]);
			used[i] = true;
			dfs(i, 1);
			v.pop_back();
			used[i] = false;
		}
	}

	printf("%lld \n%lld", maximumResult, mininumResult);

	return 0;
}
