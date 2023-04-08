// Copyright 2021 NNTU-CS
#include <ctype.h>
#include <string>
#include <map>
#include "tstack.h"

int CheckPriority(char oper) {
    switch (oper) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    }
    return -1;
}

int number(char a) {
    switch (a) {
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    }
    return -1;
}

std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string res = "";
    std::string output;
    for (int i = 0; i < inf.length(); i++) {
        if (isdigit(inf[i])) {
            res += inf[i];
        } else {
            if (res.length() > 0) {
                output += res;
                output += " ";
                res = "";
            }
            if ((!CheckPriority) ||
                CheckPriority(inf[i]) > CheckPriority(stack1.get()) ||
                stack1.isEmpty()) {
                stack1.push(inf[i]);
            } else {
                if (CheckPriority(inf[i]) == 1) {
                    char c = stack1.pop();
                    while (c != '(') {
                        output += c;
                        output += " ";
                        c = stack1.pop();
                    } else {
                        while (!stack1.isEmpty() &&
                               CheckPriority(inf[i]) <= CheckPriority(stack1.get())) {
                               output += stack1.pop();
                               output += " ";
                  }
                    stack1.push(inf[i]);
                }
            }
        }
    }
    if (res.length() > 0) {
        output += res;
        output += " ";
        res = "";
    }
    while (!stack1.isEmpty()) {
        output += stack1.pop();
        if (!stack1.isEmpty()) output += " ";
    }
    return output;
}

int eval(std::string pref) {
    TStack<int, 100> stack2;
    for (int i = 0; i < pref.length(); i += 2) {
        char a = pref[i];
        if (isdigit(a)) {
            stack2.push(number(a));
        }
        else {
            int t2 = stack2.get();
            stack2.pop();
            int t1 = stack2.get();
            stack2.pop();
            if (pref[i] == '+') stack2.push(t1 + t2);
            if (pref[i] == '-') stack2.push(t1 - t2);
            if (pref[i] == '*') stack2.push(t1 * t2);
            if (pref[i] == '/') stack2.push(t1 / t2);
        }
    }
    return stack2.get();
}
