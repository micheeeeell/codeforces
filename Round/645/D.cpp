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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> t = a;
    copy(all(t), back_inserter(a));
    debug(a);
    vector<ll> sum(2*n+1), sum2(2*n+1);
    rep(i,2*n){
        sum[i+1] = sum[i] + a[i];
        sum2[i+1] = sum2[i] + a[i] * (a[i] + 1) / 2;
    }
    debug(sum);
    ll ans = 0;
    auto c = [&](ll &k, ll &x){
        ll res = (k - x + 1 + k) * x / 2;
        x = 0;
        return res;
    };

    auto min_month =[&](ll i, ll x){
        if(a[i] >= x)return i;
        ll ok = i+1;
        ll ng = 0;
        while(abs(ok - ng) > 1){
            ll k = (ok + ng) / 2;
            if(sum[i+1] - sum[k] <= x)ok = k;
            else ng = k;
        }

        return ok-1;
    };
    for(int i = n; i < 2 * n; i++){
        ll temp = x;
        ll t_ans = 0;
        ll id = min_month(i, temp);
        t_ans += sum2[i+1] - sum2[id+1];
        debug(i, id, t_ans);
        temp -= sum[i+1] - sum[id+1];
        t_ans += c(a[id], temp);
        debug(t_ans);
        chmax(ans, t_ans);
    }

    cout << ans << "\n";
}