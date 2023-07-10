class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> t;
        int temp = 0, ans = 0;
        // Store Evens between odds
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                temp++;
            else
            {
                t.push_back(temp);
                temp = 0;
            }
        }
        t.push_back(temp);
        int ind = 0;
        // sliding window to count number of subarrays
        while (ind + k < t.size())
        {
            ans += (t[ind] + 1) * (t[ind + k] + 1);
            ind++;
        }

        return ans;
    }
};
