
/*

Allen wants to enter a fan zone that occupies a round square and has n entrances.

There already is a queue of ai people in front of the i-th entrance. 
Each entrance allows one person from its queue to enter the fan zone in one minute.

Allen uses the following strategy to enter the fan zone:

Initially he stands in the end of the queue in front of the first entrance.
Each minute, if he is not allowed into the fan zone during the minute (meaning he is not the first in the queue), 
he leaves the current queue and stands in the end of the queue of the next entrance (or the first entrance if he leaves the last).
Determine the entrance through which Allen will finally enter the fan zone.

Input
The first line contains a single integer n (2≤n≤105) — the number of entrances.
The second line contains n integers a1,a2,…,an (0≤ai≤109) — the number of people in queues. These numbers do not include Allen.

Output
Print a single integer — the number of entrance that Allen will use.

Examples
input
4
2 3 2 0
output
3

input
2
10 10
output
1

input
6
5 2 6 5 7 4
output
6

*/
