////
//// Created by Administrator on 2019/4/20.
////
//
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//using namespace std;
//struct treeNode {
//    int val;
//    treeNode *left;
//    treeNode *right;
//    treeNode(int x) :val(x), left(NULL), right(NULL) {}
//};
//
//int TreeDepth(treeNode* pRoot);
//
//int main() {
//    //测试
//    treeNode *root = new treeNode(5);
//    treeNode *node1 = new treeNode(3);
//    treeNode *node2 = new treeNode(7);
//    root->left = node1;
//    root->right = node2;
//    treeNode *node3 = new treeNode(2);
//    treeNode *node4 = new treeNode(4);
//    treeNode *node5 = new treeNode(6);
//    treeNode *node6 = new treeNode(8);
//
//    cout << TreeDepth(root) << endl;
//
//    return 0;
//}
//
////递归的求解
//int TreeDepth(treeNode* pRoot) {
//    if (pRoot == NULL)return 0;
//
//    int l = TreeDepth(pRoot->left)+1;
//    int r = TreeDepth(pRoot->right)+1;
//
//    return (l > r) ? l : r;
//}
//
////不使用递归
//int TreeDepth_bfs(treeNode* pRoot) {
//    if (pRoot == NULL)return 0;
//
//    queue<treeNode *> nodeQueue;
//    nodeQueue.push(pRoot);
//    int depth = 0;             //记录深度
//    int curNumPerLevel = 0;    //下一层的叶节点个数，会随着新的左右子节点入队而增加，更新前的值为下一层的节点个数
//    int lastNumPerLevel = 1;   //当前层的叶节点个数，随着节点出队列而逐渐减少，减少到1说明遍历完了当前层
//    while (!nodeQueue.empty()) {
//        treeNode * tmpNode = nodeQueue.front();
//        nodeQueue.pop();
//
//        if (tmpNode->left) {
//            nodeQueue.push(tmpNode->left);
//            curNumPerLevel++;
//        }
//
//        if (tmpNode->right) {
//            nodeQueue.push(tmpNode->right);
//            curNumPerLevel++;
//        }
//
//        //lastNumPerLevel--;
//        //遍历完一层不仅要更新lastNumPerLevel，还要重置curNumPerLevel
//        if (!(--lastNumPerLevel)) {
//            depth++;
//            lastNumPerLevel = curNumPerLevel;
//            curNumPerLevel = 0;
//        }
//    }
//
//    return depth;
//}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int x) :val(x), left(NULL), right(NULL) {}
};

bool IsBalanced_Solution(treeNode* pRoot);
bool balanced_tree(treeNode * pRoot, int *depth);

int main() {
    //测试
    treeNode *root = &treeNode(5);
    treeNode *node1 = &treeNode(3);
    treeNode *node2 = &treeNode(7);
    root->left = node1;
    root->right = node2;
    treeNode *node3 = &treeNode(2);
    treeNode *node4 = &treeNode(4);
    treeNode *node5 = &treeNode(6);
    treeNode *node6 = &treeNode(8);
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    if(IsBalanced_Solution(root)){
        cout << "is avl." << endl;
    }
    else{
        cout << "not avl." << endl;
    }

    return 0;
}


//二叉树的深度
//这个题可以使用树的深度来进行求解，但是存在重复遍历的问题，不是很理想
//一遍遍历的方法如下，在遍历的同时记录其深度，一遍判断其子树是否平衡
bool IsBalanced_Solution(treeNode* pRoot) {
    if (pRoot == NULL)return true;

    int depth;
    return balanced_tree(pRoot, &depth);
}

bool balanced_tree(treeNode * pRoot, int *depth) {
    if(pRoot == NULL){
        *depth = 0;
        return true;
    }

    int left, right;
    bool left_b = balanced_tree(pRoot->left, &left);
    bool right_b = balanced_tree(pRoot->right, &right);
    if(left_b && right_b){
        int dif = abs(left - right);
        if(dif < 1){
            *depth = 1 + (left > right)? left : right;
            return true;
        }
    }
    return true;
}