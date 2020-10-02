class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==-1) return 1/x;
        if(n==1) return x;
        
        //so if we draw a tree then we can see that we are calculating same value 2 times(1 for left subtree and second for right subtree)
        //so we're gonna call for only 1 subtree and then multiply with itself
        double value=myPow(x,n/2);
        value*=value;
        
        //now if the power is odd then 1 power will be remained, handling below.. for positive power simple multiply number 1 times and for negative power multiply 1/number to get that 1 remaining value to be calculated also!
        if(n%2!=0) value=n>0?value*x:value*1/x;
     
        return(value);
    }
};