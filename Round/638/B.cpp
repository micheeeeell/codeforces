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
const int n_max = 110;
#define int ll

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    rep(q,t){
        ll n,k; cin >> n >> k;
        bitset<n_max> bs(0);
        ll fi = 1;
        rep(i,n){
            ll x; cin >> x;
            x--;
            bs[x] = 1;
        }
        if(bs.count() > k){
            cout << -1 << "\n";
            continue;
        }
        vector<ll> ans;
        rep(i,n_max)if(bs[i])ans.emplace_back(i+1);
        while(ans.size() < k)ans.emplace_back(fi);
        cout << k * n << "\n";
        rep(i,n){
            for(auto &i : ans)cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}