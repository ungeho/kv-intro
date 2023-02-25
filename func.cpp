#include <iostream>
#include <kv/interval.hpp>
#include <kv/dd.hpp>
#include <kv/rdd.hpp>
#include <kv/mpfr.hpp>

// #define MPFR_FLG
// #define DD_FLG

#ifdef MPFR_FLG
    typedef kv::interval<kv::mpfr<106>> itv;
#ifdef DD_FLG
    typedef kv::interval<kv::dd> itv;
#else
    typedef kv::interval<double> itv;
#endif

template <class T>
T func(T x)
{
    itv pi;
    pi = kv::constants<itv>::pi();
     return (T)1.0 / exp((T)0.5 * x / pi);
}

int main(void)
{
    itv x,res;
    x = 0.1;
    res = func(x);
    std::cout.precision(17);
    std::cout << "  x  = " << x << '\n';
    std::cout << "f(x) = " << res << '\n';
    return 0;
}
