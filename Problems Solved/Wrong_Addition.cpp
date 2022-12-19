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
	ll a,s; cin >> a >> s;
	vll b;
	while(s>0){
		ll tmp = -1;
		if((a%10)>(s%10)){
			tmp = (s%100)-(a%10) ;
			s/=100;
		}else{
			tmp = (s%10) - (a%10) ;
			s/=10;
		}
		if(tmp>9||tmp<0){
			cout << -1 << endl;
			return;
		}
		b.emplace_back(tmp);
		a/=10;
	}    
	if(a) cout << -1 << endl;
	else{
		reverse(all(b));
		ll i=0;
		while(b[i]==0) i++;
		for(int j=i;j<siz(b);++j) cout << b[j];
		cout << endl;
	}
}
