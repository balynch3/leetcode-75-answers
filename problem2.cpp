// Greatest Common Divisor of Strings
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int str1Length = str1.length(), str2Length = str2.length();
        // This should be the length of the shared substring
        int gcdLength = gcd(str1Length, str2Length);
        // The actual substring
        string substring = str1.substr(0,gcdLength);
        if (gcdLength == 0) {
            return "";
        }

        for (int innerWordIndex = 0; innerWordIndex < str1Length; innerWordIndex += gcdLength) {
            if (str1.substr(innerWordIndex, gcdLength) != substring) {
                return "";
            }
        }
        for (int innerWordIndex = 0; innerWordIndex < str2Length; innerWordIndex += gcdLength) {
            if (str2.substr(innerWordIndex, gcdLength) != substring) {
                return "";
            }
        }
        return substring;
    }
};