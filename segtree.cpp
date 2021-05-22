    #include <bits/stdc++.h>
    using namespace std;
    typedef long long  int ll;
    typedef vector<int> vi;
    typedef pair<int, int> pi;
    #define PRIME 1000000007
    #define SIZE 33
    #define REP(i, a, b) for (int i = a; i < b; ++i)
     
     
struct segtree { 
	int size;
 
	vector<ll> sums;
	void init(int n) {
		size = 1;
		while (size < n) 
			size *= 2;
		sums.assign(2*size, 0LL);
	}
 
	void build(vector<int> &a, int s, int ls, int rs) {
		if (rs - ls == 1) {
			if (ls < (int)a.size())
				sums[s] = a[ls];
			return;
		}
		int mid  = ls + (rs - ls)/2;
 
		build(a, 2*s + 1, ls, mid);
		build(a, 2*s + 2, mid, rs);
 
		sums[s] = sums[2*s + 1] | sums[2*s + 2];
	}
 
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
 
	void set(int i, int v, int s, int ls, int rs) {
		if (rs - ls == 1) {
			sums[s] = v;
			return;
		}
 
		int mid  = ls + (rs - ls)/2;
		if (i < mid)
			set(i, v, 2*s + 1, ls, mid);
		else
			set(i, v, 2*s + 2, mid, rs);
 
		sums[s] = sums[2*s + 1] | sums[2*s + 2];
	}
 
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
 
	ll sum(int l, int r, int s, int ls, int rs) {
		if (r <= ls || l >= rs)
			return 0;
		if (ls >= l && rs <= r)
			return sums[s];
 
		int mid = ls + (rs - ls)/2;
		ll a1 = sum(l, r, 2*s + 1, ls, mid);
		ll a2 = sum(l, r, 2*s + 2, mid, rs);
		return a1 | a2;
	}
 
	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

    int test_case() {
        ll n, v;
        int l, r;
        l = r = 0;
        int mx = 0;
        cin>> n>> v;
        vi a(n);
        segtree st;
        st.init(n);
        REP(i, 0, n)
            cin>> a[i];
        st.build(a);
        while (l < n) {
            while (r < n && st.sum(l, r+1) <= v) 
                r++;
            mx = max(mx, r - l);
            l++;
            if (r < l)
                r = l;
        }
        return mx;
    }   
     
    int main() {
        // ios::sync_with_stdio(0);
        // cin.tie(0);
        freopen("wifi.in", "r", stdin);
        int t = 1;
        cin>> t;
        while (t--){
            // test_case();
            printf("%d\n", test_case());
        }
        return 0;
    }
