#include <iostream>
using namespace std;

void print(int a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i];
    }
    cout << endl;
}

void count_3(int begin[], int end[]){
    int current[3];
    for(int i=begin[0];i<end[0];i++){
        current[0]=i;
        for(int j= begin[1];j<end[1];j++){
            current[1]=j;
            for(int k = begin[2]; k<end[2];k++){
                current[2]=k;
                print(current,3);
            }
        
        }
    }   
}

int main()
{
  int begin[3]={1,1,1};
  int end[3]={3,5,4};
  count_3(begin, end);
  return 0;
  
  
}
