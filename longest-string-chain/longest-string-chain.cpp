
class Solution {
    
private:

    int dfs(unordered_set<string> &words, unordered_map<string, int> &memo, string currentWord) {
        // If the word is encountered previously we just return its value present in the map (memoization).
        if (memo.find(currentWord) != memo.end()) {
            return memo[currentWord];
        }
        // This stores the maximum length of word sequence possible with the 'currentWord' as the
        int maxLength = 1;

        // creating all possible strings taking out one character at a time from the `currentWord`
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            // If the new word formed is present in the list, we do a dfs search with this newWord.
            if (words.find(newWord) != words.end()) {
                int currentLength = 1 + dfs(words, memo, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        memo[currentWord] = maxLength;

        return maxLength;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;
        for (const string &word : words) {
            wordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, dfs(wordsPresent, memo, word));
        }
        return ans;
    }
};
