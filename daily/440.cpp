#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。

输入: n = 13, k = 2
输出: 10
解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，
所以第二小的数字是 10。
*/

class Solution {
public:
    int findKthNumber(int n, int k) {   // 变成 字符串在进行排序，天然就是 字典序
        vector<string> vec;
        for(int i = 1;i<=n;i++){
            vec.push_back(to_string(i));
        }
        //sort(vec.begin(),vec.end());
        partial_sort(vec.begin(),vec.begin()+k,vec.end());
        
        string res = vec[k-1];
        return stoi(res);
    }
};
/*

1.怎么确定一个前缀下所有子节点的个数？
2.如果第 k 个数在当前的前缀下，怎么继续往下面的子节点找？
3.如果第 k 个数不在当前的前缀，即当前的前缀比较小，如何扩大前缀，增大寻找的范围？

当然，不知道大家发现一个问题没有，当 next 的值大于上界的时候，那以这个前缀为根节点的十叉树就不是满十叉树了啊，
应该到上界那里，后面都不再有子节点。因此，count += next - cur 还是有些问题的，我们来修正这个问题:

你可能会问:咦？怎么是 n+1 ,而不是 nn 呢？不是说好了 nn 是上界吗？

我举个例子，假若现在上界 nn为 12，算出以 1 为前缀的子节点数，首先 1 本身是一个节点，接下来要算下面 10，11，12，一共有 4 个子节点。

那么如果用 curMath.min(n,next)−cur 会怎么样？

这时候算出来会少一个，12 - 10 加上根节点，最后只有 3 个。因此我们务必要写 n+1。

现在，我们搞定了前缀的子节点数问题。


*/

class Solution2 {
public:
    long getCount(long prefix, long n) {
        long cur = prefix;
        long next = cur + 1;
        long count = 0;
        while(cur <= n) {
            count += min(n+1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        long p = 1;
        long prefix = 1;
        while(p < k) {
            long count = getCount(prefix, n);
            if (p + count > k) {
                /// 说明第k个数，在这个前缀范围里面
                prefix *= 10;
                p++;
            } else if (p+count <= k) {
                /// 说明第k个数，不在这个前缀范围里面，前缀需要扩大+1
                prefix++;
                p += count;
            }
        }
        return static_cast<int>(prefix);
    }
};

int main(int argc, char const *argv[])
{
    int n = 13,k = 5;
    Solution2 sol;
    cout<<sol.findKthNumber(n,k)<<endl;
    for (int i = 0; i < 2; i++)

    system("pause");
    return 0;
}
