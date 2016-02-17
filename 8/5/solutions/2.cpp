#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>

#define BUFFER_SIZE 1000

using namespace std;

struct RepetitiveStringExpression
{
    size_t count, expressionPosition, stringPosition;
};

static inline bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    char* str = new char[BUFFER_SIZE];
    cin.getline(str, BUFFER_SIZE);
    stack<RepetitiveStringExpression> parserState;
    RepetitiveStringExpression expr;
    char* iter = str;

    while (*iter)
        if (isDigit(*iter))
        {
            expr.count = atoi(iter);
            char* expressionBeginning = iter;
            while (*iter && isDigit(*iter++));

            if (*iter++ == '(')
            {
                expr.expressionPosition = (size_t)(expressionBeginning - str);
                expr.stringPosition  = (size_t)(iter - str);
                parserState.push(expr);
            }
        }
        else if (*iter == ')')
        {
            expr = parserState.top();
            parserState.pop();
            size_t rep_str_len = (size_t) (iter - str - expr.stringPosition), rep_len = expr.count * rep_str_len;
            char* rep_str = new char[rep_len + 1];
            strncpy(rep_str, str + expr.stringPosition, rep_str_len);
            rep_str[rep_str_len] = '\0';

            for (size_t i = 2; i <= expr.count; i++)
            {
                strncat(rep_str, str + expr.stringPosition, rep_str_len);
                rep_str[i * rep_str_len] = '\0';
            }

            rep_str[rep_len] = '\0';
            size_t rest_len = strlen(++iter);
            char* new_str = new char[expr.expressionPosition + rep_len + rest_len + 1];
            strncpy(new_str, str, expr.expressionPosition);
            new_str[expr.expressionPosition] = '\0';
            strcat(new_str, rep_str);
            strcat(new_str, iter);
            rep_str[expr.expressionPosition + rep_len + rest_len] = '\0';
            iter = new_str + expr.expressionPosition + rep_len;
            delete[] rep_str;
            delete[] str;
            str = new_str;
        }
        else
            iter++;

    cout << str << endl;
    return 0;
}
