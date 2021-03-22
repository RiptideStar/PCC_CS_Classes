#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node *root = NULL;
    build(root);
    display(root);

    node *newRoot = NULL;
    cout << "Sum of nodes: " << sumOfNodes(root) << endl;
    cout << "copied leaves to a new root... new root:" << endl;
    copyLeaf(root, newRoot);
    display(newRoot);
    destroy(newRoot);

    display(root);
    destroy(root);
    return 0;
}
