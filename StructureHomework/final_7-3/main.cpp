#include <bits/stdc++.h>

using namespace std;

typedef struct park {
    int isEmpty = 1;
    int inTime = 0;
    int car;
} park;

typedef struct incident {
    char state;
    int car;
    int time;
    incident *next;
} incident;

incident *Store() {
    char state;
    int time;
    int id;
    incident *head = nullptr, *p, *q;
    p = head;
    while (true) {
        fflush(stdin);
        cin >> state;
        cin >> id >> time;
        if (state == 'E') {
            return head;
        }
        q = (incident *) malloc(sizeof(incident));
        q->state = state;
        q->car = id;
        q->time = time;
        q->next = nullptr;
        if (!head) {
            head = q;
            p = q;
        } else {
            p->next = q;
            p = q;
        }
    }
}

int main() {
    int n, i, outTime = 0;
    int wait = 0;
    cin >> n;
    park pos[n];
    incident *head = Store();
    incident *p = head;
    while (p) {
        if (p->state == 'A') {
            for (i = 0; i < n; i++) {
                if (pos[i].isEmpty == 0)
                    continue;
                pos[i].isEmpty = 0;
                pos[i].car = p->car;
                pos[i].inTime = p->time;
                if (outTime) {
                    pos[i].inTime = outTime;
                    outTime = 0;
                }
                cout << "car#" << p->car << " in parking space #" << i + 1 << endl;
                p->state = '0';
                break;
            }
            if (i == n) {
                wait++;
                cout << "car#" << p->car << " waiting" << endl;
            }
        } else if (p->state == 'D') {
            int isIn = 0;
            for (i = 0; i < n; i++) {
                if (pos[i].car != p->car)
                    continue;
                cout << "car#" << p->car << " out,parking time " << p->time - pos[i].inTime << endl;
                isIn = 1;
                p->state = '0';
                for (; i < n - 1; i++) {
                    pos[i].isEmpty = pos[i + 1].isEmpty;
                    pos[i].car = pos[i + 1].car;
                    pos[i].inTime = pos[i + 1].inTime;
                }
                pos[i].isEmpty = 1;
                break;
            }
            if (isIn == 0) {
                cout << "the car not in park" << endl;
                p->state = '0';
            }
            if (wait) {
                outTime = p->time;
                wait--;
                p = head;
            }
        }
        p = p->next;
    }
    return 0;
}
