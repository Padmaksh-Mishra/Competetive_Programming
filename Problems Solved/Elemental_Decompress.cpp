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
	ll n; cin >> n;
	vll arr(n);
	for(int i=0;i<n;++i){
		cin >> arr[i];
	}	    
	set<ll> sa,sb;
	for(int i=0;i<n;++i){
		sa.insert(i+1);
		sb.insert(i+1);
	}
	vll a(n,0),b(n,0);
	for(int i=0;i<n;++i){
		if(sa.find(arr[i])!=sa.end()){
			sa.erase(sa.find(arr[i]));
			a[i] = arr[i];
		}else if(sb.find(arr[i])!=sb.end()){
			sb.erase(sb.find(arr[i]));
			b[i] = arr[i];
		}else{
			cout << "NO" << endl;
			return;
		}
	}
	
	for(int i=0;i<n;++i){
		if(a[i]==0){
			auto it = prev(sa.upper_bound(arr[i]));
			if((*it)>arr[i]){
				cout << "NO" << endl;
				return;
			}
			a[i] = *it;
			sa.erase(it);
		}
		if(b[i]==0){
			auto it = prev(sb.upper_bound(arr[i]));
			if((*it)>arr[i]){
				cout << "NO" << endl;
				return;
			}
			b[i] = *it;
			sb.erase(it);
		}
	}
	cout << "YES" << endl;
	for(auto val : a){
		cout << val << " ";
	}
	cout << endl;
	for(auto val : b){
		cout << val << " ";
	}
	cout << endl;
}
