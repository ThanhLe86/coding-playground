#include <iostream>
using namespace std;

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;

    Tree(int input, struct Tree* leftNode, struct Tree* rightNode) : data(input), left(leftNode), right(rightNode){}
};
typedef struct Tree* tree;

tree new_node(int input_data){
    tree newbrnch = new Tree(input_data, NULL, NULL);
    return newbrnch;
}

void print_data(tree temp){
    if(temp == NULL) return;
    tree temp2;
    cout<<temp->data<<"\n";
    temp2 = temp->left;
    print_data(temp2);
    temp2 = temp->right;
    print_data(temp2);
}

int main(int argc, char const *argv[])
{
    int data[] = {31, 45, 36, 14, 52, 42, 6, 21, 73, 47, 26, 37, 33, 8};
    tree root = new Tree(data[0], NULL, NULL);
    for(int iterator : data){
        
    }
    return 0;
}
