#include "tree.h"
#include "transform.h"
#include <math.h>

int is_task(Tree *t)
{
    return ((*t) != NULL) && ((*t)->node.type == OPERATOR) && ((*t)->node.data.operator_name == '^') && 
    (((*t)->left->node.type == INTEGER) || ((*t)->left->node.type == VARIABLE) ) &&
    ((*t)->right->node.type == OPERATOR) && ((*t)->right->node.data.operator_name == '+');
}

void transform_task(Tree *t)
{
    Tree tmp = (Tree) malloc(sizeof(struct tree_node));
    tmp->node.type = OPERATOR;
    tmp->node.data.operator_name = '*';
    tmp->left = (Tree) malloc(sizeof(struct tree_node));
    tmp->right = (Tree) malloc(sizeof(struct tree_node));
    tmp->left->node.type = OPERATOR;
    tmp->right->node.type = OPERATOR;
    tmp->left->node.data.operator_name = '^';
    tmp->right->node.data.operator_name = '^';
    tmp->left->left = (Tree) malloc(sizeof(struct tree_node));
    tmp->left->right = (Tree) malloc(sizeof(struct tree_node));
    tmp->left->left->node.type = (*t)->left->node.type;
    tmp->left->left = (*t)->left;
    tmp->left->right->node.type = (*t)->right->left->node.type;
    tmp->left->right = (*t)->right->left;
    tmp->right->left = (Tree) malloc(sizeof(struct tree_node));
    tmp->right->right = (Tree) malloc(sizeof(struct tree_node));
    tmp->right->left->node.type = (*t)->left->node.type;
    tmp->right->left = (*t)->left;
    tmp->right->right->node.type = (*t)->right->right->node.type;
    tmp->right->right = (*t)->right->right;
    *t = tmp;
}

void transformation(Tree *t)
{
    if ((*t) != NULL) {
        transformation(&((*t)->left));
        transformation(&((*t)->right));
        if (is_task(t)) {
            transform_task(t);
        }
    }
}
