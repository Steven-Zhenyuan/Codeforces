
/*

There are n cities and m roads in Berland. Each road connects a pair of cities. The roads in Berland are one-way.

What is the minimum number of new roads that need to be built to make all the cities reachable from the capital?

New roads will also be one-way.

Input
The first line of input consists of three integers n, m and s (1≤n≤5000,0≤m≤5000,1≤s≤n) — the number of cities, the number of roads and 
the index of the capital. Cities are indexed from 1 to n.

The following m lines contain roads: road i is given as a pair of cities ui, vi (1≤ui,vi≤n, ui≠vi). 
For each pair of cities (u,v), there can be at most one road from u to v. 
Roads in opposite directions between a pair of cities are allowed (i.e. from u to v and from v to u).

Output
Print one integer — the minimum number of extra roads needed to make all the cities reachable from city s. 
If all the cities are already reachable from s, print 0.

Examples
input
9 9 1
1 2
1 3
2 3
1 5
5 6
6 1
1 8
9 8
7 1
output
3

input
5 4 5
1 2
2 3
3 4
4 1
output
1

*/
