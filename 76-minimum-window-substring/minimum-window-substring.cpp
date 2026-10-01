class Solution {
public:
    string minWindow(string s, string t) {

        int l = 0, r = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int startIndex = -1;
        map<char, int> mpp;

        // Store frequency of characters required in t
        for(int i = 0; i < t.size(); i++) {
            mpp[t[i]]++;
        }

        while(r < s.size()) {

            // If s[r] is required, we found one required character
            if(mpp[s[r]] > 0)
                cnt++;

            // Add s[r] to current window, so decrease its required frequency
            mpp[s[r]]--;

            // Keep removing from the left as long as the window is valid
            while(cnt == t.size()) {

                // Current window is valid, check if it is the smallest
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                // Remove s[l] from the current window,
                // so increase its required frequency
                mpp[s[l]]++;

                // If frequency becomes positive, we now need this character again
                if(mpp[s[l]] > 0)
                    cnt--;

                // Move left pointer forward
                l++;
            }

            // Expand window
            r++;
        }

        if(startIndex == -1)
            return "";

        return s.substr(startIndex, minLen);
    }
};