// # include <bits/stdc++.h>
// # define endl '\n'
// # define deb(x) cout << #x << " = " << x << endl
// # define ll long long
// # define pb push_back
// # define f first
// # define s second
// # define siz(x) (int)(x).size()
// # define vll vector<ll>
// # define all(x) (x).begin(), (x).end()

// using namespace std;

// const ll MOD = 1e9 +7;
// const int N = 1e5 + 1;

// void setIO(string name) {  
// #ifndef ONLINE_JUDGE
//     if((int)name.size() > 0){
//         freopen((name+".in").c_str(), "r", stdin);
//         freopen((name+".out").c_str(), "w", stdout);
//     }
// #endif
// }

// void solve();

// int main(){
// 	ios_base::sync_with_stdio(false); 
// 	cin.tie(NULL); 
// 	cout.tie(NULL);
//     setIO("sublime");    //Does not work with Google     
//     ll TC = 1;
//     cin >> TC;
//     for(int i=0;i<TC;++i){
//         //cout << "Case #" << i+1 << ": ";
//         solve();
//     }
//     return 0;
// }

// // Do something good 

// void solve(){
// 	ll n,k; cin >> n >> k;
// 	vll a(n);
// 	map<ll,ll> m;
// 	for(int i=0;i<n;++i){
// 		cin >> a[i];
// 		m[a[i]]++;
// 	}   
// 	vll tmp;
// 	ll maxl = -1;
// 	for(auto it=m.begin();it!=m.end();++it){
// 		if((*it).s>=k){
// 			tmp.pb((*it).f);
// 		}
// 	}
// 	ll l=0,r=0;
// 	ll mal,mar;
// 	ll mad=-1;
// 	if(siz(tmp)!=0) l=tmp[0];
// 	for(int i=1;i<siz(tmp);++i){
// 		if(tmp[i]-tmp[i-1]==1){
// 			r=tmp[i];
// 		}else{
// 			l=tmp[i];
// 		}
// 		if(r-l>mad){
// 			mar=r;
// 			mal=l;
// 			mad = r-l;
// 		}
// 	}
// 	if(siz(tmp)==0){
// 		cout << mad << endl;
// 	}else if(mad==-1) cout << tmp[0] << " " << tmp[0] << endl;
// 	else cout << mal << " " << mar << endl;
// }
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
	ll n,k; cin >> n >> k;
	vll a(n);
	map<ll,ll> m;
	for(int i=0;i<n;++i){
		cin >> a[i];
		m[a[i]]++;
	}   
	pair<ll,ll> ans = {-1,-1};
	vll tmp;
	ll maxl = -1;
	for(auto it=m.begin();it!=m.end();++it){
		if((*it).s>=k){
			tmp.pb((*it).f);
		}
	}
	ll l=0,r=0;
	for(int i=1;i<siz(tmp);++i){
		if(tmp[i]-tmp[i-1]==1){
			if(l==-1) l=i-1;
			if(i-l>maxl){
				ans = make_pair(tmp[l],tmp[i]);
				maxl = i-l;
			}
		}else{
			l=-1;
		}
	}
	if(siz(tmp)==0) {
		cout << -1 << endl;
		return;
	}else if(maxl==-1) cout << tmp[0] << " " << tmp[0] << endl;
	else cout << ans.f << " " << ans.s << endl;
}
