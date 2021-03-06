
/*

Codehorses has just hosted the second Codehorses Cup. 
This year, the same as the previous one, organizers are giving T-shirts for the winners.

The valid sizes of T-shirts are either "M" or from 0 to 3 "X" followed by "S" or "L". 
For example, sizes "M", "XXS", "L", "XXXL" are valid and "XM", "Z", "XXXXL" are not.

There are n winners to the cup for both the previous year and the current year. 
Ksenia has a list with the T-shirt sizes printed for the last year cup and is yet to send the new list to the printing office.

Organizers want to distribute the prizes as soon as possible, so now Ksenia is required not to write the whole list from the scratch 
but just make some changes to the list of the previous year. 
In one second she can choose arbitrary position in any word and replace its character with some uppercase Latin letter. 
Ksenia can't remove or add letters in any of the words.

What is the minimal number of seconds Ksenia is required to spend to change the last year list to the current one?

The lists are unordered. 
That means, two lists are considered equal if and only if the number of occurrences of any string is the same in both lists.

Input
The first line contains one integer n (1≤n≤100) — the number of T-shirts.
The i-th of the next n lines contains ai — the size of the i-th T-shirt of the list for the previous year.
The i-th of the next n lines contains bi — the size of the i-th T-shirt of the list for the current year.
It is guaranteed that all the sizes in the input are valid. It is also guaranteed that Ksenia can produce list b from the list a.

Output
Print the minimal number of seconds Ksenia is required to spend to change the last year list to the current one. 
If the lists are already equal, print 0.

Examples
input
3
XS
XS
M
XL
S
XS
output
2

input
2
XXXL
XXL
XXL
XXXS
output
1

input
2
M
XS
XS
M
output
0

解法：贪心思路，相同的string不需要进行变换，不相同的string由于长度一定一样，由题意中的string组合发现只有一位字母需要改变
      统计不一样的string即可得到最小变换次数

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    unordered_map<string,int> mp;
    string s;
    int ans=0;
    for(int i=0;i<n;++i){
        cin>>s;
        mp[s]++;
    }
    for(int i=0;i<n;++i){
        cin>>s;
        if(mp[s]) mp[s]--;
        else ans++;
    }
    printf("%d",ans);
}

