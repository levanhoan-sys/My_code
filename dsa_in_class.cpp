// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int mod = 1e9+7;
// #define FOR(i,a,b) for(int i = a; i <= b; ++i)
// #define FORD(i,a,b) for(int i = a; i >= b; --i)
// int a[1000000];
// int n,t;
// int ans;
// int f[10000];
// // int solve(int n){
// //     if(n == 1){
// //         return 1;
// //     }
    
// //     for(int i = 1; i < n; i++){
// //         if(a[i] < a[n]){
            
// //             return ans = max(ans,solve(i)+1);
// //         }
// //         else return ans = max(ans, solve(i));
        
    
// //     }
// // }
// void solve(int i){
//     if(i > n  || f[i] != 1) return;
//     int tmp = 1;
//     for(int j = 1; j < i; j++){
//         if(a[j] < a[i]){
//             tmp = max(tmp, f[j] + 1);
//         }
//     }
//     f[i] = tmp;
//     solve(i + 1);
// }
// int main(){
//     t = 1;
//     for(int i = 1; i <= 1000; i++) f[i] = 1;
//     while(t--){
//        cin >> n;
//        //for(int i = 1; i <= n; i++) cout << f[i];
//        for(int i = 1; i <= n;  i++){
//         cin >> a[i];
//        }
//        int res = 0;
//        solve(1);
//        cout << f[n] << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
int a[1000000];
int n,t;
int ans;int par[10000];int dp[1000];
int f[10000] = {1};

int solve(int i){
    if(f[i] != 0) return f[i];
    int tmp = 1;
    for(int j = 1; j < i; j++){
        if(a[j] < a[i]){
            tmp = max(tmp, solve(j) + 1);
        }
    }
    return f[i] = tmp;
}
int main(){
    t = 1;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int tail[1000] = {0};
        
       int len = 0;
       for(int i = 0; i < n; i++){
        int l  = 0, r = len - 1, pos = len;
        while(l <= r){
            int mid = (l + r)/2;
            if(tail[mid] >= a[i]){
                pos = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            dp[i] = pos = 1;
            tail[pos] = a[i];
            if(pos == len) len++;
        }
       }
       int res = 0;
       for(int i = 1;i <= n; i++){

       }
    }
    return 0;
}
