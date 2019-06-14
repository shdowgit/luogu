/*


题目描述
在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。

每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过 n-1n−1 次合并之后， 就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。

因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为 11 ，并且已知果子的种类 数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。

例如有 33 种果子，数目依次为 11 ， 22 ， 99 。可以先将 11 、 22 堆合并，新堆数目为 33 ，耗费体力为 33 。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为 1212 ，耗费体力为 1212 。所以多多总共耗费体力 =3+12=15=3+12=15 。可以证明 1515 为最小的体力耗费值。

输入输出格式
输入格式：
共两行。
第一行是一个整数 n(1\leq n\leq 10000)n(1≤n≤10000) ，表示果子的种类数。

第二行包含 nn 个整数，用空格分隔，第 ii 个整数 a_i(1\leq a_i\leq 20000)a 
i
​	 (1≤a 
i
​	 ≤20000) 是第 ii 种果子的数目。

输出格式：
一个整数，也就是最小的体力耗费值。输入数据保证这个值小于 2^{31}2 
31
  。

输入输出样例
输入样例#1： 
3 
1 2 9 
输出样例#1： 
15
说明
对于30％的数据，保证有n \le 1000n≤1000：

对于50％的数据，保证有n \le 5000n≤5000；

对于全部的数据，保证有n \le 10000n≤10000。

思路:
    1. 最小堆
    2. c++ 不事先开好空间，就是犯罪


*/
#include <iostream>
#include <vector>
using namespace std;
int size = 0;
vector<int> min_heap(10001, -(1ll << 31));

void add(int x) {
    size++;
    int i = size;
    while (x < min_heap[i / 2]) {
        min_heap[i] = min_heap[i / 2];
        i /= 2;
    }
    min_heap[i] = x;
}

int get_min() {
    int ret = min_heap[1], x = min_heap[size--];
    int parent = 1;
    while (parent * 2 <= size) {
        int child = parent * 2;
        if (child != size && min_heap[child] > min_heap[child + 1]) child++;
        if (x > min_heap[child])
            min_heap[parent] = min_heap[child];
        else
            break;
        parent = child;
    }
    min_heap[parent] = x;
    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        add(temp);
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        int a = get_min(), b = get_min();
        res += a + b;
        add(a + b);
    }
    cout << res;
    return 0;
}