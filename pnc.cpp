#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int* generate_input(int arr[], int k) {
    for (int i = 1; i <= k; i++) {
        arr[i] = i;
    }
    return arr;
}

void perm_gen(int arr[],int k,int n)
{
    if(k==n)
    {
        for(int i=0;i<n;i++)
        {
        //    cout << arr[i] << " ";
        }
       // cout << endl;
    }
    for(int i=k;i<n;i++)
    {
        int t=arr[k];
        arr[k]=arr[i];
        arr[i]=t;

        perm_gen(arr,k+1,n);

        t=arr[k];
        arr[k]=arr[i];
        arr[i]=t;
    }
}

int main()
{
     const int maxSize = 10000;
    int arr[maxSize];

    for (int i = 1; i <= 10; i += 1)
    {
        int * a = generate_input(arr, i);
        auto start = high_resolution_clock::now();

        for (int m = 1; m <= 10; m++)
        {
            perm_gen(a,0,i);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;

        cout << "inputs \t" << i << "\t Time taken: " << duration.count() << " nanoseconds" << endl;
    }


    return 0;
}


