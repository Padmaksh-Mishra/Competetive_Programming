//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S1,S2;
    cin >> S1 >> S2;
    int i = 0;
    bool ok = true;
    int size = S1.length();
    while(true) {

        int test = tolower(S1[i]);
        int check = tolower(S2[i]);
        //cout << test << " " << check << endl;
        if(test < check){
            cout << "-1";
            ok = false;
            break;
        }else if(test == check) {
            //cout << "0\n";
            
            i++;
            if(i >= size){
                break;
            }
        }else if(test > check){
            cout << "1";
            ok = false;
            break;
            }
        }
    if(ok){
        cout << "0";
        }
    
    return 0;
}