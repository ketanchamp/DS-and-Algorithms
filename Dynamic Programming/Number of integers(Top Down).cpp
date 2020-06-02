 //https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/maximum-or-1
 //Time Complexity- O(9*(4^N)), N = number of digits
 //Top Down Dynamic Programming approach
#include <bits/stdc++.h>
#define mod (1000000000 + 7)
using namespace std;
typedef long long ll;
ll add(ll a,ll b) {return (ll)(((a%mod)+(b%mod))%mod);}
ll dp[105][105][2];
// DP[pos][k][f] = Number of valid numbers <= b from this state
// pos = current position from left side (zero based)
// k = number of non zero digits
// f = the number we are building has already become smaller than n? [0 = no, 1 = yes]
ll k_nonzero(ll pos, ll n, int k, int f, string s){
	if(pos==(ll)s.size()) return (n==k ? 1 : 0);
	if(dp[pos][n][f] != -1) return dp[pos][n][f];
	int lim = 9;
	if(!f) lim = (int)(s[pos]-'0');
	ll res = 0;
	for(int i = 0; i <= lim; i++){
		int cf = f;
		if(i < lim) cf=1;
		res = add(res, k_nonzero(pos+1, n+(i!=0), k, cf, s));
	}
	return dp[pos][n][f] = res%mod;
}
int main()
{
    string l,r;
    int k;
    cin>>l>>r;
	cin>>k;
	memset(dp,-1,sizeof(dp));
    ll maxi=k_nonzero(0, 0, k, 0, r);
    memset(dp,-1,sizeof(dp));
    ll mini=k_nonzero(0, 0, k, 0, l);
    cout<<(maxi-mini+mod)%mod<<endl;
    return 0;
}