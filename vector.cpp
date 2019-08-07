/*
 * vector 模板使用
 * 成员函数
 * push_back(), pop_back()
 * reserve(int n),resize()
 * size(), capacity(), empty(), clear(),
 * at(int i)选定特定位置元素的引用， front(), back()
 * begin(), end(),rbegin(), rend()
 * assign()
 *      assign(iterator first, iterator last);//重新赋值，和初始化用法一样
 * insert(), clear(), erase()
 *      iterator erase(iterator it);
 *      iterator erase(iterator first, iterator second);
 *      iterator insert(itearator it, const T& x = T());//插入一个元素到指定位置
 *      void insert(iterator it, size_t n, const T& x);//n个相同元素插入指定位置
 *      void insert(iterator it, const_iterator first, const_iterator last);//指定范围元素插入指定位>置
  *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> a;
    a.reserve(4);  
    cout << "capacity is " << a.capacity() <<endl;
    a = {1, 2, 5, 0, -2};//赋值，5个元素，会自动扩充
    cout << "capacity is " << a.capacity() << endl;
    //按照迭代器输出
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "front is " << a.front() << " back is " << a.back()<<" 下标2的元素"<<a.at(2) <<endl;
    
    a.pop_back();
    a.push_back(19);
    for (int i=0; i<a.size(); ++i)
        cout<<a[i]<<" ";
    cout << endl;
}


