class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Determine which substring to prioritize based on points
        // We want to remove the higher-scoring substring first
        if (x >= y) {
            // Remove "ab" first (x points), then "ba" (y points)
            return removeSubstring(s, "ab", x, "ba", y);
        } else {
            // Remove "ba" first (y points), then "ab" (x points)
            return removeSubstring(s, "ba", y, "ab", x);
        }
    }
    
private:
    // Helper function to remove two types of substrings in priority order
    int removeSubstring(string s, string first, int firstPoints, string second, int secondPoints) {
        int totalScore = 0;
        
        // First pass: remove all instances of the first (higher-scoring) substring
        string afterFirst = removeAndCount(s, first, firstPoints, totalScore);
        
        // Second pass: remove all instances of the second substring from remaining string
        removeAndCount(afterFirst, second, secondPoints, totalScore);
        
        return totalScore;
    }
    
    // Function to remove all instances of a target substring and count the score
    string removeAndCount(string s, string target, int points, int& score) {
        string result = "";
        
        // Process each character in the string
        for (char c : s) {
            result += c;  // Add current character to result
            
            // Check if we can form the target substring at the end of result
            if (result.length() >= 2) {
                // Get the last two characters
                string lastTwo = result.substr(result.length() - 2, 2);
                
                // If last two characters match our target substring
                if (lastTwo == target) {
                    // Remove the target substring (pop last 2 characters)
                    result.pop_back();  // Remove last character
                    result.pop_back();  // Remove second-to-last character
                    
                    // Add points to our score
                    score += points;
                }
            }
        }
        
        return result;  // Return the string after removing all target substrings
    }
};