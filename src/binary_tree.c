#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <binary_tree.h>

void print_tree(leaf_t* tree)
{
    if (tree == NULL) {
        printf("\n");
        return;
    }

    printf("%s/", tree->label);
    print_tree(tree->left);

    if (tree->right != NULL) {
        printf("\t^%s/", tree->label);
        print_tree(tree->right);
    }
}

leaf_t* create_tree(char* label, char* content)
{
    leaf_t* root = malloc(sizeof(leaf_t));

    // copy initial contents
    // TODO: use strcpy instead of pass by reference
    if (root != NULL)
    {
        root->label = label;
        root->content = content;

        root->left = NULL;
        root->right = NULL;
    }

    return root;
}

leaf_t* add_leaf(leaf_t* parent, char* label, char* content)
{
    if (parent == NULL) {
        fprintf(stderr, "Error: failed to add leaf: %s", label);
        return NULL;
    }

    leaf_t* ptr = malloc(sizeof(leaf_t));

    ptr->label = label;
    ptr->content = content;
    ptr->left = NULL;
    ptr->right = NULL;

    if (parent->left != NULL) {
        parent = parent->left;

        while (parent->right != NULL) {
            parent = parent->right;
        }

        parent->right = ptr;
    } else {
        // parent has no siblings add this leaf as one
        parent->left = ptr;
    }

    return ptr;
}

leaf_t* search_leaf(leaf_t* tree, char* label)
{
    if (tree == NULL) {
        return NULL;
    }

    if (tree->label == label) {
        // found!
        return tree;
    }

    leaf_t* sibling = search_leaf(tree->left, label);
    leaf_t* child = search_leaf(tree->right, label);

    return sibling ? sibling : child;
}

void remove_leaf(leaf_t* tree, leaf_t* leaf)
{
    //check that leaf is removable
    if (leaf->right != NULL || tree == NULL || leaf == NULL) {
        return;
    }

    if (tree->left == leaf) {
        tree->left = leaf->left;
        free(leaf);
    }

    remove_leaf(tree->right, leaf);
    remove_leaf(tree->left, leaf);
}

void destroy_tree(leaf_t* tree)
{
    if (tree == NULL)
        return;

    destroy_tree(tree->left);
    destroy_tree(tree->right);

    free(tree);
}