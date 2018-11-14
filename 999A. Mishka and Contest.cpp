
/*

Mishka started participating in a programming contest. There are n problems in the contest. 
Mishka's problem-solving skill is equal to k.

Mishka arranges all problems from the contest into a list. Because of his weird principles, 
Mishka only solves problems from one of the ends of the list. 
Every time, he chooses which end (left or right) he will solve the next problem from. 
Thus, each problem Mishka solves is either the leftmost or the rightmost problem in the list.

Mishka cannot solve a problem with difficulty greater than k. When Mishka solves the problem, it disappears from the list, 
so the length of the list decreases by 1. Mishka stops when he is unable to solve any problem from any end of the list.

How many problems can Mishka solve?

Input
The first line of input contains two integers n and k (1≤n,k≤100) — the number of problems and Mishka's problem-solving skill.
The second line of input contains n integers a1,a2,…,an (1≤ai≤100), where ai is the difficulty of the i-th problem. 
The problems are given in order from the leftmost to the rightmost in the list.

Output
Print one integer — the maximum number of problems Mishka can solve.

Examples
input
8 4
4 2 3 1 5 1 6 4
output
5

input
5 2
3 1 2 1 3
output
0

input
5 100
12 34 55 43 21
output
5

*/
