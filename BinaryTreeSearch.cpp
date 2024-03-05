#include "BinaryTreeSearch.h"

// search by name
Node *BinaryTreeSearch::searchName(const std::string &str)
{
    return searchName(root, str);
}

// search by name
Node *BinaryTreeSearch::searchName(Node *tree, const std::string &str)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (tree->data->getCarName().compare(str) > 0)
            searchName(tree->left, str);
        else if (tree->data->getCarName().compare(str) < 0)
            searchName(tree->right, str);
        else
            return tree;
    }
    return nullptr;
}

// search by person key
Node *BinaryTreeSearch::searchKey(const std::string &str)
{
    return searchKey(root, str);
}

// search by person key
Node *BinaryTreeSearch::searchKey(Node *tree, const std::string &str)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (tree->data->getPersonKey().compare(str) > 0)
            searchKey(tree->left, str);
        else if (tree->data->getPersonKey().compare(str) < 0)
            searchKey(tree->right, str);
        else
            return tree;
    }
    return nullptr;
}

// inTraversal tree
void BinaryTreeSearch::traversal()
{
    traversal(root);
}

// inTraversal tree
void BinaryTreeSearch::traversal(Node *tree)
{
    if (tree == nullptr)
    {
        return;
    }
    traversal(tree->left);
    tree->data->Setting::printInfo();
    tree->data->printInfo();
    std::cout << '\n';
    traversal(tree->right);
}

// insert the node into the tree
void BinaryTreeSearch::insertByKey(Setting *data)
{
    insertByKey(root, data);
}

// insert the node into the tree
void BinaryTreeSearch::insertByKey(Node *&node, Setting *data)
{
    if (node == nullptr)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        node = newNode;
    }
    else
    {
        if (*(node->data) < *data)
        {
            insertByKey(node->right, data);
        }
        else if (*(node->data) > *data)
        {
            insertByKey(node->left, data);
        }
        else
        {
            std::cout << "Person key already exist!!!\n";
        }
    }
}

// insert the node into the tree
void BinaryTreeSearch::insertByName(Setting *data)
{
    insertByName(root, data);
}

// insert the node into the tree
void BinaryTreeSearch::insertByName(Node *&node, Setting *data)
{
    if (node == nullptr)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        node = newNode;
    }
    else
    {
        if (node->data->getCarName().compare(data->getCarName()) <= 0)
        {
            insertByName(node->right, data);
        }
        else
        {
            insertByName(node->left, data);
        }
    }
}

// empty tree
void BinaryTreeSearch::empty()
{
    empty(root);
}

// make an empty tree
void BinaryTreeSearch::empty(Node *&tree)
{
    if (tree == nullptr)
        return;
    empty(tree->left);
    empty(tree->right);
    delete tree;
}

Node *BinaryTreeSearch::getRoot() const
{
    return root;
}