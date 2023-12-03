#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::map;
using std::vector;
int main()
{
    int IndexSearch(vector<int> & vec, int tar);
    vector<int> vec = {1, 2, 5, 8, 9, 10, 17, 20};
    int tar;
    cin >> tar;
    int ret = IndexSearch(vec, tar);
    cout << ret << '\n';
}
int IndexSearch(vector<int> &vec, int tar)
{
    // 此处简单演示，将vec分成3组
}
map<int, int> getMap(vector<int> &vec, int n)
{
}