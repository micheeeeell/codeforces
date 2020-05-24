// #define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;
// #define int ll


void print() {
    cout << endl;
}

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << " ";
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    bool ok = true;
    bool rw = false, cw = false;
    string s[n];
    rep(i,n)cin >> s[i];
    rep(i,n){
        bool one = false;
        rep(j,m){
            if(one && j < m-1 && s[i][j] == '.' && s[i][j+1] == '#')ok = false;
            if(s[i][j] == '#')one = true;
        }
        if(!one)rw = true;
    }
    rep(j,m){
        bool one = false;
        rep(i,n){
            if(one && i < n-1 && s[i][j] == '.' && s[i+1][j] == '#')ok = false;
            if(s[i][j] == '#')one = true;
        }
        if(!one)cw = true;
    }

    if((rw + cw) % 2 == 1)ok = false;
    if(!ok){
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> used(n, vector<int>(m));
    ll cnt = 0;
    queue<Pll> que;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    int nx, ny;
    rep(i,n)rep(j,m){
        if(s[i][j] == '.')continue;
        if(used[i][j])continue;
        que.emplace(Pll(i,j));
        used[i][j] = 1;
        while(!que.empty()){
            auto p = que.front();que.pop();
            rep(k,4){
                nx = p.first + dx[k];
                ny = p.second + dy[k];
                if(nx < 0 || nx >= n)continue;
                if(ny < 0 || ny >= m)continue;
                if(s[nx][ny] == '.')continue;
                if(used[nx][ny])continue;
                que.emplace(Pll(nx, ny));
                used[nx][ny] = 1;
            }
        }
        cnt++;
        // print(used);print();
    }

    cout << cnt << endl;
}