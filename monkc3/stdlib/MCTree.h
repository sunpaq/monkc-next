#ifndef MCTree_h
#define MCTree_h

/*
 pre-order:  root  -> LsubT -> RsubT
 in-order:   LsubT -> root  -> RsubT
 post-order: LsubT -> RsubT -> root
 
 BST: Binary Search Tree
 
 AVL:
 for all the nodes
 when balanceFactor = {-1 | 0 | 1}
 tree is balanced
 */

#include "MCObject.h"

struct BSTNode {
    struct BSTNode* left;
    struct BSTNode* right;
    int balanceFactor;
    mc_generic value;
};

structure(MCBST, MCObject)
    struct BSTNode* root;
    size_t count;

    fundef(insertValue, void), mc_generic newval end_;
    fundef(traverseTree, void), struct BSTNode* (*funcptr)(struct BSTNode* node) end_;
    fundef(printTree, void) end_;
end;

constructor(MCBST) end_;

/*
 Trie Tree (Digital, Radix, Prefix - Tree)
 */

//char in C is 1byte = 2^8 (256)
#define MCTrieWidth 256

struct TrieNode {
    struct TrieNode* childs[MCTrieWidth];
    mc_generic value;
    bool isLeaf;
    char byte;
};

structure(MCTrie, MCObject)
    struct TrieNode* root;
    size_t count;

    fundef(bye, void) end_;
    fundef(insertValueByKey, void), mc_generic newval, const char* word end_;
    fundef(valueOfKey, mc_generic), const char* word end_;
    fundef(keysWithPrefix, struct MCArray*), const char* prefix end_;
    fundef(hasKey, bool), const char* word end_;
end;

constructor(MCTrie) end_;

#endif /* MCTree_h */
