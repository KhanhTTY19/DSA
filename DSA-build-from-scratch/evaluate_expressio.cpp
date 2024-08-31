#include<bits/stdc++.h>
#include<stack>

using namespace std;


bool delim(char c);
bool is_op(char c);
int priority(char c);
void process(stack <int>& expr, char op);
int evaluate(string& s);

int main()
{
    string s1;
    cin >> s1;
    int i = evaluate(s1);
    if (i != -1000000000) cout << i;
}

bool delim(char c)
{
    return c == ' ';
}

bool is_op(char c)
{
    return c == '+' || c == '-' || c == '/' || c == '*';
}

int priority(char c)
{
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void process(stack <int>& expr, char opr)
{
    int r = expr.top(); expr.pop();
    int l = expr.top(); expr.pop();
    if (opr == '+') {expr.push(l + r); return;}
    if (opr == '-') {expr.push(l - r); return;}
    if (opr == '*') {expr.push(l * r); return;}
    if (opr == '/') {expr.push(l / r); return;}
}

int evaluate(string& s)
{
    stack<int> expr;
    stack<char> op;
    int i, len = s.length();
    for (i = 0; i < len; i++) {
        //cout << s[i];
        if (delim(s[i])) continue;

        if (s[i] == '(') {
            //cout << 1;
            op.push('(');
        }
        else if (s[i] == ')') {
            //cout << 2;
            while (op.top() != '(')
            {
                process(expr, op.top());
                op.pop();
            }
            op.pop();
        }
        else if (is_op(s[i])) {
            char x = s[i];
            while (!op.empty() && (priority(op.top()) > priority(x)))
            {
                process(expr, op.top());
                op.pop();
            }
            op.push(x);
        }
        else {
            //cout << 4;
            int number = 0;
            while (i <= len && (s[i] <= '9' && s[i] >= '0'))
            {
                number = number * 10 + s[i] - '0';
                i++;
            }
            i--;
            expr.push(number);
        }
    }
    while (!op.empty())
    {
        if (op.top() == '(') {
            cout << "NOT_CORRECT";
            return -1000000000;
        }
        process(expr, op.top());
        op.pop();
    }
    return expr.top();
}