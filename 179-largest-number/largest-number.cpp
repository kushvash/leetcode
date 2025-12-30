class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;

        auto cmp=[](int& a, int& b) {
            string aS=to_string(a);
            string bS=to_string(b);

            return aS+bS>bS+aS;
        };

        sort(nums.begin(), nums.end(), cmp);

        for(int num: nums) {
            res+=to_string(num);
        }

        if(res[0]=='0') {
            return "0";
        }

        return res;
    }
};