#include <cstdio>
#include <cstring>

using namespace std;

int A[26];

int main() {
	char S[101];

	scanf("%s", S);

	for (int i(0); i < 26; ++i)
		A[i] = -1;

	for (int i(0); i < strlen(S); ++i) {
		int a(S[i] - 'a');

		if (A[a] == -1)
			A[a] = i;
	}

	for (auto& it : A)
		printf("%d ", it);

	return 0;
}
