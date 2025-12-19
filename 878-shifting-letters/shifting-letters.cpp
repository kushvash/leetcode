class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        vector<long long> diff(n, 0);

        for (int i = 0; i < n; i++) {
            diff[0] += shifts[i];
            if (i + 1 < n) {
                diff[i + 1] -= shifts[i];
            }
        }

        long long curr = 0;
        for (int i = 0; i < n; i++) {
            curr = (curr + diff[i]) % 26;
            if (curr < 0) {
                curr += 26;
            }

            int x = (s[i] - 'a' + curr) % 26;
            s[i] = char('a' + x);
        }

        return s;
    }
};