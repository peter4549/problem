#include<iostream>
#include<string>

using namespace std;

int a[13];

int main() {
	int j(0);
	string s;

	cin >> s;

	for (int i(0); i < s.length(); ++i) {
		if (s[i] == '*') {
			a[j - 1] *= 2;

			if (j > 1)
				a[j - 2] *= 2;

			continue;
		}

		if (s[i] == '#') {
			a[j - 1] = -a[j - 1];
			continue;
		}

		if (isdigit(s[i])) {
			int n = s[i++] - '0';
			
			if (n == 1)
				if (isdigit(s[i])) {
					n = 10;
					++i;
				}

			switch (s[i])
			{
			case 'S':
				break;
			case 'D':
				n *= n;
				break;
			case 'T':
				n *= n * n;
				break;
			default:
				break;
			}

			a[j++] = n;
		}
	}

	int sum(0);

	for (int i(0); i < j; ++i)
		sum += a[i];

	printf("%d", sum);

	return 0;
}
