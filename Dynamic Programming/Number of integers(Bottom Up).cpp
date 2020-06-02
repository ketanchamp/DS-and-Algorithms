//https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/maximum-or-1
//Time Complexity- O(9*(4^N)), N = number of digits
//Bottom Up Dynamic Programming approach

#include<bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define pb push_back
#define mod (1000000000 + 7)
typedef long long ll;
using namespace std;
ll fastpow(ll n, ll x, ll m){
    ll ret = 1;
    while(x){
    if(x&1) (ret*=n)%=m;
    x>>=1;
    (n*=n)%=m;
    }
 return ret;
}
ll add(ll a,ll b){
    return((a%mod)+(b%mod))%mod;
}
ll prod(ll a,ll b){
    a%=mod;
    b%=mod;
    return ((a%mod)*(b%mod)%mod);
}
ll dp[105][2][105];
// dp[pos][f][k] = Number of valid numbers <= b from this state
// pos = current position from left side (zero based)
// f = the number we are building has already become smaller than n? [0 = no, 1 = yes]
// k = number of non zero digits
ll k_nonzero(string s, int n, int k)
{
    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        ll sm = 0;
        while (sm < 2) {
            for (int j = 0; j < k + 1; ++j) {
                ll x = 0;
                while (x <= (sm ? 9 : s[i] - '0')) {
                    dp[i + 1][sm || x < (s[i] - '0')][j + (x > 0)]=add(dp[i + 1][sm || x < (s[i] - '0')][j + (x > 0)],dp[i][sm][j]);
                    ++x;
                }
            }
            sm=add(sm,1);
        }
    }

    return add(dp[n][0][k],dp[n][1][k]);
}
void solve(){
    string l,r;
    int k;
    cin>>l;
    cin>>r;
    cin>>k;
    ll maxi=k_nonzero(r,(int)r.size(),k);
    ll mini=k_nonzero(l,(int)l.size(),k);
    cout<<(maxi-mini+mod)%mod<<endl;
}
int main()
{

    ll t=1;
    while(t--) {
     solve();
    }
    return 0;
}