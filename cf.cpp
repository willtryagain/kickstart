#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const int SIZE = 3e5 + 1;

int p[SIZE];
int rk[SIZE];
int mx[SIZE];
int mn[SIZE];


int get(int a) {
    if (p[a] != a)
        p[a] = get(p[a]);
    return p[a];
}

void _union(int a, int b) {
    int sa = get(a);
    int sb = get(b);
    if (sa == sb)
        return;
    if (rk[sa] > rk[sb])
        swap(sa, sb);
    p[sa] = sb;
    rk[sb] += rk[sa]; 
    mn[sb] = min(mn[sb], mn[sa]);
    mx[sb] = max(mx[sb], mx[sa]);
}

void a() {
    int n, m;
	cin>> n>> m;
	for (int i = 0; i <= n; i++) {
		p[i] = i;
		rk[i] = 1;
        mn[i] = i;
        mx[i] = i;
	}
	for (size_t i = 0; i < m; i++) {
		char type[10];
		int u, v;
        scanf("%s", type);
		if (!strcmp(type, "union")) {
            scanf("%d%d", &u, &v);
			_union(u, v);
        }
		else {
            scanf("%d", &u);
            int root = get(u);
			printf("%d %d %d\n", mn[root], mx[root], rk[root]);
		}
	}
}

int main(int argc, char const *argv[]) {
    int t = 1;
    // cin>> t;
    while (t--) {
        a();
        // cout<<fixed<<setprecision(6)<< f();
        // cout<<"/";
        // cout<<b()<<endl;
        cout<<endl;
    }
    
    
    // d();
    return 0;
}
 

