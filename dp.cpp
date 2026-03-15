#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t,n,m,k;
int a[10000];
int dp[100005];

int main(){
	cin >> t;
	while(t--){
		cin >> m >> n;
		int a[100005], b[100005];
		map<int,int> mp;
		for(int i = 1; i <= m; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			cin >> b[i];
			mp[b[i]]++;
		}
		ll cnt = 0;
		sort(b + 1, b + n + 1);
		for(int i = 1; i<= m; i++){
			if(a[i] == 1){
				cnt += mp[0];
			}
			else if(a[i] == 2){
				auto tmp = lower_bound(b + 1, b + n + 1, 5);
				if(tmp != b + n +1){
					cnt += n - (tmp - b) + 1;
				}
				cnt += mp[1] + mp[0];
			}
			else if(a[i] == 3){
				cnt += n - mp[3];
			}
			else if(a[i] != 1 && a[i] != 0) {
				auto tmp = lower_bound(b + 1, b + n + 1, a[i] + 1);
				if(tmp != b + n + 1){
					cnt += n - (tmp - b) + 1;
				}
				cnt += mp[1] + mp[0];
			}
		}
		cout << cnt << endl;

	}	
}