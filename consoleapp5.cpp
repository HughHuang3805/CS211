// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

	void print(int current[], int size){
		for (int i = 0; i < size; i++){
			cout << current[i];
		}
		cout << endl;
	}
	void count_nested_3(int begin[], int end[]){
		int current[3];
		for (int i = begin[0]; i < end[0]; i++){
			current[0] = i;
			for (int j = begin[1]; j < end[1]; j++){
				current[1] = j;
				for (int k = begin[2]; k < end[2]; k++){
					current[2] = k;
					print(current, 3);
				}
			}
		}
	}
	void count_recur(int begin[], int end[], int size, int current[], int index){
		for (int i = begin[index]; i < end[index]; i++){
			current[index] = 1;
			if (index == size - 1) print(current, size);
			else count_recur(begin, end, size, current, index + 1);
		}
	}

	void count_recursive(int begin[], int end[], int size){
		int *current = new int[size];
		count_recur(begin, end, size, current, 0);
		delete[] current;
	}

	void count_goto(int begin[], int end[], int size){
		int *current = new int[size];
		for (int i = 0; i < size; i++) current[i] = begin[i];
		int index;

	add:
		print(current, size);
		index = size - 1;
	carry:
		if (current[index] < end[index] - 1){
			current[index]++;
			goto add;
		}
		else if (index>0){
			current[index] = begin[index];
			index--;
			goto carry;
		}
		delete[] current;
	}
	void count_while(int begin[], int end[], int size){
		int *current = new int[size];
		for (int i = 0; i < size; i++) current[i] = begin[i];
		int index;

		while (1){
			print(current, size);
			index = size - 1;
			while (1){
				if (current[index] < end[index] - 1){
					current[index]++;
					break;
				}
				else if (index>0){
					current[index] = begin[index];
					index--;
				}
				else{
					delete[] current;
					return;
				}
			}
		}
	}

	void count_for(int begin[], int end[], int size){
		int *current = new int[size];
		for (int i = 0; i < size; i++) current[i] = begin[i];
		int index;

		do{
			print(current, size);
			for (index = size - 1; current[index] == end[index] - 1 && index > 0; index--){
				current[index] = begin[index];
			}
			current[index]++;
		} while (index > 0 || current[0] < end[0]);
		delete[] current;
	}
	int _tmain(int argc, _TCHAR* argv[])
	{
		int begin[3] = { 1, 1, 1 };
		int end[3] = { 3, 5, 4 };
		//count_nested_3(begin, end);
		//system("pause");
		//count_recursive(begin, end, 3);
		//system("pause");
		//count_goto(begin, end, 3);
		//system("pause");
		count_while(begin, end, 3);
		system("pause");
		//count_for(begin, end, 3);
		return 0;
	}

