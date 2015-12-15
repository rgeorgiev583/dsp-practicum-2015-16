#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>

#define MAX_SIZE 1000

using namespace std;

struct rep_expr_t
{
    size_t count, expr_pos, str_pos;
};

int main()
{
    char* str = new char[MAX_SIZE];
    cin.getline(str, MAX_SIZE);
    stack<rep_expr_t> state;
    rep_expr_t expr;
    char* s = str;

    while (*s)
        if (*s >= '0' && *s <= '9')
        {
            expr.count = atoi(s);
            char* expr_begin = s;

            while (*s && *s >= '0' && *s <= '9')
                s++;

            if (*s++ == '(')
            {
                expr.expr_pos = (size_t)(expr_begin - str);
                expr.str_pos  = (size_t)(s - str);
                state.push(expr);
            }
        }
        else if (*s == ')')
        {
            expr = state.top();
            state.pop();
            size_t rep_str_len = (size_t) (s - str - expr.str_pos), rep_len = expr.count * rep_str_len;
            char* rep_str = new char[rep_len + 1];
            strncpy(rep_str, str + expr.str_pos, rep_str_len);
            rep_str[rep_str_len] = '\0';

            for (size_t i = 2; i <= expr.count; i++)
            {
                strncat(rep_str, str + expr.str_pos, rep_str_len);
                rep_str[i * rep_str_len] = '\0';
            }

            rep_str[rep_len] = '\0';
            size_t rest_len = strlen(++s);
            char* new_str = new char[expr.expr_pos + rep_len + rest_len + 1];
            strncpy(new_str, str, expr.expr_pos);
            new_str[expr.expr_pos] = '\0';
            strcat(new_str, rep_str);
            strcat(new_str, s);
            rep_str[expr.expr_pos + rep_len + rest_len] = '\0';
            s = new_str + expr.expr_pos + rep_len;
            delete[] rep_str;
            delete[] str;
            str = new_str;
        }
        else
            s++;

    cout << str << endl;
    return 0;
}
