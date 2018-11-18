
/*

Allen is hosting a formal dinner party. 2n people come to the event in n pairs (couples). 
After a night of fun, Allen wants to line everyone up for a final picture. The 2n people line up, but Allen doesn't like the ordering. 
Allen prefers if each pair occupies adjacent positions in the line, as this makes the picture more aesthetic.

Help Allen find the minimum number of swaps of adjacent positions he must perform to make it 
so that each couple occupies adjacent positions in the line.

Input
The first line contains a single integer n (1≤n≤100), the number of pairs of people.
The second line contains 2n integers a1,a2,…,a2n. For each i with 1≤i≤n, i appears exactly twice. 
If aj=ak=i, that means that the j-th and k-th people in the line form a couple.

Output
Output a single integer, representing the minimum number of adjacent swaps needed to line the people up 
so that each pair occupies adjacent positions.

Examples
input
4
1 1 2 3 3 2 4 4
output
2

input
3
1 1 2 2 3 3
output
0

input
3
3 1 2 3 1 2
output
3

解法：贪心思路，每遇到一个不成对的数字，就找到与其配对的数字的位置，并交换到它的右边，累加次数
      因为对于匹配的数字，总是需要将它们之间的距离缩短至0，一次交换最多缩短1，因此局部最优的交换能够得到全局最优

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;

const int MAXN=220;
int a[MAXN];

int main(){
    int n,i,j;
    scanf("%d",&n);
    n<<=1;
    for(i=1;i<=n;++i) scanf("%d",&a[i]);
    int ans=0;
    for(i=1;i<n-1;i+=2){
        if(a[i]!=a[i+1]){
            int pos=find(a+i+1,a+n,a[i])-a;
            for(j=pos;j>i+1;--j){
                ans++;
                swap(a[j],a[j-1]);
            }
        }
    }
    printf("%d",ans);
}



