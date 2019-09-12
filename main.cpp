#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#define SIZE 11
using namespace std;


/*
 *This program reads strings from a text file, and utilizes the heap sorting method to
 *alphabetize the input
 *
 *Data Structures @ TCC
 *
 *Arick Mounts
 */
void heapify(string arry[], int i, int heap_size);
void build_heap(string arry[], int heap_size);
void heap_sort(string arry[], int size);
void swap(string arry[], int a, int b);
int right(int i);
int left(int i);
void fill_array(string arry[], int size);

int main() {
  string mainArr[SIZE];
  fill_array(mainArr, SIZE);
  
  

  heap_sort(mainArr, SIZE);
  
  for (int i = 1; i < SIZE+1 ; i++){
    cout << mainArr[i] << endl;
  }
}

void fill_array(string arry[], int size){
  
  ifstream filein;
  filein.open("Input.txt");
  for (int i = 0; i < SIZE; i++){
    getline(filein, arry[i]);
  }
  filein.close();

}

void build_heap(string arry[], int heap_size){
  int i;
  for (i = floor(heap_size /2); i >=0; i--){
    heapify(arry, i, heap_size);
  }
  return;
}

void heap_sort(string arry[], int size){
  build_heap(arry, size);

  int i = 0;
  int working_size = size ;
  for (int i = size ; i >= 1; i--){
    swap(arry, i , 0);
    working_size--;

    heapify(arry, 0, working_size);
    
  }
}

void heapify(string arry[], int i, int heap_size){
  int l = left( i );
  int r = right( i );
  int smallest = i;
  if(l <= heap_size && arry[ l ] > arry[i]){
    smallest = l;
  }

  if( r <= heap_size && arry[ r ] > arry[ smallest ]){
    smallest = r;
  }

  if( smallest != i){
    swap( arry, i, smallest);
    heapify(arry, smallest, heap_size);
    
  }
}

int left(int i){
  return (2*i) + 1;
}


int right(int i){
  return (2*i) + 2;
}

void swap(string arry[], int a, int b){
  string temp = arry[ a ];
	arry[ a ] = arry[ b ];
	arry[ b ] = temp;
}
