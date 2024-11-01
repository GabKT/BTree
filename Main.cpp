#include <iostream>
#include <vector>
#include <algorithm>
#include "BTreeNode.cpp"
#include "BTree.cpp"

using namespace std;

// Método para imprimir a árvore B
void printTree(BTreeNode *node)
{
    if (node)
    {
        for (int i = 0; i < node->keys.size(); i++)
        {
            // Imprime filhos antes da chave
            if (!node->isLeaf)
            {
                printTree(node->children[i]);
            }
            std::cout << " " << node->keys[i]; // Imprime a chave
        }
        // Imprime o último filho
        if (!node->isLeaf)
        {
            printTree(node->children[node->keys.size()]);
        }
    }
}

int main()
{
    BTree t(3); // Cria uma árvore B de grau mínimo 3

    t.insert(10);
    t.insert(2);
    t.insert(4);
    t.insert(56);
    t.insert(9);
    t.insert(12);
    t.insert(3);
    t.insert(90);
    t.insert(13);
    t.insert(14);

    std::cout << "Árvore B em ordem: ";
    printTree(t.root);
    std::cout << std::endl;

    return 0;
}