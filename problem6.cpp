// Reverse Words in String

#include <regex>

class Solution {
public:
    string trimString(string s) {
        int stringStart = s.find_first_not_of(' ');
        int stringEnd = s.find_last_not_of(' ');
        int stringLen = stringEnd - stringStart + 1;
        return s.substr(stringStart, stringLen);
    }

    string reduceSpaces(string s) {
        return std::regex_replace(s, std::regex("\\s+"), " ");
    }

    string reverseWords(string s) {
        s = trimString(s);
        s = reduceSpaces(s);

        int currentIndex = 0;
        string output = "";
        // Going backwards through the string, get each substring after a
        while ((currentIndex = s.find_last_of(' ')) != string::npos) {
            if (output.length() > 0) {
                output.append(" ");
            }
            output.append(s.substr(currentIndex+1));
            s.erase(currentIndex, s.length());
        }
        // We have to deal with the last word too
        if (output.length() > 0) {
            output.append(" ");
        }
        output.append(s);
        return output;
    }
};