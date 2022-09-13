# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
//# define int ll
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;

void solve(){
	int n,q; cin >> n >> q;
	int m = -1,mv=-1;
	map<int,int> indx;
	deque<int> ips;
	for(int i=0;i<n;++i){
		int tmp; cin >> tmp;
		indx[i]=tmp;
		ips.pb(tmp);
    	if(mv<tmp) mv=tmp,m = i;
	}
    // deb(m);
	//simulation of fights till superman comes
	map<int,vi> sf;
	for(int i=0;i<=m;++i){
   		int a=ips[0],b=ips[1];
   		ips.pop_front();
   		ips.pop_front();
   		// deb(ips[0]);
   		if(a>b){
   			ips.push_front(a);
   			sf[a].pb(i);
   			ips.pb(b);
   		}else {
   			ips.push_front(b);
   			sf[b].pb(i);
   			ips.pb(a);
   		}
	}
	map<int,int> upindx;
	for(int i=0;i<n;++i) upindx[ips[i]] = i;
	for(int i=0;i<n;++i) cout << ips[i] << " ";
	cout << endl;

	//queries

	while(q--){
		int ans=0;
		int i,k; cin >> i >> k;
		i--;
		if(k<=m){
			ans+=(upper_bound(all(sf[indx[i]]),k)-sf[indx[i]].begin()-1);
		}else{
			ans+=(upper_bound(all(sf[indx[i]]),m)-sf[indx[i]].begin()-1);
			k-=m;
			if(i==0) ans+=k;
			else{
				ans+=(k/(n-1));
				int tmp = (k%(n-1))-1;
				if(tmp<=upindx[indx[i]]) ans++;
			}
		}
		cout << ans << endl;
	}
}

int main(){

    JAI SHREE RAM


    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}


//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 