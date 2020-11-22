// Given a string str, its sub-strings are formed in such a way that all the sub-strings starting with the first character of the string will occur first in the sorted order of their lengths followed by all the sub-strings starting with the second character of the string in the sorted order of their lengths and so on.
// For example for the string abc, its sub-strings in the required order are a, ab, abc, b, bc and c.
// Now given an integer k, the task is to find the kth sub-string in the required order.

// Examples:

// Input: str = abc, k = 4
// Output: b
// The required order is “a”, “ab”, “abc”, “b”, “bc” and “c”

// Input: str = abc, k = 9
// Output: -1
// Only 6 sub-strings are possible.

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to prints kth sub-string
void Printksubstring(string str, int n, int k)
{
    // Total sub-strings possible
    int total = (n * (n + 1)) / 2;

    // If k is greater than total
    // number of sub-strings
    if (k > total)
    {
        printf("-1\n");
        return;
    }

    // To store number of sub-strings starting
    // with ith character of the string
    int substring[n + 1];
    substring[0] = 0;

    // Compute the values
    int temp = n;
    for (int i = 1; i <= n; i++)
    {
        // substring[i - 1] is added
        // to store the cumulative sum
        substring[i] = substring[i - 1] + temp;
        temp--;
    }

    // Binary search to find the starting index
    // of the kth sub-string
    int l = 1;
    int h = n;
    int start = 0;

    while (l <= h)
    {
        int m = (l + h) / 2;

        if (substring[m] > k)
        {
            start = m;
            h = m - 1;
        }

        else if (substring[m] < k)
            l = m + 1;

        else
        {
            start = m;
            break;
        }
    }

    // To store the ending index of
    // the kth sub-string
    int end = n - (substring[start] - k); // kitne extra aye hue h

    // Print the sub-string
    for (int i = start - 1; i < end; i++)
        cout << str[i];
}

int main()
{
    string str;
    int k;
    cin >> str >> k;
    int n = str.length();
    Printksubstring(str, n, k);
    return 0;
}
