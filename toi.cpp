#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n >= 1) {
    towerOfHanoi(n - 1, source, destination, auxiliary);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}
}

int main() {
    int *arr = new int[10000];  // Dynamic array

    for (int i = 15; i <= 30; i += 1) {
        auto start = high_resolution_clock::now();  // Time count

        for (int m = 1; m <= 10; m++) {
            towerOfHanoi(i, 'A', 'B', 'C');  
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
       // cout << i << endl;
      cout << duration.count() << endl;
    }
    return 0;
}