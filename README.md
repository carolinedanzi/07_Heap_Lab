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

1. TODO
2. TODO

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
#####10.1 - Adding 7 to the Heap, shown through implicit representation:
| 4 | 9 | 6 | 17 | 26 | 8 | 16 | 19 | 69 | 32 | 93 | 55 | 50 | **7** | Seven is added to the end of the array

| 4 | 9 | 6 | 17 | 26 | 8 | **7** | 19 | 69 | 32 | 93 | 55 | 50 | **16**| Seven swaps with its parent, 16, since it is smaller. The new parent of seven is now 6, so we no longer need to "bubbleUp" and swap the values. Seven is in the correct location.
#####10.1 - Adding 3 to the Heap, shown through implicit representation: 
| 4 | 9 | 6 | 17 | 26 | 8 | 7 | 19 | 69 | 32 | 93 | 55 | 50 | 16 | **3** | Three is added to the end of the array

| 4 | 9 | 6 | 17 | 26 | 8 | **3** | 19 | 69 | 32 | 93 | 55 | 50 | 16 | **7** | Three swaps with its parent, 7, since it is smaller.
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO