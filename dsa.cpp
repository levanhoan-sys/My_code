// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define FOR(i,a,b) for(int i = a; i <= b; i++)
// #define FORD(i,a,b) for(int i = a; i >= b; --i)
// int dx[4] = {-1,0,0,1};
// int dy[4] = {0,-1,1,0};
// int n,m,k, cnt, maxc;
// int a[10000][100],b[10000];
// int visited[100000];
// int maxx, tmp;
// bool prime(int n){
//     for(int i = 2; i <= sqrt(n); i++){
//         if(n % i == 0) return false;
//     }
//     return n > 1;
// }
// void sinh(int i){
//     if(i > n){
//         if(tmp > maxx) maxx = tmp;
//     }
//     else{
//         for(int j = 1;j <= n; j++){
//             if(visited[j] == 0){
//                 visited[j] = 1;
//                 b[i] = j;
//                 tmp += a[i][j];
//                 if(tmp + (n-i)*maxc > maxx){
//                     sinh(i+1);
//                 }
                
//                 visited[j] = 0;
//                 tmp -= a[i][j];
//             }
//         }
//     }
// }
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//     cin >> n;
//     FOR(i,0,n-1){
//         FOR(j,0,n-1){
//             cin >> a[i][j];
//         }
//     }
//     int dp[1 << 20];
    
// dp[0] = 0;
// for(int mask = 0; mask < (1 << n); mask++){
//     int i = __builtin_popcount(mask) + 1;
//     for(int j = 0; j < n; j++){
//         if((mask & (1 << j)) == 0){
//             dp[mask | (1 << j)] = max(
//                 dp[mask | (1 << j)],
//                 dp[mask] + a[i][j + 1]
//             );
//         }
//     }
// }
// cout << dp[(1 << n) - 1];
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = -(1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<vector<ll>> a(N, vector<ll>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> a[i][j];
            }
        }

        int maxMask = 1 << N;
        vector<ll> dp(maxMask, INF);
        dp[0] = 0;

        for (int mask = 0; mask < maxMask; mask++) {
            int i = __builtin_popcount(mask); // hàng hiện tại
            if (i >= N) continue;

            for (int j = 0; j < N; j++) {
                //cout << mask << ' ' << j << endl;
                //cout << j << "    ";
                if ((mask & (1 << j)) == 0) {
                    //cout << j << "    ";
                    int newMask = mask | (1 << j);
                    dp[newMask] = max(
                        dp[newMask],
                        dp[mask] + a[i][j]
                    );
                    cout << mask << ' ' << newMask << endl;
                }
            }
        }

        cout << dp[maxMask - 1] << '\n';
    }

    return 0;
}
