# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
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
	string w; cin >> w;
	int p; cin >> p;
	int np = 0;
	vector<pair<int,int>> v;
	for(int i=0;i<siz(w);++i){
       v.pb({(w[i]-'a'+1),i});
       np+= (w[i]-'a'+1);
	}
	sor(v);
	int tbd = -p+np;
	if(tbd<=0){
		cout << w << endl;
		return;
	}
	int x = siz(w);
	multiset<int> tbr;
	for(int i=x-1;i>=0;--i){
		tbd-=v[i].f;
		tbr.insert(v[i].s);
		if(tbd<=0) break;
	}
	for(int i=0;i<x;++i){
		if(tbr.find(i)==tbr.end()) cout << w[i];
	}
	cout << endl;
	return;
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