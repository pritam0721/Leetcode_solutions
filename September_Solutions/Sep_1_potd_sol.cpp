// QESTION : ->
// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
#include<bits/stdc++.h>
using namespace std;

// output 
class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> ans(n + 1);
    
    for (int i = 0; i <= n; ++i) {
        int count = 0;
        int num = i;
        
        while (num > 0) {
            if (num % 2 == 1) {
                count++;
            }
            num /= 2;
        }
        
        ans[i] = count;
    }
    
    return ans;
    }
};