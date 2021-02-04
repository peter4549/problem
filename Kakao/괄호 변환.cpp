#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<string, string> split(string w) {
	int i(0), j(0);

	for (int k(0); k <= w.size(); ++k) {
		if (w[k] == '(')
			++i;
		else if (w[k] == ')')
			++j;

		if (i == j) 
			return make_pair(w.substr(0, k + 1), w.substr(k + 1, w.size() - k));
	}
}

bool correct(string u) {
	if (u[0] == ')')
		return false;

	vector<char> v;

	for (int i(0); i < u.size(); ++i) {
		if (u[i] == '(')
			v.push_back(u[i]);
		else if (!v.empty())
			v.pop_back();
	}

	return v.empty();
}

string flip(string u) {
	string v = "";

	for (int i(0); i < u.size(); ++i)
		if (u[i] == '(')
			v.append(")");
		else
			v.append("(");

	return v;
}

string convert(string w) {
	if (w.empty())
		return "";

	pair<string, string> p = split(w);
	string u = p.first;
	string v = p.second;

	if (correct(u))
		return u.append(convert(v));
	else {
		string s = "(";
		s.append(convert(v));
		s.append(")");
		u.erase(0, 1);
		u.erase(u.size() - 1, 1);
		s.append(flip(u));
		return s;
	}
}

int main() {
	string w, s;
    cin >> w;

	while (!correct(s = convert(w)));

	cout << s;

	return 0;
}
