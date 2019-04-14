//
// Created by Administrator on 2019/4/14.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;


struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
};

void printfromtobottom(BinaryTreeNode* proot){
    if(proot== nullptr)
        return;
    deque<BinaryTreeNode*> dequetreenode;

    dequetreenode.push_back(proot);

    while (!dequetreenode.empty()){
        BinaryTreeNode* pnode = dequetreenode.front();
        dequetreenode.pop_front();

        cout<<pnode->m_nValue<<" ";

        if(pnode->m_pLeft)
            dequetreenode.push_back(pnode->m_pLeft);
        if(pnode->m_pRight)
            dequetreenode.push_back(pnode->m_pRight);

    }
}

int main(){

}