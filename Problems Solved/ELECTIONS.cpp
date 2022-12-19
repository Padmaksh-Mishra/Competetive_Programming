//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT; 
    while(TT--){
        int Xa,Xb,Xc;
        cin >> Xa >> Xb >> Xc;
        if((Xa>=Xb)&&(Xa>=Xc)){
            if(Xa<=50){
                cout << "NOTA\n";
                continue;
            }
            cout << "A\n";
        }else if((Xb>=Xa)&&(Xb>=Xc)){
            if(Xb<=50){
                cout << "NOTA\n";
                continue;
            }
            cout << "B\n";
        }else if((Xc>=Xb)&&(Xc>=Xa)){
            if(Xc<=50){
                cout << "NOTA\n";
                continue;
            }
            cout << "C\n";
        }
    }
    return 0;
}