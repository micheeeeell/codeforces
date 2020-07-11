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
vector<ll> path;
vector<ll> used2;
void dfs(ll now, ll pre = -1){
    used2[now] = 1;
    for(auto &to : graph[now]){
        if(to == pre)continue;
        if(used2[to]){
            path.emplace_back(to);
            return ;
        }
        dfs(to, now);
    }
    path.emplace_back(now);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m,k; cin >> n >> m >> k;
    graph.resize(n);
    rep(i,0,m){
        ll f,t; cin >> f >> t;
        f--;t--;
        graph[f].emplace_back(t);
        graph[t].emplace_back(f);
    }
    vector<ll> used(n, -2);
    queue<ll> que;
    que.emplace(0);
    used[0] = 0;
    bool is_close = false;
    int node = -1;
    while(!que.empty()){
        ll now = que.front();que.pop();
        for(auto &to : graph[now]) {
            if(used[to] == used[now] - 1)
                continue;
            if(used[to] > 0){
                node = to;
                is_close = true;
                continue;
            }
            que.emplace(to);
            used[to] = used[now] + 1;
        }
    }

    used2.resize(n, 0);
}