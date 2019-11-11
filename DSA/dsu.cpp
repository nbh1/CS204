#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define pll pair < long long, long long >
#define pli pair <long long, int>
#define pil pair <int, long long>
#define pii pair < int, int>
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
ll mod=1e9+7;
ll power(ll num,ll r){
    if(r==0) return 1;
    if(r==1) return num%mod;
    ll ans=power(num,r/2)%mod;
    if(r%2==0) {
        return (ans*ans)%mod;
    } return (((ans*ans)%mod)*num)%mod;
}
ll modinv(ll num){
    return power(num,mod-2);
}
//------------------------------------------------------------
int findset(int arr[], int x){
	if(x!=arr[x]){
		arr[x]=findset(arr,arr[x]);
	}
	return arr[x];
}
void uni(int arr[],int ranks[],int a,int b){
	int ra=findset(arr,a);
	int rb=findset(arr,b);
	if(ra!=rb){
		if(ranks[ra]<ranks[rb]) swap(ra,rb);
		arr[rb]=ra;
		if(ranks[ra]==ranks[rb]){
			ranks[ra]++;
		}
	}
}
int main(){
	fastio;
	int n;
	cin>>n;
	int arr[n+1];
	int ranks[n+1]={0};
	forl(i,0,n+1) arr[i]=i; //make-set
	int x,y;
	forl(i,0,n){
		int x,y;
		cin>>x>>y;
		int rx=findset(arr,x),ry=findset(arr,y);
		if(rx==ry){
			cout<<"The redudant edges is:-"<<endl;
			cout<<x<<" "<<y;
			break;
		}
		else{
			uni(arr,ranks,x,y);
		}
	}
	return 0;
}