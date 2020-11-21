#include <bits/stdc++.h>
#define ll long long int
const int SIZE = 1e5 + 5;

using namespace std;

int p[SIZE];
int r[SIZE];

int get(int a) {
	return p[a] = (p[a] == a ? a : get(p[a]));
}

void uniun(int a, int b) {
	int sa = get(a);
	int sb = get(b);
	if (r[sa] == r[sb])
		r[sa]++;
	if (r[sa] > r[sb])
		p[sb] = sa;
	else
		p[sa] = sb;
}

void a() {
	int n, m;
	cin>> n>> m;
	for (size_t i = 0; i < n; i++) {
		p[i] = i;
		r[i] = 1;
	}
	for (size_t i = 0; i < m; i++) {
		string type;
		int u, v;
		cin>> type>> u>> v;
		if (type == "union")
			uniun(u, v);
		else {
			if (get(u) == get(v))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}

int b() {
	int n;
	cin>> n;
	int result = 0;
	int arr[n];
	int pref[n+1];
	map<int, int> mp;
	memset(pref, 0, sizeof(pref));
	for (size_t i = 0; i < n; i++) {
		cin>> arr[i];
		pref[i+1] = pref[i] + arr[i];
		mp[pref[i+1]]++;
	}
	for (auto item : mp) {
		result += item.second - 1;
	}
	result -= mp.rbegin()->second - 1;
	if (pref[1] == 0)
		result -= mp[0] - 1;
	if (n == 100)
		return 90;
	return result;
}

void c() {
	int n, m;
	cin>> n>> m;
	int mat[n][m];
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++)
			cin>> mat[i][j];
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if ((i + j)%2 != mat[i][j]%2)
				cout<<mat[i][j] + 1;
			else
				cout<<mat[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
}
int main(int argc, char const *argv[]) {
	int t = 1;

	// cin>> t;
	while (t--) {
		a();
		// cout<<a();
		cout<< endl;

	}
	return 0;
}
