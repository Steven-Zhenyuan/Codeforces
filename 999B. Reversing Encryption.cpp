
/*

A string s of length n can be encrypted by the following algorithm:

iterate over all divisors of n in decreasing order (i.e. from n to 1),
for each divisor d, reverse the substring s[1…d] (i.e. the substring which starts at position 1 and ends at position d).
For example, the above algorithm applied to the string s="codeforces" leads to the following changes: 
"codeforces" → "secrofedoc" → "orcesfedoc" → "rocesfedoc" → "rocesfedoc" 
(obviously, the last reverse operation doesn't change the string because d=1).

You are given the encrypted string t. Your task is to decrypt this string, i.e., to find a string s 
such that the above algorithm results in string t. It can be proven that this string s always exists and is unique.

Input
The first line of input consists of a single integer n (1≤n≤100) — the length of the string t. 
The second line of input consists of the string t. The length of t is n, and it consists only of lowercase Latin letters.

Output
Print a string s such that the above algorithm results in t.

Examples
input
10
rocesfedoc
output
codeforces

input
16
plmaetwoxesisiht
output
thisisexampletwo

input
1
z
output
z

解法：反向再次实现题目中的算法，divisors in increasing order

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,i;
    string s;
    cin>>n>>s;
    vector<int> a;
    for(i=1;i<=n;++i){
        if(n%i==0) a.push_back(i);
    }
    for(i=0;i<a.size();++i){
        reverse(s.begin(),s.begin()+a[i]);
    }
    cout<<s;
}


