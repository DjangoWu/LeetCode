class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        vector<bool> flags(len, false);
        vector<bool> flagg(len, false);

        int countA = 0;
        int countB = 0;

        for (int i = 0; i < len; i++)
        {
            if (secret[i] == guess[i])
            {
                countA++;
                flagg[i] = true;
                flags[i] = true;
            }
        }

        for (int i = 0; i < len; i++)
        {
            if (flagg[i])
                continue;

            for (int j = 0; j < len; j++)
            {
                if (flags[j])
                    continue;
                if (secret[j] == guess[i])
                {
                    flags[j] = true;
                    countB++;
                    break;
                }
            }
        }
        string ans;
        ans += to_string(countA);
        ans += 'A';
        ans += to_string(countB);
        ans += 'B';
        return ans;
    }
};