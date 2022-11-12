# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll TC = 1;
   	cin >> TC;
    	for(int i=0;i<TC;++i){
        	//cout << "Case #" << i+1 << ": ";
        	solve();
    	}
    	return 0;
}

// Do something good 
ll firstsetbit(ll n){
	ll i=0;
	for(int i=0;i<n;++i){
		if(n&(1<<i)!=0) return i;
	}
	return 64;
}
ll binsch(ll n){
	ll start=0,end=r;
	ll mid = (start+r)>>1;
	while(start<end){
		mid = (start+end)>>1;
		if(mid>n){
			start=mid+1;
		}
void solve(){
	ll n; cin >> n;
	vll ips(n);
	for(int i=0;i<n;++i) cin >> ips[i];
		
	return;	
}
