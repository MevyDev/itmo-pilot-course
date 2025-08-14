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

vector<int> ans;
int n, m;
vector<array<int, 3>> a;

bool works(int x) {
    ans.clear();
    ans.resize(n);
    int res = 0;
    for(int i = 0; i < n; i++) {
        int cycleLength = a[i][0]*a[i][1]+a[i][2];
        int cycleCount = x/cycleLength;
        int remaining = x%cycleLength;
        int fullCycleProd = cycleCount * a[i][1];
        int remainingProd = remaining/a[i][0];
        remainingProd = min(remainingProd, a[i][1]);
        int fullProd = fullCycleProd + remainingProd;
        res += fullProd;
        ans[i] = fullProd - max(0, res - m);
        if(res >= m) return true;
    }
    return res >= m;
}

void solve() {
    cin >> m >> n;
    a.resize(n);
    ans.resize(n);
    for(auto &A : a) {
        cin >> A[0] >> A[1] >> A[2];
    }
    int l = -1;
    int r = INT_MAX/2;
    while(l < r-1) {
        int mid = l+(r-l)/2;
        if(works(mid)) r=mid;
        else l=mid;
    }
    cout << r << '\n';
    works(r);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
