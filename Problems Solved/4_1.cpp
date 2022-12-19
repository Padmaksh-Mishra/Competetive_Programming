#include <bits/stdc++.h>

using namespace std;

typedef struct S //defing a user defined data-type using typedef
{
    int x;
    int y;
} Op;

map<int,vector<int>> mapD;

int vectormaxium(vector<int> &array, int n); // This function gives the order of largest number in the vector

// Using counting sort to sort the elements in the basis of significant places
void sort_cnt(vector<int> &array, int size, int place);

void sort_rdx(vector<int> &array, int size);

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    vector<int> ar , copyv;
    bool check = 0 , check1 = 0;
    map<int, map<int, int>> po; // Used to store the index of element
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ar.push_back(arr[i]);
    }
    
    int max_power = vectormaxium(ar,n);
    vector <Op> v;

    int max_y = 0;

    for (int i = 0; i < m; i++)
    {
        Op info;
        cin >> info.x;
        cin >> info.y;
        if (info.y > max_y)
        {
            max_y = info.y;
        }

        if(info.y >= max_power)
        {
            check = 1;
        }

        if( info.x > n || info.x < 1 )
        {
            check1 = 1;
        }
        v.push_back(info);
    }
    
    if(check && !check1)
    {
        cout<<"There is an A[j] whose number of digits is less than or equal to Opr[j].y"<<endl;
        return 0;
    }

    if( !check && check1 ) 
    {
        cout<<"There is a (Opr[i].x>n) or (Opr[i].x<1)"<<endl;
        return 0;
    }

    if( check && check1 ) 
    {
        cout<<"There is a A[j] whose number of digits is less than or equal to Opr[j].y and There is a Opr[i].x which is more than n or less than 1"<<endl;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        if (mapD.find(v[i].y) != mapD.end())
        {
            // cout << "&" << endl;
            continue;
        }

        else
        {
            for (int j = 0; j < n; j++)
            {
                copyv.push_back(arr[j] / pow(10, v[i].y));
                if (po.find(copyv[j]) == po.end())
                {
                    po[copyv[j]][v[i].y] = j;
                }
            }

            sort_rdx(copyv, n);

            mapD[v[i].y] = copyv;
            copyv.clear();   //clear the array
        }
    }

    int output_array[n];

    for (int i = 0; i < m; i++)
    {
        output_array[i] = po[mapD[v[i].y][v[i].x - 1]][v[i].y];
    }
    cout<<"Output Array: "<<endl;
    for (int i = 0; i < m; i++)
    {
        cout << output_array[i] << " ";
    }
    cout << endl;
}

void sort_rdx(vector<int> &array, int size)
{
    int max = vectormaxium(array, size);
    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
    {
        sort_cnt(array, size, place);
    }
}

void sort_cnt(vector<int> &array, int size, int place)
{
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }

    // Calculate count of elements
    for (int i = 0; i < size; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

int vectormaxium(vector<int> &array, int n) 
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}