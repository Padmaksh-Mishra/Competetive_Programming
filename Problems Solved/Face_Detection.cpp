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

    int n,m; cin >> n >> m ;
    char imj[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> imj[i][j];
        }
    }
    set<char> face = {'f','a','c','e'};
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            set<char> face2;
            //cout << imj[i][j] << " " << imj[i+1][j] << " " << imj[i][j+1] << " " << imj[i+1][j+1]<< endl;
            face2.insert(imj[i][j]);
            face2.insert(imj[i+1][j]);
            face2.insert(imj[i][j+1]);
            face2.insert(imj[i+1][j+1]);
            if(face==face2){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
