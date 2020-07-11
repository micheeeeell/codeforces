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
    ll q; cin >> q;
    while(q--){
        ll n; cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(!(i & 1))sum += a[i];
        }
        vector<ll> pre, pos;
        for(int i = 1; i < n; i++){
            if(i & 1)pre.emplace_back(a[i] - a[i-1]);
            else pos.emplace_back(a[i-1]-a[i]);
        }
        debug(pre, pos);
        vector<ll> presum(pre.size()+1), possum(pos.size()+1);
        ll min_ = 0;
        ll ans = 0;
        rep(i,0,pre.size()){
            presum[i+1] = presum[i] + pre[i];
            chmax(ans, presum[i+1] - min_);
            chmin(min_, presum[i+1]);
        }
        debug(ans);
        min_ = 0;
        rep(i,0,pos.size()){
            possum[i+1] = possum[i] + pos[i];
            chmax(ans, possum[i+1] - min_);
            chmin(min_, possum[i+1]);
        }
        debug(ans);
        debug(presum, possum);
        cout << sum + ans << "\n";
    }
}