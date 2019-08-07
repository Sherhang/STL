/*
 * 构造函数和初始化操作
 *  string();
 *  string(int len, char c);//len个c
 *  string(const char* str);
 *  string(const char* str, int len);//取str的前len个字符
 *  string(string& str, int index, int len);//str[index,index+len)区间的
 *  string(itreator start, iterator last);//迭代器
 *  =
 * 操作符
 *   == > < >= <= != + += []
 * 成员函数 字符赋值和读取类函数
 *  append(), assign(), at(), size(), max_size(), reserve(), resize(),capacity()
 *  string& append(const string &str);//末尾追加str
 *  string& append(const char* str);
 *  string& append(const string& str, int index, int len);
 *  string& append(coonst char* str, int num);//追加num个str
 *  string& append(int num, char c);//追加num个单字符c
 *  string& append(iterator first, iterator last);//[first,last)迭代器区间的元素
 *  //assign()函数基本上和初始化差不多
 *  string& assign(const string& str);//赋值，会覆盖原来的
 *  string& assign(const char* str);
 *  string& assign(cosnst string& str, int index, int len);//[index, index+len)区间的字符
 *  string& assign(int num, char c);//num个c
 *  reference at(int index);//at()返回引用，可以直接用[]更方便
 * 迭代器
 *  begin(), end(), rbegin(), rend()
 * 和char*的转换
 *  c_str();//转化为const char*
 *  data();//成员函数，转为const char* 
 *  string& copy(char* cstr, int len, int index);//demo: str.copy(cstr, 2, 0);*(cstr+2)='\0';
 * 修改和替换成员函数
 *  erase(), insert(), replace(), swap(),
 *  iterator erase(iterator it);//删除it位置的元素，返回it下一个迭代器
 *  iterator erase(iterator first, iterator last);//删除一个区间的元素，返回下一个迭代器
 *  string& erase(int p=0, int len = npos);//删除索引从p开始的len个元素,同时把删除后的结果作为返回值，方便链式表达
 *  //insert 函数功能很多，列举常用的，分为索引式和迭代器方式
 *  string& insert(int p, const string& str);//常用
 *  string& insert(int p, const string& str, int index, int len);//把str的子串[index,index+len)插入p位置
 *  string& insert(int p, const char* cstr);//在索引p位置插入cstr,并返回
 *  string& insert(int p, const char* cstr, int len);//在索引p位置插入cstr的前len个字符,并返回
 *  string& insert(int p, int num, char c);//在p位置插入num个单字符c
 *  iterator insert(iterator it, char c);//在it位置插入c
 *  void insert(iterator it, int num, char c);//在it位置插入num个c
 *  void insert(iterator it, iterator first, iterator last);//插入一个区间
 *  //replace 替换,str前面的是原串的区间，后面的是str的区间或个数，结果还会返回
 *  string & replace( int index, int num, const string& str );//使用str替换原串从index位置开始的num个字符，常用
 *  string & replace( int index1, int num1, const string &str, int index2,int num2 );//使用str的[index2,index2+num)替换原串[index1,index1+num)
 *  string & replace( int index, int num, const char* cstr );//使用
 *  string & replace( int index, int num1, const char *str, int num2 );
 *  string & replace( int index, int num1, int num2, char ch );
 *  string & replace( iterator start, iterator end, const string &str );
 *  string & replace( iterator start, iterator end, const char *str );
 *  string & replace( iterator start, iterator end, const char *str, int num );
 *  string & replace( iterator start, iterator end, int num, char c );
 * 查找
 * find(), rfind(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
 * int find(const string& str, int p=0);//从原串的p索引开始找str,返回第一次出现的位置,没找到则返回string::npos
 * int find(const char* cstr, int p=0);
 * int find(const char* cstr, int index=0, int len);//len是指选取cstr的前len个字符
 * int find(char c, int index);
 * //rfind和find()用法一样，是逆向查找
 * //find_first_of()和find()用法一样，find_last_of()和rfind()用法一样
 * //find_first_not_of()和前面用法一样，找第一个不相等的字符串或单字符
 * 输入输出
 * <<, >>, getline()
 * bool getline(istream, string str, char c);//以c为分界读取输入流，遇到结束符返回false.第三个参数不写则全部读入str
 * //格式化字符串demo: snprintf(cstr, 100, "%02f-%03d", 12.3, 324.0);string s = cstr;
 * int snprintf(char* cstr, size_t len, const char *format, ...);//<stdio.h> c函数,限制长度上限len,格式化放到str中,成功返回源串的长度(strlen, 不含'\0'),失败返回负数。
 * int sprintf(char*cstr, const char* format, ...);//不限制长度
 * c语法格式控制
 *   %d,%ld 实际长度输出整型数和长整型
 *   %2d  指定宽度输出整型数，左边补空格，实际长度比n大则以实际宽度输出
 *   %02d 指定宽度(2)输出整型数，左边补 0 ，实际长度比n大则以实际宽度输出
 *   %f   单精度和双精度实际长度输出
 *   %.2f 小数点保留2位
 *   %6.2f 小数点保留2位，字符总长度调整为6位，左端补空格
 *   %06.2f 小数点保留2位，字符总长度调整为6位，左端补0
 *   %o   八进制输出整数
 *   %x   16进制输出整数
 *        %x、%X、%#x、%#X  分别对应  2f, 2F, 0x2f, 0X2F
 *   %s  字符串
*/

#include <iostream>
#include <stdio.h>
#include <string> //使用标准c++的string
#include <iterator>
using namespace std;

int main()
{
    {
        cout<<"构造："<<endl;
        string str1();//默认是 1
        string str2(3, 'a');//aaa
        char cc[10]={'h','e','l','l','o'};
        char* cstr3 = cc;
        string str3(cstr3);//hello
        string str4(cstr3, 3);//hel
        string s = "hello";
        string str5(s,1,2);//el
        string str6(++s.begin(),--s.end());//ell
        string str7 = "hello";//hello
        string str8("hello");
        cout<<str1<<endl;
        cout<<str2<<endl;
        cout<<str3<<endl;
		cout<<str4<<endl;
		cout<<str5<<endl;		
		cout<<str6<<endl;
		cout<<str7<<endl;
        cout<<str8<<endl;
    }
    {
        cout<<"修改和替换"<<endl;
        cout<<"erase: "<<endl;
        string str0("This is");
        string s1(str0);
        cout<<"s1.npos="<<s1.npos<<endl;//18446744073709551615
        cout<<s1.erase(4, 2);//此时 s1 = "Thiss"
        auto it = s1.begin();it++;//it->'h'
        it = s1.erase(it);cout<<s1<<endl;//s1 = Tiss
        cout<<*it<<endl;//it指向下一个元素，it -> 'i'
        s1.assign(str0);//s1 = "This is"
        cout<<"erase 使用"<<endl;
        string  s2("for the first time");
        cout<<s1.replace(5,3,s2)<<endl;//s1 = This for the first time
    }
    {
        cout<<"查找功能"<<endl;
        string str("this is a test");
        string s1="is";
        cout<<str.find(s1)<<endl;//2
        cout<<str.find(s1, 3)<<endl;//5,从原串3索引开始找
        cout<<str.find("test", 0, 1)<<endl;//0，因为只是找"t"
    }
    {
        cout<<"格式化字符串"<<endl;
        char cstr[100];//不能直接用char*, char* 直接初始化时没有分配内存
        snprintf(cstr,100, "%06.2f%s", 0.5,"hi");
        string str = cstr;
        cout<<str.size()<< " " <<str<<endl;
    }
}
