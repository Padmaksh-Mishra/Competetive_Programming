//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
const int siz = 1e5;
using namespace std;

ll games[siz];
ll hsh[siz];
ll p[siz],inv[siz];
int n;

int bexpo(int n,int p);
void pows();
ll hashed(string const &s);
void bigHash(string const &s,int n);
ll check(int b,int k);

void solve(){
	int k; cin >> n >> k;    
	string cd; cin >> cd;
	cd = cd + cd;
	//deb(cd);
	int g; cin >> g;
	for(int i = 0;i<g;i++){
		string tmp; cin >> tmp;
		games[i] = hashed(tmp);
		//deb(games[i]);
	}
	vector<int> kaam;
	bigHash(cd,(n+k)*k);
	//sort(games,games+g);

	for(int i = 0 ;i<(n+k)*k;i++){
		ll tmp = check(i,k);
		//deb(tmp);
		for(int j = 0;j<g;j++){
			if(tmp==games[j]){
				//deb(j);
				
				kaam.push_back(j+1);
				//if(kaam.size()==n) break;
			}
		}
	}
	if(kaam.size()<n){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		for(int i  = 0 ;i< n;i++) cout << kaam[i] << " ";
			cout << endl;
	}

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything
    pows();
    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}

void pows(){
	p[0] = 1;
	inv[0] = bexpo(p[0],MOD-2);
	for(int i=1;i<siz;i++) {
		p[i] = (p[i-1]*1LL*31)%MOD;
		inv[i] = bexpo(p[i],MOD-2);
	}
}

ll hashed(string const &s){
	ll ans = 0;
	int l = s.length();
	for(int i = 0;i<l;i++) ans = (ans + ((s[i]-'a'+1)*p[i])%MOD)%MOD;
	return ans;
}

void bigHash(string const &s,int n){
	hsh[0] = 0;
	for(int i=1;i<=n;i++){
		hsh[i]=(hsh[i-1] + ((s[i-1]-'a'+1)*p[i-1])%MOD)%MOD;
	}
}

ll check(int b,int k){
	ll invv  = inv[b];
	ll tmp;
	// if(b==n){ 
	// 	cout << "FK" << endl;
	// 	tmp = ((((hsh[n]  - hsh[n-] + MOD)%MOD)*invv)%MOD);
	// }
	// else 
		tmp = ((((hsh[b+k]  - hsh[b] + MOD)%MOD)*invv)%MOD);
	return tmp;

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
