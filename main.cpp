#include "Heap.h"
#include <string>
#include <iostream>

void testHeap(){
  Heap<int,std::string> myHeap;
  myHeap.add(std::make_pair(5,"5"));
  myHeap.add(std::make_pair(1,"1"));
  myHeap.add(std::make_pair(0,"0"));
  myHeap.add(std::make_pair(7,"7"));
  myHeap.add(std::make_pair(10,"10"));
  
  if(myHeap.getNumItems() != 5){
    std::cout << "ERROR: Expected 5 items, but got " << myHeap.getNumItems() << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Found 5 items, as expected." << std::endl;
  }

  std::pair<int,std::string> item;
  item = myHeap.remove();
  if(item.first != 0){
    std::cout << "ERROR: Expected key 0, but got " << item.first << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Found item 0 as expected." << std::endl;
  }

  if(myHeap.getNumItems() != 4){
    std::cout << "ERROR: Expected 4 items, but got " << myHeap.getNumItems() << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Found 4 items, as expected." << std::endl;
  }

  item = myHeap.remove();
  if(item.first != 1){
    std::cout << "ERROR: Expected key 1, but got " << item.first << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Found item 1 as expected." << std::endl;
  }

  item = myHeap.remove();
  if(item.first != 5){
    std::cout << "ERROR: Expected key 5, but got " << item.first << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Found item 5 as expected." << std::endl;
  }

  item = myHeap.remove();
  if(item.first != 7){
    std::cout << "ERROR: Expected key 7, but got " << item.first << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Found item 7 as expected." << std::endl;
  }

  item = myHeap.remove();
  if(item.first != 10){
    std::cout << "ERROR: Expected key 10, but got " << item.first << std::endl;
    exit(1);
  } else {
    std::cout << "SUCCESS: Found item 10 as expected." << std::endl;
  }

}

int main(){
  testHeap();
  Heap<int, std::string> testHeap;
  testHeap.add(std::make_pair(1, "1"));
  testHeap.add(std::make_pair(2, "2"));
  testHeap.add(std::make_pair(3, "3"));
  testHeap.add(std::make_pair(4, "4"));
  testHeap.add(std::make_pair(5, "5"));
  testHeap.add(std::make_pair(6, "6"));
  testHeap.add(std::make_pair(7, "7"));
  testHeap.add(std::make_pair(8, "8"));
  testHeap.add(std::make_pair(9, "9"));
  testHeap.add(std::make_pair(10, "10"));
  // Add one more to make the array grow
  testHeap.add(std::make_pair(11, "11"));

  std::cout << testHeap.getNumItems() << std::endl;

  Heap<int, std::string> remTest;
  remTest.add(std::make_pair(0, "0"));
  remTest.add(std::make_pair(1, "1"));
  remTest.add(std::make_pair(2, "2"));
  remTest.remove();
  std::pair<int, std::string> removedItem = remTest.remove();
  std::pair<int, std::string> removedLast = remTest.remove();

  std::cout << "Removed item should be 1 and it is: " << removedItem.first << std::endl;
  std::cout << "Removed last item should be 2: " << removedLast.first << std::endl;

  try{
	  remTest.remove();
  }
  catch (std::string e){
	  std::cout << "Caught exception: " << e << std::endl;
  }

  return 0;
}
