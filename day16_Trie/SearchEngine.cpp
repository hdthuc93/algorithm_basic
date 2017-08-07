////
//// Created by ThucHD on 7/15/17.
////
//
//#include "SearchEngine.h"
//
//priority_queue<pair<int, string>, vector<pair<int, string> >, less<pair<int, string> > > pq;
//string qStr;
//
//void SearchEngine() {
//    int n, q, w;
//    string str;
//    Node* root = newNode();
//    Node* pNode;
//    cin >> n >> q;
//    for(int i = 0; i < n; ++i) {
//        cin >> str >> w;
//        addWord(root, str, w);
//    }
//
//    for(int i = 0; i < q; ++i) {
//        cin >> str;
//        qStr = str;
//        pNode = getLastCh(root, str);
//
//        if(pNode == NULL)
//            cout << -1 << endl;
//        else
//            cout << pNode->w << endl;
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
//    n->w = 0;
//    n->countLeaf = 0;
//    return n;
//}
//
//void addWord(Node* root, string s, int w) {
//    Node* temp = root;
//    int ch;
//    for(int i = 0; i < s.size(); ++i) {
//        ch = s[i] - 'a';
//
//        if (temp->children[ch] == NULL) {
//            temp->children[ch] = newNode();
//        }
//
//        temp->w = max(temp->w, w);
//        temp = temp->children[ch];
//    }
//
//    temp->countLeaf++;
//}
//
//Node* getLastCh(Node* root, string s) {
//    Node* temp = root;
//    int ch;
//    for(int i = 0; i < s.size(); ++i) {
//        ch = s[i] - 'a';
//
//        if (temp->children[ch] == NULL) {
//            return NULL;
//        }
//
//        temp = temp->children[ch];
//    }
//
//    return temp;
//}
//
//void findAllWord(Node* root, string resWord) {
//    Node* temp = root;
//    if(temp->countLeaf > 0) {
//        pq.push(make_pair(temp->w, qStr + resWord));
//    }
//
//    for(int i = 0; i < MAX; ++i) {
//        if(temp->children[i] != NULL)
//            findAllWord(temp->children[i], resWord + (char)(i + 'a') );
//    }
//}
