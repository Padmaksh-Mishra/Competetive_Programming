# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
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

struct anstype{
	ll a,b,c;
};

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
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
	ll n,m; cin >> n >> m;
	vector<vll> v(n,vll(m+1));
	ll totalOnes = 0;
	for(int i=0;i<n;++i){
		ll o=0;
		for(int j=0;j<m;++j){
			cin >> v[i][j];
			o+=(v[i][j]==1);
			// cout << v[i][j] << " ";
		}
		v[i][m] = o;
		totalOnes+=o;
		// cout << v[i][m] << endl;
	}	    
	if(totalOnes%n){
		cout << -1 << endl;
		return;
	}
	ll need = totalOnes/n;
	ll e=0,d=0;
	vector<anstype> answer;
	for(;e<n&&d<n;){
		for(int i=0;i<m;++i){
			if(v[d][m]-need >= 0){
				d++;
				break;
			}
			if(v[e][m]-need <= 0){
				e++;
				break;
			}
			if(v[d][i]==0&&v[e][i]==1){
				// cout << "HI" << endl;
				v[d][i]=1;
				v[e][i]=0;
				v[d][m]++;
				v[e][m]--;
				anstype tmp = {e+1,d+1,i+1};
				answer.emplace_back(tmp);
			}
		}
		// deb(e);
		// deb(d);
	}
	cout << siz(answer) << endl;
	for(auto ans : answer){
		cout << ans.a << " " << ans.b << " " << ans.c << endl;
	}
}
