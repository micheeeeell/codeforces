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
const int n_max = 1e5+10;
#define int ll
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    rep(q,t){
        ll n,k; cin >> n >> k;
        // bool ok = true;
        // vector<int> cnt(26);
        string s;cin >> s;
        sort(all(s));
        string ans;
        if(s[0] == s[n-1]){
            ans.assign((n + k -1) / k, s[0]);
        }
        else if(s[0] != s[k-1]){
            ans = s[k-1];
        }
        else{
            if(s[k-1] == s[k])ans = s[0] + s.substr(k);
            else{
                if(s[k] == s[n-1]){
                    ans.assign((n - 1) / k, s[k]);
                    ans += s[0];
                    reverse(all(ans));
                }
                else ans = s[0] + s.substr(k);
            }
        }

        cout << ans << "\n";

    }
}