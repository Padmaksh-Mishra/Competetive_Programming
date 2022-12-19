//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;
int ans = 0;
bool solve(){
    ans = 0;
    string I,P; cin >> I >> P;
    if(P.length()<I.length()){
        return false;
    }
    int same = 0;int j  = 0;
    for(int i=0;(i<P.length())&&(j<I.length());i++){
        if(P[i]==I[j]){
            same++;
            j++;
        }
    }
    ans = P.length() - same;
    if(same==I.length()) return true;
    else return false;
        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    int p = 1;
    while(TC--){
        bool hua = solve();
        if(hua) cout << "CASE #" << p << ": " <<  ans << endl;
        else cout << "CASE #" << p << ": " << "IMPOSSIBLE" << endl;
        p++;
    }
    return 0;
}
