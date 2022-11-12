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
	ll n,x,y; cin >> n >> x >> y;
	string a,b; cin >> a >> b;
	int xx = 0,yy = 0;
	for(int i=0;i<n;++i){
		if(a[i]!=b[i]){
			if(a[i+1]!=b[i+1]&&i!=n-1){
				xx++;
				b[i]=a[i];
				b[i+1]=a[i+1];
				++i;
			}	
		}
	}
	for(int i=0;i<n;++i){
		if(a[i]!=b[i]){
			++yy;	
		}
	}
	if(x<y){
		//	
	}else{
		if((2*xx)+yy>2) x=y;
		else if(x>2*y) x=2*y;
	}
	if(((2*xx)+yy)%2!=0) cout << -1 << endl;
	else cout << xx*x + (yy/2)*y << endl;
}
