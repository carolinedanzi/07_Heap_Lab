07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. I think I met this requirement. Grow is definitely O(n) because it copies over all the elements to a new array. Add and remove call bubbleUp and trickleDown, respectively, and I think each takes O(lgn) time. To be honest, though, I am not quite sure. I am a little confused as to what O(lgn) means.
2. I do not think I leaked memory.  I was sure to delete the backingArray in the destructor and grow, and set the pointers to NULL.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
#####10.1 - Adding 7 to the Heap, shown through implicit representation:
| 4 | 9 | 6 | 17 | 26 | 8 | 16 | 19 | 69 | 32 | 93 | 55 | 50 | **7** | Seven is added to the end of the array

| 4 | 9 | 6 | 17 | 26 | 8 | **7** | 19 | 69 | 32 | 93 | 55 | 50 | **16**| Seven swaps with its parent, 16, since it is smaller. The new parent of seven is now 6, so we no longer need to "bubbleUp" and swap the values. Seven is in the correct location.
#####10.1 - Adding 3 to the Heap, shown through implicit representation: 
| 4 | 9 | 6 | 17 | 26 | 8 | 7 | 19 | 69 | 32 | 93 | 55 | 50 | 16 | **3** | Three is added to the end of the array

| 4 | 9 | 6 | 17 | 26 | 8 | **3** | 19 | 69 | 32 | 93 | 55 | 50 | 16 | **7** | Three swaps with its parent, 7, since it is smaller.

| 4 | 9 | **3** | 17 | 26 | 8 | **6** | 19 | 69 | 32 | 93 | 55 | 50 | 16 | 7 | Three swaps with its parent, 6, since it is smaller.

| **3** | 9 | **4** | 17 | 26 | 8 | 6 | 19 | 69 | 32 | 93 | 55 | 50 | 16 | 7 | Finally, three swaps with its parent, 4, since it is smaller. The swapping stops here - three is the minimum value in the entire Heap, so it has higher priority and thus is at the front of the array (or, to think of the explicit representation, it is the first node).
#####10.2 - Removing 6, as shown through the implicit representation: 
| 6 | 9 | 8 | 17 | 26 | 50 | 16 | 19 | 69 | 32 | 93 | 55 | The array before removing

| **55** | 9 | 8 | 17 | 26 | 50 | 16 | 19 | 69 | 32 | 93 | Six is removed from the array and 55 takes its place

| **8** | 9 | **55** | 17 | 26 | 50 | 16 | 19 | 69 | 32 | 93 | Fifty-five swaps with its smaller child, 8

| 8 | 9 | **16** | 17 | 26 | 50 | **55** | 19 | 69 | 32 | 93 | Fifty-five swaps with its smaller child, 16.  It has no more children, so it has reached the correct location.
#####10.2 - Removing 8, as shown through the implicit representation: 
| 8 | 9 | 16 | 17 | 26 | 50 | 55 | 19 | 69 | 32 | 93 | The array before removing

| **93** | 9 | 16 | 17 | 26 | 50 | 55 | 19 | 69 | 32 | Eight is removed and replaced with 93

| **9** | **93** | 16 | 17 | 26 | 50 | 55 | 19 | 69 | 32 | Ninety-three swaps with 9, its smaller child

| 9 | **17** | 16 | **93** | 26 | 50 | 55 | 19 | 69 | 32 | Nintey-three swaps with 17, its smaller child

| 9 | 17 | 16 | **19** | 26 | 50 | 55 | **93** | 69 | 32 | Ninety-three swaps with 19, its smaller child. It has no more children, so the swapping stops here.
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
For a tree with d children that is implemented using an array, the following functions can be used to find the index of a node's parent and d children.  To find the parent, subtract one from the index and multiply by d: **parent = (i-1)*d** For example, in a tree with d=3, nodes 1, 2, and 3 will have parent 0. (1-1)/3 = 0; (2-1)/3 = 0; and (3-1)/3 = 0.
To find the nth child (1st child, 2nd child, etc.) the equation is this: **nth child = (i*d) + n**. In the previous example of a d=3 tree, the children of 0 are (0*3)+1 = 1; (0*3)+2 = 2; and (0*3)+3 = 3.  
#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I am a little confused about O(lgn) time. I know it has something to do with the fact that this is a binary tree (base 2), but I do not quite understand where lgn comes from. 