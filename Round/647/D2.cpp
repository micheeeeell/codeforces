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
        cout << a+1;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

// 有向グラフ上のトポロジカルソート
vector<ll> topo_sort(vvl &graph){
    queue<ll> que;
    vector<ll> ans;
    ll v = graph.size();
    vector<ll> in(v);
    for(auto &vec : graph){
        for(auto &to : vec)in[to]++;
    }
    rep(i,v)if(in[i] == 0){
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


template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

signed main(){

    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n);
    rep(i,m) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<ll> t(n);
    rep(i,n) {
        cin >> t[i];
        t[i]--;
    }
    vvl graph2(n);
    bool ok = true;
    // bitset<n_max> bs(0);
    rep(i,n){
        ll cnt = 0;
        bool bs[t[i]+1];
        fill(bs, bs + t[i] + 1, false);
        for(auto &to : graph[i]){
            if(t[i] == t[to]){
                cout << -1 << "\n";
                return 0;
            }
            if(t[i] > t[to]){
                if(bs[t[to]] == 0){
                    cnt++;
                    bs[t[to]] = 1;
                }
                graph2[to].emplace_back(i);
            }
        }
        if(cnt != t[i]){
            cout << -1 << endl;
            return 0;
        }
    }
 
    auto topo = topo_sort(graph2);
    if(topo.size() != n){
        cout << -1 << "\n";
        return 0;
    }
    print(topo);
}