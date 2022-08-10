//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	vector<int> v,s;
	v.push_back(-MOD);
	s.push_back(-MOD);
	int tmp;
	for(int i=1;i<=n;++i) {
		cin >> tmp;
		if(tmp!=v[i-1]){
			v.push_back(tmp);
			s.push_back(tmp);
		}
	}
	//v.push_back(MOD);
	int indx = -1,e=-1;
	sort(s.begin(), s.end());
	for(int i=1;i<n;++i){
		// cout << v[i] << " " << s[i] << endl;
		if(v[i]!=s[i]){
			if(indx==-1) indx = i,e=s[i];
		}
		if(v[i]==e&&indx!=-1){
			cout << i-indx << endl;
			return;
		}

	}
	cout << 0 << endl;
	return;
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