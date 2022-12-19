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

    int n,k; cin >> n >> k;
    int count = 0,point = 0;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        while(tmp){
            if((tmp%10==4)||(tmp%10==7)) count++;
            tmp /= 10;
        }
        if(count<=k) point++;
        count = 0;
    }
    cout<< point << endl;
    return 0;
}
