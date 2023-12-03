#include <bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int> &vec, int tarValue, int leftIndex, int rightIndex);
int main()
{
    vector<int> vec = {1, 2, 4, 5, 6, 7, 9, 12, 15, 19, 23, 26, 29, 34, 39};
    int tar;
    cin >> tar;
    int ret = BinarySearch(vec, tar, 0, vec.size());
    cout << ret << endl;
}

int BinarySearch(vector<int> &vec, int tarValue, int leftIndex, int rightIndex)
{
    // Since there is no -1 on the right boundary at input, so using >=
    if (leftIndex >= rightIndex)
    {
        return -1;
    }
    // Using this method prevents (rightIndex+LeftIndex) from crossing the line
    int halfIndex = leftIndex + (rightIndex - leftIndex) / 2;
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