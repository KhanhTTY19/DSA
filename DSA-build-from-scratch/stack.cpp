#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> stack;
    string s = "{[()())]";
    int i;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') 
            {stack.push(s[i]); }
        if (s[i] == ']') {
            if (stack.top() != '[') {
                cout << s[i] << 0;
                return 0;
            }
            else stack.pop();
        } else if (s[i] == ')') {
            if (stack.top() != '(') {
                cout << 0;
                cout << s[i];
                return 0;
            }
            else stack.pop();
        } else if (s[i] == '}') {
            if (stack.top() != '{') {
                cout << 0;
                cout << s[i];
                return 0;
            }
            else stack.pop();
        }
    }
    
    if (stack.empty()) {
        cout << 1;
        return 0;
    } 
    cout << 0;

}