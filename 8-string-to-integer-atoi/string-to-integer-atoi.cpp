class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int result = 0;
        int i = 0;
        int n = s.size();

        // Discard all spaces from the beginning of the s string.
        while (i < n && s[i] == ' ') {
            i++;
        }

        // sign = +1, if it's positive number, otherwise sign = -1.
        if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        } else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }

        // Traverse next digits of s and stop if it is not a digit.
        // End of string is also non-digit character.
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow and underflow conditions.
            if ((result > INT_MAX / 10) ||
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                // If integer overflowed return 2^31-1, otherwise if underflowed
                // return -2^31.
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // Append current digit to the result.
            result = 10 * result + digit;
            i++;
        }

        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign * result;
    }
};