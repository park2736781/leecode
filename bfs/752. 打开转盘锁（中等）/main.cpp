#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/***
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。列表 deadends 包含了一组死亡数字，
一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。
***/

string plusOne(string curr_char, int i)
{
    if (curr_char[i] == '9')
    {
        curr_char[i] = '0';
    }
    else
    {
        curr_char[i] += 1;
    }
    return curr_char;
}

string minusOne(string curr_char, int i)
{
    if (curr_char[i] == '0')
    {
        curr_char[i] = '9';
    }
    else
    {
        curr_char[i] -= 1;
    }
    return curr_char;
}

int openLock(vector<string> deadends, string target, string init_num)
{
    set<string> visited;
    queue<string> perform;
    perform.push(init_num);
    int step = 0;
    while (!perform.empty())
    {
        int size = perform.size();
        for (int i = 0; i < size; i++)
        {
            string cur = perform.front();
            perform.pop();
            if (find(deadends.begin(), deadends.end(), cur) != deadends.end())
            {
                continue;
            }
            if (cur == target)
            {
                return step;
            }
            for (int i = 0; i < cur.length(); i++)
            {
                string up = plusOne(cur, i);
                if (visited.find(up) == visited.end())
                {
                    perform.push(up);
                }
                string down = minusOne(cur, i);
                if (visited.find(down) == visited.end())
                {
                    perform.push(down);
                }
            }
        }

        step++;
    }
    // 穷举完还没有找到返回-1
    return -1;
}

int main()
{
    string *deadend = new string[5];
    deadend[0] = "0201";
    deadend[1] = "0102";
    deadend[2] = "0101";
    deadend[3] = "1212";
    deadend[4] = "2002";
    string target = "0202";
    vector<string> deadends;
    for (int i = 0; i < 5; i++)
    {
        deadends.push_back(deadend[i]);
    }
    string init_num = "0000";
    cout << openLock(deadends, target, init_num) << endl;
    return 0;
}