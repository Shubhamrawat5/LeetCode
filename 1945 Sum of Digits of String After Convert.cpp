#include <iostream>
using namespace std;

int main()
{
    string s = "leetcode";
    int k = 2;
    string cur = "";
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        int temp = (s[i] - 'a' + 1);
        if (temp >= 10) // double digit
        {
            ans += (temp % 10); //last digit
            temp = temp / 10;   //now remain 1 digit
        }
        ans += temp;
    }
    // cout << ans << endl;
    k = k - 1;

    while (k--)
    {
        int temp = 0;
        while (ans > 0)
        {
            temp += (ans % 10);
            ans = ans / 10;
        }
        ans = temp;
        // cout << ans << endl;
    }
    cout << ans;
}