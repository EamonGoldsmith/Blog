// basic definition for a leaf on the tree
typedef struct leaf {
    char* label;
    char* content;

    struct leaf *left;
    struct leaf *right;
} leaf_t;

// print the tree
void print_tree(leaf_t* root);

// create a tree
leaf_t* create_tree(char* label, char* content);

// add a leaf to the tree
leaf_t* add_leaf(leaf_t* parent, char* label, char* content);

// search for a leaf using a path
leaf_t* search_leaf(leaf_t* tree, char* label);

// remove a leaf
int remove_leaf(leaf_t* leaf);

// destroy the tree
void destroy_tree(leaf_t* root);