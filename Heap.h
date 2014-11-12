#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 *
 */
template<class Pri, class T>
class Heap : public Queue < std::pair<Pri, T> > {
public:
	Heap();
	~Heap();

	//Add a new item
	virtual void add(std::pair<Pri, T> toAdd);

	//Remove the item with lowest priority, and return it
	//If the queue is empty, throw a string exception
	virtual std::pair<Pri, T> remove();

	//Return the number of items currently in the queue
	virtual unsigned long getNumItems();

private:
	int arrSize;
	int numItems;
	std::pair<Pri, T>* backingArray;

	//Grow the backingArray by making a new array of twice the size,
	// and copying over the data
	void grow();

	//Check the item at index, and make sure it is in the right place.
	// If not, swap it up the "tree" of the heap until you find the right
	// place
	void bubbleUp(unsigned long index);

	//Check the item at index, and make sure it is in the right place.
	// If not, swap it down the "tree" of the heap until you find the right
	// place
	void trickleDown(unsigned long index);
};

#include <string>

/*
Caroline Danzi
11 November 2014

Heap lab
Originality Note: I worked alone on this project.  I went to Dr. Brinkman's
office hours for help, but did not consult with other students.
*/

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	arrSize = START_SIZE;
	backingArray = new std::pair<Pri, T>[arrSize];
	numItems = 0;
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	delete[] backingArray;
	backingArray = NULL;
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){
	// Make a new array that is two times larger than the current array
	arrSize = 2 * arrSize;
	std::pair<Pri, T>* newArray = new std::pair<Pri, T>[arrSize];

	// Copy over the items from the backing array
	for (int i = 0; i < numItems; i++){
		newArray[i] = backingArray[i];
	}
	// Make backingArray point to the new array, and delete
	// the old backing array
	delete[] backingArray;
	backingArray = newArray;
	newArray = NULL;
}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	// If adding another item will go beyond the end of the
	// array, grow the Heap
	if (numItems + 1 > arrSize){
		grow();
	}
	// Put the item at the end of the array (index = numItems)
	// and "bubble it up" to where it should stay. Increase numItems.
	backingArray[numItems] = toAdd;
	bubbleUp(numItems);
	numItems++;
}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	// If we just added the first element, we do not need
	// to bubbleUp
	if (index == 0){
		return;
	}
	// If the item at the index's priority is less than 
	// its parent's priority, swap them and then continue 
	// to bubble up. Note: the parent of a node at index i 
	// can be found at index (i-1)/2
	else if (backingArray[index].first < backingArray[(index - 1) / 2].first){
		std::pair<Pri, T> temp = backingArray[(index - 1) / 2];
		backingArray[(index - 1) / 2] = backingArray[index];
		backingArray[index] = temp;

		bubbleUp((index - 1) / 2);
	}
	// Else if the item's parent's priority is less than or equal to
	// this item's priority, keep them where they are and just return
	else{
		return;
	}

}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	// If the current priority is greater than one of its children's 
	// priorities, switch it with the child with lower priority
	// Swap and call trickleDown again with the index of the child we replaced

	// Find the indices of the children. The left child will
	// be at index*2+1, and the right child will be at index*2+2
	int leftChild = index * 2 + 1;
	int rightChild = index * 2 + 2;

	// Put in a case that will prevent trickleDown when there
	// are no children. There may still be values in the array 
	// past the last item, which can cause issues if we try to 
	// check for children at indices beyond the last value still
	// in the Heap.
	if (leftChild >= numItems && rightChild >= numItems){
		return;
	}
	// If the left child has lower priority and the left child
	// has lower priority than the right child, swap with the left
	else if (backingArray[index].first > backingArray[leftChild].first && backingArray[leftChild].first < backingArray[rightChild].first){
		std::pair<Pri, T> temp = backingArray[index];
		backingArray[index] = backingArray[leftChild];
		backingArray[leftChild] = temp;
		trickleDown(leftChild);
	}
	// If the right child has lower priority and the right child
	// has lower priority than the left child, swap with the right
	else if (backingArray[index].first > backingArray[rightChild].first && backingArray[rightChild].first < backingArray[leftChild].first){
		std::pair<Pri, T> temp = backingArray[index];
		backingArray[index] = backingArray[rightChild];
		backingArray[rightChild] = temp;
		trickleDown(rightChild);
	}
	else{
		return;
	}
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	if (numItems == 0)
		throw new std::string("Tried to remove from an empty Queue");

	std::pair<Pri, T> removedItem = backingArray[0];

	// Put the item in the last spot of the array into
	// the first spot (last index = numItems - 1)
	numItems--;
	backingArray[0] = backingArray[numItems];

	// Swap the item to the correct location in the array
	trickleDown(0);

	return removedItem;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}
