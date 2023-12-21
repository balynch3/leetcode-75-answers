// String Compression
class Solution {
public:
    int compress(vector<char>& chars) {
        // The char we last saw in the list. Used to see if the char has changed
        char lastSeenChar = chars[0];
        // Number of times we have seen the last seen char.
        int charOccurences = 0;
        // Index we are writing to in the list
        int writeIndex = 0;
        // We write to the write index, and read from the read index.
        for (int readIndex = 0; readIndex < chars.size(); readIndex++) {
            // If the character is changed, we write the content to the list (char, # times)
            if (lastSeenChar != chars[readIndex]) {
                chars[writeIndex] = lastSeenChar;
                lastSeenChar = chars[readIndex];
                writeIndex++;
                if (charOccurences > 1) {
                    string charOccurencesString = to_string(charOccurences);
                    for (int placeValue = 0; placeValue < charOccurencesString.length(); placeValue++) {
                        chars[writeIndex] = charOccurencesString[placeValue];
                        writeIndex++;
                    }
                }
                charOccurences = 1;
            } else {
                charOccurences++;
            }
            cout << writeIndex << endl;
        }
        chars[writeIndex] = lastSeenChar;
        writeIndex++;
        if (charOccurences > 1) {
            string charOccurencesString = to_string(charOccurences);
            for (int placeValue = 0; placeValue < charOccurencesString.length(); placeValue++) {
                chars[writeIndex] = charOccurencesString[placeValue];
                writeIndex++;
            }
        }
        chars.resize(writeIndex);
        return chars.size();
    }
};