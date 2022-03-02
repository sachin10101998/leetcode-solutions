
class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string decodedString = "";
                // get the encoded string
                while (stack.top() != '[') {
                    decodedString += stack.top();
                    stack.pop();
                }
                // pop [ from stack
                stack.pop();
                int base = 1;
                int k = 0;
                // get the number k
                while (!stack.empty() && isdigit(stack.top())) {
                    k = k + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }
                int currentLen = decodedString.size();
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString[j]);
                    }
                    k--;
                }
            }
            // push the current character to stack
            else {
                stack.push(s[i]);
            }
        }
        // get the result from stack
        string result;
        for (int i = stack.size() - 1; i >= 0; i--) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};

