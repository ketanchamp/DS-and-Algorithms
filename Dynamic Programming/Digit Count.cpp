 //https://vjudge.net/problem/LightOJ-1122
 //Time Complexity- O(9*(4^N)), N = number of digits
 // Recursive approach
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 map<ll,ll> ma;
 ll run(ll pos,ll prev,ll n){
 	if(pos==n){
 		return 1;
 	}
 	ll res=0;
 	for(int i=prev-2;i<=prev+2;i++){
 		if(ma[i]) res+=run(pos+1,i,n);
 	}
 	return res;
 }
 void solve(){
 	ll m,n,x,ans=0;
     cin>>m>>n;
     ma.clear();
     for(int i=0;i<m;i++) {cin>>x;ma[x]=1;}
     for(int i=0;i<=9;i++) if(ma[i]) ans+=run(1,i,n);
     cout<<ans<<endl;
     return;
 }
 int main()
 {
     ll t,co=1;
     cin>>t;
     while(t--) {
        cout<<"Case "<<co++<<": ";
 	   solve();
 	}
     return 0;
 }