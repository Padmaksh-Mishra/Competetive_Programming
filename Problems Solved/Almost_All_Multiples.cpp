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
	ll n,x; cin >> n >> x;
	vll perm(n+1);
	for(int i=0;i<n;++i){
		perm[i+1] = i + 1;
	}    
	if(n%x){
		cout << -1 << endl;
	}
	else{
		perm[1] = x;
		perm[x] = n;
		perm[n] = 1;
		for(int i=x+1;i<n;++i){
			if(n%i==0&&perm[i]%x==0){
				perm[x] = perm[i];
				perm[i] = n;
				x=i;
				//break;
			}
		}
		for(auto val : perm){
			if(val) cout << val << " ";
		}
		cout << endl;
	}
}
