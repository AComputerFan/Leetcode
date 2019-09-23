#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
using std::cout;
using std::vector;
using std::endl;
using std::min;
using std::max;

// #define min(a, b) (a) > (b) ? (b) : (a)
// #define max(a, b) (a) > (b) ? (a) : (b)


class Solution {
private:
    int **ptr;
    int len;
    
public:
    void Clear() {
        for (int i = 0; i < len; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }
    ~Solution() {
        Clear();
    }


    int maxArea(vector<int>& height) {
        /*
         *  从i-j之间最大的矩形为 m(i, j)
         *  它可以变成
         *  m(i, j) = max(m(i-1, j), m(i-1, j), min(h[i], h[j]) * (j - i))
         */
        int n = height.size();
        int rs = 0;

        // 初始化二维数组
        len = n;
        ptr = new int*[n];
        for (int i = 0; i < n; i++) {
            ptr[i] = new int[n];
        }
        
        // 遍历数组进行计算   
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j != 0) { 
                    ptr[i][j] = max( max(ptr[i - 1][j], ptr[i][j - 1]), min(height[i], height[j]) * (i - j));
                } else {
                    ptr[i][j] = max(ptr[i - 1][j], (min(height[i], height[j]) * (i - j)));
                }
                
                if (ptr[i][j] > rs) {
                    rs = ptr[i][j];
                }
            }
        }      
        return rs;

    }
};

int main() {
    Solution s;

    vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7}; 
    cout << s.maxArea(heights) << endl;

}