// Program to check if the parentheses are balanced.
#include <iostream>
#include <stack>

using namespace std;
 
bool checkBalancedParentheses(string myStr)   // function to check if the parentheses are balanced.
{ 
    stack<char> stk;   //Defined in #include<stack> header file.

    for(int i=0; i<myStr.length(); i++)    //Traversing the string.
    {
        if(stk.empty())
            stk.push(myStr[i]);

        else if( (stk.top() == '(' && myStr[i] == ')' )  ||  (stk.top() == '{' && myStr[i] == '}')  ||  (stk.top() == '[' && myStr[i] == ']') )
            stk.pop();

        else
            stk.push(myStr[i]);
    }   //End of for()

    if(stk.empty())
    {
        return true;
    }
    return false;

}   // End of function.
 
int main()
{
    //string str = "()[[]]";

    string str;

    //cout << "\n---------- Checking if the parentheses are balanced or not ----------\n\n";

    cout << "Enter some parentheses: " << endl;
    cin >> str;
 
    if (checkBalancedParentheses(str))      //Function call.
        cout << "Parentheses are balanced.";
    else
        cout << "Parentheses are not Balanced";

    return 0;
}