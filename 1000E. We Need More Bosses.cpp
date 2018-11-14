
/*

Your friend is developing a computer game. He has already decided how the game world should look like — 
it should consist of n locations connected by m two-way passages. 
The passages are designed in such a way that it should be possible to get from any location to any other location.

Of course, some passages should be guarded by the monsters. 
Some crucial passages will be guarded by really fearsome monsters, requiring the hero to prepare for battle and 
designing his own tactics of defeating them (commonly these kinds of monsters are called bosses). 
And your friend wants you to help him place these bosses.

The game will start in location s and end in location t, but these locations are not chosen yet. 
After choosing these locations, your friend will place a boss in each passage 
such that it is impossible to get from s to t without using this passage. 
Your friend wants to place as much bosses as possible (because more challenges means more fun, right?), 
so he asks you to help him determine the maximum possible number of bosses, considering that any location can be chosen as s or as t.

Input
The first line contains two integers n and m (2≤n≤3⋅105, n−1≤m≤3⋅105) — the number of locations and passages, respectively.
Then m lines follow, each containing two integers x and y (1≤x,y≤n, x≠y) describing the endpoints of one of the passages.
It is guaranteed that there is no pair of locations directly connected by two or more passages, 
and that any location is reachable from any other location.

Output
Print one integer — the maximum number of bosses your friend can place, considering all possible choices for s and t.

Examples
input
5 5
1 2
2 3
3 1
4 1
5 2
output
2

input
4 3
1 2
4 3
3 2
output
3

题意：无向图，任意两点都要能连通，则存在一些必经的边为关键边，找一条路径，使得其关键边最多，输出关键边的数量

解法：若几个结点之间存在环，则这个环的任意一条边都不是关键边，用Tarjan算法缩点，重新建图得到树图，该树的直径即为关键边的数量
      
            _____________                      _______
           |             |                    |       |           1
      1 —— 2 ——— 3   4   5  将1,2,3缩点，得到  1   4   5  即为    /  \    求树的直径为2
      ||_________|   |                        |___|            4     5
      |______________|
      
Tarjan缩点：即为Tarjan算法求强连通分量，在无向图中无需vis[]标记当前结点是否in stack

*/

