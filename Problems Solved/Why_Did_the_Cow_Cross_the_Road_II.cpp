//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

map<char,pair<int,int>> sem;
int top;
void solve(){
	string s; cin >> s;
	for(int i=1;i<=52;++i){
		if(sem[s[i-1]].first == 0) sem[s[i-1]].first = i;
		else if(sem[s[i-1]].second == 0) sem[s[i-1]].second = i;
	}

	int ans = 0;
	for(auto &val : sem){
		deb(val.first);
		cout << val.second.first << " " << val.second.second << endl;
		for(auto &tmp : sem){
			if(val.second.first<tmp.second.first&&val.second.second>tmp.second.second) ans++;
		}
	}
	cout << (ans>>1) << endl;
}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}