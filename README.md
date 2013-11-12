Author
==========
"Monnin, Sebastian", monninse
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

1. add and remove work as they are supposed to, I think
2. no memory leaks

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
TODO

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
parent= (index-1)/2
right=2index+2
left=2index+1
#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
I actually didn't have any problems with this exercise oddly. I thought the book was really helpful, tell the other students to use the book and read it a lot for this one.
