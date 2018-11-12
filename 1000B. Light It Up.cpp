
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

解法：首先记录下到ai时刻一共开的时长on[i]和关的时长off[i]
      为了使开的时间最长，由贪心发现插入位置x在a[i]-1或者a[i]+1
      
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=100010;
int a[MAXN];
int on[MAXN];
int off[MAXN];
int n,M;

int main() {
    scanf("%d%d",&n,&M);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    a[n+1]=M;
    for(int i=1;i<=n+1;++i){
        if(i&1){
            on[i]=on[i-1]+a[i]-a[i-1];  // 奇数位为关，即累加之前开的时间a[i]-a[i-1]
            off[i]=off[i-1];
        }else{
            on[i]=on[i-1];  
            off[i]=off[i-1]+a[i]-a[i-1];  // 偶数位为开，即累加之前关的时间a[i]-a[i-1]
        }
    }
    int ans=on[n+1];
    for(int i=1;i<=n;++i){
        int tmp=0;
        if(a[i]-a[i-1]>1||a[i+1]-a[i]>1){  // 判断左或右有空余位置
            if(i&1){
                tmp=on[i]-1+off[n+1]-off[i];  // 奇数位为关，在a[i]-1位置插入，即a[i]-1为关，a[i]为开，a[i]位置开的时间减一
             // tmp=on[i]+off[n+1]-off[i]-1;  // 在a[i]+1位置插入，即a[i]为关，a[i]+1为开，a[i]位置之后反转后开的时间减一
            }else{
                tmp=on[i]+1+off[n+1]-off[i];  // 偶数位为开，在a[i]-1位置插入，即a[i]-1为开，a[i]为关，a[i]位置关的时间减一，即开的时间加一
             // tmp=on[i]+off[n+1]-off[i]+1;  // 在a[i]+1位置插入，即a[i]为开，a[i]+1为关，a[i]位置之后反转后关的时间减一，即开的时间加一
            }
        }
        ans=max(ans,tmp);
    }
    printf("%d",ans);
}


