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

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,l,r; cin >> n >> l >> r;    
	vll lh(200001),rh(200001);
	for(int i=0;i<l;++i){
		ll tmp; cin >> tmp;
		lh[tmp]++;
	}
	for(int i=l;i<n;++i){
		ll tmp; cin >> tmp;
		rh[tmp]++;
	}
	ll lsum=0,rsum=0;
	ll cost = 0;
	for(int i=1;i<n+1;++i){
		ll tmp = min(lh[i],rh[i]);
		lh[i]-=tmp;
		rh[i]-=tmp;
		lsum+=lh[i];
		rsum+=rh[i];
	}
	ll news=0;
	//if(rsum>lsum){
		for(int i=1;i<n+1;++i){
			news+=((rh[i]>>1)+(rh[i]%2));
		}
	//}else{
		for(int i=1;i<n+1;++i){
			news+=((lh[i]>>1)+(lh[i]%2));	
		}
	//}
	cost = min(max(rsum,lsum),news);
	cout << cost  << endl;
}
