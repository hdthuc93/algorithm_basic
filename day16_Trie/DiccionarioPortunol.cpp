//
// Created by ThucHD on 7/17/17.
//

#include "DiccionarioPortunol.h"
long long res;
int suffixCount;
int ch[MAX];

void DiccionarioPortunol() {
    int P, S;
    string str;
    Node* prefixTree;
    Node* suffixTree;

    while(cin >> P >> S) {
        if(P == 0 && S == 0)
            break;

        prefixTree = newNode();
        suffixTree = newNode();
        suffixCount = -1;
        res = 0;
        memset(ch, 0, sizeof(ch));

        for(int i = 0; i < P; ++i) {
            cin >> str;
            addWord(prefixTree, str);
        }

        for(int i = 0; i < S; ++i) {
            cin >> str;
            reverse(str.begin(), str.end());
            addWord(suffixTree, str);
        }

        suffixProcessing(suffixTree, 0);
        prefixProcessing(prefixTree, 0);
        cout << res << endl;
        delNode(prefixTree);
        delNode(suffixTree);
    }
}

Node* newNode() {
    Node* n = new Node;

    for(int i = 0; i < MAX; ++i) {
        n->children[i] = NULL;
    }

    n->countLeaf = 0;
    return n;
}

void addWord(Node* root, string s) {
    Node* temp = root;
    int ch;

    for(int i = 0; i < s.size(); ++i) {
        ch = s[i] - 'a';

        if (temp->children[ch] == NULL) {
            temp->children[ch] = newNode();
        }

        temp = temp->children[ch];
    }
    temp->countLeaf++;
}

void suffixProcessing(Node* root, int level) {
    ++suffixCount;

    for(int i = 0; i < MAX; ++i) {
        if(root->children[i] != NULL) {
            if(level > 0)
                ++ch[i];

            suffixProcessing(root->children[i], level + 1);
        }
    }
}

void prefixProcessing(Node* root, int level) {
    if(level > 0)
        res += suffixCount;

    for(int i = 0; i < MAX; ++i) {
        if(root->children[i] != NULL) {
            if(level > 0) res -= ch[i];
            prefixProcessing(root->children[i], level + 1);
        }
    }
}

void delNode(Node* root) {
    for(int i = 0; i < MAX; ++i) {
        if(root->children[i] != NULL)
            delNode(root->children[i]);
    }
    delete(root);
}