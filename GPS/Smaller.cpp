//ICPC
# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll q; cin >> q;
	bool fine = false;
	ll lt,ls;lt=ls=1;
	ll na=1;
	while(q>0){
		ll d,k; cin >> d >> k;
		string s; cin >> s;
			if(d==2){
				for(int i=0;i<siz(s);++i){
					if(s[i]!='a'){
						fine = true;
					}else lt+=k;
				}
			}else{
				for(int i=0;i<siz(s);++i){
					if(s[i]=='a'){
						na+=k;
					}
					ls+=k;
				}
				// deb(lt);
				// deb(na);
			}
			if((lt>na&&ls==na)||fine){
				cout << "YES" << endl;
			}else cout << "NO" << endl;
			q--;
	}    
}
