#include<iostream>

using namespace std;

class A
{
    public:
    A(int a)
    {
        cout<< "A()..."<<a <<endl;
        m_a = a;
    }
    ~A()
    {
        cout<< "~A()..." <<endl;
    }
    void printfA(){
        cout << "a= "<<m_a<<endl;
    }
    private:
    int m_a;
};

class B
{
    public:
    B(A &a1,A &a2,int b):m_a1(a1),m_a2(a2)
    {
        cout <<  "B(A&,A&,int)..."<<endl;
        m_b =b;
    }
    // 构造对象成员的顺序跟初始化列表无关
    // 而是跟成员对象的定义顺序有关
    B(int a1,int a2,int b):m_a1(a1),m_a2(a2)
    {
        cout <<  "B(int,int,int)..."<<endl;
        m_b =b;
    }
    void printfB()
    {
        cout<< "b = "<<m_b<<endl;
        m_a1.printfA();
        m_a2.printfA();
    }
    ~B()
    {
        cout << "~B().."<<endl;
    }
    private:
    int m_b;
    A m_a1;
    A m_a2;
};


int main()
{
    A a1(10),a2(100);
    B b1(a1,a2,1000);
    b1.printfB();
    return 0;
}
