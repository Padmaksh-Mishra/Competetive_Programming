//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,t; cin >> n >> t;
    char students[n];
    for(int i = 0; i < n;i++){
        cin >> students[i];
    }
    for(int i = 0; i <t;i++){
        for(int j = 0; j < n-1; j++){
            if((students[j] == 'B')&&(students[j+1] == 'G')){
                swap(students[j],students[j+1]);
                j++;
            }
        }
    }
    for(int i = 0; i < n;i++){
        cout << students[i];
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        solve();
    return 0;
}
