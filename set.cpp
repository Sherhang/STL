/* set和multiset, 无法调用修改泛型算法
 * 初始化时自定义排序规则
 *      set<int, greater<int>> nums; //优先使用这种，包括自己的仿函数
 *      set<int> nums(greater<int>());
 * 成员函数
 * size(), empty(), max_size(), count(), begin(), end(),rbegin(), rend()
 * find(), low_bound(), upper_bound(), equal_range()
 *      iterator find (const T& key) const;
 *      iterator low_bound(const T& n);//大于等于n的第一个元素位置，下届
 *      pair<iterator, iterator> equal_range(const T& n) const;//第一个迭代器元素 >= n, 第二个 > n
 * insert(), erase(), clear()
 *      pair<iterator, bool> insert(const T& x);//插入元素
 *      iterator insert(iterator it, const T& x);
 *      void insert(const T* first, const T* last);//一般用迭代器插入一段数据 
 *      
 *      iterator erase(iterator it);//返回下一个元素位置
 *      iterator erase(iterator first, iterator last);//左闭右开
 *      size_t erase(const T& x);
 * key_comp(), value_comp()//用于确定set的排序形式
 *      key_compare key_comp() const;//按照key比较，由于set只有key，所以只需要这个
 *      value_compare value_comp() const;
 *      
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>        //use abs()
using namespace std;
#define  display for_each(nums.begin(), nums.end(), print);cout<<endl
void print(int item)
{
    cout<<item<<" ";
}

//仿函数，按照绝对值大小排序
template <class T>
struct abs_compare
{   
    bool operator() (T n1, T n2)   //这里不能用&
    {
        return (abs(n1) < abs(n2) );//从小到大
    }
};

int main()
{
    vector<int> tmp={1,0,-2,5,7,9,-4,5,5,6};
    set<int, greater<int>> nums(tmp.begin(),tmp.end());//初始化，默认从小到大，greater从大到小
    set<int, greater<int>>::iterator it = nums.begin();
    cout << "max_size is "<<nums.max_size()<<endl;
    cout<<"nums按照迭代器顺序输出: "<<endl;
    for_each(nums.begin(), nums.end(), print); cout<<endl;
    
    {
        cout<<"按照绝对值排序："<<endl;
        vector<int> tmp = {1,-1,0,0,2,-3,4,-5};
        set<int,abs_compare<int>> nums(tmp.begin(),tmp.end());//-1和1视为相等元素
        nums.insert(10);
        display;
    }
    
    cout<<"insert 用法：" << endl;
    for_each(nums.begin(), nums.end(), print); cout<<endl;
    tmp={100,101,102,101};
    nums.insert(tmp.begin(), tmp.end());
    display;
     
    cout << "erase 用法： "<<endl;
    display;
    cout<<"it位置元素：" <<*it<<endl;
    it = nums.erase(nums.begin(), it);
    display;
    cout<< "it位置元素： "<<*it<<endl;

    cout<<"key_comp 用法："<<endl; 
    set<int, greater<int>>::value_compare kc = nums.value_comp();//这里原本用key
    if(kc(0,1))
        cout<< "从小到大排序"<<endl;
    else 
        cout<< "从大到小排序" <<endl;
}
