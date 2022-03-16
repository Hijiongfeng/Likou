#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<list>
#include<string>

using namespace std;

/*
请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。

实现 AllOne 类：

AllOne() 初始化数据结构的对象。
inc(String key) 字符串 key 的计数增加 1 。
如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
dec(String key) 字符串 key 的计数减少 1 。
如果 key 的计数在减少后为 0 ，那么需要将这个 key 从数据结构中删除。
测试用例保证：在减少计数前，key 存在于数据结构中。
getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
*/

struct Node
{
public:
    int val;
    unordered_set<string> keys;

    Node(int vall) : val(vall){}
};

class AllOne {
private:
    // key到list的迭代器指针的映射
    unordered_map<string,list<Node>::iterator> key2iterator;
    // 双向链表（按照val从小到大递增）
    list<Node> nodes;
public:
    AllOne() {

    }
    
    void inc(string key) {
        list<Node>::iterator nextNode;
        if(key2iterator.find(key) != key2iterator.end()){       // key存在的情况
            list<Node>::iterator currNode = key2iterator[key];
            nextNode = next(currNode,1);                // next即用来获取一个距离指定迭代器 n 个元素的迭代器。 默认为 1
             // 考虑下一个结点可能不存在 或者 不是 val+1点，则要插入并更新nextNode
            if(nextNode == nodes.end() || nextNode->val > currNode->val+1){
                nextNode = nodes.insert(nextNode,Node(currNode->val+1));
                
            }
            // 如果currNode无keys，则删除改结点
            currNode->keys.erase(key);
            if (currNode->keys.empty())
            {
                nodes.erase(currNode);
            }
        }else
        {
            // key不存在，插入到第一个结点
            nextNode = nodes.begin();

            // 为空或者不存在1的结点，则插入新的
            if (nodes.empty() || nodes.begin()->val != 1)
            {
                nextNode = nodes.insert(nodes.begin(), Node(1));
            }
        }

        // 公共的部分
        // 更新keys
        nextNode->keys.insert(key);
        // 更新到map表里
        key2iterator[key] = nextNode;
    }
    
    void dec(string key) {
            // 只需要考虑 key存在的情况
        if (key2iterator.find(key) != key2iterator.end())
        {
            // 找到该节点
            list<Node>::iterator currNode = key2iterator[key];
            if (currNode->val > 1)
            {
                // 找到更小的上一个结点
                list<Node>::iterator lastNode = next(currNode, -1);
                // 考虑上一个结点可能不存在 或者 不是 val-1点，则要插入并更新nextNode
                if (currNode == nodes.begin() || lastNode->val < currNode->val-1)
                {
                    // 坑： 这里是要插入到原来结点上一个的位置来填充val-1的位置
                    lastNode = nodes.insert(currNode, Node(currNode->val-1));
                }
                lastNode->keys.insert(key);
                // 更新map
                key2iterator[key] = lastNode;
            }
            else
            {
                // 如果已经是最小的结点（即val =1 ）则直接删除map里关系即可
                key2iterator.erase(key);
            }

            // 下面是公共的部分，更新当前结点
            currNode->keys.erase(key);
            if (currNode->keys.empty())
            {
                nodes.erase(currNode);
            }
        }
    }
    
    string getMaxKey() {
        return nodes.empty() ? "" : *(nodes.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return nodes.empty() ? "" : *(nodes.begin()->keys.begin());
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
