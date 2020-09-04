
// 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template<typename T>
void swaps(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
void output(T a, T b)
{
    std::cout << a << " - " << b << std::endl;
}

template<typename T>
void result(T a, T b)
{
    output(a, b);
    swaps(a, b);
    output(a, b);
}

int main()
{
    int i1 = 1, i2 = 2;
    unsigned int ui1 = 1, ui2 = 2;
    short s1 = 1, s2 = 2;
    unsigned short us1 = 1, us2 = 2;
    long l1 = 1, l2 = 2;
    unsigned long ul1 = 1, ul2 = 2;
    long long ll1 = 1, ll2 = 2;
    unsigned long long ull1 = 1, ull2 = 2;
    double d1 = 0.1, d2 = 0.2;
    long double ld1 = 0.1, ld2 = 0.2;
    float f1 = 0.1, f2 = 0.2;

    result(i1,i2);
    result(ui1,ui2);
    result(s1,s2);
    result(us1,us2);
    result(l1,l2);
    result(ul1,ul2);
    result(ll1,ll2);
    result(ull1,ull2);
    result(d1,d2);
    result(ld1,ld2);
    result(f1,f2);

    system("pause");
    return 0;
}
