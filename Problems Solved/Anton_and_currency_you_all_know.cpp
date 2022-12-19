# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long ll;
string n;

void solve(){
	cin >> n;
	int bigevn = -1;
	for(int i = 0;i<n.length();i++){
		int tmp = n[i] - 48;
		if(tmp%2==0){
			if(bigevn==-1) bigevn = i;
			if(n[bigevn]<n[n.length()-1]) continue;
			bigevn = i;
		}
	}
	if(bigevn==-1){
		cout << bigevn << endl;
	}else{
		swap(n[bigevn],n[n.length()-1]);
		cout << n << endl;
	}
	
}

int main(){
	solve();
	return 0;
}