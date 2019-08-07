#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;//todo
void print(int a)
{
    cout<<a<<" ";
}

int main()
{
    vector<int> n={1,2,3,4,5};
    set<int> nums(n.begin(), n.end());
    for(auto it=nums.begin();it!=nums.end();)
    {
        bool flag = false;
        for( int j=0;j<7;j++)
        {
            if(j%2 == 1)
                if(1)
            {
                flag=true;
                break;
            }
        }
        if(flag)

            nums.erase(it++);
        else
            it++;
        for_each(nums.begin(), nums.end(), print);cout<<endl;
    }
    cout<<nums.size();
}
