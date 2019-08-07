/* deque双端队列
 * 特点：随机访问，在两端快速删除和插入，和vector几乎一样的接口
 * deque比vector多了push_front(), pop_front(),可以在头部操作
 * 构造函数（初始化）
 *     deque<typename T> name;
 *     deque<typename T> name(size);
 *     deque<typename T> name(size, value);
 *     deque<typename T> name(elsedeque);
 *     deque<typename T> name(elsedeque.begin(),elsedeque.end());//使用其它deque初始化
 * 成员函数
 *   resize(), max_size(), size()
 *     void resize(size_type n, x);//把deque的大小调整为n, 并把元素初始化为x
 *   插入和删除：
 *      push_front(), pop_front(), push_back(), pop_back(), insert(), erase(), clear()
 *      void insert(iterator it, T& x);//在it迭代器位置插入x
 *      void insert(iterator it, size_t n, T& x);//插入多个相同元素
 *      void insert(iterator it, iterator first, iterator last);//插入一段区间的元素
 *      void erase(iterator it);//删除
 *      void erase(iterator first, iterator last);//删除指定区间
 *   迭代器相关：
 *     begin(), end(), rbegin(), rend(), back(), front() 
 *   empty()
 *   元素访问：[], at(), back(), front()
 *   元素重置：assign()
 *       void assign(iterator first, iterator last);
 *       void assign(size_type n, x);
 *   交换元素：swap(),
 * 
 */

#include <iostream> 
#include <deque>
using namespace std;

int main()
{
	deque<int> nums(5, 0);
	nums.push_front(1);
	nums.push_back(2);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	cout << "max_size()" << nums.max_size() << endl;
}
