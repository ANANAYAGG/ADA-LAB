#include<iostream>
#include <cstdlib>
#include<chrono>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int * generate(int a[],int i)
{
    for(int k=1;k<=i;k++)
    {
        a[k]=rand();
    }
    return a;
}

int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];

    }
    return sum;
}



int main()
{
    int *a = new int(100000);
    for(int i=10000;i<=100000 ;i=i+1000)
    {
    a = generate(a,i);

    auto begin = high_resolution_clock::now();



    for(int p =1;p<=10;p++)
    {
        sum(a,i);
    }
    auto end = high_resolution_clock::now();
    auto timetaken = (duration_cast<nanoseconds>(end-begin))/10;
    cout << "inputs    " << i    << "     Time taken    " << timetaken.count() << " nanoseconds   " << endl ;

    }

return 0;
}
