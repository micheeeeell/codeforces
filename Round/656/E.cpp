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


// 有向グラフ上のトポロジカルソート
vector<ll> topo_sort(vvl &graph){
    queue<ll> que;
    vector<ll> ans;
    ll v = graph.size();
    vector<ll> in(v);
    for(auto &vec : graph){
        for(auto &to : vec)in[to]++;
    }
    rep(i,0,v)if(in[i] == 0){
        que.emplace(i);
        ans.emplace_back(i);
    }
    while(!que.empty()) {
        auto f = que.front();que.pop();
        for(auto &to : graph[f]) {
            in[to]--;
            if(!in[to]) {
                ans.emplace_back(to);
                que.emplace(to);
            }
        }
    }

    return ans;
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll q; cin >> q;
    while(q--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> graph(n);
        vector<Pll> v;
        for(int i = 0; i < m; i++) {
            ll t,a,b;cin >> t >> a >> b;
            a--;b--;
            v.emplace_back(a,b);
            if(t == 0){
                continue;
            }
            graph[a].emplace_back(b);
        }

        auto topo = topo_sort(graph);
        vector<ll> memo(n);
        if(topo.size() != n){
            cout << "NO" << "\n";
            continue;
        }
        rep(i,0,n){
            memo[topo[i]] = i;
        }
        debug(topo,memo);
        cout << "YES" << "\n";
        for(auto &p : v){
            if(!(memo[p.first] < memo[p.second]))swap(p.first, p.second);
            cout << p.first+1 << " " << p.second+1 << "\n";
        }
    }
}