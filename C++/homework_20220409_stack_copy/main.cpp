#include  <iostream>
#include  <algorithm>

using namespace std;

class CStack {
public  :

    CStack() : m_sp(nullptr)          //构造函数
    {}

    ~CStack();                                  //析构函数
    CStack(const CStack &rhs);//复制构造

    CStack &operator=(const CStack &rhs);//运算符重载 复制

    CStack(CStack &&rhs);//移动构造

    CStack &operator=(CStack &&rhs);//运算符重载 移动

    void push(int x);          //入栈
    bool empty() const;    //判栈空
    int top() const;        //非空时取栈顶元素
    void pop();                          //非空时出栈
private  :
    struct Node      //  内嵌结点类
    {
        Node() : next(nullptr) {}    //结点建立时指针域值为nullptr
        int data;
        Node *next;
    };

    Node *m_sp;                            //链表首指针
};

CStack::~CStack() {
    //删除所有结点
    while (m_sp != nullptr) {
        Node *p = m_sp;              //临时指针变量p
        m_sp = m_sp->next;
        delete p;                          //删除p所指结点，删除后不可使用该结点
    }
}

void CStack::push(int x) {
    Node *p = new Node;                //动态分配1个结点
    p->data = x;
    p->next = m_sp;
    m_sp = p;
}

bool CStack::empty() const {
    return (m_sp == nullptr);
}

int CStack::top() const {
    return m_sp->data;
}

void CStack::pop() {
    Node *p = m_sp;
    m_sp = p->next;
    delete p;
}

//将栈内所有元素出栈并显示
void DumpStack(CStack &S) {
    while (!S.empty()) {
        int x;
        x = S.top();
        cout << x << "  ";
        S.pop();
    }
    cout << endl;
}

//栈的拷贝构造代码
CStack::CStack(const CStack &rhs) {
    if (rhs.m_sp != nullptr) {
        m_sp = new Node;
        m_sp->data = rhs.m_sp->data;
        Node *me = m_sp;
        Node *p = rhs.m_sp->next;
        while (p) {
            Node *tmp = new Node;
            tmp->data = p->data;
            tmp->next = me->next;
            me->next = tmp;
            me = tmp;
            p = p->next;
        }
        me->next = nullptr;
    } else {
        m_sp = nullptr;
    }
}

//栈的复制赋值代码
CStack &CStack::operator=(const CStack &rhs) {
    CStack(tmp) = rhs;
    Node *t = m_sp;
    m_sp = tmp.m_sp;
    tmp.m_sp = t;
    return *this;
}

//栈的移动构造代码
CStack::CStack(CStack &&rhs) {
    m_sp = rhs.m_sp;
    rhs.m_sp = nullptr;
}

//栈的移动赋值代码
CStack &CStack::operator=(CStack &&rhs) {
    Node *tmp = m_sp;
    m_sp = rhs.m_sp;
    rhs.m_sp = tmp;
    return *this;
}

//测试函数
int main() {
    CStack S1, S2;
    int v, x;

    while (cin >> v >> x) {
        if (v == 1)
            S1.push(x);
        else
            S2.push(x);
    }

    CStack S3(S1), S4, tmp1(S1), tmp2 = S2;
    S4 = S2;
    S1.push(100);
    S2.push(200);
    S3.push(300);
    S4.push(400);

    CStack S6 = S3, S5(std::move(tmp1));  //指定移动构造
    S6 = std::move(tmp2);  //指定移动赋值
    S5.push(500);
    S6.push(600);

    DumpStack(S1);
    DumpStack(S2);
    DumpStack(S3);
    DumpStack(S4);
    DumpStack(S5);
    DumpStack(S6);
}