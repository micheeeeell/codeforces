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
void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

vector<vector<ll>> graph;
vector<ll> used;
ll pre_dfs(ll now, ll pre = -1){
    used[now] = 1;
    ll ret = -1;
    for(auto &to : graph[now]){
        if(to == pre)continue;
        if(used[to]) return to;
        chmax(ret, pre_dfs(to, now));
    }

    return ret;
}

vector<ll> path;
bool dfs(ll s, ll now, ll pre = -1){
    debug(now);
    used[now] = 1;
    bool ret = false;
    for(auto &to : graph[now]){
        if(to == pre)continue;
        if(to == s){
            path.emplace_back(now+1);
            return true;
        }
        if(used[to])continue;
        ret |= dfs(s, to, now);
        if(ret)break;
    }
    debug(now, ret);
    if(ret)path.emplace_back(now+1);
    return ret;
}

vector<ll> color;
void c_dfs(ll now, ll c = 0){
    color[now] = c;
    used[now] = 1;
    for(auto &to : graph[now]){
        if(used[to])continue;
        c_dfs(to, c ^ 1);
    }
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m,k; cin >> n >> m >> k;
    graph.resize(n);used.resize(n, 0);
    for(int i = 0; i < m; i++) {
        ll a,b;cin >> a >> b;
        a--;b--;
        if(a >= k || b >= k)continue;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    ll s = -1;
    rep(i,0,k){
        if(!used[i])chmax(s, pre_dfs(i));
    }
    debug(s);
    if(s != -1){
        fill(all(used), 0);
        dfs(s, s);
        debug(path);
        print(2);
        cout << path.size() << "\n";
        print(path);
    }
    else{
        fill(all(used), 0);
        color.resize(k);
        vector<ll> cnt(2);
        rep(i,0,k){
            if(!used[i]) c_dfs(i);
            cnt[color[i]]++;
        }
        ll t;
        if(cnt[0] > cnt[1]) t = 0;
        else t = 1;
        ll c = 0;
        vector<ll> ans;
        rep(i,0,k){
            if(color[i] == t){
                ans.emplace_back(i+1);
                c++;
            }
            if(c == (k + 1) / 2)break;
        }
        print(1);
        // print(ans.size());
        print(ans);
    }

}