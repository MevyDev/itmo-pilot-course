#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << #x << R"(: )" << x << endl;
#define ans(s) {cout << s << endl; return;}
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

int n, x, y;

bool works(int k) {
    if(k/x + (k-x)/y >= n) return true;
    return false;
}

void solve() {
    cin >> n >> x >> y;
    if(x > y) swap(x, y);
    int l = -1;
    int r = x*n;
    while(l<r-1) {
        int mid = l+(r-l)/2;
        if(works(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    ans(r);
}

int main() {
    solve();
}
