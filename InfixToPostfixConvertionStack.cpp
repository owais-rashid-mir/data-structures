//Infix to postfix conversion using stacks.
//Learnt from Apna College(Youtube).
#include <iostream>
#include <stack>

using namespace std;

int setPrecedence(char c)  //Function to define precedence.
{
    if(c == '^')    // Power has the highest precedence.
        return 3;

    else if(c=='*' || c =='/')
        return 2;

    else if(c=='+' || c =='-')
        return 1;

    else
        return -1;
}

string infixToPostfixConv(string str)   //Conversion function.
{
    stack<char> stk;    //Defined in #include<stack> header file.
    string result;

    for(int i=0; i<str.length(); i++)     //Traversing the string.
    {
        if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'z') )      // If operand - print (Add to result).
            result += str[i];

        else if( str[i] == '(' )    //if '(' : push to stack
            stk.push(str[i]);   // push() is defined in stack header file.

        else if( str[i] == ')' )    // If ')' : Pop from stack and print until '(' is found
        {
            while( !stk.empty() && stk.top() != '(' )
            {
                result += stk.top();
                stk.pop();
            }

            if( !stk.empty() )  // While stack is not empty.
                stk.pop();
        }

        else    // If operator : Pop from stack and print until an operator with less precendence is found.
        {
            while( !stk.empty() && setPrecedence( stk.top()) > setPrecedence(str[i]) )
            {
                result += stk.top();
                stk.pop();
            }
            stk.push( str[i] );
        }


    }   //End of for()

    while( !stk.empty() )
    {
        result += stk.top();
        stk.pop();
    }
    return result;

}   // End of infixToPostfixConv() function.


int main()
{
    //cout << infixToPostfixConv( "(a-b/c)*(a/k-l)" ) << endl;

    string exp, res;

    cout << "\n---------- Infix to postfix conversion using stack ----------\n\n";

    cout << "Enter an infix myStresson: " << endl;
    cin >> exp;

    res = infixToPostfixConv(exp);    //function call.

    cout << "After conversion, the postfix myStression is: " << res << endl << endl;

    return 0;
}