class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringSub(s, k, 0, s.length()-1);
    }
    
private:
    int longestSubstringSub(string s, int k, int start, int end)
    {
        //std::cout << "start: " << start << " end: " << end << std::endl;
        if(start > end)
            return 0;
        vector<int> count(26, 0);
        for(int i = start; i <= end; i++)
            count[s[i] - 'a']++;
        for(int i = 0; i < 26; i++)
        {
            if(count[i] > 0 && count[i] < k)
            {
                int pos = s.find(i+'a', start);
                
                return max(longestSubstringSub(s, k, start, pos-1), longestSubstringSub(s, k, pos+1, end));
            }
        }
        return end-start+1;
        
    }
};