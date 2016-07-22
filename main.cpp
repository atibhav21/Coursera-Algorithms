//
//  main.cpp
//  algorithms
//
//  Created by Atibhav Mittal on 7/22/16.
//  Copyright © 2016 Ati. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int countSplitInversions(int arr[], int N)
{
    vector<int> result;
    int leftIndex = 0;
    int rightIndex = N/2;
    int count = 0;
    while(leftIndex < N/2 && rightIndex < N)
    {
        if(arr[leftIndex] < arr[rightIndex])
        {
            // no inversion, so copy element and increment count
            result.push_back( arr[leftIndex]);
            leftIndex++;
        }
        else
        {
            // no equal elements as described in problem, so left element > right element, i.e. inversion found
            result.push_back(arr[rightIndex]);
            count += (N/2) - leftIndex;
            rightIndex++;
        }
    }
    while (leftIndex < N/2)
    {
        result.push_back(arr[leftIndex]);
        leftIndex++;
    }
    while(rightIndex < N)
    {
        // copy remaining elements in right half
        result.push_back(arr[rightIndex]);
        rightIndex++;
    }
    for(int i = 0; i< N; i++)
    {
        arr[i] = result[i];
    }
    return count;
}

long long int countInversions(int arr[], int N)
{
    if(N <= 1)
    {
        return 0;
    }
    long long int countLeft = countInversions(arr, N/2);
    long long int countRight = countInversions(arr+ N/2, (N - N/2));
    long long int countSplit = countSplitInversions(arr, N);
    assert(countLeft >= 0);
    assert(countRight >= 0);
    assert(countSplit >= 0);
    return (countLeft + countRight + countSplit);
    
}

int main()
{
    const int n = 100000;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long long int x = countInversions(arr, n);
    cout<< x;
    
    
}
