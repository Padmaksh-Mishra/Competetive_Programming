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

void solve(){
	string s; cin >> s;
	vector<pair<char,int>> ans;
	int n = siz(s);
	int moves = 0;
	char big,small;
	bool kill = false;
	
	if(s[n-1]>s[0]) {
		big = s[n-1];
		small=s[0];
	}
	else {
		kill=true;
		big=s[0];
		small=s[n-1];
	}
	int cost = big-small;
    for(int i=1;i<n-1;++i){
    	if(s[i]>=small&&s[i]<=big){
            moves++;
            ans.pb({s[i],i});
    	}
    }
    sort(all(ans));
    if(kill) reverse(all(ans));
    cout << cost << " " << moves+2 << endl;
    cout << 1 << " ";
    for(auto val : ans){
    	cout << val.s+1 << " ";
    }
    // cout << endl;
    cout << n << endl;
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