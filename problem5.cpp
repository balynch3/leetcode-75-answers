// Reverse Vowels of a String
class Solution {
public:
    bool isVowel(char letter) {
        return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o'
                || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I'
                || letter == 'O' || letter == 'U');
    }

    string reverseVowels(string s) {
        // We go forwards and backwards in the string swapping the vowels we see.
        // We move backwards/forwards until we get to a vowel, where we then stop.
        // If forward and backwards both see a vowel, then we swap them and move both on.
        // If forward equals backwards (or move past each other), then we stop.
        int startIndex = 0;
        int endIndex = s.length()-1;

        while (startIndex < endIndex) {
            if (!isVowel(s[startIndex])) {
                startIndex++;
            }
            if (!isVowel(s[endIndex])) {
                endIndex--;
            }
            if (isVowel(s[startIndex]) && isVowel(s[endIndex])) {
                char temp = s[startIndex];
                s[startIndex] = s[endIndex];
                s[endIndex] = temp;
                startIndex++;
                endIndex--;
            }
        }
        return s;
    }
};