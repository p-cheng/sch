#include <iostream>

using namespace std;
class Test
{
    public:
        Test(int a,int b):m_a(a),m_b(b)
    {
        cout << "Test(int ,int)"<<endl;
    }
    ~Test()
    {
        cout<< " ~Test() ..."<<endl;
    }
    void printT()
    {
        cout <<"a= "<<this->m_a << ",b ="<<this->m_b <<endl;
    }
    int getA()
    {

        return this->m_a;
    }
    int getB()
    {
        return this->m_b;
    }
    Test Testadd3(Test &another)
    {
        Test temp(this->m_a+another.m_a,this->m_b+another.m_b);
        return temp;
    }
    Test& Testadd4(Test &another)
    {
        this->m_a+=another.m_a;
        this->m_b+=another.m_b;
        return *this;
    }
    private:
    int m_a;
    int m_b;
};

Test Testadd(Test &t1,Test &t2)
{
    Test temp(t1.getA()+t2.getA(),t1.getB()+t2.getB());
    return temp;
}


int main()
{
    Test t1(10,20);
    Test t2(100,200);

    Test t3 = Testadd(t1,t2);
    t3.printT();
    t1 = t1.Testadd3(t2);
    t3.printT();
    t1.Testadd4(t2);
    t1.printT();
    t1.Testadd4(t2).Testadd4(t2);
    t1.printT();
    return 0;
}
