class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size();
        //logic: Create odd array where sum will be stored of odd indexes(taken as 1 based index) from end to start, same with even array
        //with this we will know upcoming array even and odd index elements sum!
        //nums[]={2,1,6,4}
        //so..
        //odd[]={5,5,4,4,0}
        //even[]={8,6,6,0,0}
        vector<int> odd(n + 1), even(n + 1);

        odd[n] = 0;
        even[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if ((i + 1) % 2 == 0)
            {
                even[i] = even[i + 1];
                odd[i] = odd[i + 1] + nums[i];
            }
            else
            {
                odd[i] = odd[i + 1];
                even[i] = even[i + 1] + nums[i];
            }
        }

        //now current odd,even index sum will be stored and with current, upcoming sum will be added and check if equal or not
        int count = 0;
        int curOdd = 0, curEven = 0;

        for (int i = 1; i < n; ++i)
        {
            if (odd[i] + curOdd == even[i] + curEven)
                ++count; //current index will be ignored as curOdd,curEven have sum till previous index AND even[i],odd[i] will have upcoming odd even index sum

            if ((i - 1) % 2 == 0)
                curOdd += nums[i - 1];
            else
                curEven += nums[i - 1];
        }

        if (curEven == curOdd)
            ++count; //for last index element

        return count;
    }
};