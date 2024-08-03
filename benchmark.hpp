#ifndef _BENCHMARK_HPP
#define _BENCHMARK_HPP

#include <iostream>
#include <time.h>
#include <functional>

template <typename T, typename U>
T benchmark(std::function<T (U) > func, U arg)
{
    clock_t t1, t2;
    t1 = clock();
    if (std::is_same<T, void>::value) {
        func(arg);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return;
    }
    else {
        T res = func(arg);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return res;
    }
}

template <typename T, typename U, typename V>
T benchmark(std::function<T (U, V)> func, U arg1, V arg2)
{
    clock_t t1, t2;
    t1 = clock();
    if (std::is_same<T, void>::value){
        func(arg1, arg2);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return;
    }
    else {
        T res = func(arg1, arg2);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return res;
    }
}

template <typename T, typename U, typename V, typename W>
T benchmark(std::function<T (U, V, W)> func, U arg1, V arg2, W arg3)
{
    clock_t t1, t2;
    t1 = clock();
    if (std::is_same<T, void>::value){
        func(arg1, arg2, arg3);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return;
    }
    else {
        T res = func(arg1, arg2, arg3);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return res;
    }

    t2 = clock();
    std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
}

template <typename T, typename U, typename V, typename W, typename X>
T benchmark(std::function<T (U, V, W, X)> func, U arg1, V arg2, W arg3, X arg4)
{
    clock_t t1, t2;
    t1 = clock();
    if (std::is_same<T, void>::value) {
        func(arg1, arg2, arg3, arg4);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return;
    }
    else {
        T res = func(arg1, arg2, arg3, arg4);
        t2 = clock();
        std::cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << "s\n";
        return res;
    }
}

#endif