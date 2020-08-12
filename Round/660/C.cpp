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

vector<ll> p, h, sub;
vector<vector<ll>> g, clear;
void dfs(ll now, ll par = -1){
    sub[now] = 0;
    for(auto &to : g[now]){
        if(to == par)continue;
        dfs(to, now);
        sub[now] += sub[to];
    }
    sub[now] += p[now];
}

bool ok = true;
vector<ll> x(n_max), y(n_max);
void dfs2(ll now, ll par = -1){
    if((h[now] + sub[now]) & 1)ok = false;
    x[now] = (h[now] + sub[now]) / 2;
    y[now] = (sub[now] - h[now]) / 2;
    if(x[now] < 0 || y[now] < 0)ok = false;
    if(x[now] > sub[now] || y[now] > sub[now])ok = false;
    ll sum = 0;
    for(auto &to : g[now]){
        if(to == par)continue;
        dfs2(to, now);
        sum += x[to];
    }
    if(sum > x[now])ok = false;
}

void YES(bool ok){
    cout << (ok ? "YES" : "NO") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll q; cin >> q;
    while(q--){
        ok = true;
        ll n,m; cin >> n >> m;
        p.resize(n, 0LL);
        for(int i = 0; i < n; i++) cin >> p[i];
        h.resize(n, 0LL);
        for(int i = 0; i < n; i++) cin >> h[i];
        sub.resize(n, 0);
        clear.resize(n);
        g = clear;
        rep(i,0,n-1){
            ll a,b; cin >> a >> b;
            a--;b--;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        debug(g);
        dfs(0);
        debug(sub);
        dfs2(0);
        // debug(x, y);
        YES(ok);

    }
}