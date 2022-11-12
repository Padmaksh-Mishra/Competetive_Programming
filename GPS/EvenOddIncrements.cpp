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
	ll n,q; cin >> n >> q;
	vll ips(n);
	ll odd,even,sum;odd=even=sum=0;
	for(int i=0;i<n;++i) {
		cin >> ips[i];  
		sum+=ips[i];  
		if(ips[i]%2==0) even++;
		else odd++;
	}
	while(q--){
		ll a,b; cin >> a >> b;
		if(a==1){
			sum+=(odd*b);
			if(b%2!=0){
				even+=odd;
				odd=0;
			}
		}else{
			sum+=(even*b);
			if(b%2!=0){
				odd+=even;
				even=0;
			}
		}
		cout << sum << endl;
	}
}
