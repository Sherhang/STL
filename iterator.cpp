/* 迭代器使用
 *
 *五种迭代器：
 *  随机访问迭代器 ---> 双向型迭代器 ---> 前向型迭代器 ---> 输入型迭代器
 *                                                     ---> 输出型迭代器
 *  1. 输入型迭代器 input iterator
 *      *, ->, ++. ==, !=, TYPE(iter)
 *  2. 输出型迭代器 output iterator
 *      *, ++,
 *  3. 前向迭代器 forward iterator
 *      *, ->, ++, ==, !=, TYPE, =
 *  4. 双向迭代器 
 *      所有前向迭代器的功能, 加上 --
 *  5. 随机访问迭代器
 *      使用随机访问型迭代器一定要注意迭代器是否有效，比如--iter可能指向begin()之前
 *      支持随机访问迭代器的模板：vector, deque, string, wstring, 普通数组array，vector的迭代器一般作为指针
 *      iter[n], iter += n, iter -= n, iter+n, iter-n, 
 *      iter2 - iter1 //两个迭代器的距离
 *      iter1 < iter2, <=, >, >=
 *
 *迭代器配接器
 *  1. 逆向型迭代器 reverse_iterator
 *      所有容器可以使用
 *  2. 插入器
 *      生成函数
 *      back_inserter(cont);//后插入型迭代器
 *      front_inserter(cont);//前插入型迭代器
 *      Inserter(cont, pos);//产生型迭代器
 * 3. 流型迭代器
 *      ostream_iterator<T> (ostream);//输出流
 *      ostrean_iterator<T> (ostream, delim);//各个元素之间用delim作为分隔符。
 *      iter = value;// 将value写到ostream, 等效于ostream<<value
 *      istream_iterator<T>();//产生一个end-of-stream迭代器
 *      istream_iterator<T>(istream);//
 *      *, ->, ++, ==, !=
 *
 *辅助函数
 * advance(), distance(), iter_swap()
 *      advance()可以用于非随机访问迭代器,比如set的迭代器
 *      void advance(iterator& it, int n);//迭代器前进或后退n步。demo: iter.advance(iter, -2);//后退2步
 *      int distance(iterator it1, iterator, it2);//
 *      void iter_swap(iterator it1, iterator it2);//交换两个迭代器的内容，只要所指向的元素可以相互赋值即可      
 */

#include<iostream>
#include<set>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
template <class T>
void print(const T& a)
{
    cout<<a<<" ";
}
int main()
{
    cout<<"逆向迭代器使用："<<endl;
}

