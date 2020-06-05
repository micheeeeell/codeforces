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
template <class T>
void print(vector<T> &vec, ll k){
    ll n = vec.size();
    k = min(k, n);
    rep(i,k-1)cout << vec[i] << " ";
    cout << vec[k-1] << endl;
}
template <class T>
void print(vector<vector<T>> &vec, ll k){
    ll n = vec[0].size();
    k = min(k, n);
    for(auto &i : vec)print(i, k);
}
vector<vector<ll>> graph(n_max);
vector<ll> a(n_max),b(n_max),c(n_max);
vector<ll> pre(n_max), nxt(n_max);
vector<ll> sub(n_max);
void pre_dfs(ll now, ll par = -1){
    ll cnt = b[now];
    ll nxt_cnt = c[now];
    ll sc = 1;
    for(auto &to : graph[now]){
        if(to == par)continue;
        pre_dfs(to, now);
        cnt += pre[to];
        nxt_cnt += nxt[to];
        sc += sub[to];
    }
    pre[now] = cnt;
    nxt[now] = nxt_cnt;
    sub[now] = sc;
}
ll ans = 0;
void dfs(ll now, ll par = -1, ll cost = INF, ll up = 0){
    ll cnt = b[now] != c[now];
    chmin(cost, a[now]);
    for(auto &to : graph[now]){
        if(to == par)continue;
        cnt += abs(pre[to] - nxt[to]);
        dfs(to, now, cost, abs(pre[to] - nxt[to]));
    }
    debug(now, cnt, cost);
    cnt -= up;
    if(sub[now] > 1)ans += cost * cnt;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll bc = 0, cc = 0;
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
        bc += b[i];
        cc += c[i];
    }
    rep(i,n-1) {
        ll u,v;cin >> u >> v;
        u--;v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    if(bc != cc){
        cout << -1 << endl;
        return 0;
    }

    pre_dfs(0);
    // print(pre, 10);
    // print(nxt, 10);
    // print(sub, 10);
    dfs(0);
    cout << ans << endl;
}