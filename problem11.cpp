// Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // sIndex stores position we are comparing from within the substring.
        // We increment this only when we find a match so we can match the next letter.
        int sIndex = 0;
        for (int tIndex = 0; tIndex < t.length(); tIndex++) {
            // If we reach the end of s, then we have matched all of its letters
            if (sIndex >= s.length()) {
                return true;
            }
            // When we find a match, increment sIndex to prepare to match the next letter
            if (s.at(sIndex) == t.at(tIndex)) {
                sIndex++;
            }
        }
        return sIndex >= s.length();
    }
};