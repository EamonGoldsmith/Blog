#include <stdio.h>
#include <binary_tree.h>

int main()
{
    // create tree
    leaf_t* root = NULL;
    root = create_tree("home", "www/index.html");
    
    if (root == NULL) {
        fprintf(stderr, "binary_tree: tree creation failed");
        return 1;
    }

    // show tree thusfar
    print_tree(root);

    // add some complexity
    add_leaf(root, "child1", "this is child 1");
    add_leaf(root, "child2", "this is a sibling of child 1");
    add_leaf(root->left, "child3", "this is a child of child1");

    // show new tree
    print_tree(root);

    // find a child
    leaf_t* child2 = search_leaf(root, "child2");
    printf("%s: %s\n", child2->label, child2->content);

    destroy_tree(root);

    return 0;
}