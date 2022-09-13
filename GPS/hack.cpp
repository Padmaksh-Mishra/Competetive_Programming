#include<bits/stdc++.h>
#define fi first
#define se second
#define MP make_pair
//#define int long long
using namespace std;
typedef pair <int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unsigned long long int ull;
typedef long long LL;
const int N=3e5+1;
const int MOD=1e9+7;
//priority_queue < pii, vector<pii>, greater<pii>> pq;

string str = "#Timur";
vector<string> ans;

int n, a[1000],chuaxet[1000];

void in(){
    // for(int j = 1; j<=n ; j++) {
    //     cout << a[j]<< " ";
    // }
    // cout << endl;
    string ss = "";
    for(int j = 1; j<=n ; j++) {
        ss += str[a[j]];
    }
    // cout << ss << endl;
    ans.push_back(ss);
}

void Try(int i){
    for(int j = 1; j<=n;j++){
        if(chuaxet[j] == 0){
            a[i] = j;
            chuaxet[j] = 1;
            if(i == n){
                in();
            }
            else{
                Try(i+1);
            }
            chuaxet[j] = 0;
        }
    }
    return;
}

int x[N];
void solve(){
    n = 5;
    int k;
    cin >> k;
    string s;
    cin >> s;
    Try(1);
    // cout << "hung" <<endl;
    for(auto x : ans){
        if(x == s){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;


}
main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
