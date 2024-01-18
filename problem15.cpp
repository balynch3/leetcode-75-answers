// Maximum Number of Vowels in a Substring of Given Length
class Solution {
public:
    bool isVowel(char x) {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }
    int maxVowels(string s, int k) {
        // Maximum Average Subarray I
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += (int) isVowel(s.at(i));
        }
        int largestSum = windowSum;
        for (int i = k; i < s.length(); i++) {
            windowSum -= (int) isVowel(s.at(i-k));
            windowSum += (int) isVowel(s.at(i));
            largestSum = max(largestSum, windowSum);
        }
        return largestSum;
    }
};