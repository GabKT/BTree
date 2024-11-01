#include <iostream>
#include <vector>
#include <algorithm>
#include "BTreeNode.cpp"

using namespace std;

class BTree
{
public:
    BTreeNode *root;
    int t;

    BTree(int _t) : t(_t)
    {
        root = nullptr;
    }

    void insert(int key)
    {
        if (!root)
        {
            root = new BTreeNode(t, true);
            root->keys.push_back(key);
        }
        else
        {
            if (root->keys.size() == (2 * t - 1))
            {
                BTreeNode *s = new BTreeNode(t, false);
                s->children.push_back(root);
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < key)
                {
                    i++;
                }
                s->children[i]->insertNonFull(key);
                root = s;
            }
            else
            {
                root->insertNonFull(key);
            }
        }
    };
};