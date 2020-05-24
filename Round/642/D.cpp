// #define LOCAL
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

struct state{
    state(ll l, ll r): l(l), r(r){}
    ll l; ll r;
    const bool operator>(const state &rhs) const {
        return (r - l) < (rhs.r - rhs.l) || ((r - l) == (rhs.r - rhs.l) && l > rhs.l);
    }
    const bool operator<(const state &rhs) const {
        return (r - l) > (rhs.r - rhs.l) || ((r - l) == (rhs.r - rhs.l) && l < rhs.l);
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> ans(n);
        priority_queue<state, vector<state>, greater<>> que;
        que.emplace(0,n);
        ll i = 1;
        while(!que.empty()){
            auto p = que.top();que.pop();
            ll l = p.l, r = p.r;
            ll id = l + (r - l - 1) / 2;
            ans[id] = i++;
            if(id != l)que.emplace(l,id);
            if(id+1 != r)que.emplace(id+1, r);
        }

        for(auto &i : ans)cout << i << " ";
        cout << "\n";
    }
}