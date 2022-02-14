//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n; i++)     
    
    // Last i elements are already in place 
    for (j = i+1; j < n-i; j++) 
        if ((arr[i] > arr[j])&&(arr[i] & arr[j])) 
            swap(&arr[i], &arr[j]); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        ll n;
        cin >> n;
        int arr[n];
        for (int i = 0 ; i < n; i++) cin >> arr[i];
        bubbleSort(arr, n);
        bool yes = true;
        for (int i = 0;i<n-1;i++){
            if (arr[i]>arr[i+1]) yes = false;
        }
        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}