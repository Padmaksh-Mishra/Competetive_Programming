// Coding_Duck PM

#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> V;
void addingNos()
{
    //cout << "Adding nos..." << endl;
    
    for (int i = 1; i <= 1000; i++)
    
    {
        bool added = true;
        int temp = i;
        while (temp > 0)
        {
            if ((temp % 10 != 4) && (temp % 10 != 7))
            {
                //cout << temp << " ";
                added = false;
                break;
            }
            //cout << endl;
            temp = temp / 10;
        }
        //cout << added << endl;
        if (added)
        {
            V.push_back(i);
            //cout << i << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    addingNos();
    int n;
    bool flag = false;
    cin >> n;
    for(auto val : V){
        if(n%val == 0){
            flag = true;
        }
    }
    if(flag){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    
    return 0;
}