////
//// Created by ThucHD on 7/15/17.
////
//
//#include "ConsistencyChecker.h"
//
//void ConsistencyCheck() {
//    int t, n;
//    string str;
//    vector<string> vStr;
//    Node* pNode;
//    string res;
//    cin >> t;
//
//    for(int i = 1; i <= t; ++i) {
//        cin >> n;
//        Node* root = newNode();
//        vStr.clear();
//        res = "YES";
//
//        for(int j = 0; j < n; ++j) {
//            cin >> str;
//            vStr.push_back(str);
//            addWord(root, str);
//        }
//
//        for(int j = 0; j < n; ++j) {
//            pNode = lastCh(root, vStr[j]);
//            if(!isEmpty(pNode)) {
//                res = "NO";
//                del(pNode);
//                break;
//            }
//            del(pNode);
//        }
//
//        cout << "Case " << i << ": " << res << endl;
//        del(root);
//    }
//}
//
//
//Node* newNode() {
//    Node* n = new Node;
//    n->countLeaf = 0;
//    for(int i = 0; i < MAX; ++i) {
//        n->children[i] = NULL;
//    }
//
//    return n;
//}
//
//void addWord(Node* root, string s) {
//    int ch;
//    Node* temp = root;
//    for(int i = 0; i < s.size(); ++i) {
//        ch = s[i] - '0';
//        if(temp->children[ch] == NULL) {
//            temp->children[ch] = newNode();
//        }
//        temp = temp->children[ch];
//    }
//    temp->countLeaf++;
//}
//
//Node* lastCh(Node* root, string s) {
//    int ch;
//    Node* temp = root;
//    for(int i = 0; i < s.size(); ++i) {
//        ch = s[i] - '0';
//        if(temp->children[ch] == NULL) {
//            return newNode();
//        }
//        temp = temp->children[ch];
//    }
//    return temp;
//}
//
//bool isEmpty(Node* root) {
//    for(int i = 0; i < MAX; ++i) {
//        if(root->children[i] != NULL) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void del(Node *cur) {
//    for(int i = 0; i < 10; i++) {
//        if (cur->children[i] != NULL) {
//            del(cur->children[i]);
//            cur->children[i] = NULL;
//        }
//    }
//    delete cur;
//}