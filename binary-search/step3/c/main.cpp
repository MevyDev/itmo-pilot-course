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

int n, k;
vector<int> a;

bool works(int x) {
    int remainingCows = k-1;
    int lastCow = a[0];
    for(int i = 1; i < n; i++) {
        if(lastCow+x <= a[i]) {
            lastCow = a[i];
            remainingCows--;
        }
    }
    return remainingCows <= 0;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for(auto &A : a) {
        cin >> A;
    }
    sort(all(a));
    int l = 0;
    int r = a[n-1];
    while(l+1 < r) {
        int mid = l+(r-l)/2;
        if(works(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    ans(l);
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
