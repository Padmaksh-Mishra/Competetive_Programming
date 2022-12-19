# include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT;
    while(TT--){
        int N;
        cin >> N;
        int f[N+1],A[N];
        for(int i = 0; i < N;i++){
            cin >> A[i];
        }
        f[0] = 0;
        f[1] = 1;
        for(int i = 1 ; i < N ; i++){
            if(A[i]>=A[i-1]){
                f[i+1] = f[i] + 1 + 1;
            }else{
                f[i+1] = f[i] + 1;
            }
        }
        cout << f[N] << "\n";
    }
    return 0;
}