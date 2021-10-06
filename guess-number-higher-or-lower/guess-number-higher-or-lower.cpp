/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int solve(int l, int r){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(guess(mid)==0){
                return mid;
            } else if(guess(mid)==-1){
                return solve(l, mid-1);
            } else{
                return solve(mid+1,r);
            }
        }
        return -1;
    }

    int guessNumber(int n) {
        int l=1;
        int r = n;
        if(n==1){
            return 1;
        }
        return solve(1,n);        
    }
};