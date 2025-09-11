
class Solution {
public:
    std::string sortVowels(std::string s) {
        std::vector<char> vowels;
        std::string result = s;

        // Step 1: Extract all vowels while preserving their original case
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Step 2: Sort the extracted vowels based on their ASCII value
        std::sort(vowels.begin(), vowels.end());

        // Step 3: Replace the vowels in the original string with the sorted ones
        int vowel_idx = 0;
        for (int i = 0; i < result.length(); ++i) {
            if (isVowel(result[i])) {
                result[i] = vowels[vowel_idx++];
            }
        }

        return result;
    }

private:
    bool isVowel(char c) {
        c = std::tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
