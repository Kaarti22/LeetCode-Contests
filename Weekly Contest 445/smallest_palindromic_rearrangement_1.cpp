/*
Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/?slug=find-closest-person&region=global_v2

You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.

 

Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest palindrome.

Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
s is guaranteed to be palindromic.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>m;
        for(auto it: s) m[it]++;
        int n = s.size();
        string ans(n, ' ');
        for(int i=0; i<n/2; i++){
            auto it = m.begin();
            while(it->second < 2) it++;
            ans[i] = ans[n-i-1] = it->first;
            it->second -= 2;
            if(it->second == 0) m.erase(it->first);
        }
        if(!m.empty()) ans[n/2] = m.begin()->first;
        return ans;
    }
};