#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 2e5+10;
// #define int ll

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    bitset<n_max> bs(0);
    rep(_, t){
        int cnt = 0;
        int n; cin >> n;
        int temp, temp2;
        rep(j,n){
            cin >> temp;
            temp %= n;
            if(temp < 0)temp += n;
            temp2 = (temp + j) % n;
            if(bs[temp2] == 0){
                cnt++;
                bs[temp2] = 1;
            }
        }
        bs = 0;
        cout << (cnt == n ? "YES" : "NO") << endl;
    }
}