// Coding_Duck PM

#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int a = 5, b = 55;
    // cout << a << " " << b << endl;
    // swap(a, b);
    // cout << a << " " << b << endl;
    int TC;
    cin >> TC;
    while (TC--)
    {
        int n, maxi, mini;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }
        for (int i = 0; i < n; i++)
        {
            if(A[i] < B[i]){
                swap(A[i], B[i]);
            }
        }
        //cout << "--------------------------------------\n";
        maxi = A[0];
        mini = B[0];
        for (auto val : A){
            //cout << val << " ";
            maxi = max(val,maxi);
        }
        //cout << "\n";
        for (auto val : B){
            //cout << val << " ";
            mini = max(val,mini);
        }
        //cout << endl;
        cout << maxi*mini << endl;
    }
    return 0;
    }