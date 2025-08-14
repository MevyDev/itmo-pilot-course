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

string t, p;
vector<int> a;
unordered_map<char, int> needed;

bool canMakeWord(int x, string curT) {
    for(int i = 0; i < x; i++) {
        curT[a[i]] = ' ';
    }
    int pIdx = 0;
    for(int i = 0; i < t.size(); i++) {
        if(curT[i] == p[pIdx]) {
            pIdx++;
        }
        if(pIdx == p.size()) return true;
    }
    return false;
}

void solve() {
    cin >> t >> p;
    a.resize(t.size());
    for(int i = 0; i < p.size(); i++) {
        needed[p[i]]++;
    }
    for(int i = 0; i < t.size(); i++) {
        cin >> a[i];
        a[i]--;
    }

    int l = -1;
    int r = t.size();
    while(l+1 < r) {
        int mid = l+(r-l)/2;
        if(canMakeWord(mid, t)) {
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
