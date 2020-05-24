#define LOCAL
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
    ll t; cin >> t;
    while (t--){
        ll h,w; cin >> h >> w;
        vector table(h, vector(w, 0LL));
        rep(i,h)rep(j,w){
            cin >> table[i][j];
            table[i][j] -= i + j;
        }
        vvl dp(h, vl(w, INF));
        dp[0][0] = 0;
        queue<Pll> que;
        que.emplace(0,0);
        vvl used(h,vl(w));
        used[0][0] = 1;
        while(!que.empty()){
            auto [x, y] = que.front();que.pop();
            ll u = INF;
            ll l = INF;
            if(x-1 >= 0){
                if(table[x][y] >= table[x-1][y]){
                    chmin(u, dp[x-1][y] + table[x][y] - table[x-1][y]);
                }
                else{
                    chmin(u, dp[x-1][y] + (table[x-1][y] - table[x][y]) * (x + y));
                }

            }
            if(y-1 >= 0){
                if(table[x][y] >= table[x][y-1]){
                    chmin(l, dp[x][y-1] + table[x][y] - table[x][y-1]);
                }
                else{
                    chmin(l, dp[x][y-1] + (table[x][y-1] - table[x][y]) * (x + y));
                }
            }
            if(x+1 < h && !used[x+1][y])que.emplace(x+1, y);
            if(y+1 < w && !used[x][y+1])que.emplace(x, y+1);

            if(u == l && u == INF)continue;
            if(u >= l){
                dp[x][y] = l;
                table[x][y] = min(table[x][y], table[x][y-1]);
            }
            else{
                dp[x][y] = u;
                table[x][y] = min(table[x][y], table[x-1][y]);
            }
        }
        debug(table);debug(dp);
        cout << dp[h-1][w-1] << "\n";
    }
    
    
}