//
// Created by Administrator on 2019/4/20.
//

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
void inorder(treeNode *root);
void inorderByStack(treeNode *root);
treeNode *inorder(treeNode *root, int &k);
treeNode* KthNode(treeNode* pRoot, int k);

treeNode* KthNode_it(treeNode* pRoot, int k);
int main() {
    //测试
    treeNode *root = new treeNode(5);
    treeNode *node1 = new treeNode(3);
    treeNode *node2 = new treeNode(7);
    root->left = node1;
    root->right = node2;
    treeNode *node3 = new treeNode(2);
    treeNode *node4 = new treeNode(4);
    treeNode *node5 = new treeNode(6);
    treeNode *node6 = new treeNode(8);
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    int a = 4;
    treeNode * resu = KthNode(root,a);
    cout << resu->val << endl;
    system("pause");
    return 0;
}

treeNode* KthNode(treeNode* pRoot, int k)
{
    return inorder(pRoot, k);
}

//不使用递归
//注意只需要改动KthNode函数
treeNode* KthNode_it(treeNode* pRoot, int k) {
    if (pRoot == NULL)return NULL;
    treeNode *tmp = pRoot,*resu = NULL;
    stack<treeNode *> nodeStack;
    while (tmp != NULL || !nodeStack.empty()) {
        if (tmp != NULL) {
            nodeStack.push(tmp);
            tmp = tmp->left;
        }
        else {
            tmp = nodeStack.top();
            nodeStack.pop();
            k--;
            if (k == 0)
                return tmp;
            tmp = tmp->right;
        }
    }
    return NULL;
}

//中序遍历解面试题53
treeNode *inorder(treeNode *root, int &k) {
   if(root == nullptr)
       return nullptr;

   treeNode *resu = nullptr;

   resu = inorder(root->left, k);

    k--;
   if(k == 0){
       resu = root;
       return resu;
   }

   resu = inorder(root->right, k);

    return resu;
}