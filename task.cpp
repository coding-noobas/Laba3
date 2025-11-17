#include <iostream>
#include <cmath>

bool is_natural (int x){
    return x > 0 && static_cast<int>(x) == x;
}

void fail (){
    std::cout << "You've probably messed up the input. You were probably asked to enter a natural number and you entered something else, or you were simply asked to enter a number and you entered a letter. Very bad!\n";
    exit(0);
}

void solve(int n, long double* a){
    int flag = 0;
    long double sum = 0, usum = 0, x = 0;
    for(int i = 0;i < n;++i){
        if(a[i] < 0){
            flag = 1;
            usum = 0;
        }
        if(flag == 1) {
            sum += a[i];
        }
        if(a[i] >= 0) {
            usum += a[i];
        }
    }
    sum -= usum;
    std::cout << "Sum of elements between first and last negative elements is equal: " << sum << "\n";
    std::cout << "Enter the pivot element by which the array will be sorted: ";
    std::cin >> x;
    std::cout << "First, the numbers less than X but without changing the order: ";
    for(int i = 0;i < n;++i){
        if(abs(a[i]) <= x) std::cout << a[i] << " ";
    }
    for(int i = 0;i < n;++i){
        if(abs(a[i]) > x) std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int n, ind_mn, flag = 0;
    long double  a[100000], sum = 0, usum = 0, x, mn = 1e8;
    std::cout << "Enter length of array(natural number): ";
    std::cin >> n;
    if(!is_natural(n)) {
        fail();
    }
    std::cout << "Enter elements of array: ";
    for(int i = 0;i < n;++i){
        std::cin >> a[i];
        if(a[i] <= mn) {
            ind_mn = i, mn = a[i];
        }
    }
    std::cout << "Number of minimal element: " << ind_mn + 1 << "\n";
    solve(n, a);
    return 0;
}
