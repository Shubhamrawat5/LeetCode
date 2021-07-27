#include <iostream>
using namespace std;

int main()
{
    int change[] = {0, 9, 2, 3, 3, 2, 5, 5, 5, 5};
    string num = "334111";

    // int change[] = {9, 8, 5, 0, 3, 6, 4, 2, 6, 8};
    // string num = "132";
    string ans = "";
    int i;
    bool flag = 0;
    for (i = 0; i < num.length(); ++i)
    {
        int n = (num[i] - '0');
        if (n < change[n])
        {             //bigger available
            flag = 1; // we have changed the substring
            ans += change[n] + '0';
            continue;
        }
        else if (n > change[n])
        {
            if (flag == 1) //we have already changed a substring then its break time
                break;
        }
        ans += (n + '0'); // add current number of num
        cout << ans << endl;
    }
    if (num.length() == ans.length())
        cout << ans << endl;
    cout << ans + num.substr(i) << endl;
}