#include "DiccionarioPortunol.h"
#include <math.h>
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    DiccionarioPortunol();
    return 0;
}

bool removeWord(Node* root, string s, int level, int len) {
    if(!root) 
        return false;

    int ch = s[level] - 'a';
    if(level == len) {
        if(root->countLeaf > 0) {
            root->countLeaf--;
            return true;
        }
        return false;
    }

    int flag = removeWord(root->children[ch], s, level + 1, len);
    if(flag && !leafNode(root->children[ch]) && isEmpty(root->children[ch])) {
        delete root->children[ch];
        root->children[ch] = NULL;
    }
    return flag;
}

bool isEmpty(Node* pNode) {
    for(int i = 0; i < MAX; ++i) {
        if(pNode->children[i] != NULL) {
            return false;
        }
    }
    return true;
}

bool leafNode(Node* pNode) {
    return (root->countLeaf != 0);
}