#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
    {
        vector<int> a={1,3,2,4,6,5,8,7,0,9};
        priority_queue<int> nums;
        priority_queue<int,vector<int>, greater<int> > nums1;
        for(int i=0;i<a.size();++i)
        {
            nums.push(a[i]);
            nums1.push(a[i]);
        }
        while(nums.size()>0)
        {
            int a = nums.top();
            cout<<a<<" ";
            nums.pop();
        }
        cout<<endl;
        while(nums1.size()>0)
        {
            int a = nums1.top();
            cout<<a<<" ";
            nums1.pop();
        }
        cout<<endl;
    }
    return 0;
}
