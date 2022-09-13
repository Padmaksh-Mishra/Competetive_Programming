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
	int n; cin >> n;
	multiset<int> m;
	vi ip(n);
	vi so(n);
	for(int i=0;i<n;++i){
		cin >> ip[i];
		//m.insert(ip[i]);
		so[i]=ip[i];
	}
	sor(so);
	map<int,int> mapp;
	// for(auto it = m.begin();it!=m.end();++it){
	// 	auto fi = m.upper_bound(((*it)*2));
	// 	fi--;
	// 	if(fi==it) fi--;
	// 	auto tmp = m.begin();
	// 	--tmp;
	// 	if(fi!=tmp) mapp[(*it)]=(*fi);
	// 	else mapp[(*it)] = -1;
	// }
	for(auto it = so.begin();it!=so.end();++it){
		auto fi = upper_bound(all(so),(*it)*2);
		fi--;
		if(fi==it) fi--;
		auto tmp = so.begin();
		tmp--;
		if(fi!=tmp) mapp[(*it)]=(*fi);
		else mapp[(*it)] = -1;
	}
	for(auto val : ip) cout << mapp[val] << " ";
	cout << endl;
}

int main(){

    JAI SHREE RAM


    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	cout << "Case #" << i+1 << ": ";
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