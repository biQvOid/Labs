#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Tree
{
    int data;
    struct Tree* son;
    struct Tree* brother;
    struct Tree* parent;
};

typedef struct Tree Tree;

Tree* create_tree(int value)
{
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->parent = NULL;
    root->brother = NULL;
    root->son = NULL;
    root->data = value;
    return root;
}

Tree* find_node(Tree* tree, int value)
{
    if (tree == NULL) {
        return NULL;
    }
    if (tree->data == value) {
        return tree;
    }
    Tree* finder = NULL;
    if (tree->son) {
        finder = find_node(tree->son, value);
        if (finder != NULL) {
           return finder;
        }
    }
    if (tree->brother) {
        finder = find_node(tree->brother, value);
        if (finder != NULL) {
            return finder;
        }
    }
}

void add_node(Tree* tree, int node, int value)
{
    Tree* top = find_node(tree, node);
    Tree* father = top;
    if (top->son == NULL) {
        top->son = create_tree(value);
        top->son->parent = top;
        return;
    }
    top = top->son;
    while (top->brother != NULL) {
        top = top->brother;
    }
    top->brother = create_tree(value);
    top->brother->parent = father;
}

void to_delete_undertree(Tree* parent)
{
    if (parent == NULL) {
        return;
    } else {
        if (parent->son) {
            parent = parent->son;
        } else {
            return;
        }
        if (parent->son) {
            to_delete_undertree(parent->son);
        }
        Tree* next = parent;
        Tree* prev = NULL;
        while (next->brother) {
            prev = next;
            next = next->brother;
            if (next->son) {
                to_delete_undertree(next->son);
            }
            free(prev);
        }
        free(next);
    }
}

void to_delete_node(Tree* tree, int value)
{
    if (tree != NULL) {
        if (tree->son != NULL) {
            if (tree->son->data == value) {
                Tree* prev = tree->son;
                tree->son = tree->son->brother;
                free(prev);
                prev = NULL;
            } else {
                to_delete_node(tree->son, value);
            }
        }
        if (tree->brother != NULL) {
            if (tree->brother->data == value) {
                Tree* prev = tree->brother;
                tree->brother = tree->brother->brother;
                free(prev);
                prev = NULL;
            } else {
                to_delete_node(tree->brother, value);
            }
        }
    }
}

void tree_destroy(Tree* root)
{
    if (root->son) {
        tree_destroy(root->son);
    }
    if (root->brother) {
        tree_destroy(root->brother);
    }
    free(root);
    root = NULL;
}

void delete_node(Tree* tree, int value) 
{
    Tree* finder = find_node(tree, value);
    to_delete_undertree(finder);
    to_delete_node(tree, value);
}

int depth(Tree* root, int* h, int k)
{
    if (root != NULL) {
        if (k > *h) {
            *h = k;
        }
        depth(root->son, h, k + 1);
        depth(root->brother, h, k);
    }
    return *h;
}

void find_max_deep_nonterminal_node(Tree* node, int* h, int k, int tree_deep)
{
    if (node != NULL) {
        if (k > *h) {
            *h = k;
            if (node->parent != NULL && *h == tree_deep) {
                printf("%d",node->parent->data);
                printf("\n");
            }
        }
    }
    if (node->brother != NULL) { 
        find_max_deep_nonterminal_node(node->brother, h, k, tree_deep);
    }
    if (node->son != NULL) {
        find_max_deep_nonterminal_node(node->son, h, k + 1, tree_deep);
    }
}

void max_deep_nonterminal_node(Tree* tree)
{
    int g = 0;
    int p = 0;
    int DEEP = depth(tree, &g, 0);
    find_max_deep_nonterminal_node(tree, &p, 0, DEEP);
}

void print_the_tree(Tree* root, int count)
{
    if (root != NULL) {
        for (int i = 0; i < count; i++) {
            printf(" ");
        }
        printf("%d", root->data);
        printf("\n");
    }
    if (root->son != NULL) {
        print_the_tree(root->son, count + 2);
    }
    if (root->brother != NULL) {
        print_the_tree(root->brother, count);
    }
}

void tree_print(Tree* root)
{
    if (root != NULL) {
        print_the_tree(root, 0);
    } else {
        printf("The tree not exists\n");
    }
}

int main()
{
    printf("Набор команд:\n");
    printf("c - создать дерево(необходимо ввести значение узла)\n");
    printf("a - добавить узел в дерево(необходимо ввести значение родительского и нового узла)\n");
    printf("d - удалить узел из дерева(необходимо ввести значение узла)\n");
    printf("p - графическое представление дерева\n");
    printf("f - вывести значение максимального по глубине нетерминального узла\n");
    printf("b - удалить дерево\n");
    char c;
    int value;
    int k = 0;
    int first, second;
    Tree* v;
    while ((c = getchar()) != EOF) {
        if (c == 'c' && k == 0) {
            k++;
            scanf("%d", &value);
            v = create_tree(value);
        } else if (c == 'c' && k != 0) {
            printf("The tree already exists\n");
        } else if (c == 'a' && k != 0) {
            scanf("%d%d", &first, &second);
            Tree* first_finder = find_node(v, first);
            Tree* second_finder = find_node(v, second);
            if (first_finder != NULL && second_finder == NULL) {
                add_node(v, first, second);
            } else if (first_finder == NULL) {
                printf("Such node not exists\n");
            } else if (second_finder != NULL) {
                printf("Such node already exists\n");
            }
        } else if (c == 'a' && k == 0) {
            printf("The tree not exists\n");
        } else if (c == 'd' && k != 0) {
            scanf("%d", &value);
            Tree* finder = find_node(v, value);
            if (finder != NULL) {
                if (finder->brother == NULL) {
                    tree_destroy(v);
                    v = NULL;
                    k--;
                } else {
                    delete_node(v, value);
                }
            } else {
                printf("Such node not exists\n");
            }
        } else if (c == 'd' && k == 0) {
            printf("The tree not exists\n");
        } else if (c == 'p' && k != 0) {
            tree_print(v);
        } else if (c == 'p' && k == 0) {
            printf("The tree not exists\n");
        } else if (c == 'f' && k != 0) {
            max_deep_nonterminal_node(v);
        } else if (c == 'f' && k == 0) {
            printf("The tree not exists\n");
        } else if (c == 'b' && k != 0) {
            tree_destroy(v);
            v = NULL;
            k--;
        } else if (c == 'b' && k == 0) {
            printf("The tree not exists\n");
        }
    }
    return 0;
}
