#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BTreeNode
{
public:
    vector<int> keys;
    vector<BTreeNode *> children;
    bool isLeaf;
    int t;

    BTreeNode(int _t, bool _isLeaf) : t(_t), isLeaf(_isLeaf) {}

    void inserNonFull(int key)
    {
        int i = keys.size() - 1;

        if (isLeaf)
        {
            keys.push_back(0);
            while (i >= 0 && keys[i] > key)
            {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
        }
        else
        {
            while (i >= 0 && keys[i] > key)
            {
                i--;
            }
            i++;
            if (children[i]->keys.size() == (2 * t - 1))
            {
                splitChild(i, children[i]);
                if (keys[i] < key)
                {
                    i++;
                }
            }
            children[i]->inserNonFull(key);
        }
    };
    void splitChild(int i, BTreeNode *y)
    {
        BTreeNode *z = new BTreeNode(y->t, y->isLeaf);

        for (int j = 0; j < t; j++)
        {
            z->keys.push_back(y->keys[j + t]);
        }

        if (!y->isLeaf)
        {
            for (int j = 0; j < t; j++)
            {
                z->children.push_back(y->children[j + t]);
            }
        }

        y->keys.resize(t - 1);

        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    };
}