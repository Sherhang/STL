#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
 int main()
{
    map<int, string> myMap;//declartion
    myMap[5] = "abc";//insert,  as array
    myMap[5] = "bcd";//会覆盖
    myMap[2] = "ye";
    myMap[10] = "he";
    myMap.insert(pair<int,string>(1,"def"));//多用这种
    myMap.insert(map<int, string>::value_type(3, "efg"));//第三种
    myMap.insert(pair<int, string>(1, "hij"));//有1了，所以不会做任何操作
    map<int, string>::iterator it = myMap.begin();
    cout<<"按照迭代器顺序输出"<<myMap.size()<<"个元素"<<endl;
    for(it; it != myMap.end(); ++it)
    {
        cout<<it->first<<" "<<it->second<<endl;//map will sort by the key(first)
    }
    it = myMap.find(5);
    if(it != myMap.end())
    {
        cout<<"key 5 的value是"<<it->second<<", 删除"<<endl;
    }

    myMap.erase(it);
    it = myMap.find(5);
    if (it == myMap.end())
        cout<<"未找到key 5"<<endl;
}
