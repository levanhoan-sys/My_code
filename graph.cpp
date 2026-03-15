#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,t,k,s,p;
vector<int> ke[1005];
bool visited[1005];
vector<int> ans;
int par[1005];int deg[1005];int color[1005];
void kahn(){
    queue<int> pq;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) pq.push(i);
    }
    while(!pq.empty()){
        int u = pq.front();
        visited[u] = true;
        ans.push_back(u);
        pq.pop();
        for(int v : ke[u]){
            if(!visited[v]){
                deg[v]--;
                if(deg[v] == 0){
                pq.push(v);
            }
            }
        }
    }
}
bool dfs(int u){
    color[u] = 1;
    for(int v : ke[u]){
        if(!color[v]){
            if(dfs(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;
    return false;
}
bool dfs2(int u, int par){
    color[u] = 3 - color[par];
    for(int v: ke[u]){
        if(!color[v]){
            if(!dfs2(v,u)) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}
void in(){
    cin >> n >> m;
    
    memset(visited, false, sizeof(visited));
    for(int i = 1; i < 1005; i++) color[i] = 0;
    for(int i = 1; i < 1005; i++) ke[i].clear();
    for(int i = 1; i <= m; i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }


}
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        in();
        bool ok = true;
        color[0] = 1;
        for(int i = 1; i <= n; i++){
            if(!color[i]){
                if(!dfs2(i,0)){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    
}