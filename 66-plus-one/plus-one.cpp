class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), i=0;
        reverse(digits.begin(), digits.end());
        bool carry=true;

        while(carry){
            if(i<n){
                if(digits[i]==9){
                    digits[i]=0;
                }else{
                    digits[i]++;
                    carry=false;
                }
            }else{
                digits.push_back(1);
                carry=false;
            }
            i++;
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};