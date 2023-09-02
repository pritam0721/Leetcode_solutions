// You are given a 0-indexed string s and a dictionary of words dictionary.
//  You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. 
//  There may be some extra characters in s which are not present in any of the substrings.
// Return the minimum number of extra characters left over if you break up s optimally.

 

// Example 1:

// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output: 1
// Explanation: We can break s in two substrings: 
// "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
         int n = s.length();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (const string& word : dictionary) {
            int len = word.length();
            if (i >= len && s.substr(i - len, len) == word) {
                dp[i] = min(dp[i], dp[i - len]);
            }
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    return dp[n];
    }
};