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
    stack<int> shelf; 
    while(TT--){
        int a;
        cin >> a;
        if(a<0){
            if(shelf.empty()){
                cout << "kuchbhi?\n";
            }else{
                int temp = shelf.top();
                shelf.pop();
                cout << temp << "\n";
            }
        }else{
            int N;
            cin >> N;
            shelf.push(N);
        }
    }
    return 0;
}