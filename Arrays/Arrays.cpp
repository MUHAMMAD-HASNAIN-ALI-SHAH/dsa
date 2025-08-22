#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// kadans method
// time complexity n
void maxSubArraySum2(int *arr, int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int start = 0; start < n; start++)
    {
        currSum += arr[start];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "Maximum sub array sum " << maxSum;
}

// optimized approach
// time complexity n square
void maxSubArraySum1(int *arr, int n)
{
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++)
    {
        int currSum = 0;
        for (int end = start; end < n; end++)
        {

            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Maximum sub array sum " << maxSum;
}

// simple approach
// time complexity n cube
void maxSubArraySum(int *arr, int n)
{
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int currSum = 0;
            for (int i = start; i <= end; i++)
            {
                currSum += arr[i];
            }
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Maximum sub array sum " << maxSum;
}

// time complexity n cube
void printSubArrays(int *arr, int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            // cout << "(" << start << "," << end << ")  ";
            for (int i = start; i <= end; i++)
            {
                cout << arr[i];
            }
            cout << ",";
        }
        cout << endl;
    }
}

void maxProfit(int *prices, int n)
{
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i - 1], prices[i - 1]);
    }
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    cout<<"Max profit : "<<maxProfit<<endl;
}

int main()
{
    int arr[6] = {7, 1, 5, 3, 6, 4};
    int n = 6;
    maxProfit(arr, n);
}