#include <iostream>
#include <cmath>

void is_natural(int32_t* x) {
    while (!(std::cin >> *x) || *x < 0) {
        std::cout << "Please enter NATURAL number: ";
    }
}

void is_number(long double* x) {
    while (!(std::cin >> *x)) {
        std::cout << "Please enter NUMBER: ";
    }
}

void summ(int32_t n, long double* a) {
    int32_t flag = 0;
    long double sum = 0, usum = 0;
    for (int32_t i = 0; i < n; ++i) {
        if (a[i] < 0) {
            flag = 1;
            usum = 0;
        }
        if (flag == 1) {
            sum += a[i];
        }
        if (a[i] >= 0) {
            usum += a[i];
        }
    }
    sum -= usum;
    std::cout << "Sum of elements between first and last negative elements is equal: " << sum << "\n";
}

void srt(int32_t n, long double* a) {
    long double x{};
    std::cout << "Enter the pivot element by which the array will be sorted: ";
    std::cin >> x;
    std::cout << "First, the numbers less than X but without changing the order: ";
    for (int32_t i = 0; i < n; ++i) {
        if (abs(a[i]) <= x) std::cout << a[i] << " ";
    }
    for (int32_t i = 0; i < n; ++i) {
        if (abs(a[i]) > x) std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int32_t main()
{
    int32_t n, ind_mn, flag = 0;
    long double  a[100000], sum = 0, usum = 0, x, mn = 1e8;
    std::cout << "Enter length of array(natural number): ";
    is_natural(&n);
    std::cout << "Enter elements of array: ";
    for (int32_t i = 0; i < n; ++i) {
        is_number(&a[i]);
        if (a[i] <= mn) {
            ind_mn = i, mn = a[i];
        }
    }
    std::cout << "Number of minimal element: " << ind_mn + 1 << "\n";
    summ(n, a);
    srt(n, a);
    return 0;
}
