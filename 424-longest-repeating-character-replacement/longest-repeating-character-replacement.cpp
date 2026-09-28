class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxlen = 0;
        int maxf = 0;
        int hash[26] = {0};

        int n = s.size();

        while (r < n) {

            hash[s[r] - 'A']++;

            maxf = max(maxf, hash[s[r] - 'A']);

            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};