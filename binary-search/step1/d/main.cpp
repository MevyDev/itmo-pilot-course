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

void solve() {
        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
                cin >> a[i];
        }
        sort(all(a));

        int k; cin >> k;

        for(int i = 0; i < k; i++) {
                int leftBound = -1;
                int rightBound = -1;

                int toFind;
                cin >> toFind;

                int l = -1;
                int r = n;
                while(l+1 < r) {
                        int mid = l + (r-l)/2;
                        if(a[mid] < toFind) {
                                l = mid;
                        }
                        else {
                                r = mid;
                        }
                }
                leftBound = r;

                cin >> toFind;

                l = -1;
                r = n;
                while(l+1 < r) {
                        int mid = l + (r-l)/2;
                        if(a[mid] <= toFind) {
                                l = mid;
                        }
                        else {
                                r = mid;
                        }
                }
                rightBound = l;

                cout << rightBound-leftBound+1 << ' ';
        }
}

int main() {
        // ios::sync_with_stdio(false); cin.tie(nullptr);
        int t = 1;
        while(t--) solve();
}
