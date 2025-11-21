class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        unordered_set<string> uniquePalindromes;

        // Track the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        // Identify palindromic subsequences
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) {
                unordered_set<char> middleChars;
                for (int j = first[i] + 1; j < last[i]; ++j) {
                    middleChars.insert(s[j]);
                }
                for (char c : middleChars) {
                    uniquePalindromes.insert(string(1, 'a' + i) + c + string(1, 'a' + i));
                }
            }
        }

        return uniquePalindromes.size();
    }
};