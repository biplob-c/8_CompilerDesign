// C++ program to evaluate value of a postfix
// expression Using Stack
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to evaluate a postfix expression given as a vector of strings
int evaluatePostfix(vector<string>& arr) {
    stack<int> st;

    // Loop through each element in the vector
    for (string token : arr) {

        // If it's an operand (number), push it onto
        // the stack
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(stoi(token));
        }

        // Otherwise, it must be an operator
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (token == "+") {
                st.push(val2 + val1);
            } else if (token == "-") {
                st.push(val2 - val1);
            } else if (token == "*") {
                st.push(val2 * val1);
            } else if (token == "/") {
                st.push(val2 / val1);
            }
        }
    }
    return st.top();
}

int main() {
    vector<string> arr = {"1", "2", "3", "+", "4", "-", "*"};
    cout << evaluatePostfix(arr) << endl;
    return 0;
}
///////////////////////////////////////

/////////////////////////////////////
#include <iostream>
#include <stack>//includes stack data structure
#include <vector>//allows using dynamic arrays (vector)

using namespace std;

// Function to evaluate a postfix expression given as a vector of strings
int postfix2infix(vector<string>& arr){
    stack<int> st; //creates an integer stack to store operands

    //Loop through each element in the vector
    for(string token: arr){ //Iterates over each element (token) in the input vector.
        //If it's an operand (number), push it onto the Stack
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(stoi(token));
            //isdigit(token[0]): Checks if the first character is a digit (e.g., "1").
            //(token.size() > 1 && token[0] == '-'): Handles negative numbers (e.g., "-5").
            //st.push(stoi(token)): Converts the string to an integer (stoi) and pushes it onto the stack.
        }
        //If Token is an Operator
        else {
            int val1 = st.top();//st.top(): Gets the top element of the stack.
            st.pop();           //st.pop(): Removes the top element.
            int val2 = st.top();//val1 and val2: The two most recent operands (note: val2 is the earlier operand).
            st.pop();

            //Perform the Operation
            if (token == "+") {
                st.push(val2 + val1);
            } else if (token == "-") {
                st.push(val2 - val1);
            } else if (token == "*") {
                st.push(val2 * val1);
            } else if (token == "/") {
                st.push(val2 / val1);
            }
            //+: Adds val2 and val1.
            //-: Subtracts val1 from val2.
            //*: Multiplies val2 and val1.
            //"/": Divides val2 by val1.
            //The result is pushed back onto the stack.
        }
    }
    return st.top(); // Return the Final Result
}

int main()
{
    //Takes a vector of strings (each string is a token, e.g., "1", "+").
    vector<string> arr = {"1","2","3","+", "4", "-", "*"};
    cout<<postfix2infix(arr)<<endl;

    return 0;
}

/*
Example Walkthrough
For {"1", "2", "3", "+", "4", "-", "*"}:

1, 2, 3 are pushed → Stack: [1, 2, 3]

+ → 2 + 3 = 5 → Stack: [1, 5]

4 is pushed → Stack: [1, 5, 4]

- → 5 - 4 = 1 → Stack: [1, 1]

* → 1 * 1 = 1 → Stack: [1]

Returns 1.
*/
