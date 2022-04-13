//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,m; cin >> n >> m ;
    int task[m];
    ll time = 0;
    int presentHouse = 1;
    for(int i=0;i<m;i++){
        cin >> task[i];
        time = time + (n+task[i] - presentHouse)%n;
        presentHouse = task[i]; 
    }
    cout << time << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        solve();
    return 0;
}
