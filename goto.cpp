#include <iostream>
using namespace std;

void print(int a[], int size) {
    for (int i = 0; i < size; i++) cout << a[i];
    cout << endl;
}

void count_goto(int begin[], int end[], int size) {
    int *current = new int[size];
    for (int i = 0; i < size; i++) current[i] = begin[i]; // INIT
    int index;
    add:
        print(current, size);
        index = size - 1;
        carry:
            if (current[index] < end[index] - 1) {
                current[index]++;
                goto add;
            }
            else if (index > 0) {
                current[index] = begin[index];
                index--;
                goto carry;
            }
    
    delete [] current;
}

int main()
{
    int begin[4] = {0,0};
    int end[4] = {10,10};
    count_goto(begin, end, 2);
    return 0;
}
