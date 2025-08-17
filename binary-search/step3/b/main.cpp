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

int n;
int k;
vector<int> a;

bool works(ll x) {
    int segCount = 0;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > x) {
            return false;
        }
        if(cur + a[i] > x) {
            cur = a[i];
            segCount++;
        }
        else {
            cur += a[i];
        }
    }
    segCount++;
    return segCount <= k;
}

void solve() {
    cin >> n;
    cin >> k;
    a.resize(n);
    for(auto &A : a) {
        cin >> A;
    }

    ll l = 0;
    ll r = 1e15;
    while(l+1 < r) {
        ll mid = l+(r-l)/2;
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
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
