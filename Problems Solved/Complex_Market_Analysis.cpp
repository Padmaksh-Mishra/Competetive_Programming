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

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 1e6;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();
bool prime[N+1];
void SieveOfEratosthenes()
{
    // bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    prime[1] = false;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    SieveOfEratosthenes();
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,e; cin >> n >> e;
	vll arr(n);
	for(int i=0;i<n;++i) cin >> arr[i];
	ll ans = 0;
	vll one;
	for(int i=0;i<e;++i){
		ll tmp = 0;
		// deb(i);
		for(int j=i;j<n;j+=e){
			// deb(arr[j]);
			if(arr[j]==1){
				tmp++;
			}else if(prime[arr[j]]){
				one.emplace_back(tmp);
				tmp=0;
			}else break;
		}
		if(siz(one)>0)one.emplace_back(tmp);
		if(siz(one)>1){
			for(int o = 0;o<siz(one)-1;++o){
				ans+=(one[o]+one[o+1]+(one[o]*one[o+1]));
			}
		}else if(siz(one)==1) ans+=one[0];
		one.clear();
		//deb(ans);
	}	
	cout << ans << endl;    
}
