#include <stdio.h>
#include <binary_tree.h>

int main()
{
    // create tree
    leaf_t* root = NULL;
    root = create_tree("home", "www/index.html");

    print_tree(root);

    // add some complexity
    add_leaf(root, "child1", "this is child 1");
    add_leaf(root, "child2", "this is a sibling of child 1");
    add_leaf(root->left, "child3", "this is a child of child1");

    print_tree(root);

    // find a child
    leaf_t* child2 = search_leaf(root, "child2");

    //remove a leaf
    remove_leaf(root, child2);

    print_tree(root);

    destroy_tree(root);

    return 0;
}