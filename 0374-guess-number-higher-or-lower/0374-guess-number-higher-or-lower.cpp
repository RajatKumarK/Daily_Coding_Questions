/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1;
        int h= n;
        while(l<=h){
            int mid = (h-l)/2 +l;
            int r = guess(mid);
            if(r==0){
                return mid;
            }
            else if(r==1){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return 0;
    }
};