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
constexpr ll n_max = 160, k_max = 10;
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
    vector<vector<ll>> memo(n_max, vector<ll>(k_max, -1));
    auto f = [&](ll x){
        ll res = 0;
        while(x){
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    ll t = 0, m = 0;
    ll sum = 0;
    rep(j,0,k_max){
        t = 0;
        m = 0;
        sum = 0;
        rep(i,0,1e7){
            while(t <= j){
                sum += f(m);
                t++;m++;
            }
            // if(!i)debug(i, j, sum,t,m);
            if(sum >= n_max)continue;
            if(memo[sum][j] == -1){
                memo[sum][j] = i;
            }
            t--;
            sum -= f(i);
        }
    }
    // debug(memo);
    ll q; cin >> q;
    while(q--){
        ll n,k; cin >> n >> k;

        if(memo[n][k] != -1){
            cout << memo[n][k] << "\n";
            continue;
        }
        ll t = k * (k + 1) / 2;
        ll ans = 0;
        if((n - t) % (k + 1) == 0){
            ll fu = (n-t)/(k+1);
            ll p = 10;
            ans = 9-k;
            fu -= ans;
            while(fu){
                if(fu >= 9){
                    ans += 9 * p;
                    fu -= 9;
                }
                else{
                    ans += fu * p;
                    fu = 0;
                }
                p *= 10;
            }
            cout << ans <<"\n";
            continue;
        }

        cout << memo[n][k] << "\n";
    }
}