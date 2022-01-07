#include <iostream>
#include <climits>
using namespace std;
 
// Function to check if string `X[i…j]` is a palindrome or not
bool isPalindrome(string X, int i, int j)
{
    while (i <= j)
    {
        if (X[i++] != X[j--]) {
            return false;
        }
    }
    return true;
}
 
// Recursive function to find the minimum cuts needed in a string
// such that each partition is a palindrome
int findMinCuts(string X, int i, int j)
{
    // base case: if starting index `i` and ending index `j` are equal,
    // or `X[i…j]` is already a palindrome.
 
    if (i == j || isPalindrome(X, i, j)) {
        return 0;
    }
 
    // stores the minimum number of cuts needed to partition `X[i…j]`
    int min = INT_MAX;
 
    // take the minimum over each possible position at which the
    // string can be cut
 
    for (int k = i; k <= j - 1; k++)
    {
        // recur to get minimum cuts required in `X[i…k]` and `X[k+1…j]`
        int count = 1 + findMinCuts(X, i, k) + findMinCuts(X, k + 1, j);
 
        if (count < min) {
            min = count;
        }
    }
 
    // return the minimum cuts required
    return min;
}
 
// Wrapper over findMinCuts() function
int findMinimumCuts(string X)
{
    int n = X.length();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    return findMinCuts(X, 0, n - 1);
}
 
int main()
{
    string X = "BABABCBADCD";       // BAB|ABCBA|DCD
 
    cout << "The minimum cuts required are " << findMinimumCuts(X);
 
    return 0;
}



#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
 
// Bottom-up DP function to mark if string `X[i…j]` is a palindrome
// or not for all possible values of `i` and `j`
bool findAllPalindromes(string X, int n, auto &isPalindrome)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j) {
                isPalindrome[i][j] = true;
            }
            else if (X[i] == X[j]) {
                isPalindrome[i][j] = ((j - i == 1) ? true: isPalindrome[i + 1][j - 1]);
            }
            else {
                isPalindrome[i][j] = false;
            }
        }
    }
}
 
// Recursive function to find the minimum cuts needed in a string
// such that each partition is a palindrome
int findMinCuts(int i, int j, auto &lookup, auto &isPalindrome)
{
    // base case: if starting index `i` and ending index `j` are equal,
    // or `X[i…j]` is already a palindrome
 
    if (i == j || isPalindrome[i][j]) {
        return 0;
    }
 
    // Construct a unique map key from dynamic elements of the input.
    // lookup[key] stores the minimum number of cuts needed to partition `X[i…j]`
 
    string key = to_string(i) + "|" + to_string(j);
 
    // if the subproblem is seen for the first time, solve it and
    // store its result in a map
 
    if (lookup.find(key) == lookup.end())
    {
        // take the minimum over each possible position at which the
        // string can be cut
 
        lookup[key] = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            // recur to get minimum cuts required in `X[i…k]` and `X[k+1…j]`
            int count = 1 + findMinCuts(i, k, lookup, isPalindrome) +
                        findMinCuts(k + 1, j, lookup, isPalindrome);
 
            if (count < lookup[key]) {
                lookup[key] = count;
            }
        }
    }
 
    // return the minimum cuts required
    return lookup[key];
}
 
int findMinimumCuts(string X)
{
    int n = X.length();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    // create a map to store solutions to subproblems
    unordered_map<string, int> lookup;
 
    // isPalindrome[i][j] stores if substring X[i][j] is palindrome or not
    vector<vector<bool>> isPalindrome(n + 1, vector<bool>(n + 1));
 
    // find all substrings of `X` that are palindromes
    findAllPalindromes(X, n, isPalindrome);
 
    return findMinCuts(0, n - 1, lookup, isPalindrome);
}
 
int main()
{
    string X = "BABABCBADCD";
 
    cout << "The minimum cuts required are " << findMinimumCuts(X);
 
    return 0;
}




#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
// Bottom-up DP function to mark if string `X[i…j]` is a palindrome
// or not for all possible values of `i` and `j`
bool findAllPalindromes(string X, auto &isPalindrome)
{
    int n = X.length();
 
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j) {
                isPalindrome[i][j] = true;
            }
            else if (X[i] == X[j]) {
                isPalindrome[i][j] = ((j - i == 1) ? true: isPalindrome[i + 1][j - 1]);
            }
            else {
                isPalindrome[i][j] = false;
            }
        }
    }
}
 
// Iterative function to find the minimum cuts needed in a string
// such that each partition is a palindrome
int findMinCuts(string X, auto &isPalindrome)
{
    int n = X.length();
 
    // create a lookup table to store solutions to subproblems
    // `lookup[i]` stores the minimum cuts needed in substring `X[i…n)`
 
    int lookup[n];
 
    // start from the string's end
    for (int i = n - 1; i >= 0; i--)
    {
        lookup[i] = INT_MAX;
 
        // if `X[i…n-1]` is a palindrome, the total cuts needed is 0
        if (isPalindrome[i][n-1]) {
            lookup[i] = 0;
        }
        else {
            // otherwise, find lookup[i]
            for (int j = n - 2; j >= i; j--)
            {
                if (isPalindrome[i][j]) {
                    lookup[i] = min(lookup[i], 1 + lookup[j + 1]);
                }
            }
        }
    }
 
    return lookup[0];
}
 
// Wrapper over findMinCuts() function
int findMinimumCuts(string X)
{
    int n = X.length();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    // isPalindrome[i][j] stores if substring X[i][j] is palindrome or not
    vector<vector<bool>> isPalindrome(n + 1, vector<bool>(n + 1));
 
    // find all substrings of `X` that are palindromes
    findAllPalindromes(X, isPalindrome);
 
    return findMinCuts(X, isPalindrome);
}
 
int main()
{
    string X = "BABABCBADCEDE";     // BAB|ABCBA|D|C|EDE
 
    cout << "The minimum cuts required are " << findMinimumCuts(X);
 
    return 0;
}