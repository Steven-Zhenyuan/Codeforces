
/*

You are given an array consisting of n integers a1,a2,…,an, and a positive integer m. It is guaranteed that m is a divisor of n.

In a single move, you can choose any position i between 1 and n and increase ai by 1.

Let's calculate cr (0≤r≤m−1) — the number of elements having remainder r when divided by m. 
In other words, for each remainder, let's find the number of corresponding elements in a with that remainder.

Your task is to change the array in such a way that c0=c1=⋯=cm−1=nm.

Find the minimum number of moves to satisfy the above requirement.

Input
The first line of input contains two integers n and m (1≤n≤2⋅105,1≤m≤n). It is guaranteed that m is a divisor of n.
The second line of input contains n integers a1,a2,…,an (0≤ai≤109), the elements of the array.

Output
In the first line, print a single integer — the minimum number of moves required to satisfy the following condition: 
for each remainder from 0 to m−1, the number of elements of the array having this remainder equals nm.

In the second line, print any array satisfying the condition and can be obtained from the given array with the minimum number of moves. 
The values of the elements of the resulting array must not exceed 1018.

Examples
input
6 3
3 2 0 6 10 12
output
3
3 2 0 7 10 14 

input
4 2
0 1 2 3
output
0
0 1 2 3 

解法：余数为0,1,...,m-1，用c[i]统计该余数i出现的次数，用set来存放未填满的余数
      当该余数出现的次数达到n/m时，从set中移除
      对每个余数d=a[i]%m，贪心思路，由于要使最终移动的次数最小，因此首先找离d最近的余数，在set中用二分搜索找到第一个大于等于d的余数，set已经排好序
      特殊情况：当二分搜索找到的位置超过set的最后位置，由余数的性质，返回set里的第一个余数
      最后再累加答案和更新原数组

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200020;
ll a[MAXN],c[MAXN];
set<int> s;

int main(){
    int n,m,i;
    ll ans=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;++i) s.insert(i);  // 先将所有可能的余数加入set
    for(i=0;i<n;++i){
        scanf("%lld",&a[i]);
        int d=a[i]%m,x;
        if(d>*s.rbegin()) x=*s.begin();  // 特殊情况处理
        else x=*s.lower_bound(d);  // 二分搜索找到set里第一个大于等于余数d的余数x
        if(++c[x]==n/m) s.erase(x);  // 该余数出现的次数已经达到n/m
        ans+=(x-d+m)%m;  // 累加答案，+m防止x-d为负数，即处理特殊情况
        a[i]+=(x-d+m)%m;  // 更新原数组，同理 
    }
    printf("%lld\n",ans);
    for(i=0;i<n;++i) printf("%lld ",a[i]);
}


