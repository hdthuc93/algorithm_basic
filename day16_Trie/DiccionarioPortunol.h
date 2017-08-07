//
// Created by ThucHD on 7/17/17.
//

#ifndef DAY16_TRIE_DICCIONARIOPORTUNOL_H
#define DAY16_TRIE_DICCIONARIOPORTUNOL_H
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define MAX 26

struct Node {
    Node* children[MAX];
    int countLeaf;
};

// Diccionario Portunol: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3803
void DiccionarioPortunol();
Node* newNode();
void addWord(Node* root, string s);
void prefixProcessing(Node* root, int level);
void suffixProcessing(Node* root, int level);
void delNode(Node* root);

#endif //DAY16_TRIE_DICCIONARIOPORTUNOL_H
