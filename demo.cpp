#include <bits/stdc++.h>
using namespace std;

struct Rule {
    string left;
    vector<string> right;
};

class CFG {
    vector<Rule> rules;
    set<string> variables, terminals;

public:
    void addRule(const string &left, const vector<string> &right) {
        rules.push_back({left, right});
        variables.insert(left);
        for (const string &symbol : right) {
            if (islower(symbol[0])) terminals.insert(symbol);
            else variables.insert(symbol);
        }
    }

    // Step 1: Replace terminals in RHS of length > 1
    void replaceTerminals() {
        map<string, string> termMap;
        int tCount = 1;
        vector<Rule> updated;
        for (auto &r : rules) {
            vector<string> newRHS;
            for (auto &sym : r.right) {
                if (terminals.count(sym) && r.right.size() > 1) {
                    if (!termMap.count(sym)) {
                        string newVar = "T" + to_string(tCount++);
                        termMap[sym] = newVar;
                        updated.push_back({newVar, {sym}});
                    }
                    newRHS.push_back(termMap[sym]);
                } else {
                    newRHS.push_back(sym);
                }
            }
            updated.push_back({r.left, newRHS});
        }
        rules = updated;
    }

    // Step 2: Binarize rules (RHS length > 2)
    void binarize() {
        vector<Rule> updated;
        int xCount = 1;
        for (auto &r : rules) {
            if (r.right.size() <= 2) {
                updated.push_back(r);
            } else {
                string prev = r.right[0];
                for (size_t i = 1; i < r.right.size() - 1; i++) {
                    string newVar = "X" + to_string(xCount++);
                    updated.push_back({newVar, {prev, r.right[i]}});
                    prev = newVar;
                }
                updated.push_back({r.left, {prev, r.right.back()}});
            }
        }
        rules = updated;
    }

    // Step 3: Remove epsilon-productions
    void removeEpsilon() {
        set<string> nullable;
        // Find nullable variables (A -> ε)
        bool changed = true;
        while (changed) {
            changed = false;
            for (auto &r : rules) {
                if (r.right.empty() || all_of(r.right.begin(), r.right.end(),
                        [&](string s){ return nullable.count(s); })) {
                    if (!nullable.count(r.left)) {
                        nullable.insert(r.left);
                        changed = true;
                    }
                }
            }
        }
        // Generate new rules by removing nullable variables in RHS
        vector<Rule> newRules;
        for (auto &r : rules) {
            vector<vector<string>> rhsOptions = {{}};
            for (auto &sym : r.right) {
                vector<vector<string>> tmp;
                for (auto &opt : rhsOptions) {
                    vector<string> opt1 = opt;
                    opt1.push_back(sym);
                    tmp.push_back(opt1);
                    if (nullable.count(sym)) {
                        tmp.push_back(opt); // omit nullable symbol
                    }
                }
                rhsOptions = tmp;
            }
            for (auto &opt : rhsOptions) {
                if (!opt.empty() || r.left == "S") { // keep empty only for start
                    newRules.push_back({r.left, opt});
                }
            }
        }
        rules = newRules;
    }

    // Step 4: Remove unit productions (A -> B)
    void removeUnitProductions() {
        vector<Rule> newRules;
        map<string, set<vector<string>>> prodMap;
        for (auto &r : rules) prodMap[r.left].insert(r.right);

        for (auto &var : variables) {
            set<vector<string>> closure;
            queue<string> q;
            q.push(var);
            while (!q.empty()) {
                string u = q.front(); q.pop();
                for (auto &rhs : prodMap[u]) {
                    if (rhs.size() == 1 && variables.count(rhs[0])) {
                        if (!closure.count({rhs[0]})) {
                            closure.insert({rhs[0]});
                            q.push(rhs[0]);
                        }
                    } else {
                        closure.insert(rhs);
                    }
                }
            }
            for (auto &rhs : closure) {
                newRules.push_back({var, rhs});
            }
        }
        rules = newRules;
    }

    void convertToCNF() {
        replaceTerminals();
        binarize();
        removeEpsilon();
        removeUnitProductions();
    }

    void printGrammar() {
        for (auto &r : rules) {
            
            cout << r.left << " -> ";
            if (r.right.empty()) cout << "ε";
            else for (auto &s : r.right) cout << s << " ";
            cout << "\n";
        }
    }
};

int main() {
    CFG g;

    g.addRule("S", {"A", "B", "C"});
    g.addRule("A", {"a"});
    g.addRule("B", {"b"});
    g.addRule("C", {"c", "D"});
    g.addRule("D", {"d"});

    cout << "Input CFG:\n";
    g.printGrammar();

    g.convertToCNF();

    cout << "\nCNF Grammar:\n";
    g.printGrammar();

    return 0;
}
