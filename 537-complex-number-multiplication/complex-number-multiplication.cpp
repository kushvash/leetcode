class Solution {
public:
    int complexNumberMultiplyHelper(string num, int& i, char c) {
        int n=0, neg=1;
        if(num[i]=='-') {
            neg=-1;
            i++;
        }

        while(num[i]!=c) {
            n*=10;
            n+=(num[i]-'0');
            i++;
        }

        return n*neg;
    }
    
    string complexNumberMultiply(string num1, string num2) {
        int i1=0, i2=0, c1=0, c2=0;
        int i=0;
        i1=complexNumberMultiplyHelper(num1, i, '+');
        i++;
        c1=complexNumberMultiplyHelper(num1, i, 'i');

        i=0;
        i2=complexNumberMultiplyHelper(num2, i, '+');
        i++;
        c2=complexNumberMultiplyHelper(num2, i, 'i');
    
        int real = i1 * i2 - c1 * c2;
        int imag = i1 * c2 + c1 * i2;

        return to_string(real) + "+" + to_string(imag) + "i";
    }
};