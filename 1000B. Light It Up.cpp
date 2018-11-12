
/*

Recently, you bought a brand new smart lamp with programming features. At first, you set up a schedule to the lamp. 
Every day it will turn power on at moment 0 and turn power off at moment M. 
Moreover, the lamp allows you to set a program of switching its state (states are "lights on" and "lights off"). 
Unfortunately, some program is already installed into the lamp.

The lamp allows only good programs. Good program can be represented as a non-empty array a, where 0<a1<a2<⋯<a|a|<M. 
All ai must be integers. Of course, preinstalled program is a good program.

The lamp follows program a in next manner: at moment 0 turns power and light on. 
Then at moment ai the lamp flips its state to opposite (if it was lit, it turns off, and vice versa). 
The state of the lamp flips instantly: for example, if you turn the light off at moment 1 and then do nothing, 
the total time when the lamp is lit will be 1. 
Finally, at moment M the lamp is turning its power off regardless of its state.

Since you are not among those people who read instructions, and you don't understand the language it's written in, 
you realize (after some testing) the only possible way to alter the preinstalled program. 
You can insert at most one element into the program a, so it still should be a good program after alteration. 
Insertion can be done between any pair of consecutive elements of a, or even at the begining or at the end of a.

Find such a way to alter the program that the total time when the lamp is lit is maximum possible. 
Maybe you should leave program untouched. If the lamp is lit from x till moment y, then its lit for y−x units of time. 
Segments of time when the lamp is lit are summed up.

Input
First line contains two space separated integers n and M (1≤n≤105, 2≤M≤109)—the length of program a and the moment when power turns off.
Second line contains n space separated integers a1,a2,…,an (0<a1<a2<⋯<an<M)—initially installed program a.

Output
Print the only integer — maximum possible total time when the lamp is lit.

Examples
input
3 10
4 6 7
output
8
input
2 12
1 10
output
9
input
2 7
3 4
output
6

*/
