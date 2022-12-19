//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const int END = 1e6;
using namespace std;

void solve(){
    map<int,vector<int>> inks;
    int tmp;
    for(int i=0; i < 3; i++){
        cin >> tmp;
        inks[1].push_back(tmp);
        
        cin >> tmp;
        inks[2].push_back(tmp);
        
        cin >> tmp;
        inks[3].push_back(tmp);
        
        cin >> tmp;
        inks[4].push_back(tmp);
        
    }
    int cryan = *min_element(inks[1].begin(),inks[1].end());
    int meg = *min_element(inks[2].begin(),inks[2].end());
    meg = min(meg,END-cryan);
    int yello = *min_element(inks[3].begin(),inks[3].end());
    yello = min(yello,END-cryan-meg);
    int Kivi = *min_element(inks[4].begin(),inks[4].end());
    Kivi = min(Kivi,END-cryan-meg-yello);
    int inksum = cryan + Kivi + meg + yello;
    //deb(inksum);
    if(inksum<END) cout << "IMPOSSIBLE" << endl;
    else {
        cout << cryan << " " << meg << " " << yello << " " << Kivi << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC = 1;
    cin >> TC;
    ll x = 0;
    while(TC--){
        x++;
        cout << "Case #" << x << ": ";
        solve();
    }
    return 0;
}
