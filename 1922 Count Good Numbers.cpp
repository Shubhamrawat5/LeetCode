class Solution
{
public:
    int mod = 1000000007;
    long long pow(long long n, long long p)
    {
        if (p == 0)
            return 1;
        if (p == 1)
            return n;

        //if we make a tree then power will be divide by 2 in left right child
        long long left = pow(n, p / 2) % mod;
        long long full = (left * left) % mod; //left*right

        if (p % 2 != 0)
            full = (full * n) % mod; //if power was odd then 1 power will remain
        return full;
    }

    int countGoodNumbers(long long n)
    {
        if (n == 1)
            return 5;
        long long ans = 1;

        //LOGIC: combination 0,2,6 even place will have always 5 values and 1,3,5 odd place will have always 4 values
        long long evenInd = n / 2;
        long long oddInd = n - evenInd;
        // cout<<"ODD "<<oddInd<<" ,even "<<evenInd<<endl;
        // cout<<"5 "<<pow(5,oddInd)%mod<<endl;
        // cout<<"4 "<<pow(4,evenInd)%mod<<endl;

        ans = (pow(5, oddInd) % mod) * (pow(4, evenInd) % mod);
        return ans % mod;
    }
};