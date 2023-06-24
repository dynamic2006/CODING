#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sift_down(vector<int>& heap, int start_node, int end_node)
{
    int child_node, left, right;

    while(start_node < end_node)
    {
        child_node = start_node;
        left = 2*(start_node) + 1;
        right = left + 1;

        if(left < end_node && heap[left]>heap[child_node])
            child_node = left;
        if(right<end_node && heap[right]>heap[child_node])
            child_node = right;
        if(child_node == start_node)
            return;

        swap(heap[start_node], heap[child_node]);
        start_node = child_node;
    }
}

void make_heap(vector<int>& arr)
{
    int start_node = (arr.size() / 2) - 1;

    while(start_node >= 0)
    {
        sift_down(arr, start_node, arr.size());
        start_node--;
    }
}

void findLessThanValue(vector<int>& data, int root, int value)
{
    if(root < data.size())
    {
        if(data[root] < value)
            cout << data[root] << " ";
        findLessThanValue(data, 2*(root)+1, value);
        findLessThanValue(data, 2*(root)+2, value);
    }
}

int main()
{
    int values[10] = {3,5,7,1,2,4,6,8,9,0};

    vector<int> data(values, values+10);

    make_heap(data);

    findLessThanValue(data,0,5);
    cout << endl;
}