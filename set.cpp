#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    set<int> nums;
    nums.insert(1);
    nums.insert(4);
    nums.insert(3);
    nums.insert(2);
    nums.insert(1);
    nums.insert(2);
    nums.insert(-2);
    set<int>::iterator it = nums.begin();
    for(it; it!=nums.end();it++)
    {
        cout<<*it<<" "<<endl;
    }

}
