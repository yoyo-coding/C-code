#include <iostream>
#include <string>
using namespace std;

void postOrder(string inOrder, string preOrder, int inStart, int inEnd, int preStart, int preEnd) {
    if (inStart > inEnd || preStart > preEnd) {
        return;
    }
    
    // 前序遍历的第一个字符是当前子树的根节点
    char root = preOrder[preStart];
    
    // 在中序遍历中找到根节点的位置
    int rootIndex = inStart;
    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == root) {
            rootIndex = i;
            break;
        }
    }
    
    // 计算左子树的大小
    int leftSubtreeSize = rootIndex - inStart;
    
    // 递归处理左子树
    postOrder(inOrder, preOrder, inStart, rootIndex - 1, preStart + 1, preStart + leftSubtreeSize);
    
    // 递归处理右子树
    postOrder(inOrder, preOrder, rootIndex + 1, inEnd, preStart + leftSubtreeSize + 1, preEnd);
    
    // 输出根节点（后序遍历）
    cout << root;
}

int main() {
    string inOrder, preOrder;
    cin >> inOrder >> preOrder;
    
    int n = inOrder.length();
    postOrder(inOrder, preOrder, 0, n - 1, 0, n - 1);
    
    return 0;
}