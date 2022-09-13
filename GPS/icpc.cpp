# include <bits/stdc++.h>
# define DEATH ios_base::sync_with_stdio(false); 
# define AWAITS cin.tie(NULL); 
# define YOU cout.tie(NULL);
# define int long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "No" << endl
# define YES cout << "Yes" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (int)(x).size()
# define vi vector<int>
# define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = 1e9 +7;
const int N = 2e5;

void setIO(string name = "sublime");

void solve(){
	int n; cin >> n;
	int x; cin >> x;
	string bs; cin >> bs;
	bitset<N> bits(bs);
	int i=-1,j=0;
	vi costs;
	int ones = bits.count();
	for(j=0;j<n;++j){
		if(bs[j]=='1'){
			if(j-i-1!=0){
				// deb(j-i-1);
				costs.pb(((j-i-1)<<1)+1);
			}
			i=j;
		}
	}
	costs.pb(((j-i-1)<<1)+1);
	sort(all(costs),greater<int>());
	for(auto val : costs){
		// deb(val);
		if(val<=x){
			x-=val;
			int z = (val-1)/2;
			ones+=z;
		}
		else{
			int z = (x-1)/2;
			if(z>0){
				ones+=z;
				x-=(z*2)+1;
			}
		}
		if(x<=0) break;
	}
	cout << ones << endl;
}

int32_t main(){

    DEATH AWAITS YOU

    setIO();	//Does not work with Google 	
    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

void setIO(string name) {  
#ifndef ONLINE_JUDGE
	if((int)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}