#include <stdio.h>
#include <malloc.h>

typedef struct Heap {
    int v;
    struct Heap *l; // filho da esquerda
    struct Heap *r; // filho da direita
    struct Heap *p; // pai
}node;

typedef struct List {
    struct LinkedList *prox; // proximo elemento
    node* e; // elemento
}LinkedList;

node* createNode(int x, node *p) {
    node* nn = malloc(sizeof(node));
    nn->v = x;
    nn->l = NULL;
    nn->r = NULL;
    nn->p = p;
    return nn;
}

LinkedList* createList(node *e) {
    LinkedList *l = malloc(sizeof(LinkedList));
    l->prox = NULL;
    l->e = e;
    return l;
}

void freeList(LinkedList **l) {
    LinkedList *list = *l;
    while(list != NULL) {
        *l = list->prox;
        free(list);
        list = *l;
    }
}

void insertOnList(node *n, LinkedList **last) {
    if (n->l != NULL) {
        (*last)->prox = createList(n->l);
        (*last) = (*last)->next;
    }
    if (n->r != NULL) {
        (*last)->prox = createList(n->r);
        (*last) = (*last)->prox;
    }
}

void minHeapify(struct Heap *node) {

}

void heap_insert(node **r, int x) {
    //insert new node if the heap is empty
    if(*r == NULL) {
        *r = get_a_node(x, NULL);
    }
    //serach for a proper insert point
    else {
        LinkedList* q = createList(*r);
        LinkedList* = q;
        LinkedList* last_q = q;
        node* current_node;
 
        while(current_q != NULL) {
            //get one node out of queue
            current_node = current_q->element;
 
                if(current_node->left == NULL) {
                    current_node->left = get_a_node(x, current_node);
                    current_node = current_node->left;
                }
                else if(current_node->right == NULL) {
                    current_node->right = get_a_node(x, current_node);
                    current_node = current_node->right;
                }
                else {
                    queue_put(current_node, &last_q);
                    //increment the current pointer
                    current_q = current_q->next;
                    continue;
                }
 
                //put the node to proper point
                while(current_node->parent != NULL && current_node->parent->val < current_node->val) {
                    //swap the value
                    int temp = current_node->parent->val;
                    current_node->parent->val = current_node->val;
                    current_node->val = temp;
                    current_node = current_node->parent;
                }
                break;
 
        }
 
        free_queue(&q);
    }
    return;
}

void initHeap() {
    struct Heap *node = malloc(sizeof(struct Heap));
    node->v = 0;
    node->heap_size = 0;
    node->l = NULL;
    node->r = NULL;
    node->p = NULL;
}

void main() {
    node *r = NULL;

}