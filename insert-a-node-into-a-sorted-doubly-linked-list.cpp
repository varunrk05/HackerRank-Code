#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    cout << "Start\n";
    DoublyLinkedListNode *t = head, *tt;
    DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
    if(!t) {
        t = node;
    } else if(!t->next) {
        t->next = node;
        node->prev = t;
    } else {
        int f = 0;
        while(t) {
            // if(t->data == node->data) {
            //     node->next = t->next;
            //     node->prev = t;
            //     t->next->prev = node;
            //     t->next = node;
            //     break;
            // } else if(t->next == nullptr) {
            //     t->next = node;
            //     node->prev = t;
            //     break;
            // } else if(t->data > node->data) {
            //     node->next = t;
            //     t->prev = node;
            //     head = node;
            //     break;
            // } else if(t->data < node->data && t->next->data > node->data) {
            //     node->next = t->next;
            //     node->prev = t;
            //     t->next->prev = node;
            //     t->next = node;
            //     break;
            // }  else {
            //     t = t->next;
            // }
            if(node->data < t->data) {
                node->next = t;
                t->prev = node;
                head = node;
                break;
            } else if(t->next == nullptr) {
                t->next = node;
                node->prev = t;
                break;
            } else if(t->data <= node->data && node->data <= t->next->data) {
                node->next = t->next;
                node->prev = t;
                t->next->prev = node;
                t->next = node;
                break;
            } else {
                t = t->next;
            }
        }
    }

    return head;
}

int main()