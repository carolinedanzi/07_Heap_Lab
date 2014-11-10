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

	// If the left child (at index * 2 + 1) has lower priority
	if (backingArray[index].first > backingArray[index * 2 + 1].first && backingArray[index * 2 + 1].first < backingArray[(index + 1) * 2].first){
		std::pair<Pri, T> temp = backingArray[index];
		backingArray[index] = backingArray[index * 2 + 1];
		backingArray[index * 2 + 1] = temp;
		trickleDown(index * 2 + 1);
	}
	// If the right child (at (index + 1) * 2) has lower priority
	else if (backingArray[index].first > backingArray[(index + 1) * 2].first && backingArray[(index + 1) * 2].first < backingArray[index * 2 + 1].first){
		std::pair<Pri, T> temp = backingArray[index];
		backingArray[index] = backingArray[(index + 1) * 2];
		backingArray[(index + 1) * 2] = temp;
		trickleDown((index + 1) * 2);
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
