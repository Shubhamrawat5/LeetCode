class Solution {
public:
    bool isPowerOfTwo(int n) {
        //in bits 1 and 0.. power of 2 have always single 1 so if we subtract 1 from power of 2s then we will get 011111.. type sequence in bits like
        //8 = 1000 and 8-1=7=0111 so if we take bitwise and of these 2, we will get 0 always for power of 2s numbers..
        //to handle number 0 case and last negative value case, using first 2 conditions in if
        
        if(n && n!=INT_MIN && (n & (n-1))==0) return true;
        return false;
    }
};