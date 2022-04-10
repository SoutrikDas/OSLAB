#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (i = 0; i < n; i++)

class block
{
public:
    int size = -1;
    string nam;
    int psize;
    int IF;
    bool isEmpty = true;
    block()
    {
        size = -1;
    }
    block(int s)
    {
        size = s;
    }
};

void worst_fit(block *arr, int n, int process, int ind)
{
    int i = 0;
    int ex = 0;
    int low = 9999999, ptr = -1;
    int temp = 0;
    FOR(i, n)
    {
        if (arr[i].isEmpty && arr[i].size >= process)
        {
            temp = arr[i].size - process;
            if (temp < low)
            {
                ptr = i;
                low = temp;
            }
        }
    }
    if (ptr != -1)
    {
        // means there is a match hence it will be assigned
        arr[ptr].isEmpty = false;
        arr[ptr].psize = process;
        arr[ptr].IF = arr[ptr].size - process;
        cout << "P" << ind << " size:" << process << " is being assigned to  block " << ptr<<" (size="<<arr[ptr].size<<") with IF=" << arr[ptr].IF << endl;
        return;
    }
    // if not assigned 
    FOR(i, n)
    {
        if (arr[i].isEmpty)
        {
            ex += arr[i].size;
        }
        else
        {
            ex += arr[i].IF;
        }
    }
    cout << "P" << ind << " size:" << process << " was not assigned to any of the blocks, EF=" << ex << endl;
}

int main()
{
    int n, s;
    cout << "Enter no. of blocks \n";
    cin >> n;
    int i = 0, j = 0, temp = 0, c = 0;
    int m;
    block arr[100];
    int process[100];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i].size;
    }

    cout << "Enter no. of process \n";
    cin >> m;
    FOR(i, m)
        cin >> process[i];

    FOR(i, m)
    {
        worst_fit(arr, n, process[i], i);
    }
}