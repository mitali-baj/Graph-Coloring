# Graph-Coloring
Exam Scheduler using Graph Coloring
Timetable scheduling is a complex and time-consuming real-life problem. In this 
project, we have attempted to provide a solution to the problem with the help of 
graph coloring technique. We have assumed each student to give 3 subject exams. 
We aim to find schedule in such a way that no subject exam time shares common 
students. Input is taken with subject codes, and stored in linked list with each 
node containing information of a student. The linked list data is processed to 
create adjacency matrix. The graph is made such that each vertex represents a 
subject. Graph coloring is carried out. Output generates a timetable with 
minimum number of time slots required for conducting the examinations. 
Minimal constraints are provided as a pilot for this project. In real life, the graph 
coloring can be carried out with additional hard and soft constraints.

Algorithm:
1. We input from students roll no, subject1 code, subject2 code, subject3 
code.
2. Linked list is created with each node containing
Roll_no Sub1 code Sub2 code Sub3 code next
A new node is created for each student registering.
3. Linked list is traversed to store interconnections between the three subjects,
for each node in the adjacency matrix. Adjacency matrix is 10X10 for 10 
subjects.
4. Graph coloring function is called from main with chromatic number 
starting from 1.
5. If the graph can be colored in given chromatic number, schedule is made 
with node colors inserted in an array where index indicates a subject.
6. If it is not possible to color the graph with current chromatic number, graph 
coloring function is called again from main with incremented chromatic 
number. This continues until a chromatic number can fully color the given 
graph.
7. Next, input roll no from user and traverse linked list to find the particular 
subjects of the student. Retrieve the time slots of those subjects from the 
graph coloring output array and display.
