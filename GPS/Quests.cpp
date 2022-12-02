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
ll n,c,d;
bool ok(vll &arr,ll k){
	ll coins = c;
	for(int i=0;i<d;++i){
		ll indx = (i%(k+1));
		indx = (indx>n) ? n+1 : indx;
		coins-=arr[indx];
		if(coins<=0) return true;
	}
	return (coins <= 0);
}
void solve(){
	cin >> n >> c >> d;
	vll arr(n+2);
	fill(all(arr),0);
	for(int i=0;i<n;++i) cin >> arr[i];
	sort(all(arr),[](ll a,ll b)->bool{return a>b;}); 
	ll s = 0,e = d+2,mid;
	if(!ok(arr,0)){ 
		cout << "Impossible" << endl;
		return;
	}else if(ok(arr,d+2)){
		cout << "Infinity" << endl;
		return;
	}
	while(e-s>1){
		mid = (s+e)/2;
		if(ok(arr,mid)) s = mid;
		else e = mid-1;
	} 
	//cout << s << ' ' << mid << " " << e << endl;
	if(ok(arr,e)) cout << e << endl;		//for maxima we see end first 
											//(iske pehele wale questions me lower bound dhunda tha)
	else if(ok(arr,mid)) cout << mid << endl;
	else cout << s << endl;  
}
