#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
string to_string(const char c) {return to_string((string) &c);}
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
    
    ll q; cin >> q;
    while(q--){
        long double h,c,t; cin >> h >> c >> t;
        if(t * 2 <= (h + c)){
            cout << 2 << "\n";
            continue;
        }

        auto tem = [&](ll k)->long double{
            return (h * (k + 1) + c * k) / (2 * k + 1);
        };
        ll ans;
        ll ok = 1e9;
        ll ng = -1;
        while(abs(ok - ng) > 1){
            ll x = (ok + ng) / 2;
            if(tem(x) <= t)ok = x;
            else ng = x;
        }
        long double dif = INF;
        debug(ok, ng, abs(t - tem(ng)), abs(t - tem(ok)));
        if(chmin(dif, abs(t - tem(ng)))){
            ans = ng * 2 + 1;
        }
        if(chmin(dif, abs(t - tem(ok)))){
            ans = ok * 2 + 1;
        }
        // if(abs(t - tem(ok)) < abs(t - tem(ng))){
        //     ans = ok * 2 + 1;
        // }
        // else {
        //     ans = ng * 2 + 1;
        // }
        cout << ans << "\n";
    }
}