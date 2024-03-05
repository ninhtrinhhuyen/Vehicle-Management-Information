#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include "Setting.h"

struct Node
{
    Setting *data;
    Node *left;
    Node *right;
};

class BinaryTreeSearch
{
public:
    BinaryTreeSearch()
    {
        root = nullptr;
    }
    ~BinaryTreeSearch()
    {
        empty(root);
    }

    Node *getRoot() const;

    // insert the node into the tree
    void insertByKey(Setting *data);
    // insert the node into the tree
    void insertByName(Setting *data);
    // inTraversal tree
    void traversal();
    // make an empty tree
    void empty();
    // search by person key
    Node *searchKey(const std::string &str);
    // search by name
    Node *searchName(const std::string &str);

private:
    Node *root;
    // insert the node into the tree
    void insertByKey(Node *&node, Setting *data);
    // insert the node into the tree
    void insertByName(Node *&node, Setting *data);
    // inTraversal tree
    void traversal(Node *tree);
    // empty tree
    void empty(Node *&tree);
    // search by person key
    Node *searchKey(Node *tree, const std::string &str);
    // search by name
    Node *searchName(Node *tree, const std::string &str);
};

#endif // TREE_H_