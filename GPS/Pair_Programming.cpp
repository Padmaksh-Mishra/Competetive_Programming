//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int k,n,m;cin >> k >> n >> m;
        int M[n];
        int P[m];
        int ans[m+n];
        int i=0,j=0;
        bool possible = true;
        for(int o=0;o<n;o++) {
            cin >> M[o];
        }
        for(int o=0;o<m;o++) {
            cin >> P[o];
        }
        for(int x=0;x<m+n;x++){
            if((M[i]==0)&&(i<n)){
                k++;
                i++;
                ans[x] = 0;
            }
            else if((P[j]==0)&&(j<m)){
                k++;
                j++;
                ans[x] = 0;
            }
            else if((M[i]<=k)&&(i<n)) {
                ans[x] = M[i];
                i++;
            }else if((P[j]<=k)&&(j<m)){
                ans[x] = P[j];
                j++;
            }else{
                possible = false;
            }
        }
        if(possible){
            for(int i=0;i<n+m;i++) cout << ans[i] << " ";
            cout << endl;
        }else cout << -1 << endl;
    }
    return 0;
}
