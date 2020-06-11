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
    cout << (ok ? "Yes" : "No") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll q; cin >> q;
    while(q--){
        ll h,w; cin >> h >> w;
        ll dx[] = {0,0,1,-1};
        ll dy[] = {1,-1,0,0};
        string s[h];
        auto is_out = [&](ll x, ll y){
           if(x < 0 || x >= h || y < 0 || y >= w)return true;
           if(s[x][y] == '#')return true;
           return false;
        };

        rep(i,0,h)cin >> s[i];
        rep(i,0,h)rep(j,0,w){
            if(s[i][j] == 'B'){
                rep(k,0,4){
                    ll nx = i + dx[k], ny = j + dy[k];
                    if(is_out(nx, ny))continue;
                    if(s[nx][ny] == '.')s[nx][ny] = '#';
                }
            }
        }

        vvl used(h, vl(w));
        auto c = [&](ll x, ll y){
            if(s[x][y] == '#')return ;
            queue<Pll> que;
            que.emplace(x, y);
            used[x][y] = 1;
            while(!que.empty()){
                auto [i, j] = que.front();que.pop();
                rep(k,0,4){
                    ll nx = i + dx[k], ny = j + dy[k];
                    if(is_out(nx, ny))continue;
                    if(used[nx][ny])continue;
                    used[nx][ny] = 1;
                    que.emplace(nx, ny);
                }
            }
        };
        bool ok = true;
        c(h-1, w-1);
        rep(i,0,h)rep(j,0,w){
            if(s[i][j] != 'B' && s[i][j] != 'G')continue;
            if(s[i][j] == 'B'){
                ok &= used[i][j] == 0;
            }
            else{
                ok &= used[i][j] == 1;
            }
        }

        YES(ok);
    }
}