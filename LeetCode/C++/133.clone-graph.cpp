/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
# include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/* 
 * Authored by Eroiko at 2021/08/27
 * Time : beats 54.6 %
 * Space : beats 70.4 %
 */
# define MAX_SIZE 100
class Solution {
public:
    Node * cloneGraph(Node * node) {
        if (node == NULL)
            return NULL;
        bool checkExist[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; ++i)
            checkExist[i] = false;
        int cnt = 0, * cnt_ptr = &cnt;
        scanWalk(node, checkExist, cnt_ptr);
        Node * res = new Node[cnt];
        for (int i = 0; i < cnt; ++i)
            res[i] = Node(i + 1);
        copyWalk(res, node, checkExist);
        // print(res, cnt, 0);
        return res;
    }

private:
    void scanWalk(Node * node, bool arr[], int * cnt){
        if (!arr[node->val - 1]){
            arr[node->val - 1] = true;
            ++(* cnt);
            for (auto n : node->neighbors){
                scanWalk(n, arr, cnt);
            }
        }
    }
    void copyWalk(Node * targetArray, Node * from, bool arr[]){
        if (arr[from->val - 1]){
            auto & vec = targetArray[from->val - 1].neighbors;
            auto & src = from->neighbors;
            for (auto & n : src)
                vec.push_back(&targetArray[n->val - 1]);
            cout << endl;
            arr[from->val - 1] = false;
            for (auto & n : src){
                copyWalk(targetArray, n, arr);
            }
        }
    }
    void print(Node * res, int num, int cur){
        while (cur < num){
            cout << cur + 1 << ": [";
            for (int i = 0, len = res[cur].neighbors.size(); i < len; ++i)
                cout << res[cur].neighbors[i]->val << ((i < len - 1) ? ", " : "]\n");
            ++cur;
        }
    }
};
// @lc code=end

