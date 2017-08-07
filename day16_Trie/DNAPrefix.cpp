////
//// Created by ThucHD on 7/17/17.
////
//
//#include "DNAPrefix.h"
//
//map<char, int> mIndex;
//int res;
//
//void DNAPrefix() {
//    mIndex['A'] = 0;
//    mIndex['C'] = 1;
//    mIndex['G'] = 2;
//    mIndex['T'] = 3;
//
//
//    int t, n;
//    string str;
//    Node* root;
//    cin >> t;
//
//    for(int iTC = 1; iTC <= t; ++iTC) {
//        res = 0;
//        cin >> n;
//
//        root = newNode();
//        for(int i = 0; i < n; ++i) {
//            cin >> str;
//            addWord(root, str);
//        }
//        cout << "Case " << iTC << ": " << res << endl;
//        delNode(root);
//    }
//}
//
//Node* newNode() {
//    Node* n = new Node;
//
//    for(int i = 0; i < MAX; ++i) {
//        n->children[i] = NULL;
//    }
//
//    n->countMatch = 1;
//    n->countLeaf = 0;
//    return n;
//}
//
//void addWord(Node* root, string s) {
//    Node* temp = root;
//    int ch;
//    for(int i = 0; i < s.size(); ++i) {
//        ch = mIndex[s[i]];
//
//        if (temp->children[ch] == NULL) {
//            temp->children[ch] = newNode();
//        } else
//            temp->children[ch]->countMatch++;
//
//        temp = temp->children[ch];
//        res = max(res, temp->countMatch * (i + 1));
//    }
//
//    temp->countLeaf++;
//}
//
//void delNode(Node* root) {
//    for(int i = 0; i < MAX; ++i) {
//        if(root->children[i] != NULL)
//            delNode(root->children[i]);
//    }
//    delete(root);
//}