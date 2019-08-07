/* map和multimap使用
 * 初始化
 *      map<K, V>
 *      map<K, V, greater<K> >  //也可以自定义排序规则
 * 成员函数
 * size(), max_size(), empty(), 
 * begin(), end(), rbegin(), rend()
 * insert(), erase(), clear()
 * swap()
 *      void swap(map& x);//demo: m1.swap(m2);//这种只有m1的内容变了，不是真正的交换
 * count(), find(),
 * upper_bound(), lower_bound(), equal_range()
 *      pair<iterator, iterator> equal_range(const K& key); //第一个迭代器是lower_bound的返回值，第二个是upper_bound的返回值
 * key_comp(), value_comp() 
 *      key_compare key_comp() const;
 * get_allocate()
 *      
 * 
 * */

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
template <class T>
void print(T x)
{
    cout<< x.first <<" "<< x.second << endl;
}
int main()
{
    cout<< "map的使用："<<endl;
    map<int, string, greater<int> > myMap;//declartion
    myMap[5] = "abc";//insert,  as array
    myMap[5] = "bcd";//会覆盖
    myMap[2] = "ye";
    myMap[10] = "he";
    myMap.insert(pair<int,string>(1,"def"));//多用这种
    myMap.insert(map<int, string>::value_type(3, "efg"));//第三种
    myMap.insert(pair<int, string>(1, "hij"));//有1了，所以不会做任何操作
    map<int, string>::iterator it = myMap.begin();
    cout<<"按照迭代器顺序输出"<<myMap.size()<<"个元素"<<endl;
    for_each(myMap.begin(), myMap.end(), print<pair<int, string> >);//批量操作
    it = myMap.find(5);
    if(it != myMap.end())
    {
        cout<<"key 5 的value是"<<it->second<<", 删除"<<endl;
    }
    myMap.erase(it);
    it = myMap.find(5);
    if (it == myMap.end())
        cout<<"未找到key 5"<<endl;
    for_each(myMap.begin(), myMap.end(), print<pair<int, string> >);cout<<endl;
    for (map<int, string>::iterator it=myMap.begin(); it!=myMap.end(); )
    {
        if((it->second).size()<3)
        {
            myMap.erase(it++);
        }
        else
            it++;
        for_each(myMap.begin(), myMap.end(),print<pair<int,string> >);
        cout<<endl;


    }
}
