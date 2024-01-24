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


void selection(int a[],int n)
{
    for(int i=0;i<n;i++ ){ 
        int j=i;
        for(int k=i+1;k<n;k++){
            if(a[j]<a[k]){
                j=k;
            }
        }

        int temp=a[i];//swapping i and j
        a[i]=a[j];
        a[j] = temp;

    }
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

