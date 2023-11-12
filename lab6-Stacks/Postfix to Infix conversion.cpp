#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert a postfix expression to infix
string postfixToInfix(const string& postfix) {
    stack<string> stack;
    for (char c : postfix) {
        if (isOperator(c)) {
            // Pop two operands from the stack and construct an infix expression
            string operand2 = stack.top();
            stack.pop();
            string operand1 = stack.top();
            stack.pop();
            string result = "(" + operand1 + c + operand2 + ")";
            stack.push(result);
        } else {
            // Push operands onto the stack
            stack.push(string(1, c)); // Convert char to string
        }
    }
    // The final result will be on the top of the stack
    return stack.top();
}

int main() {
    string postfixExpression;
	cout << "Enter an Postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);
    cout << "Postfix: " << postfixExpression << endl;
    cout << "Infix: " << infixExpression << endl;
    return 0;
}
