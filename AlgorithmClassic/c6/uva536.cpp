#include <iostream>
#include <string>

using namespace std;
string preOrder;
string inOrder;

void makeTree(int preOrderLower, int preOrderUpper,
              int inOrderLower, int inOrderUpper) {
    char head = preOrder[preOrderLower];
    int inOrderHeadIndex = inOrder.find(head);
    int leftTreeSize = inOrderHeadIndex - inOrderLower;

    int newPreLower1 = preOrderLower + 1;
    int newPreUpper1 = preOrderLower + leftTreeSize;
    int newPreLower2 = preOrderLower + leftTreeSize + 1;
    int newPreUpper2 = preOrderUpper;

    int newInLower1 = inOrderLower;
    int newInUpper1 = inOrderHeadIndex - 1;
    int newInLower2 = inOrderHeadIndex + 1;
    int newInUpper2 = inOrderUpper;

    if (newPreLower1 <= newPreUpper1)
        makeTree(newPreLower1, newPreUpper1, newInLower1, newInUpper1);
    if (newPreLower2 <= newPreUpper2)
        makeTree(newPreLower2, newPreUpper2, newInLower2, newInUpper2);
    cout << head;
}

int main() {
    //freopen("read.in", "r", stdin);
    while (cin >> preOrder) {
        cin >> inOrder;
        makeTree(0, preOrder.size() - 1, 0, inOrder.size() - 1);
        cout << endl;
    }

    return 0;
}