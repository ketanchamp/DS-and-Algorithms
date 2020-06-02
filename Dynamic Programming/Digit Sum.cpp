#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> num;
ll dp[16][15*10][2];
// DP[pos][sum][f] = Number of valid numbers <= b from this state
// pos = current position from left side (zero based)
// sum = sum of all the digits so far
// f = the number we are building has already become smaller than n? [0 = no, 1 = yes]
ll run(ll pos, ll sum, int f){
	if(pos == (ll)num.size()) return sum;
	if(dp[pos][sum][f] != -1) return dp[pos][sum][f];
	int lim = 9;
	if(!f) lim = num[pos];
	ll res = 0;
	for(int i = 0; i <= lim; i++){
		int cf = f;
		if(i < lim) cf=1;
		res += run(pos+1, sum+i, cf);
	}
	return dp[pos][sum][f] = res;
}
ll solve(ll a){
	num.clear();
	while(a>0){
		num.push_back(a%10);
		a/=10;
	}
	memset(dp,-1,sizeof(dp));
	reverse(num.begin(), num.end());
    return run(0, 0, 0);
}
int main()
{
    ll a,b,t;
    cin>>t;
    while(t--) {
       cin>> a >> b;
	   cout << solve(b) - solve(a-1) << endl;
	}
    return 0;
}