#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // cout << "Start\n";
    SinglyLinkedListNode *t1 = (head1->data <= head2->data) ? head1 : head2;
    SinglyLinkedListNode *t2 = (head1->data > head2->data) ? head1 : head2;
    // cout << "t1 " << t1->data << " t2 " << t2->data;

    while(t1->next && t2) {
        if(((t1->data < t2->data) && (t1->next->data > t2->data)) || t1->data == t2->data) {
            SinglyLinkedListNode *node = new SinglyLinkedListNode(t2->data);
            node->next = t1->next;
            t1->next = node;
            t1 = t1->next;
            t2 = t2->next;
        } else {
            t1 = t1->next;
        }
    }

    if(t2) {
        // cout << "t2 is left\n";
        while(t2) {
            cout << t2->data << endl;
            SinglyLinkedListNode *node = new SinglyLinkedListNode(t2->data);
            t1->next = node;
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    return (head1->data <= head2->data) ? head1 : head2;
}

int main()