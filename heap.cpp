// heap.cpp
// Albert Nguyen

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  // add value to end
  vdata.push_back(value);

  // reorganize heap
  int i = vdata.size() - 1;
  while (i > 0){
    int parent = (i - 1) / 2;
    if (vdata[i] < vdata[parent]){
      int temp = vdata[i];
      vdata[i] = vdata[parent];
      vdata[parent] = temp;
      i = parent;
    }
    else {
      break;
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
      if (vdata.empty()) return;

    // replace root with last element
    vdata[0] = vdata.back();
    vdata.pop_back();

    // heapify down from root to restore min-heap property
    int i = 0;
    int n = vdata.size();

    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < n && vdata[left] < vdata[smallest])
            smallest = left;
        if (right < n && vdata[right] < vdata[smallest])
            smallest = right;

        if (smallest != i) {
            int temp = vdata[i];
            vdata[i] = vdata[smallest];
            vdata[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
}


// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    