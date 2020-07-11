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
    ll n; cin >> n;
    string s, t;cin >> s >> t;
    vector<ll> id;
    ll suma = 0, sumb = 0, cnt = 0;
    rep(i,0,n){
        ll st = s[i] - '0', tt = t[i] - '0';
        suma += st, sumb += tt;
        if(st != tt){
            id.emplace_back(st);
            cnt++;
        }
    }
    if(suma != sumb){
        std::cout << -1 << endl;
        return 0;
    }
    if(id.size() == 0){
        std::cout << 0 << endl;
        return 0;
    }
    assert(cnt % 2 == 0);
    ll ans = 0;
    // ランレングス圧縮
    ll c = 1;
    vector<vector<ll>> num(2);
    rep(i,0,id.size()-1){
        if(id[i] == id[i+1]){
            c++;
            continue;
        }
        else{
            num[0].emplace_back(c);
            c = 1;
        }
    }
    num[0].emplace_back(c);
    debug(num);
    ll turn = 0, nxt;
    while(!num[turn].empty()){
        ll min_ = INF;
        nxt = (turn ^ 1);
        if(num[turn].size() % 2 == 0){
            rep(i,0,num[turn].size()) chmin(min_, num[turn][i]);
            rep(i,0,num[turn].size()){
                ll c = num[turn][i] - min_;
                if(c == 0){
                    if(i == 0 || i == num[turn].size()-1)continue;
                    else{
                        ll temp = 0;
                        if(!num[nxt].empty()){
                            temp = num[nxt].back();num[nxt].pop_back();
                        }
                        num[turn][i+1] += temp;
                    }
                }
                else{
                    num[nxt].emplace_back(c);
                }
            }
        }
        else{
            rep(i,0,num[turn].size()) chmin(min_, num[turn][i]);
            rep(i,0,num[turn].size()-1){
                ll c = num[turn][i] - min_;
                if(c == 0){
                    if(i == 0 || i == num[turn].size()-1)continue;
                    else{
                        ll temp = 0;
                        if(!num[nxt].empty()){
                            temp = num[nxt].back();num[nxt].pop_back();
                        }
                        num[turn][i+1] += temp;
                    }
                }
                else{
                    num[nxt].emplace_back(c);
                }
            }
            num[nxt].emplace_back(num[turn].back());
        }
        
        ans += min_;
        num[turn].clear();
        debug(num[nxt]);
        turn = nxt;
    }


    std::cout << ans << endl;
}