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
    
    ll n,d,m; cin >> n >> d >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> up, down;
    rep(i,0,n){
        if(a[i] > m)up.emplace_back(a[i]);
        else down.emplace_back(a[i]);
    }
    sort(all(up), greater<ll>());
    sort(all(down),greater<ll>());
    vector<ll> up_sum(up.size() + 1), down_sum(down.size() + 1);
    rep(i,0,up.size()){
        up_sum[i + 1] = up[i] + up_sum[i];
    }
    rep(i,0,down.size()){
        down_sum[i + 1] = down[i] + down_sum[i];
    }
    ll temp;
    auto c = [&](ll y){
        if(y > down.size())return false;
        ll t = (n - y + d) / (d + 1);
        if(t > up.size())return false;
        temp = down_sum[y] + up_sum[t];
        return true;
    };
    ll ans = 0;
    ll t = (n + d) / (d + 1);
    if(t <= up.size()){
        ans = up_sum[t];
    }
    rep(i,1,n + 1){
        if(c(i))chmax(ans, temp);
    }

    if(up.size() == 0){
        ans = 0;
        rep(i,0,n)ans += a[i];
    }

    cout << ans << "\n";
}