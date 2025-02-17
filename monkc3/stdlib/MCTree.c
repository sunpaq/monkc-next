#include "MCTree.h"
#include "MCArray.h"

struct BSTNode* BSTNodeCreate(mc_generic value) {
    struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    node->value = value;
    node->left  = null;
    node->right = null;
    return node;
}

static struct BSTNode* freenode(struct BSTNode* node) {
    if (node) {
        free(node);
        return null;
    }
    return node;
}

static struct BSTNode* printnode(struct BSTNode* node) {
    if (node) {
        printf("node.value=%.2f [left=%p right=%p]\n",
               node->value.f, node->left, node->right);
    }
    return node;
}

fun(insert, struct BSTNode*), struct BSTNode* root, mc_generic newval end_ as(MCBST)
    if (!root) {
        root = BSTNodeCreate(newval);
        it->count++;
    }
    if (MCGenericCompare(newval, root->value) < 0)
        root->left = insert(it, root->left, newval);
    if (MCGenericCompare(newval, root->value) > 0)
        root->right = insert(it, root->right, newval);
    return root;
end

fun(traverse, void), struct BSTNode* root, struct BSTNode* (*funcptr)(struct BSTNode* node) end_ as(MCBST)
    if (!root) return;
    if (root->left)
        traverse(it, root->left, funcptr);
    root = (*funcptr)(root);
    if (root->right)
        traverse(it, root->right, funcptr);
end

fun(insertValue, void), mc_generic newval end_ as(MCBST)
    it->root = insert(it, it->root, newval);
end

fun(traverseTree, void), struct BSTNode* (*funcptr)(struct BSTNode* node) end_ as(MCBST)
    traverse(it, it->root, funcptr);
end

fun(printTree, void) end_ as(MCBST)
    traverse(it, it->root, printnode);
    printf("total %ld nodes\n", it->count);
end

constructor(MCBST) end_ is
    MCObject(any, "MCBST");
    as(MCBST)
        it->root = null;
        it->count = 0;
    end
    dynamic(MCBST)
        funbind(insertValue);
        funbind(traverseTree);
        funbind(printTree);
    end
    return any;
end

/*
 Trie Tree (Digital, Radix, Prefix - Tree)
 */

fun(createNode, struct TrieNode*), char byte end_ is
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isLeaf = false;
    node->byte = byte;
    int i;
    for (i=0; i<MCTrieWidth; i++)
        node->childs[i] = null;
    return node;
end

fun(releaseNode, void), struct TrieNode* node end_ is
    if (node) {
        int i;
        for (i=0; i<MCTrieWidth; i++)
            if (node->childs[i])
                releaseNode(any, node->childs[i]);
        free(node);
    }
end

//return current node
fun(insertNodeIntoParent, struct TrieNode*), struct TrieNode* parent, struct TrieNode* node end_ is
    if (parent && node) {
        struct TrieNode* current = parent->childs[node->byte];
        if (current == null) {
            parent->childs[node->byte] = node;
            return node;
        } else {
            return current;
        }
    }
    return null;
end

//return Leaf node
fun(insertWordIntoParent, struct TrieNode*), struct TrieNode* parent, const char* word end_ as(MCTrie)
    if (parent && word) {
        size_t len = strlen(word);
        struct TrieNode *node=null, *p=parent;
        size_t i;
        for (i=0; i<len; i++) {
            char c = *word;
            node = createNode(it, c);
            //update parent
            p = insertNodeIntoParent(it, p, node);
            word++;
        }
        if (node) {
            //last node is leaf
            node->isLeaf = true;
        }
        return node;
    }
    return null;
end

fun(retrievalNodeByKey, struct TrieNode*), const char* word end_ as(MCTrie)
    size_t len = strlen(word);
    struct TrieNode *node=null, *p=it->root;
    size_t i;
    for (i=0; i<len; i++) {
        char c = *word;
        node = p->childs[c];
        if (node) {
            p = node;
            word++;
        }
    }
    return node;
end

//fun(keysWithPrefixFromIndex, struct MCArray*), const char* prefix, struct TrieNode* index) as(MCTrie)
//    struct MCArray* array = MCArray(alloc(MCArray), 10);
//    struct TrieNode* node = retrievalNodeByKey(it, prefix);
//    int i;
//    for (i=0; i<MCTrieWidth; i++) {
//        struct TrieNode* child = node->childs[i];
//        if (child->isLeaf) {
//
//        } else {
//
//        }
//    }
//
//    return array;
//}

fun(insertValueByKey, void), mc_generic newval, const char* word end_ as(MCTrie)
    struct TrieNode* leaf = insertWordIntoParent(it, it->root, word);
    leaf->value = newval;
end

fun(valueOfKey, mc_generic), const char* word end_ as(MCTrie)
    struct TrieNode* node = retrievalNodeByKey(it, word);
    //last leaf node have value
    if (node->isLeaf) {
        return node->value;
    }
    return gen_p(null);
end

fun(keysWithPrefix, struct MCArray*), const char* prefix end_ is
    struct MCArray* array = MCArray(alloc(MCArray), 10);
    return array;
end

fun(hasKey, bool), const char* word end_ as(MCTrie)
    struct TrieNode* node = retrievalNodeByKey(it, word);
    if (node && node->isLeaf) {
        return true;
    }
    return false;
end

fun(bye, void) end_ as(MCTrie)
    releaseNode(it, it->root);
end

constructor(MCTrie) end_ is
    MCObject(any, "MCTrie");
    as(MCTrie)
        it->root = createNode(it, ' ');
        it->count = 0;
    end
    dynamic(MCTrie)
        funbind(insertValueByKey);
        funbind(valueOfKey);
        funbind(keysWithPrefix);
        funbind(hasKey);
        funbind(bye);
    end
    return any;
end
