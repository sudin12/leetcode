class Solution {
public:
    std::string makeGood(string s) {
        int endPosition = 0; 
        char charArray[s.size()]; 
        
        // Convert the string to a character array
        for (int i = 0; i < s.size(); ++i) {
            charArray[i] = s[i];
        }

        // Loop through each character in the string
        for (int currentPosition = 0; currentPosition < s.size(); currentPosition++) {
            // Check if the current character can be removed
            if (endPosition > 0 && abs(charArray[currentPosition] - charArray[endPosition - 1]) == 32)
                endPosition--; 
            else {
                charArray[endPosition] = charArray[currentPosition];
                endPosition++;
            }
        }

        return string(charArray, charArray + endPosition);
    }
};