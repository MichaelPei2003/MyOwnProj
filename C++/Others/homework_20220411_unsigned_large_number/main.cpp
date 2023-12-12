#include <bits/stdc++.h>

using namespace std;

class Num {
    struct node {
        int data;
        struct node *prev;
        struct node *next;
    } *m_pHead, *m_pTail{};

    int m_len;

public:
    Num();

    ~Num();

    Num(Num &&rhs) noexcept;

    void read();

    void show() const;

    Num &operator=(Num &&rhs) noexcept;

    Num Plus(Num &rhs);

    Num Subtraction(Num &rhs);

    int Compare(const Num &rhs) const;

    void Compare_display(const Num &rhs) const;
};

Num::Num() {
    m_pHead = new node;
    m_pHead->next = nullptr;
    m_len = 0;
}

Num::~Num() {
    while (m_pHead) {
        node *p = m_pHead;
        m_pHead = p->next;
        delete p;
    }
}

Num::Num(Num &&rhs) noexcept {
    m_pHead = rhs.m_pHead;
    rhs.m_pHead = nullptr;
    m_len = rhs.m_len;
}

Num &Num::operator=(Num &&rhs) noexcept {
    node *p = this->m_pHead;
    this->m_pHead = rhs.m_pHead;
    rhs.m_pHead = p;
    p = this->m_pTail;
    this->m_pTail = rhs.m_pTail;
    rhs.m_pTail = p;
    this->m_len = rhs.m_len;
    return *this;
}

void Num::read() {
    string tmp;
    cin >> tmp;
    node *p = m_pHead;
    int i = 0;
    while (tmp[i] != '\0') {
        node *q = new node;
        q->data = tmp[i] - '0';
        p->next = q;
        q->prev = p;
        p = q;
        i++;
    }
    m_pTail = p;
    m_len = i;
}

void Num::show() const {
    node *p = m_pHead->next;
    for (int i = 0; i < m_len; i++) {
        cout << p->data;
        p = p->next;
    }
}

Num Num::Plus(Num &rhs) {
    int i;
    Num rtn;
    //front of calculated digit
    node *front = new node;
    //s is used to record the very end of list
    //to avoid errors, s will be free at end of operation
    node *s = front;
    node *p = m_pTail;
    node *q = rhs.m_pTail;
    int tmp = 0;
    for (i = 0; i < min(m_len, rhs.m_len); i++) {
        node *newNode = new node;
        newNode->data = (p->data + q->data + tmp) % 10;
        tmp = (p->data + q->data + tmp) / 10;
        //insert newNode in front of 'front'
        newNode->next = front;
        front->prev = newNode;
        //move front forward
        front = newNode;
        p = p->prev;
        q = q->prev;
    }

    //end of adding two numbers
    //add tmp to the rest of the longer number
    //Compare m_len

    //*this is longer
    if (m_len > min(m_len, rhs.m_len)) {
        for (i = 0; i < m_len - min(m_len, rhs.m_len); i++) {
            node *newNode = new node;
            newNode->data = (p->data + tmp) % 10;
            tmp = (p->data + tmp) / 10;
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
            p = p->prev;
        }
        if (tmp > 0) {
            node *newNode = new node;
            //insert "newNode" in front of front
            newNode->data = tmp;
            front->prev = newNode;
            front = newNode;
            //link rtn to *this
            rtn.m_pHead->next = front;
            front->prev = rtn.m_pHead;
            //number is 1 digit longer, add 1 to length recorder
            rtn.m_len = m_len + 1;
        } else {
            rtn.m_pHead->next = front;
            front->prev = rtn.m_pHead;
            rtn.m_len = m_len;
        }
    }
        //rhs is longer
    else if (rhs.m_len > min(m_len, rhs.m_len)) {
        for (i = 0; i < rhs.m_len - min(m_len, rhs.m_len); i++) {
            node *newNode = new node;
            newNode->data = (q->data + tmp) % 10;
            tmp = (q->data + tmp) / 10;
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
            q = q->prev;
        }
        if (tmp > 0) {
            node *newNode = new node;
            newNode->data = tmp;
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
            rtn.m_pHead->next = front;
            front->prev = rtn.m_pHead;
            rtn.m_len = rhs.m_len + 1;
        } else {
            rtn.m_pHead->next = front;
            front->prev = rtn.m_pHead;
            rtn.m_len = rhs.m_len;
        }
    }
        //two numbers have same length
    else {
        if (tmp > 0) {
            node *newNode = new node;
            newNode->data = tmp;
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
            rtn.m_pHead->next = front;
            front->prev = rtn.m_pHead;
            //use rhs.m_len or m_len is okay(?)
            rtn.m_len = rhs.m_len + 1;
        } else {
            rtn.m_pHead->next = front;
            front->prev = rtn.m_pHead;
            rtn.m_len = rhs.m_len;
        }
    }
    //link pTail to end of rtn
    rtn.m_pTail = s->prev;
    s->prev->next = nullptr;
    delete s;
    return rtn;
}

Num Num::Subtraction(Num &rhs) {
//    int i;
//    Num rtn;
//    node *front = new node;
//    node *s = front;
//    node *p = m_pTail;
//    node *q = rhs.m_pTail;
//    //this is longer than rhs
//    if (Compare(rhs) == 2) {
//        for (i = 0; i < rhs.m_len; i++) {
//            node *newNode = new node;
//            if (p->data < q->data) {
//                newNode->data = p->data - q->data + 10;
//                p->prev->data -= 1;
//            } else {
//                newNode->data = p->data - q->data;
//            }
//            p = p->prev;
//            q = q->prev;
//            front->prev = newNode;
//            newNode->next = front;
//            front = newNode;
//        }
//        //since *this is longer/larger, add untouched digits to front of the list(if exists)
//        for (i = 0; i < m_len - rhs.m_len; i++) {
//            node *newNode = new node;
//            newNode->data = p->data;
//            p = p->prev;
//            front->prev = newNode;
//            newNode->prev = front;
//            front = newNode;
//        }
//        //delete 0 in front of the number
//        //this will only happen when m_len = rhs.m_len
//        rtn.m_len = m_len;
//        node *tmp = front;
//        while (front->data == 0) {
//            //move front backward
//            front = front->next;
//            delete tmp;
//            tmp = front;
//            rtn.m_len--;
//        }
//    }
//        //rhs is longer than this
//    else if (Compare(rhs) == 0) {
//        for (i = 0; i < m_len; i++) {
//            node *newNode = new node;
//            if (q->data < p->data) {
//                newNode->data = q->data - p->data + 10;
//                q->prev->data -= 1;
//            } else {
//                newNode->data = q->data - p->data;
//            }
//            p = p->prev;
//            q = q->prev;
//            front->prev = newNode;
//            newNode->next = front;
//            front = newNode;
//        }
//        for (i = 0; i < rhs.m_len; i++) {
//            node *newNode = new node;
//            newNode->data = q->data;
//            q = q->prev;
//            front->prev = newNode;
//            newNode->next = front;
//            front = newNode;
//        }
//        rtn.m_len = rhs.m_len;
//        node *tmp = front;
//        while (front->data == 0) {
//            front = front->next;
//            delete tmp;
//            tmp = front;
//            rtn.m_len--;
//        }
//    }
//        //the two numbers are exactly the same, result = 0
//    else {
//        node *newNode = new node;
//        newNode->data = 0;
//        front->prev = newNode;
//        newNode->next = front;
//        front = newNode;
//        rtn.m_len = 1;
//    }
//    rtn.m_pHead->next = front;
//    front->prev = rtn.m_pHead;
//    rtn.m_pTail = s->prev;
//    s->prev->next = nullptr;
//    delete s;
//    return rtn;
    Num result;
    node *front = new node;
    node *s = front;    //为了和原来的链表具有一样的结构，最后释放这个空的尾结点；
    node *p = m_pTail;
    node *q = rhs.m_pTail;
    if (Compare(rhs) == 2) {
        for (int i = 0; i < rhs.m_len; i++) {
            node *newNode = new node;
            if (p->data < q->data) {
                newNode->data = p->data - q->data + 10;
                p->prev->data -= 1;
            } else { newNode->data = p->data - q->data; }
            p = p->prev;
            q = q->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        for (int i = 0; i < m_len - rhs.m_len; i++) {
            node *newNode = new node;
            newNode->data = p->data;
            p = p->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        //去除前导0
        result.m_len = m_len;
        node *tmp = front;
        while (front->data == 0) {
            front = front->next;
            delete tmp;
            tmp = front;
            result.m_len--;
        }
    } else if (Compare(rhs) == 0) {
        for (int i = 0; i < m_len; i++) {
            node *newNode = new node;
            if (q->data < p->data) {
                newNode->data = q->data - p->data + 10;
                q->prev->data -= 1;
            } else { newNode->data = q->data - p->data; }
            p = p->prev;
            q = q->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        for (int i = 0; i < rhs.m_len - m_len; i++) {
            node *newNode = new node;
            newNode->data = q->data;
            q = q->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        //去除前导0
        result.m_len = rhs.m_len;
        node *tmp = front;
        while (front->data == 0) {
            front = front->next;
            delete tmp;
            tmp = front;
            result.m_len--;
        }
    } else {
        node *newNode = new node;
        newNode->data = 0;
        front->prev = newNode;
        newNode->next = front;
        front = newNode;
        result.m_len = 1;
    }
    result.m_pHead->next = front;
    front->prev = result.m_pHead;
    result.m_pTail = s->prev;
    s->prev->next = nullptr;
    delete s;
    return result;
}

int Num::Compare(const Num &rhs) const {
    if (m_len < rhs.m_len) {
        return 0;//<
    } else if (m_len > rhs.m_len) {
        return 2;//>
    } else  {
        node *p1 = m_pHead->next;
        node *p2 = rhs.m_pHead->next;
        int i = 1;
        while (i < m_len && p1->data == p2->data) {
            p1 = p1->next;
            p2 = p2->next;
            i++;
        }
        if (p1->data > p2->data) {
            return 2;//>
        } else if (p1->data < p2->data) {
            return 0;//<
        } else {
            return 1;//=
        }
    }
}

void Num::Compare_display(const Num &rhs) const {
    show();
    if (Compare(rhs) == 2) {
        cout << " > ";
    } else if (Compare(rhs) == 1) {
        cout << " == ";
    } else if (Compare(rhs) == 0) {
        cout << " < ";
    }
    rhs.show();
}

int main() {
    Num num1, num2, num3, num4;
    num1.read();
    num2.read();
    num1.Compare_display(num2);
    cout << endl;
    num3 = num1.Plus(num2);
    num4 = num1.Subtraction(num2);
    num3.show();
    cout << endl;
    num4.show();
}

/*   Num result;
    node *front = new node;
    node *s = front;    //为了和原来的链表具有一样的结构，最后释放这个空的尾结点；
    node *p = m_pTail;
    node *q = rhs.m_pTail;
    if (Compare(rhs) == 2) {
        for (int i = 0; i < rhs.m_len; i++) {
            node *newNode = new node;
            if (p->data < q->data) {
                newNode->data = p->data - q->data + 10;
                p->prev->data -= 1;
            } else { newNode->data = p->data - q->data; }
            p = p->prev;
            q = q->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        for (int i = 0; i < m_len - rhs.m_len; i++) {
            node *newNode = new node;
            newNode->data = p->data;
            p = p->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        //去除前导0
        result.m_len = m_len;
        node *tmp = front;
        while (front->data == 0) {
            front = front->next;
            delete tmp;
            tmp = front;
            result.m_len--;
        }
    } else if (Compare(rhs) == 0) {
        for (int i = 0; i < m_len; i++) {
            node *newNode = new node;
            if (q->data < p->data) {
                newNode->data = q->data - p->data + 10;
                q->prev->data -= 1;
            } else { newNode->data = q->data - p->data; }
            p = p->prev;
            q = q->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        for (int i = 0; i < rhs.m_len - m_len; i++) {
            node *newNode = new node;
            newNode->data = q->data;
            q = q->prev;
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        //去除前导0
        result.m_len = rhs.m_len;
        node *tmp = front;
        while (front->data == 0) {
            front = front->next;
            delete tmp;
            tmp = front;
            result.m_len--;
        }
    } else {
        node *newNode = new node;
        newNode->data = 0;
        front->prev = newNode;
        newNode->next = front;
        front = newNode;
        result.m_len = 1;
    }
    result.m_pHead->next = front;
    front->prev = result.m_pHead;
    result.m_pTail = s->prev;
    s->prev->next = nullptr;
    delete s;
    return result;
    */