#include <bits/stdc++.h>
using namespace std;

// map terminals to table indices
map<char,int> idx = {
    {'i',0},
    {'+',1}, {'-',2},
    {'*',3}, {'/',4},
    {'(',5}, {')',6},
    {'$',7}
};

// operator precedence table
char table[8][8] = {
/* i   +   -   *   /   (   )   $ */
/*i*/{'e','>','>','>','>','e','>','>'},
/*+*/{'<','>','>','<','<','<','>','>'},
/*-*/{'<','>','>','<','<','<','>','>'},
/**/ {'<','>','>','>','>','<','>','>'},
/*/ */{'<','>','>','>','>','<','>','>'},
/*(*/{'<','<','<','<','<','<','=','e'},
/*)*/{'>','>','>','>','>','e','>','>'},
/*$*/{'<','<','<','<','<','<','e','='}
};

// helper: is this a terminal?
bool isTerminal(char c) {
    return idx.count(c) > 0;
}

// find topmost terminal in stack
char topTerminal(const vector<char>& st) {
    for (int i = (int)st.size() - 1; i >= 0; --i)
        if (isTerminal(st[i])) return st[i];
    return '$'; // fallback
}

// parse function
bool parseOPG(const string &expr) {
    vector<char> st;
    st.push_back('$');     // init stack
    string input = expr + "$"; // append end marker

    int ip = 0;
    while (ip < (int)input.size()) {
        char a = topTerminal(st);
        char b = input[ip];

        if (!isTerminal(b)) return false; // invalid char

        char rel = table[idx[a]][idx[b]];
        if (rel == 'e') return false; // invalid

        if (rel == '<' || rel == '=') {
            // shift
            st.push_back(b);
            ip++;
        } else if (rel == '>') {
            // reduce
            char rightTerm;
            bool poppedTerm = false;
            // pop until we remove at least one terminal
            do {
                if (st.empty()) return false;
                rightTerm = st.back(); st.pop_back();
                if (isTerminal(rightTerm)) poppedTerm = true;
            } while (!poppedTerm);

            // extend handle if needed
            while (true) {
                char leftTerm = topTerminal(st);
                if (table[idx[leftTerm]][idx[rightTerm]] == '<') break;
                // pop more
                char nextTerm;
                bool gotTerm = false;
                do {
                    if (st.empty()) return false;
                    nextTerm = st.back(); st.pop_back();
                    if (isTerminal(nextTerm)) gotTerm = true;
                } while (!gotTerm);
                rightTerm = nextTerm;
            }

            // push nonterminal marker
            st.push_back('N');
        }
    }
    return (st.size() == 2 && st[0] == '$' && st[1] == 'N');
}

int main() {
    string expr;
    if (!getline(cin, expr)) return 0;
    cout << (parseOPG(expr) ? "VALID\n" : "INVALID\n");
    return 0;
}
