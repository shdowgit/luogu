/*

题目描述
某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前5名学生发奖学金。期末，每个学生都有3门课的成绩:语文、数学、英语。先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面，这样，每个学生的排序是唯一确定的。

任务：先根据输入的3门课的成绩计算总分，然后按上述规则排序，最后按排名顺序输出前五名名学生的学号和总分。注意，在前5名同学中，每个人的奖学金都不相同，因此，你必须严格按上述规则排序。例如，在某个正确答案中，如果前两行的输出数据(每行输出两个数:学号、总分) 是:

77 279279
55 279279

这两行数据的含义是:总分最高的两个同学的学号依次是77号、55号。这两名同学的总分都是 279279 (总分等于输入的语文、数学、英语三科成绩之和) ，但学号为77的学生语文成绩更高一些。如果你的前两名的输出数据是:

55 279279
77 279279

则按输出错误处理，不能得分。

输入输出格式
输入格式：
共n+1行。

第11行为一个正整数n( \le 300)n(≤300)，表示该校参加评选的学生人数。

第22到n+1n+1行，每行有33个用空格隔开的数字，每个数字都在00到100100之间。第jj行的33个数字依次表示学号为j-1j−1的学生的语文、数学、英语的成绩。每个学生的学号按照输入顺序编号为1~n1 n（恰好是输入数据的行号减11）。

所给的数据都是正确的，不必检验。

//感谢 黄小U饮品 修正输入格式

输出格式：
共5行，每行是两个用空格隔开的正整数，依次表示前55名学生的学号和总分。

输入输出样例
输入样例#1： 
6
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
输出样例#1： 
6 265
4 264
3 258
2 244
1 237

输入样例#2： 
8
80 89 89
88 98 78
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
输出样例#2： 
8 265
2 264
6 264
1 258
5 258


思路:
    记得好初始化 total


*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    int id;
    int chin;
    int math;
    int eng;
    int total;
} stu;

bool cmp(const stu &s1, const stu &s2) {
    if (s1.total != s2.total) return s1.total > s2.total;
    if (s1.chin != s2.chin) return s1.chin > s2.chin;
    return s1.id < s2.id;
}

int main() {
    int n;
    cin >> n;
    vector<stu> stus(n);
    for (int i = 0; i < n; i++) {
        stus[i].id = i + 1;
        cin >> stus[i].chin >> stus[i].math >> stus[i].eng;
        stus[i].total = stus[i].chin + stus[i].math + stus[i].eng;
    }
    sort(stus.begin(), stus.end(), cmp);
    for (int i = 0; i < 5; i++)
        cout << stus[i].id << ' ' << stus[i].total << endl;
    return 0;
}