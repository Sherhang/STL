/* list 模板类
 * 成员函数
 * push_front(T& x), pop_front()
 * push_back(T& x), pop_back()
 * clear(), erase(), insert()
 *      iterator erase(iterator it);
 *      iterator erase(iterator first, iterator second);
 *
 *      iterator insert(itearator it, const T& x = T());//插入一个元素到指定位置
 *      void insert(iterator it, size_t n, const T& x);//n个相同元素插入指定位置
 *      void insert(iterator it, const_iterator first, const_iterator last);//指定范围元素插入指定位置
 * resize(size_t n), size(), max_size()
 * begin(), end(), rbegin(), rend(), front(), back()
 * empty()
 * assign()
 *      void assign(const_iterator first, const_iterator last);
 *      void assign(size_t n)
 * merge(), sort(), remove(), remove_if(), splice()
 *      void merge(list& x);//x中元素合并到调用者，并且会自动排序
 *      void merge(list& x, greater<T> pr);
 *      sort();
 *      sort(greater<T> pr);//从大到小排序
 */
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<double> nums(5, 0.2);
    list<double>::iterator it;
    nums.pop_front();
    nums.push_front(0.1);
    nums.push_back(0.5);
    for (it = nums.begin(); it != nums.end(); ++it)
        cout << *it <<" ";
    cout << endl;
    nums.assign(3,0.3);
    it = nums.begin();
    cout << "插入2个4" <<endl;
    nums.insert(++it, 2, 4);
    for (it = nums.begin(); it != nums.end(); ++it)
        cout << *it <<" ";
    cout << endl;
    cout << "max_size is " << nums.max_size()<< endl;

}
