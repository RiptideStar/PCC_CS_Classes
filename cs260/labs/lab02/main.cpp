#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "Index 3: ";
    printNth(head, 3);
    cout << "Index \"30\" (last number if list isn't long enough): ";
    printNth(head, 30); //bigger than size
    insertAtN(head, 30, 156); //156 at end of list
    insertAtN(head, 0, 156); //156 at beginning of list
    insertAtN(head, 2, 156); // 156 at index 2

    display(head);
    destroy(head);    
    return 0;
}
