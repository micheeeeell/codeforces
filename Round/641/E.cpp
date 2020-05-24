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
void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w,t; cin >> h >> w >> t;
    vector<string> s(h);
    rep(i,h)cin >> s[i];
    ll dx[] = {0,0,1,-1};
    ll dy[] = {1,-1,0,0};
    auto update = [&](){
        vector<string> s2 = s;
        rep(i,h)rep(j,w){
            ll t = s[i][j] - '0';
            bool ch = false;
            rep(k,4){
                ll nx = dx[k] + i;
                ll ny = dy[k] + j;
                if(0 > nx || 0 > ny || nx >= h || ny >= w)continue;
                ch |= s[i][j] == s[nx][ny];
            }
            if(ch)s2[i][j] = char('0' + (t ^ 1));
        }
        return s2;
    };
    vvl table(h, vl(w));
    queue<Pll> que;
    rep(i,h)rep(j,w){
        ll t = s[i][j] - '0';
        bool ch = false;
        rep(k,4){
            ll nx = dx[k] + i;
            ll ny = dy[k] + j;
            if(0 > nx || 0 > ny || nx >= h || ny >= w)continue;
            ch |= s[i][j] == s[nx][ny];
        }
        if(ch){
            table[i][j] = 1;
            que.emplace(i,j);
        }
    }
    while(!que.empty()){
        auto p = que.front();que.pop();
        auto [x, y] = p;
        rep(k,4){
            ll nx = dx[k] + x;
            ll ny = dy[k] + y;
            if(0 > nx || 0 > ny || nx >= h || ny >= w)continue;
            if(table[nx][ny] == 0){
                table[nx][ny] = table[x][y] + 1;
                que.emplace(nx,ny);
            }
        }
    }

    
    rep(_,t){
        ll i,j,p; cin >> i >> j >> p;
        i--;j--;
        if(table[i][j] > p){
            cout << s[i][j] << "\n";
            continue;
        }
        if(table[i][j] == 0){
            cout << s[i][j] << "\n";
            continue;
        }
        ll temp = s[i][j] - '0';
        if((p - table[i][j] + 1) & 1){
            cout << (temp ^ 1) << "\n";
        }
        else{
            cout << temp << "\n";
        }
    }
}