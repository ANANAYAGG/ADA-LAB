#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
int* generate_input(int arr[], int k) {
    for (int j = 0; j < k; j++) {
        arr[j] = rand();
    }
    return arr;
}

void maxmin(int low, int high, int arr[], int* max, int* min) {
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    int max1, min1, max2, min2;
    maxmin(low, mid, arr, &max1, &min1);
    maxmin(mid + 1, high, arr, &max2, &min2);

    if(max1>max2)
    {
        *max=max1;
    }
    else
    {
        *max=max2;
    }
    if(min1<min2)
    {
        *min=min1;
    }
    else
    {
        *min=min2;
    }
}

int main() {
  int* arr = new int[100000];
   int max, min;
    for (int i = 1000; i <= 10000; i += 1000) {
        arr = generate_input(arr, i);
        auto start = high_resolution_clock::now();
        for (int m = 1; m < 10; m++) {
           maxmin(0, i - 1, arr, &max, &min);
           /* for (int j = 0; j < i; j++) {
                cout << arr[j] << " ";
            }*/
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "inputs \t" << i << "\t Time taken: " << duration.count() << "nanoseconds" << endl;
    }
    return 0;
}

