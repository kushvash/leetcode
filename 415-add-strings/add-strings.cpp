class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int i=0, j=0, carry=0;
        
        while(i<num1.size() && j<num2.size()) {
            int temp=carry;
            carry=0;

            temp+=num1[i]-'0';
            temp+=num2[j]-'0';

            if(temp>9) {
                carry=temp/10;
                temp%=10;
            }

            res+=to_string(temp);
            i++;
            j++;
        }

        while(i<num1.size()) {
            int temp=carry;
            carry=0;

            temp+=num1[i]-'0';
            
            if(temp>9) {
                carry=temp/10;
                temp%=10;
            }

            res+=to_string(temp);
            i++;
        }

        while(j<num2.size()) {
            int temp=carry;
            carry=0;

            temp+=num2[j]-'0';
            
            if(temp>9) {
                carry=temp/10;
                temp%=10;
            }

            res+=to_string(temp);
            j++;
        }

        if(carry!=0) {
            res+=to_string(carry);
        }

        reverse(res.begin(), res.end());

        return res;

    }
};