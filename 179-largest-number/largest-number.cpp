class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;

        auto cmp=[](int& a, int& b) {
            string i1=to_string(a);
            string i2=to_string(b);

            return i1+i2>i2+i1;
        };

        sort(nums.begin(), nums.end(), cmp);

        for(int& num: nums) {
            res+=to_string(num);
        }

        if(res[0]=='0') {
            return "0";
        }

        return res;
    }
};