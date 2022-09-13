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
const int N = 1e5 + 1;

void setIO(string name = "sublime");
int count(string s){
	// deb(s);
	int cnt = 0;
	int n = siz(s);
	int i=-1,j=0;
	while(i<n&&j<n){
		while(s[j]=='F'){
			j++;
		}
		if(j>=n) break;
		if(i==-1){
			i=j;
		}
		else if(s[j]!=s[i]){
			cnt++;
			i=j;
		}
		j++;
	}
	cnt = (cnt%MOD);
	// deb(cnt);
	return cnt;
}
void solve(){
	int n; cin >> n;
	string s; cin >> s;
	// vi hsh(n+1,0);
	int cnt = 0;
 	// for(int j=1;j<n+1;++j){
 	// 	int tmp = count(s.substr(0,j));
 	// 	cnt = cnt%MOD;
 	// 	cnt+=tmp;
 	// 	hsh[j] = cnt;
 	// }
 	// cnt=0;
 	for(int i=0;i<n;++i){
 		for(int j=1;j<n-i+1;++j){
 			cnt+=count(s.substr(i,j));
 		}
 	}	
	cout << cnt << endl;
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