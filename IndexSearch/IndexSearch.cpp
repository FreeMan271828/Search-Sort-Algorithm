#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::map;
using std::vector;

struct IndexTable
{
    int firstIndex;
    int maxData;
};

// (Optional) Dichotomous sorting：for quickier running
int BinarySearch(vector<int> &vec, int tarValue, int leftIndex, int rightIndex);
// The first is the data source, the second is the number of indexes to be divided, and the third is the number of elements in each interval.
vector<IndexTable> getIndexTable(vector<int> &vec, int n, int &Interval);
// The first is the data source, the second is the target, and the third is the separator number
int IndexSearch(vector<int> &vec, int tar, int num);

int main()
{
    vector<int> vec = {3, 1, 2, 5, 8, 9, 5, 7};
    int ret = IndexSearch(vec, 8, 3);
    cout << ret << '\n';
}

int IndexSearch(vector<int> &vec, int tar, int num)
{
    int Interval = ceil((double)vec.size() / num);
    vector<IndexTable> IndexTables = getIndexTable(vec, num, Interval);
    for (auto &elm : IndexTables)
    {
        if (elm.maxData < tar)
        {
            continue;
        }
        else
        {
            // normal sort
            //  for (int i = elm.firstIndex; i < elm.firstIndex + Interval; i++)
            //  {
            //      if (vec[i] == tar)
            //      {
            //          return i;
            //      }
            //  }

            // You can also use a binary sort, but you must make sure you have this function(The default has it)
            int BinarySearchRet = BinarySearch(vec, tar, elm.firstIndex, elm.firstIndex + Interval - 1);
            // None to be found.
            if (BinarySearchRet == -1)
            {
                continue;
            }
            else
            {
                return BinarySearchRet;
            }
        }
    }
    return -1;
}
vector<IndexTable> getIndexTable(vector<int> &vec, int n, int &Interval)
{
    vector<IndexTable> IndexTables;
    for (int i = 0; i < n - 1; i++)
    {
        IndexTable node;
        // node's firstIndex is i*interval
        node.firstIndex = i * Interval;
        // node's maxData is to find the maximum value from [i*interval,(i+1)*interval) of the source data vec
        node.maxData = *std::max_element(vec.begin() + i * Interval, vec.begin() + (i + 1) * Interval);
        IndexTables.push_back(node);
    }
    // Special treatment for the last item as there may be gaps.
    IndexTable tempNode;
    tempNode.firstIndex = (n - 1) * Interval;
    tempNode.maxData = *std::max_element(vec.begin() + (n - 1) * Interval, vec.end());
    IndexTables.push_back(tempNode);
    return IndexTables;
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