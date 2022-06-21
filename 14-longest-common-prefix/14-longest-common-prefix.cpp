class Solution {
    struct TrieNode {
        bool last = false;
        unordered_map<char, TrieNode *> letters;
    };
    class Trie {
        TrieNode head;
    public:
        void addWord(const string &s) {
            auto *p = &head;
            for(char c : s) {
                if(p->letters.count(c) == 0) {
                    p->letters[c] = new TrieNode{};
                }
                p = p->letters[c];
            }
            p->last = true;
        }
        string lcp() {
            string ret;
            auto *p = &head;
            
            while(p->letters.size() == 1 && !p->last) {
                auto it = p->letters.begin();
                p = p->letters[it->first];
                ret += it->first;
            }
            return ret;
        }
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(const auto &w : strs) {
            trie.addWord(w);
        }
        return trie.lcp();
    }
};