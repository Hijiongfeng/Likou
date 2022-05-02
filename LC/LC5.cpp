#include <bits/stdc++.h>

using namespace std;

/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 
注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。
*/

class Solution
{
    bool vaild(vector<vector<string>> &board, int x, int y)
    {
        int m = board.size();
        int n = board[0].size();
        // 验证行
        unordered_set<string> row_set;
        for (int j = 0; j < n; j++)
        {
            if (board[x][j] != ".")
            {
                if (row_set.count(board[x][j]))
                {
                    return false;
                }
                else
                {
                    row_set.insert(board[x][j]);
                }
            }
        }

        // 验证列
        unordered_set<string> col_set;
        for (int i = 0; i < m; i++)
        {
            if (board[i][y] != ".")
            {
                if (col_set.count(board[i][y]))
                {
                    return false;
                }
                else
                {
                    col_set.insert(board[i][y]);
                }
            }
        }

        // 验证正方形
        unordered_set<string> sqare_set;
        int i1 = x / 3 * 3;
        int j1 = y / 3 * 3;

        int i2 = i1 + 2, j2 = j1 + 2;
        for (int i = i1; i <= i2; i++)
        {
            for (int j = j1; j <= j2; j++)
            {
                if (board[i][j] != ".")
                {
                    if (sqare_set.count(board[i][j]))
                    {
                        return false;
                    }
                    else
                    {
                        sqare_set.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<string>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == ".")
                {
                    continue;
                }
                else if (board[i][j] != "." && !vaild(board, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<string>> board =
        {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
         {"6", ".", ".", "1", "9", "5", ".", ".", "."},
         {".", "9", "8", ".", ".", ".", ".", "6", "."},
         {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
         {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
         {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
         {".", "6", ".", ".", ".", ".", "2", "8", "."},
         {".", ".", ".", "4", "1", "9", ".", ".", "5"},
         {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    Solution sol;
    cout << sol.isValidSudoku(board) << endl;

    system("pause");
    return 0;
}
