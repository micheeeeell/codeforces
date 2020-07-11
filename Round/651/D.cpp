#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i,s,t) for(ll i = (ll)(s-1);(ll)(t) <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max()/4;
constexpr ll n_max = 2e5+10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char *c) {return to_string((string) c);}
string to_string(bool b) {return (b ? "true" : "false");}
template <size_t N>
string to_string(bitset<N> v){
    string res = "";
    for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if(!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll j = k / 2;
    auto c = [&](ll x){
        // dpは最初をとっても良い, dp2は最初は取らない
        vector<ll> dp(n+1), dp2(n+1);
        if(a[0] <= x)dp[1] = 1;
        rep(i,1,n){
            if(a[i] <= x){
                dp[i+1] = dp[i-1] + 1;
                dp2[i+1] = dp2[i-1] + 1;
            }
            else{
                dp[i+1] = dp[i];
                dp2[i+1] = dp2[i];
            }
        }
        debug(x, dp, dp2);
        if(k % 2 == 0){
            return (dp[n-1] >= j) || (dp2[n] >= j);
        }
        else{
            if(dp2[n-1] >= j)return true;
            if(dp[n] >= j + 1)return true;
            return false;
        }
    };

    ll ok = 1e9;
    ll ng = 0;
    while(abs(ok - ng) > 1){
        ll x = (ok + ng) / 2;
        if(c(x))ok = x;
        else ng = x;
    }

    cout << ok << endl;
}