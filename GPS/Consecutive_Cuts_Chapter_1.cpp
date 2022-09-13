# include <bits/stdc++.h>
# define DEATH ios_base::sync_with_stdio(false); 
# define AWAITS cin.tie(NULL); 
# define YOU cout.tie(NULL);
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
const int N = 1e5 + 1;

void setIO(string name = "sublime");

void solve(){
	int n,k; cin >> n >> k;
	vi a(n),b(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	for(int i=0;i<n;++i){
		cin >> b[i];
	}
	int t = -1;
	for(int i=0;i<n;++i){
		if(b[i]==a[0]) {
			t=i;
			break;
		}
	}
	if(t!=-1&&k==0){
		cout << "NO" << endl;
		return;
	}
	int j = t;
 	for(int i=0;i<n;++i){
 		if(a[i]!=b[j%n]){
 			cout << "NO" << endl;
 			return;
 		}
 		j++;
 	}
 	cout << "YES" << endl;
}

int32_t main(){

    DEATH AWAITS YOU

    setIO();	//Does not work with Google 	
    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	cout << "Case #" << i+1 << ": ";
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