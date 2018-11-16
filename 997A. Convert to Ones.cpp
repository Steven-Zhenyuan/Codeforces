
/*

You've got a string a1,a2,…,an, consisting of zeros and ones.

Let's call a sequence of consecutive elements ai,ai + 1,…, aj (1≤ i≤ j≤ n) a substring of string a.

You can apply the following operations any number of times:

Choose some substring of string a (for example, you can choose entire string) and reverse it, paying x coins for it 
(for example, «0101101» → «0111001»);
Choose some substring of string a (for example, you can choose entire string or just one symbol) and 
replace each symbol to the opposite one (zeros are replaced by ones, and ones — by zeros), paying y coins for it 
(for example, «0101101» → «0110001»).
You can apply these operations in any order. It is allowed to apply the operations multiple times to the same substring.

What is the minimum number of coins you need to spend to get a string consisting only of ones?

Input
The first line of input contains integers n, x and y (1 ≤ n ≤ 300000,0≤x,y≤109) — length of the string, 
cost of the first operation (substring reverse) and cost of the second operation (inverting all elements of substring).

The second line contains the string a of length n, consisting of zeros and ones.

Output
Print a single integer — the minimum total cost of operations you need to spend to get a string consisting only of ones. 
Print 0, if you do not need to perform any operations.

Examples
input
5 1 10
01000
output
11

input
5 10 1
01000
output
2

input
7 2 3
1111111
output
0

解法：有两种方法将整个string转换为00...0，先计数连续的0为cnt
     1. 将每段连续的0取反，则cnt*y
     2. 反转连续的两段0和1，即可将两段0连接起来，如000111000反转为111000000，因此共有cnt-1次反转操作，最后在取反，则(cnt-1)*x+y
     x>=y时，cnt*y<(cnt-1)*x+y
     x<y时，cnt*y>=(cnt-1)*x+y

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=300030;
char s[MAXN];

int main(){
    int n,x,y,cnt=0;
    scanf("%d%d%d%s",&n,&x,&y,s);
    for(int i=0,j=0;i<n;i=j){
        while(j<n&&s[i]==s[j]) j++;  // 定位连续的0或1
        if(s[i]=='0') cnt++;  // 计数连续的0
    }
    ll ans;
    if(!cnt) ans=0;
    else if(x<y) ans=x*(cnt-1ll)+y;
    else ans=1ll*y*cnt;
    printf("%lld",ans);
}




