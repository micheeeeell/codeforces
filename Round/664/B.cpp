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
constexpr ll n_max = 2e5 + 10;
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
template<typename T>
struct edge{
    int f,t;
    T c;
    int id;
    edge(){};
    edge(int f,int t,T c,int id = 0):f(f),t(t),c(c),id(id){};
    bool operator< (const edge &rhs) const {
        return (*this).c < rhs.c;
    }
    bool operator> (const edge &rhs) const {
        return (*this).c > rhs.c;
    }
    friend string to_string(edge<T> e){
        return "(" + to_string(e.f) + ", " + to_string(e.t) + ", " + to_string(e.c) + ")";
    }

};

template<typename T>
struct graph{
    std::vector<std::vector<edge<T> > > data;
    graph(){};
    graph(int v):data(v){};
    void resize(int n){
        data.resize(n);
    }
    void add_edge(edge<T> &e){
        data[e.f].push_back(e);
    }
    void add_edge(int f,int t,T c){
        data[f].emplace_back(f,t,c);
    }
    size_t size(){
        return data.size();
    }
    vector<edge<T>> &operator[](int n){
        return data[n];
    }
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
    }
};
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m,k; cin >> n >> m >> k;
    graph<ll> g(n);
    rep(i,0,m){
        ll f,t,c; cin >> f >> t >> c;
        f--;t--;
        g.add_edge(f, t, c);
    }
    vector<vector<ll>> table(k);

    vector<vector<bitset<n_max>>> dp(k, vector<bitset<n_max>>(k));
    vector ok(k, vector(k, 0));
    rep(i,0,n){
        ll t = g[i].size() - 1;
        if(t < 0){
            cout << 0 << "\n";
            return 0;
        }
        sort(all(g[i]));
        table[t].emplace_back(i);
        rep(j,0,t + 1){
            auto e = g[i][j];
            dp[t][j][e.t] = 1;
        }
    }

    // debug(dp);
    vector<ll> v(k);
    ll ans = 0;
    bitset<n_max> bs(0), save(0);
    auto dfs = [&](auto self, bitset<n_max> &bs, ll d = 0){
        if(d == k){
            debug(v);
            if(bs.count() == n)ans++;
            return ;
        }
        else{
            rep(i,0,d + 1){
                save = bs;
                v[d] = i;
                bs |= dp[d][i];
                if(bs.count() - save.count() != table[d].size()){
                    bs = save;
                    continue;
                }
                self(self, bs, d + 1);
                bs = save;
            }
        }
    };

    dfs(dfs, bs);
    cout << ans << "\n";
}