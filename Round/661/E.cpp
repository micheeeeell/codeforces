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

struct item {
    ll num, cnt;
    item(){};
    item(ll num, ll cnt) : num(num), cnt(cnt){};
    ll cost() const {
        return (num - num / 2) * cnt;
    };
    bool operator>(const item &rhs) const {
        return cost() > rhs.cost();
    }
    bool operator<(const item &rhs) const {
        return cost() < rhs.cost();
    }
    
};
signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    while(t--) {
        ll n,s; cin >> n >> s;
        graph<ll> g(n);
        rep(i, 0, n - 1) {
            ll f,t,c; cin >> f >> t >> c;
            f--;
            t--;
            g.add_edge(f, t, c);
            g.add_edge(t, f, c);
        }

        vector<ll> sub(n);
        priority_queue<item> pq;
        ll sum = 0;
        auto dfs = [&](auto self, ll now, ll pre = -1) -> void {
            bool is_leaf = true;
            for(auto &e : g[now]) {
                if(e.t == pre) continue;
                is_leaf = false;
                self(self, e.t, now);
                sub[now] += sub[e.t];
                pq.emplace(e.c, sub[e.t]);
                sum += sub[e.t] * e.c;
            }

            if(is_leaf) sub[now]++;
        };

        dfs(dfs, 0);
        debug(sub, sum);
        ll ans = 0;
        while(sum > s) {
            auto t = pq.top();
            pq.pop();
            ll num = t.num / 2;
            sum -= (t.num - num) * t.cnt;
            ans++;
            pq.emplace(num, t.cnt);
            debug(sum, t.num, t.cnt, num);
        }

        cout << ans << "\n";
    }
}