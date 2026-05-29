#include <iostream>
#include <string>
#define size 10

using namespace std;

class stack
{
private:
    int top;
    char data[size];

public:
    stack()
    {
        top = -1;
    }

    bool IsEmpty()
    {
        return top == -1;
    }

    bool IsFull()
    {
        return top == size - 1;
    }

    void Push(char n)
    {
        if (IsFull())
        {
            cout << "Stack is full\n";
        }
        else
        {
            data[++top] = n;
        }
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            top--;
        }
    }

    char top_val()
    {
        if (IsEmpty())
            return '\0';
        else
            return data[top];
    }
};

bool pair(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    else if (open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else
        return false;
}

bool balanced(stack &s, string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.Push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.IsEmpty())
                return false;

            if (pair(s.top_val(), exp[i]) == false)
                return false;

            s.Pop();
        }
    }

    return s.IsEmpty();
}

int main()
{
    stack open_brackets;
    string s;

    cin >> s;

    if (balanced(open_brackets, s))
        cout << "Expression is balanced\n";
    else
        cout << "Expression is not balanced\n";

    return 0;
}