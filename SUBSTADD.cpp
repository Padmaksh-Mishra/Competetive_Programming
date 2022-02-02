//Name.Redacted PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        int N,X,Y;
        cin >> N >> X >> Y;
        int A[N],B[N];
        bool flag = true;
        for(int i = 0;i< N;i++) cin >> A[i];
        for(int i = 0;i< N;i++) cin >> B[i];
        for(int i = 0;i< N;i++){
            if((abs(A[i] - B[i])!=X)&&(abs(A[i] - B[i])!=Y)){
                flag = false;
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}