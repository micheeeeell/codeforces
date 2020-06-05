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
void YES(bool ok){
    cout << (ok ? "YES" : "NO") << "\n";
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll q; cin >> q;
    while(q--){
        ll n,m; cin >> n >> m;
        ll a,b; cin >> a >> b;
        bool ok = false;
        bool t = false;
        if(n% b == 0 && m % a == 0){
            if(n / b == m / a){
                ok = true;
                t = true;
            }
        }
        if((n - b) > 0 && (m - a) > 0 && n % (n - b) == 0 && m % (m - a) == 0){
            if(n / (n - b) == m / (m - a))ok = true;
        }

        YES(ok);
        if(!ok)continue;

        string s[n];
        if(t){
            rep(i,n){
                ll x = (i / b) * a;
                rep(j,m){
                    if(x <= j && j < x + a )s[i] += '1';
                    else s[i] += '0';
                }
            }
        }
        else{
            a = m - a;
            b = n - b;
            debug(a, b);
            rep(i,n){
                ll x = (i / b) * a;
                rep(j,m){
                    if(x <= j && j < x + a)s[i] += '0';
                    else s[i] += '1';
                }
            }
        }

        rep(i,n)cout << s[i] << "\n";
    }
}