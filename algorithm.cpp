/*STL泛型算法
 * for_each()
 * count(), couont_if 
 *      int count(iterator begin, iterator end, const T& value);//统计某个元素
 *      int count_if(iterator begin, iterator end, UnaryPredicate op);//统计op条件为真的元素个数
 * min_element(), max_element()
 *      //如果有多个最值，只返回第一个找到的迭代器
 *      iterator min_element(iterator begin, iterator end);//以<进行比较
 *      iterator min_element(iterator begin, iterator end, compFunc op);//以op进行比较
 * find(), find_if()
 *      //搜索第一个匹配的元素的迭代器
 *      iterator find (iterator begin, iterator end, const& T value);
 *      iterator find_if (iterator begin, iterator end, UnaryPredicate op);
 * search_n(), search， find_end(), find_first_of()
 *      //搜索第一组，n个连续匹配的值都匹配，返回第一个元素的迭代器，失败返回end()
 *      iterator search_n (iterator begin, iterator end, size_t n, const T& value);
 *      iterator search_n (iterator begin, iterator end, size_t n, const T& value, BinaryPredicate op);
 *      //搜索第一个匹配的子区间
 *      iterator search(iterator begin, iterator end, iterator sbegin, iterator send);
 *      iterator search(iterator begin, iterator end, iterator sbegin, iterator send, BinaryPredicate op);
 *      //搜索最后一个匹配的子区间
 *      iterator find_end(iterator begin, iterator end, iterator sbegin, iterator send);
 *      iterator find_end(iterator begin, iterator end, iterator sbegin, iterator send，BinaryPredicate op);         
 * adjacent_find()
 *      //搜索两个连续相等的元素, T E 通常用迭代器
 *      template <class T>
 *              T adjacent_find(T first, T last);
 *      template <class T, class E>
 *              T adjacent_find(T first, T last, E pr);//pr是一个二元判断如void pr(int i, int j);              
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void print(T& item)
{
    cout<<item<<" ";
}
    
bool even_num(const int num)
{
    return num%2==0;
}

bool is_double_num(int num1, int num2)
{
    return num2/2==num1;
}

int main()
{
    cout<< "for_each使用："<<endl;
    vector<int> nums(10,1);
    for (int i=0; i<10; ++i)
    {
        nums[i] = i+1;
    }
    for_each (nums.begin(), nums.end(), print<int>);//这里必须指明int型模板
    cout<<endl;

    cout << "count_if, find_if, search_n使用："<<endl;
    cout << "nums中偶数个数是 " << count_if(nums.begin(), nums.end(), even_num) <<endl;
    cout<<"第一个大于3的元素："<<
        *find_if(nums.begin(), nums.end(), bind2nd(greater<int>(), 3))<<endl;
    cout<<"5个小于7的元素组头元素:"<<
        *search_n(nums.begin(), nums.end(), 5, 7, less<int>())<<endl;
    
    cout<<"adjacent_find使用："<<endl;
    nums = {4,1,2,3,3,3,4,2,8,0}; cout<<"nums: ";
    for_each(nums.begin(), nums.end(), print<int>); cout<<endl;
    cout<<"第一组相等的元素："<<
        *adjacent_find(nums.begin(), nums.end()) << endl;
    cout<<"第一组第二个元素是第一个元素的2倍："<<
        *adjacent_find(nums.begin(), nums.end(), is_double_num) << endl;
}

