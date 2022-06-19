//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,k; cin >> n >> k;
	string s; cin >> s;
	vector<int> z,o;

	for(int i=0;i<s.length();i++){
		if(s[i]=='0') {
			z.push_back(i);
		}
		else{
			o.push_back(i);
		}
	}    
	if((k!=0)&&(z.size()>0)&&(o.size()>0)){
		if(z[z.size()-1]==n-1){
			//deb(z[z.size()-1]);
			if(z[z.size()-1] - o[o.size()-1]<=k){
				k-= z[z.size()-1] - o[o.size()-1];
				swap(s[z[z.size()-1]],s[o[o.size()-1]]);
			}
		}

		if(z[0]==0){
			if((o[0]-z[0] <=k)&&(o[0]!=n-1)){  
				k-= o[0]-z[0];
				swap(s[z[0]],s[o[0]]);
			}
		}
	}

	//deb(s);
	ll sum=0;

	for(int i=0;i<s.length()-1;i++){
		sum += (10*(s[i]-'0')) + (s[i+1]-'0');
	}
	cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
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
