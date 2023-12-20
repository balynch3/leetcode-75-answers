// Merge Strings Alternatively
class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int sharedCharIndex = 0;

        string outputString = "";

        while (
                sharedCharIndex < word1.length() &&
                sharedCharIndex < word2.length()) {

            outputString += word1.at(sharedCharIndex);
            outputString += word2.at(sharedCharIndex);
            sharedCharIndex++;
        }
        // After this point, sharedCharIndex equals one of the two lengths
        // This is for if word 1 is the larger one
        if (sharedCharIndex < word1.length()) {
            outputString.append(word1.substr(sharedCharIndex));
            // This is for is word 2 is the larger one
        } else if (sharedCharIndex < word2.length()) {
            outputString.append(word2.substr(sharedCharIndex));
        }

        return outputString;
    }
};