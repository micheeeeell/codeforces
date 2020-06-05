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
    ll q; cin >> q;

    auto c = [&](string &s, string &t){
        ll m = s.size();
        ll cnt = 0;
        rep(i,m){
            if(s[i] != t[i])cnt++;
        }
        return cnt <= 1;
    };
    while(q--){
        ll n,m; cin >> n >> m;
        string s[n];
        rep(i,n)cin >> s[i];

        ll dif = 0;
        string s1, s2;
        rep(i,n)rep(j,n){
            string s1t = "";
            string s2t = "";
            if(i <= j)continue;
            ll cnt = 0;
            rep(k,m){
                if(s[i][k] != s[j][k]){
                    cnt++;
                    if(cnt == 1){
                        s1t += s[i][k];
                        s2t += s[j][k];
                    }
                    else{
                        s1t += s[j][k];
                        s2t += s[i][k];
                    }
                }
                else{
                    s1t += s[i][k];
                    s2t += s[i][k];
                }
            }
            chmax(dif, cnt);
            if(cnt == 2){
                s1 = s1t;
                s2 = s2t;
            }
        }

        debug(s1, s2, dif);
        if(dif <= 1){
            cout << s[0] << "\n";
            continue;
        }
        if(dif > 2){
            cout << -1 << "\n";
            continue;
        }
        bool t1 = true, t2 = true;
        rep(i,n){
            t1 &= c(s1, s[i]);
            t2 &= c(s2, s[i]);
        }

        if(t1){
            cout << s1 << "\n";
        }
        else if(t2){
            cout << s2 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}