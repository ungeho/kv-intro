#include <iostream>
#include <kv/interval.hpp>
#include <kv/dd.hpp>
#include <kv/rdd.hpp>
#include <kv/mpfr.hpp>
#include <kv/rmpfr.hpp>

/*
ITV_FLG
区間の値をdoubleにする場合はITV_FLGに0を設定
double-doubleにする場合はITV_FLGに1を設定
コンパイルは  g++ func.cpp -O3 -DNDEBUG
mpfrを使う場合はITV_FLGに2を設定
kv::mpfr<N>のNは精度(bit)を設定
単精度24bit倍精度53bit四倍精度113bit八倍精度237bit
コンパイルは g++ func.cpp -lmpfr -O3 -DNDEBUG
*/
#define ITV_FLG 2

#if ITV_FLG == 2
    typedef kv::interval<kv::mpfr<53>> itv;
#elif ITV_FLG == 1
    typedef kv::interval<kv::dd> itv;
#else
    typedef kv::interval<double> itv;
#endif

template <class T>
T func(T x)
{
    itv pi;
    pi = kv::constants<itv>::pi();
     return (T)"1.0" / exp((T)"0.5" * x / pi);
}

int main(void)
{
    itv x,res;
    x = "0.1";
    res = func(x);
    std::cout.precision(17);
    std::cout << "  x  = " << x << '\n';
    std::cout << "f(x) = " << res << '\n';
    return 0;
}
