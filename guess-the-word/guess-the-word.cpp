/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

#include <bits/stdc++.h>

 
// Shuffle array

class Solution {
public:
    vector<string>random_arr;
    void shuffle_array(string arr[], int n)
    {

        // To obtain a time-based seed
        unsigned seed = 0;

        // Shuffling our array
        shuffle(arr, arr + n,
                default_random_engine(seed));

        // Printing our array
        for (int i = 0; i < n; ++i)
        {cout << arr[i] << " ";
            random_arr.push_back(arr[i]);}
        cout << endl;
    }
    int match(string a , string b){
        int m = a.length();
        int n = b.length();
        int matches =0;
        for(int i=0;i<m;i++){
            if(a[i]==b[i]){
                matches++;
            }
        }
        return matches;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        string arr[n];
        for(int i=0;i<n;i++){
            arr[i]=wordlist[i];
        }
        shuffle_array(arr, n);
    
        set<string>s(wordlist.begin(),wordlist.end());
        for(int i=0;i<n;i++){
            string temp = random_arr[i];
            if(s.find(temp)==s.end()){
                continue;
            } else{
                int temp2 = master.guess(temp);
                for(auto x:s){
                    if(match(x,temp)!=temp2){
                        s.erase(x);
                    }
                }
            }
        }
        
        
    }
};