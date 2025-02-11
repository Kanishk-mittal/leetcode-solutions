# include <iostream>
# include <string>

using namespace std;
class Solution
{
public:
    long long countSubstrings(string s)
    {
        long long count;
        // checking for last number 1,2,5
        int zero_count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]=='0')
            {
                zero_count++;
            }
            if (s[i]=='1'|| s[i]=='2' || s[i]=='5')
            {
                count+=((i+1)-zero_count);
            }
        }
        // checking for 3,6,9 using sliding window and digit sum property
        int digit_sum = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]!='3' && s[i]!='6' && s[i]!='9')
            {
                continue;
            }
            
            digit_sum+=s[i]-'0';
            while (digit_sum>9)
            {
                digit_sum-=s[left]-'0';
                left++;
            }
            if (digit_sum%3==0)
            {
                count+=i-left+1;
            }
        }
        // checking for 4,8 using their property i.e for 4 last two digits should be divisible by 4 and for 8 last three digits should be divisible by 8
        int last_two = 0;
        int last_three = 0; 
        for (int i = 0; i < s.size(); i++)
        {
            last_two = (last_two*10 + s[i]-'0')%100;
            last_three = (last_three*10 + s[i]-'0')%1000;
            if (last_two%4==0)
            {
                count+=i+1;
            }
            if (last_three%8==0)
            {
                count+=i+1;
            }
        }
        // checking for 7
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]=='7')
            {
                
            }
        }
        
    }
};
