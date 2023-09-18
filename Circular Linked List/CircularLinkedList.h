# ifndef CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H
# define CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

template <class t>
class CircularLinkedList {
private:
    struct node {
        t info;
        node *next;
    };
    node *head;
    node *last;
    int length;
public:
    CircularLinkedList() {
        head = last = nullptr;
        length = 0;
    }
    void insertAtHead(t item){

        node *new_node = new node;
        new_node->info = item;

        if (length == 0) {
            head = last = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        last->next = head;
        length++;
    }
    void insertAtTail(t item)
    {
        node *new_node = new node;
        new_node->info = item;
        if(length ==0)
        {
            head = last = new_node;
            new_node->next = head;
        }
        else
        {
            last ->next = new_node;
            new_node->next = head;
            last = new_node;
        }
        length++;
    }
    void insertAt(t item, int position)
    {
        node* new_node = new node;
        if(position <0 || position >length)
        {
            cerr<<"bad alloc"<<endl;
        }
        else
        {
            if(position == 0){
                insertAtHead(item);
            }
            else if(position == length)
            {
                insertAtTail(item);
            }
            else
            {
                node * current = head;
                for (int i = 0; i < position-1; ++i){
                    current = current->next;
                }
                new_node->info = item;
                new_node->next = current->next;
                current->next = new_node;
                length++;
            }
        }
    }

    void removeAtHead()
    {
        if(isEmpty())
        {
            cerr<<"is_empty"<<endl;
            return;
        }
        else
        {
            node* newnode = head;
            head = head->next;
            last->next = head;
            delete newnode;
        }
        length--;

    }
    void removeAtTail()
    {
        if(isEmpty())
        {
            cerr<<"is_empty"<<endl;
            return;
        }
        else if(head == last)
        {
            delete head;
            head = nullptr;
            last = nullptr;
        }
        else
        {
            node * current = head;
            while(current->next != last){
                current = current->next;
            }
            delete last ;
            last = current ;
            last->next = head;
        }
        length--;
    }
    void removeAt(int position)
    {
        if(position <0 || position >length)
        {
            cerr<<"bad alloc"<<endl;
            return;
        }
        else if(position == 0)
        {
            removeAtHead();
            return;
        }
        else if(position == length-1)
        {
            removeAtTail();
            return;
        }
        else
        {
            node * current = head;
            node * p;
            for (int i = 0; i < position-1; ++i){
                current = current->next;
            }
            p = current->next;
            current->next = current->next->next;
            delete [] p;
            length--;
        }
    }
    t retrieveAt(int position)
    {
        t ele;
        node * current = head;
        if(position <0 || position >=length)
        {
            cerr<<"bad alloc"<<endl;
        }
        else
        {
            for (int i = 0; i < position; ++i) {
                current = current->next;
            }
            ele = current->info;
        }
        return ele;
    }
    void replaceAt(t newData, int position)
    {
        node * current = head;
        if(position <0 || position >length)
        {
            cerr<<"bad alloc"<<endl;
        }
        else
        {
            for (int i = 0; i < position; ++i) {
                current = current->next;
            }
            current->info = newData;
        }

    }

    bool isExist(t item)
    {
        node * current = head;
        for (int i = 0; i < length; ++i) {
            if(current->info == item)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool isItemAtEqual(t element, int position)
    {
        node * current = head;
        if(position <0 || position >length)
        {
            cerr<<"bad alloc"<<endl;
        }
        else
        {
            for (int i = 0; i < position; ++i) {
                current = current->next;
            }
            if(current->info == element)
                return true;
            else
                return false;
        }

    }
    node* getNode(int idx)
    {
        node* curr = head;
        if(idx<0 || idx>=this->length)
        {
            curr = nullptr;
        }
        else {
            for (int i = 0; i < idx; ++i) {
                curr = curr->next;
            }
        }
        return curr;
    }

    void swap(int x, int y)
    {
        if(x<0 || x>=this->length || y<0 || y>=this->length)
        {
            cerr<<"bad alloc"<<endl;
            return;
        }

        if(x == y)
        {
            cerr<<"i cannot swap they are the same node"<<endl;
            return;
        }

        node * currX = getNode(x);
        node * prevX = getNode(x-1);
        node * currY = getNode(y);
        node * prevY = getNode(y-1);
        if(prevX == nullptr)
            head = currY;
        else
            prevX->next = currY;

        if(prevY == nullptr)
            head = currX;
        else
            prevY->next = currX;

        node* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;


        if(currX == last)
        {
            last = currY;

        }
        else if(currY == last)
        {
            last = currX;
        }
        last->next = head;
    }

    bool isEmpty()
    {
        return length == 0;

    }
    int CircularLinkedListSize()
    {
        return length;
    }
    void clear()
    {
        node * current;
        while(head != last)
        {
            current = head;
            head = head ->next;
            delete current;
        }
        last = nullptr;
        length = 0;

    }
    void print()
    {
        node *loop = head;
        for (int i = 0; i < length; ++i) {
            cout<<loop->info<<" ";
            loop = loop ->next;
        }
        cout<<endl;
    }


};
# endif //CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H