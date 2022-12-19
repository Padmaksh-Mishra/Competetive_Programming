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
const int N = 2e5 + 1;

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
	ll n; cin >> n;
	vll s(n);
	for(int i=0;i<n;++i) cin >> s[i];
	auto calc = [n](vll &s)->ll{
		vll z(n+1);
		z[n]=0;
		for(int i=n-1;i>=0;--i){
			z[i] = z[i+1] + (s[i]==0);
		}	    
		ll ans = 0;
		for(int i=0;i<n;++i){
			ans+=(s[i]*z[i]);
		}
		return ans;
	};
	ll ans1 = calc(s);
	ll badi = -1;
	for(int i=0;i<n;++i){
		if(s[i]==0){
			s[i]=1;
			badi = i;
			break;
		}
	}
	ll ans2 = calc(s);
	if(badi!=-1) s[badi] = 0;
	for(int i=n-1;i>=0;--i){
		if(s[i]==1){
			s[i]=0;
			break;
		}
	}
	ll ans3 = calc(s);
	
	cout << max(ans3,max(ans1,ans2)) << endl;
	
}
