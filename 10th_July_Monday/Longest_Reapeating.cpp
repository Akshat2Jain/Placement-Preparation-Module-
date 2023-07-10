class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, ans = 0, max_count = 0;

        // mapping character ans its count
        unordered_map<char, int> map;

        for (int right = 0; right < s.length(); right++)
        {
            map[s[right]]++;

            // max_count is maximum of similar letter count
            max_count = max(max_count, map[s[right]]);

            // probable ans  right - left + 1 is greater than k after subtracting max_count
            if (right - left + 1 - max_count > k)
            {
                map[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};