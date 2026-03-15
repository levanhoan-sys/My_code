#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int t,n,m,k,p;
int cnt, ans;
int a[1005][1005];
bool visited[100005];
vector<int> ke[100005];
int deg[100005];
vector<pair<int, int>> dscanh;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
        if(i < j){
            dscanh.push_back({i,j});
            a[i][]
        }

    }
    if(t == 1){
        for(int i = 1; i <=n; i++){
            cout << deg[i] <<" ";
        }
        cout << endl;
    }
    else{
        cout << n << endl;
        
        for(int i = 1; i <= n; i++){
            cout << ke[i].size() << " ";
            for(int j : ke[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
}