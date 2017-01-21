#include <iostream>
using namespace std;

void print(int a[], int size) {
    for (int i = 0; i < size; i++) cout << a[i];
    cout << endl;
}

void count_recur(int begin[], int end[], int size, int current[], int index) {
    for (int i = begin[index]; i < end[index]; i++) {
        current[index] = i;
        if (index == size - 1) print(current, size);
        else count_recur(begin, end, size, current, index + 1);
    }
}

void count_recursive(int begin[], int end[], int size) {
    int *current = new int[size];
    count_recur(begin, end, size, current, 0);
    delete [] current;
}

int main()
{
    int begin[4] = {1,1,1,1};
    int end[4] = {3,5,4,6};
    count_recursive(begin, end, 4);
    return 0;
}
