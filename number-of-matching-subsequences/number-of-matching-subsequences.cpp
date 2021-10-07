class Solution {
public:
    // General Idea:
    // - Brute force checking will time out, we need efficent way to look up words
    // - Create an vector that stores indices for each character a-z in S
    // - Then for each word, do a binary search for next index for current character in word 
    //   that is greater than the index we last found for the alst character
    // - If it doesn't exist, word doesn't exist, otherwise continue to search for word
    
	int numMatchingSubseq (string S, vector<string>& words) {
		vector<vector<int>> alpha (26);
		for (int i = 0; i < S.size (); ++i) alpha[S[i] - 'a'].push_back (i);
		int res = 0;

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
				if (it == alpha[c - 'a'].end ()) found = false;
				else x = *it;
			}

			if (found) res++;
		}

		return res;
	}
};