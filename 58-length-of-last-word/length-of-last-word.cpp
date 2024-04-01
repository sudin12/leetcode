class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool foundWord = false;

        // Iterate through the string in reverse
        for (int i = s.length() - 1; i >= 0; i--) {
            // If a non-space character is found, start counting the length of the last word
            if (s[i] != ' ') {
                foundWord = true;
                length++;
            } else {
                // If a space is found and we've already counted a word, we've reached the end of the last word
                if (foundWord) {
                    break;
                }
            }
        }

        return length;
    }
};