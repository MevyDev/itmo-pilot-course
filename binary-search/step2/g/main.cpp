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

void solve() {
    cin >> k >> n;
    a.resize(n);
    for(auto &A : a) {
        cin >> A;
    }
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
