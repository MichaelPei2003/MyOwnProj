#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5000;
int cnt = 0;
pair<string, vector<string> > exps[MAX_N];
set<string> Vns, Vts;
map<string, set<string> > first;

bool is_terminal(const string &s) {
    regex nt("[A-Z]*");
    if (regex_match(s, nt)) {
        return false;
    }
    return true;
}

void readExps() {
    string str;
    cout << "input information (end with #):" << endl;
    while (getline(cin, str)) {
        if (str.find('#') != -1) break;
        int mid_pos = (int) str.find("->");
        if (mid_pos == -1) {
            cout << "Invalid input" << endl;
            continue;
        }
        int ls = 0, le = mid_pos;
        while (str[ls] == ' ') ls++;
        for (int i = ls; i < mid_pos; i++) {
            if (str[i] == ' ') {
                le = i;
                break;
            }
        }
        exps[cnt].first = str.substr(ls, le - ls);
        Vns.insert(exps[cnt].first);
        for (int i = mid_pos + 2; i < (int) str.length(); i++) {
            if (str[i] == ' ') continue;
            exps[cnt].second.push_back(str.substr(i, 1));
            string exp_elem = str.substr(i, 1);
            if (is_terminal(exp_elem)) {
                Vts.insert(exp_elem);
                first[exp_elem].insert(exp_elem);
            }
        }
        cnt++;
    }
}

void cal_first() {
    int pre_size = -1, now_size = 0;
    while (pre_size != now_size) {
        pre_size = now_size;
        for (int i = 0; i < cnt; i++) {
            string str = exps[i].first;
            vector<string> elements = exps[i].second;
            if (is_terminal(elements[0])) {
                first[str].insert(elements[0]);
            } else {
                for (int j = 0; j < (int) elements.size(); j++) {
                    if (is_terminal(elements[j])) {
                        break;
                    }
                    for (string tmp: first[elements[j]]) {
                        if (tmp != "~") {
                            first[str].insert(tmp);
                        } else if (j == elements.size() - 1) {
                            first[str].insert(tmp);
                        }
                    }
                    if (first[elements[j]].find("~") == first[elements[j]].end()) {
                        break;
                    }
                }
            }
            now_size = 0;
            for (string tmp: Vns) {
                now_size += (int) first[tmp].size();
            }
        }
    }
}

int main() {
    Vts.insert("#");
    readExps();
    cal_first();
    cout << "----first----" << endl;
    for (string n: Vns) {
        cout << n << ":";
        for(string tmp : first[n]) {
            cout << tmp << " ";
        }
        cout << endl;
    }
    return 0;
}