/*STL泛型算法
 * 1.非修改型算法
 * for_each()
 *      第三个参数可以是普通一元函数，也可以是仿函数
 * count(), count_if 
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
 * 2.比较算法
 *  equal(), mismatch(), lexicographical_compare()
 *      bool equal(iterator start, iterator end, iterator comp_start);//比较两组迭代器内容是否相等，第二组只要给出起始位置，只比较到和第一组一样长的位置
 *      bool equal(iterator start, iterator end, iterator comp_start, Pred pr);//用自定义二元规则pr进行比较
 *      template<class T, class E> 
 *              pair<T, E> mismatch(T first, T last, E compare_first); //一般都是迭代器T,E, 从头开始找不同的元素的位置
 *      tempolate<class T, class E> 
 *              pair<T, E> mismatch(T first, T last, E comapre_first, Pred pr);
 *      bool lexicographical_compare(T first, T last, E first2, E last2);//字典式比较,第一组小于第二组则返回true
 *      bool lexicographical_compare(T first, T last, E first2, E last2, Pred pr);
 * 3.修改性算法
 * 注意:set, map类不可以用。它们只能使用自己的成员函数
 * 3.1 复制
 * copy(), copy_backward()
 *      iterator copy(iterator first, itreator last, iterator begin);//把first到last的元素正向复制到begin开始，覆盖，目标区间需要足够空间
 *      iterator copy_backward(iterator first, iterator last, iterator end);//把区间[first, last)从后向前复制到end结束
 * 3.2 转换
 * transform(),
 *      iterator transform(iterator first, iterator last, iterator begin, Unop op);//对[first, end)区间的每个元素调用op(ele)函数，写入begin开始的目标区间
 *      iterator transform(iterator first1, iterator last, iterator first2, iterator begin, Binop bop);//对区间[first, end)和对应的[first,)元素，调用二元函数bop(ele1, ele2),运算后写入[begin,)
 * 3.3 互换
 * swap()
 * 3.4 赋值
 * fill(), fill_n(), generate(), generate_n()
 *      void fill(iterator first, iterator last, const T& x);//对区间[first, last)赋x
 *      void fill_n(iterator begin, size_t n, const T& x);//对[begin, begin+n)赋x
 *      void generate(iterator first, iterator last, Gen g);//用子进程或仿函数对区间赋值
 *      void generate_n(iterator begin, size_t n, Gen g);
 * 3.5 替换
 * replace(), replace_if()
 *      void replace(iterator first, iterator last, const T& old, const T& new);//在区间把old替换成new
 *      void replace_if(iterator first, iterator last, Pred pr, const T& new);//在区间把满足一元判断的替换成new
 * 3.6 逆转
 * reverse(), reverse_copy()
 *      iterator reverse_copy(iterator first, iterator last, iterator begin);//反转区间并放到[begin,)，返回目标区间未被覆盖的下一个位置
 * 3.7 旋转
 * rotate(), rotate_copy()
 *      void rotate(iterator first, iterator middle, itrator last);//把middle移到first的位置，环形移动
 *      iterator rotate_if(iterator first, iterator middle, itrator last, iterator result);//把middle移到first的位置，环形移动, 放到目标区间
 * 3.8 排列
 * next_permutation(), random_shuffle(), partition()
 *      bool next_permutation(iterator first, iterator last);//升序，到最后一个排列返回false。自动重排
 *      bool next_permutation(iterator first, iterator last, Coompare comp);//以自定义顺序排列
 *      void random_shuffle(iterator first, iterator last);//均匀分布
 *      void random_shuffle(iterator first, iterator last, Generator& gen);//按指定规则
 *      iterator partition(iterator first, iterator last, Predicate pred);//前向搬移元素，不排序。把不满足一元判断的元素向前搬移到pr为false的第一个元素之前
 *      iterator stable_partition(iterator first, iterator last, Predicate pred);//会保留一个相对的顺序
 * 4 排序及其相关算法
 *  用随机访问型迭代器进行操作，一般是vector, deque, c数组
 *  4.1 排序算法
 * sort(), stable_sort(), partial_sort(), partial_sort_copy(), nth_element()
 *      void sort(iterator first, iterator last);//stable_sort和sort调用形式一样
 *      void sort(iterator first, iterator last, Pred pr);//以二元判断pr进行排序,如greater<int>()
 *      void partial_sort(iterator first, iterator middle, iterator last);//对[first, last)之间的元素进行排序，有序的放在[first, middle)，无序的放在末尾,只会排序last-first个元素
 *      void partial_sort(iterator first, iterator middle, iterator last, Pred pr);//二元判断
 *      iterator partical_sort_copy(iterator first1, iterator last1, iterator first2, iterator last2);//排序数量是两个区间中较小值
 *      iterator partical_sort_copy(iterator first1, iterator last1, iterator first2, iterator last2, Pred pr);//二元
 *      void nth_element(iterator first, iterator nth, iterator last); // nth位置元素就位，这种方法很方便取n大或n小个数
 *      void nth_element(iterator first, iterator nth, iterator last, Compare comp);//用二元判断
 *  4.2 堆算法
 * push_heap(), pop_heap(), sort_heap(), make_heap()
 *      void make_heap(iterator first, iterator last);//区间变成堆，默认从大到小
 *      void make_heap(iterator first, iterator last, Compare comp);//二元判断，如greater<>() 实现从小打到
 *      void push_heap(iterator first, iterator last);//新插入元素放在堆栈末尾，原来的区间必须已经是堆
 *      void push_heap(iterator first, iterator last, Compare comp);//二元判断
 *      void pop_heap(iterator first, iterator last);
 *      void pop_heap(iterator first, iterator last, Compare comp);
 *      void sort_heap(iterator first, iterator last);
 *      void sort_heap(iterator first, iterator last, Compare comp);
 *  4.3 并，交，叉集, 新生成的区间都是有序的
 * merge(), set_union(), set_intersection(), set_difference(), inplace_merge()
 *      iterator merge(iterator first1, iterator last1, iterator first2, iterator last2, iterator x);//[first1, last1)和[first2, last2)合并到[x, ), 一般来说，两个区间应该有序。
 *      iterator merge(iterator first1, iterator last1, iterator first2, iterator last2, iterator x, Compare comp);//二元判断
 *      iterator set_union(iterator first1, iterator last1, iterator first2, iterator last2, iterator begin);//[first1,last1)和[first2, last2)取并集到[begin,),如果原区间有重复元素，那么新容器保留个数较大的作为保留个数
 *      iterator set_union(iterator first1, iterator last1, iterator first2, iterator last2, iterator begin, Compare comp);
 *      iterator set_intersection(iterator first1, iterator last1, iterator first2, iterator last2, iterator begin);//交集，有重复元素取个数较小的区间作为个数
 *      iterator set_intersection(iterator first1, iterator last1, iterator first2, iterator last2, iterator begin, Compare comp);
 *      iterator set_difference(iterator first1, iterator last1, iterator first2, iterator last2, iterator begin);//差集，区间1 - 区间2，重复元素个数等于区间1-区间2，最小为0个
 *      iterator set_difference(iterator first1, iterator last1, iterator first2, iterator last2, iterator begin, Compare comp);
 *      iterator set_symmetric_difference(iterator first1, terator last1, iterator first2, iterator last2, iterator begin);//合并的新区间不包含原区间共同存在的元素
 *      iterator set_symmetric_difference(iterator first1, terator last1, iterator first2, iterator last2, iterator begin, Compare comp);//
 *      void inplace_merge(iterator first, iterator middle, iterator last);//[first, middle) , [middle, last); 合并为[first, last)
 *      iterator set_symmetric_difference(iterator first1, terator last1, iterator first2, iterator last2, iterator begin, Commpare comp);//
 * 4.6 搜索算法
 * binary_search(), includes(), lower_bound(), equal_range(), upper_bound()
 *      bool binary_search(iterator first, iterator last, const T& x);//二分查, 原区间必须有序
 *      bool binary_search(iterator first, iterator last, const T& x, Compare comp);//二元判断作为排序准则
 *      bool includes(iterator first1, iterator last1, iterator first2, iterator last2, Compare comp);//检查区间2 是否在区间1 中， 二元判断comp可有可无
 * 4.7 移除算法
 * remove(), remove_if(), remove_copy(), remove_copy_if(), unique(), unique_copy()
 *      iterator remove(iterator first, iterator last, const T& x);//返回值是新容器的末尾，以下返回值都是新容器末尾，返回值非常重要。因为不是真的删除
 *      iterator remove_if(iterator first, iterator last, Predicate pr);//用一元判断删除条件为真的元素
 *      iterator remove_copy(iterator first, iterator last, iterator begin, const T& x);//在复制过程中删除元素
 *      iterator remove_copy_if(iterator first, iteerator last, iterator begin, const T& x, Predict pr);//一元判断
 *      iterator unique(iterator first, iterator last);//移除相邻的重复元素，如果想去重，应该先sort，然后截取
 *      iterator unique(iterator first, iterator last, Compare comp);//二元判断
 *      iterator unique_copy(iterator first, iterator last, iterator begin);//
 *      iterator unique_copy(iterator first, iterator last, iterator begin, Compare comp);
 * 5 其它
 * distance()
 *      int distance(iterator first, iterator last);//计算迭代器距离
 */


#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iterator> //ostream_iterator<>
#include <limits.h> //INT_MAX
using namespace std;

template <class T>
void print(const T& item)//注意，不要用&，对于set等，不可以用修改性算法
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
bool adjacent_even(int a, int b)
{
    return (a%2 == 0 && b%2==0);
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
    {
        cout <<"equal 使用："<<endl;
        vector<int> n1={3,2,1,0,2,1,4,5};
        set<int> nums(n1.begin(), n1.end());
        for_each(nums.begin(),nums.end(), print<int>);cout<<endl;
        vector<int> n2={6,4,2,0,4,2,8,10,11,13};
        set<int> nums1(n2.begin(),n2.end());
        for_each(nums1.begin(),nums1.end(), print<int>);cout<<endl;
        bool eq_vector = equal(n1.begin(),n1.end(),n2.begin());
        if(eq_vector) 
            cout<<"n1==n2"<<endl;
        bool eq_set = equal(nums.begin(),nums.end(),nums1.begin(), is_double_num);//是否每个元素都是两倍
        if(eq_set)
            cout<<"nums==2*nums1"<<endl;
    }
    {
        cout<<"mismach使用："<<endl;
        vector<int> nums1={1,3,5,6,7,8,9};
        vector<int> tmp={1,3,5,6,8,9,0};
        list<int> nums2(tmp.begin(),tmp.end());
        for_each(nums1.begin(), nums1.end(), print<int>); cout<<endl;
        for_each(nums2.begin(), nums2.end(), print<int>); cout<<endl;
        pair<vector<int>::iterator, list<int>::iterator> pvl;
        pvl = mismatch(nums1.begin(), nums1.end(), nums2.begin());
        if(pvl.first == nums.end())
            cout<< "没有找到相异点，但不代表nums1==nums2" <<endl;
        cout<< "不匹配的元素是："<<*pvl.first<<" "<<*pvl.second<<endl;
    }
    {
        cout<<"lexicographical_compare使用："<<endl;
        vector<int> nums1={1,3,4,5};
        vector<int> nums2={1,3,4,5,7};
        for_each(nums1.begin(), nums1.end(), print<int>);cout<<endl;
        for_each(nums2.begin(), nums2.end(), print<int>); cout<<endl;
        bool flag = lexicographical_compare(nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
        if(flag)
            cout<<"nums1<nums2 "<<endl;
    }
    {
        cout<<"copy和copy_backward使用："<<endl;
        vector<int> nums1={1,2,3,4,5,6,7,8,9,0};
        vector<int> tmp={10,11,12,13,14};
        list<int> nums2(tmp.begin(), tmp.end());
        copy(nums1.begin(),nums1.end(), ostream_iterator<int>(cout, " "));cout<<endl;//拷贝到输出流中，实现输出
        copy(nums2.begin(), nums2.end(),ostream_iterator<int>(cout, " "));cout<<endl;
        cout<<"nums1的容量："<<nums1.capacity()<<endl;
        for_each(nums1.begin(),nums1.end(), print<int>);cout<<endl;
        copy_backward(nums2.begin(), nums2.end(), nums1.end());
        nums1.reserve(20);//增加容量,否则下面的会溢出
        cout<<"nums1的容量："<<nums1.capacity()<<endl;
        cout<<"nums1的size；"<<nums1.size()<<endl;
        copy(nums2.begin(),nums2.end(), nums1.end());//有内存溢出风险,这样复制也没用。nums的size还是10
        cout<<"nums1的size；"<<nums1.size()<<endl;
        copy(nums1.begin(),nums1.end(), ostream_iterator<int>(cout, " "));cout<<endl;
    }
    {
        cout<<"transform使用："<<endl;
        int a[10]={1,2,3,4,5,6,7,8,9,10};
        vector<int> nums1;
        nums1.assign(a, a+10);//用assign赋值
        list<int> list1, list2;
        transform(nums1.begin(), nums1.end(), back_inserter(list1), negate<int>());//用插入型迭代器，取相反数
        cout<<"nums1:"<<endl;
        for_each(nums1.begin(), nums1.end(), print<int>);cout<<endl;
        cout<<"list1:"<<endl;
        for_each(list1.begin(), list1.end(), print<int>);cout<<endl;
        transform(list1.begin(), list1.end(), list1.begin(), bind2nd(multiplies<int>() ,10) );//给list1的每个元素乘以10，再写给自己
        transform(list1.begin(), list1.end(),list1.begin(),  bind2nd(plus<int>(), 25));//注意用for_each + plus是不行的：
        cout<<"list1*10+25:"<<endl;
        for_each(list1.begin(), list1.end(), print<int>);cout<<endl;
        transform(list1.begin(), list1.end(), nums1.begin(), back_inserter(list2), divides<int>());//第一组除以第二组
        cout<<"list2=list1/nums1:"<<endl;
        for_each(list2.begin(), list2.end(), print<int>);cout<<endl;
    }
    {
        cout<<"fill ,generate 使用："<<endl;
        vector<int> nums1(10,1);
        vector<int> nums2(20,2);
        fill(++nums1.begin(), --nums1.end(), 3);
        for_each(nums1.begin(), nums1.end(), print<int>);cout<<endl;
        generate(nums2.begin(), nums2.begin()+20, rand);
        transform(nums2.begin(), nums2.end(), nums2.begin(), bind2nd(divides<int> (), INT_MAX/10));//随机数变换到1-10：
        for_each(nums2.begin(), nums2.end(), print<int>);cout<<endl;
    }
    {
        cout<<"replace 使用："<<endl;
        vector<long> nums1={1,2,3,4,5,6,7,8,9,0};
        replace_if(nums1.begin(), nums1.end(), even_num, 0);//把偶数替换成0
        for_each(nums1.begin(), nums1.end(), print<int>);cout<<endl;
    }
    {
        cout<<"random_shuffle使用："<<endl;
        vector<int> nums={1,2,3,4,5,6,7,8,9,0};
        random_shuffle(nums.begin(), nums.end());
        for_each(nums.begin(), nums.end(),print<int> );cout<<endl;//123395642,并且不会随机变化
    }
    {
        cout<<"partition使用："<<endl;
        vector<int> a={1,2,3,4,5,6,7,8,9};
        vector<int>::iterator it1, it2;
        //把偶数移到前面：
        it1 = stable_partition(a.begin(), a.end(), not1(bind2nd(modulus<int>(), 2)));//模2，not1构造一个和谓词结果相反的一元谓词。等效于偶数为true
        for_each(a.begin(), a.end(), print<int>);cout<<endl;
    }
    {
        cout<<"sort等排序测试:"<<endl;
        vector<int> nums1={9,8,7,6,5,4,3,2,1,0};
        for_each(nums1.begin(), nums1.end(), print<int>);cout<<endl;
        partial_sort(nums1.begin(), nums1.begin()+5, nums1.end());//会取前5个有序的放前面，其它位置顺序不管
        for_each(nums1.begin(), nums1.end(), print<int>);cout<<endl;
        cout<<"nth_element测试：,下标3就位："<<endl;
        nums1={1,2,3,4,5,6,7,8,9,0};
        nth_element(nums1.begin(), nums1.begin()+3, nums1.end(), greater<int> () );//前三个元素比3号位大,后面的比它小
        for_each(nums1.begin(), nums1.end(), print<int> );cout<<endl;


    }
    {
        cout<<"堆算法测试："<<endl;
        vector<int> nums={5,7,6,9,8,0,1,2,4};
        for_each(nums.begin(), nums.end(), print<int>);cout<<endl;
        cout<<"make_heap:"<<endl;
        make_heap(nums.begin(), nums.end());//默认以<排序,此时只是内部是堆，直接输出是乱的
        for_each(nums.begin(), nums.end(), print<int>);cout<<endl;
        cout<<"push_heap:"<<endl;
        nums.push_back(3);
        push_heap(nums.begin(), nums.end());
        for_each(nums.begin(), nums.end(), print<int>);cout<<endl;
        cout<<"pop_heap:"<<endl;
        pop_heap(nums.begin(),nums.end());
        nums.pop_back();//注意顺序
        cout<<"sort_heap:"<<endl;
        sort_heap(nums.begin(), nums.end());
        for_each(nums.begin(), nums.end(), print<int>);cout<<endl;
    }
    {
        cout<<"移除算法测试："<<endl;
        vector<int> a = {1,2,3,2,4,5};
        list<int> nums(a.begin(), a.end());
        list<int>::iterator it1, it2, it3;
        for_each(nums.begin(), nums.end(), print<int> );cout<<endl;
        cout<<"unique:"<<endl;
        it1 = unique(nums.begin(), nums.end());//unique只能移除相邻的重复元素，如果想去重，应该先sort
        for_each(nums.begin(), nums.end(), print<int>);cout<<endl;
        cout<<"新容器末尾序号："<<distance(nums.begin(), it1)<<endl<<"unique(,,is_double_num):"<<endl;
        it2 = unique(nums.begin(), nums.end(), adjacent_even);//移除连续偶数,把连续偶数中后面的都当成“相等的元素”移除
        for_each(nums.begin(), nums.end(), print<int> ); cout<<endl;
        cout<<"新容器末尾是："<<*it2<<endl;

        cout<<"remove 使用:"<<endl;
        nums = {1,2,3,4,5,2,4,6,8,0};
        for_each(nums.begin(), nums.end(), print<int>);cout<<endl;
        it1 = remove(nums.begin(), nums.end(), 2);//移除2
        cout<<"remove 2 之后："<<endl;
        for_each(nums.begin(), nums.end(), print<int>);
        cout<<"新容器end(): "<<distance(nums.begin(), it1)<<endl;
        cout<<"remove 偶数: "<<endl;
        it2 = remove_if(nums.begin(), nums.end(), even_num);
        for_each(nums.begin(), nums.end(), print<int>);
        cout<<"新容器end(): "<<distance(nums.begin(),it2)<<endl;
    }
}

