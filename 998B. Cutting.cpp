
/*

There are a lot of things which could be cut — trees, paper, "the rope". In this problem you are going to cut a sequence of integers.

There is a sequence of integers, which contains the equal number of even and odd numbers. 
Given a limited budget, you need to make maximum possible number of cuts 
such that each resulting segment will have the same number of odd and even integers.

Cuts separate a sequence to continuous (contiguous) segments. 
You may think about each cut as a break between two adjacent elements in a sequence. 
So after cutting each element belongs to exactly one segment. Say, [4,1,2,3,4,5,4,4,5,5] → two cuts → [4,1|2,3,4,5|4,4,5,5]. 
On each segment the number of even elements should be equal to the number of odd elements.

The cost of the cut between x and y numbers is |x−y| bitcoins. 
Find the maximum possible number of cuts that can be made while spending no more than B bitcoins.

Input
First line of the input contains an integer n (2≤n≤100) and an integer B (1≤B≤100) — 
the number of elements in the sequence and the number of bitcoins you have.

Second line contains n integers: a1, a2, ..., an (1≤ai≤100) — elements of the sequence, 
which contains the equal number of even and odd numbers

Output
Print the maximum possible number of cuts which can be made while spending no more than B bitcoins.

Examples
input
6 4
1 2 5 10 15 20
output
1

input
4 10
1 3 2 4
output
0
input
6 100
1 2 3 4 5 6
output
2

解法：记录每个可以cut的位置以及cost，用两个变量代表odd和even
      贪心思路，为了获得最多数量的cut，将所有cost排序，从最小的开始累加直到超过上限m

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=110;
int a[MAXN],c[MAXN];

int main(){
    int n,m,i,tot=0,odd,even;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i) scanf("%d",&a[i]);
    odd=even=0;
    for(i=1;i<n;i+=2){
        if(a[i]%2) odd++;
        else even++;
        if(a[i+1]%2) odd++;
        else even++;
        if(odd==even&&i!=n-1){
            odd=even=0;
            c[tot++]=abs(a[i+2]-a[i+1]);
        }
    }
    sort(c,c+tot);
    int ans=0;
    for(i=0;i<tot;++i){
        if(m-c[i]>=0){
            m-=c[i];
            ans++;
        }
    }
    printf("%d",ans);
}



