#include <iostream>
using namespace std;
class node
    {
        public:
        int data;
        node* next;
    };
class SingleLinkedList
{
private:

    node* head;

public:
    SingleLinkedList()
    {
        head = NULL;
    }

    bool IsEmpty()
    {
        return head == NULL;
    }

    void show()
    {
        node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    bool search(int item)
    {
        node* temp = head;

        while (temp != NULL)
        {
            if (temp->data == item)
                return true;

            temp = temp->next;
        }

        return false;
    }

    int count()
    {
        int counter = 0;
        node* temp = head;

        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    void Insert_add_first(int val)
    {
        node* new_node = new node();

        new_node->data = val;
        new_node->next = head;
        head = new_node;
    }

    void add_anyposition(int item, int val)
    {
        if (IsEmpty())
        {
            Insert_add_first(val);
        }
        else
        {
            node* temp = head;

            while (temp != NULL && temp->data != item)
            {
                temp = temp->next;
            }

            if (temp == NULL)
            {
                cout << "Item not found\n";
                return;
            }

            node* new_node = new node();
            new_node->data = val;

            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void add_last(int val)
    {
        if (IsEmpty())
        {
            Insert_add_first(val);
        }
        else
        {
            node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            node* new_node = new node();
            new_node->data = val;
            new_node->next = NULL;

            temp->next = new_node;
        }
    }
};

int main()
{
    SingleLinkedList list;

    list.Insert_add_first(10);
    list.Insert_add_first(5);
    list.add_last(20);
    list.add_anyposition(10, 15);

    cout << "List items:\n";
    list.show();

    cout << "\nNumber of items: " << list.count() << endl;

    int item;
    cout << "\nEnter item to search: ";
    cin >> item;

    if (list.search(item))
        cout << "Item found\n";
    else
        cout << "Item not found\n";

    return 0;
}