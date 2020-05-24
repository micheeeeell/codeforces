#define _GLIBCXX_DEBUG
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
const int n_max = 2e5+10;
#define int ll

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


bitset<n_max> used(0);
bool ok = true;
vector<ll> topo_sort(vvl &graph){
    queue<ll> que;
    vector<ll> ans;
    ll v = graph.size();
    vector<ll> in(v);
    for(auto &vec : graph){
        for(auto &to : vec)in[to]++;
    }
    rep(i,v)if(in[i] == 0){
        que.emplace(i);
        ans.emplace_back(i);
    }
    while(!que.empty()) {
        auto f = que.front();que.pop();
        for(auto &to : graph[f]) {
            in[to]--;
            if(!in[to]) {
                ans.emplace_back(to);
                que.emplace(to);
            }
        }
    }

    return ans;
};

bitset<n_max> flag(0), flag2(0);
void dfs(vvl &graph,bitset<n_max> &flag,  ll pos){
    flag[pos] = 1;
    for(auto &to : graph[pos]){
        if(flag[to])continue;
        dfs(graph, flag, to);
    }
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<int> in(n);
    vector<vector<int>> graph(n);
    vector<vector<int>> graph_d(n);
    rep(i,m){
        int f,t; cin >> f >> t;
        f--;t--;
        graph[f].emplace_back(t);
        graph_d[t].emplace_back(f);
    }

    auto topo = topo_sort(graph);
    ok &= topo.size() == n;

    if(!ok){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    string s;
    rep(i,n){
        if(flag[i] == 0 && flag2[i] == 0){
            s += 'A';ans++;
        }
        else{
            s += 'E';
        }
        dfs(graph, flag,  i);
        dfs(graph_d, flag2,  i);
    }


    cout << ans << endl;
    cout << s << endl;

}