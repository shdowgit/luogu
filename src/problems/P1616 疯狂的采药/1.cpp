/*

题目背景
此题为NOIP2005普及组第三题的疯狂版。

此题为纪念LiYuxiang而生。

题目描述
LiYuxiang是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同种类的草药，采每一种都需要一些时间，每一种也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

如果你是LiYuxiang，你能完成这个任务吗？

此题和原题的不同点：

1.每种草药可以无限制地疯狂采摘。

2.药的种类眼花缭乱，采药时间好长好长啊！师傅等得菊花都谢了！

输入输出格式
输入格式：
输入第一行有两个整数T（1 <= T <= 100000）和M（1 <= M <= 10000），用一个空格隔开，T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到10000之间（包括1和10000）的整数，分别表示采摘某种草药的时间和这种草药的价值。

输出格式：
输出一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。

输入输出样例
输入样例#1： 
70 3
71 100
69 1
1 2
输出样例#1： 
140


*/
#include <iostream>
using namespace std;
int t, m, f[100001], cost[10001], values[10001];
int main() {
    cin >> t >> m;
    for (int i = 0; i < m; i++)
        cin >> cost[i] >> values[i];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= t; j++) {
            if (j >= cost[i])
                f[j] = max(f[j], f[j - cost[i]] + values[i]);
        }
    }
    cout << f[t];
    return 0;
}