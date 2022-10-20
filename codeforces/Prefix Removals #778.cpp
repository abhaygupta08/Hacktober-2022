#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	string s;
	cin >> s;
	vector<int> last(26, (int)s.length());
	for (int i = 0; i < (int)s.length(); ++i) {
		int c = s[i] - 'a';
		last[c] = i;
	}
	s = s.substr(*min_element(all(last)));
	cout << s << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}
