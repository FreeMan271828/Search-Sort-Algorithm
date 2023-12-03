#include <bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>& vec, int tarValue, int leftIndex, int rightIndex);
int main()
{
    vector<int> vec = {1, 2, 5, 8, 9, 10, 17, 20};
    int tar;
    cin >> tar;
    int ret = BinarySearch(vec, tar, 0, vec.size() - 1);
    cout << ret << endl;
}

int BinarySearch(vector<int>& vec, int tarValue, int leftIndex, int rightIndex)
{
    if (leftIndex > rightIndex)
    {
        return -1;
    }
    int halfIndex = (leftIndex + rightIndex) / 2;
    int halfValue = vec[halfIndex];
    if (tarValue == halfValue)
    {
        return halfIndex;
    }
    else if (tarValue < halfValue)
    {
        return BinarySearch(vec, tarValue, leftIndex, halfIndex - 1);
    }
    else
    {
        return BinarySearch(vec, tarValue, halfIndex + 1, rightIndex);
    }
}