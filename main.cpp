/*Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. If no three numbers sum up to the target sum, the function should return an empty array*/



// C++ program to find triplets in a given
// array whose sum is zero
#include<bits/stdc++.h>
using namespace std;

// function to print triplets with 0 sum
void findTriplets(int arr[], int n, int sumOfTriplets)
{
    bool found = false;

    // sort array elements
    sort(arr, arr+n);

    for (int i=0; i<n-1; i++)
    {
        int l = i + 1;
        int r = n - 1;
        int x = arr[i];
        while (l < r)
        {
            if (x + arr[l] + arr[r] == sumOfTriplets)
            {
                // print elements if it's sum is equal to  sumOfTriplets 
                printf("%d %d %d\n", x, arr[l], arr[r]);
                l++;
                r--;
                found = true;
                  break;
            }

            // If sum of three elements is less than zero then increment in left
            else if (x + arr[l] + arr[r] < sumOfTriplets)
                l++;

            // if sum is greater than sumOfTriplets than decrement in right side
            else
                r--;
        }
    }

    if (found == false)
        cout << " []" << endl;
}

// Driven source
int main()
{
    int arr[] = {6, -1, 2, -3, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sumOfTriplets = 5;
    findTriplets(arr, n, sumOfTriplets);
    
    return 0;
}