#include<bits/stdc++.h>

using namespace std;

/*

给你一个二维整数数组 tiles ，其中 tiles[i] = [li, ri] ，表示所有在 li <= j <= ri 之间的每个瓷砖位置 j 都被涂成了白色。

同时给你一个整数 carpetLen ，表示可以放在 任何位置 的一块毯子。

请你返回使用这块毯子，最多 可以盖住多少块瓷砖。


示例 1：
输入：tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
输出：9
解释：将毯子从瓷砖 10 开始放置。
总共覆盖 9 块瓷砖，所以返回 9 。
注意可能有其他方案也可以覆盖 9 块瓷砖。
*/

class Solution {
    
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        int maxNum = tiles[n-1][1];
        
        vector<int> preFix(maxNum+1);
        vector<bool> isvaild(maxNum+1,true);
        for(int i = 0;i<n-1;i++){
            int left = tiles[i][0];
            int right = tiles[i][1];
            int right2 = tiles[i+1][0];
            for(int j = left;j<=right;j++){
                preFix[j] = preFix[j-1]+1;
            }
            for(int j = right+1;j<right2;j++){
                preFix[j] = preFix[j-1];
                isvaild[j] = false;
            }
        }
        int left = tiles[n-1][0];
        int right = tiles[n-1][1];
        for(int j = left;j<=right;j++){
            preFix[j] = preFix[j-1]+1;
        }

        if(maxNum < carpetLen){
            return preFix.back() - preFix.front();
        }

        int stop = maxNum+1-carpetLen;
        int ans = INT_MIN;
        for(int i = 1;i<=stop;i++){
            if(isvaild[i] == true){
                ans = max(ans,preFix[i+carpetLen-1] - preFix[i] + 1);
            }else{
                ans = max(ans,preFix[i+carpetLen-1] - preFix[i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{/*{{8051,8057},{8074,8089},{7994,7995},{7969,7987},
                                 {8013,8020},{8123,8139},{7930,7950},{8096,8104},{7917,7925},{8027,8035},{8003,8011}};*/
    vector<vector<int>> tiles = {{8051,8057},{8074,8089},{7994,7995},{7969,7987},
                                 {8013,8020},{8123,8139},{7930,7950},{8096,8104},{7917,7925},{8027,8035},{8003,8011}};
    int carpetLen = 9854;
    Solution sol;
    cout<<sol.maximumWhiteTiles(tiles,carpetLen)<<endl;
    system("pause");
    return 0;
}
