# include <bits/stdc++.h>
# define f first
# define s second

using namespace std;
int lcs[3002][3002];
int main(){
	string s,t; cin >> s >> t;
	int n = s.size();
	int m = t.size();
	// int lcs[n+1][m+1];
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i==0||j==0){
				lcs[i][j]=0;
			}
			else if(s[i-1]==t[j-1]){
				lcs[i][j]=lcs[i-1][j-1]+1;
			}
			else{
				lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
			}
		}
	}
	int j=m;
	string ans = "";
	for(int i=n;i>0;--i){
		if(lcs[i][j]==lcs[i-1][j]){
			continue;
		}else{
			ans+=s[i-1];
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}