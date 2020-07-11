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
    ll q; cin >> q;
    auto c = [&](vector<string> &s){
        ll mar = -INF, mir = INF, mac = -INF, mic = INF;
        ll n = s.size();
        rep(i,0,n){
            ll sum = 0, sum2 = 0;
            rep(j,0,n){
                sum += s[i][j] - '0';
                sum2 += s[j][i] - '0';
            }
            chmin(mir, sum);chmax(mar, sum);
            chmin(mic, sum2);chmax(mac, sum2);
        }

        return (mar - mir) * (mar - mir) + (mac - mic) * (mac - mic);
    };
    while(q--){
        ll n,k; cin >> n >> k;
        vector<string> v(n, string(n, '0'));
        rep(i,0,n){
            if(!k)break;
            ll x = 0, y = i;
            rep(j,0,n){
                if(!k)break;
                v[x][y] = '1';
                x++;
                y++;
                x %= n;
                y %= n;
                k--;
            }
        }

        cout << c(v) << "\n";
        rep(i,0,n)cout << v[i] << "\n";
    }

}