#include <iostream>
using namespace std;

typedef struct node {
    node* prev;
    int data;
    node* next;
}node;

node* generate() {
    node* ptr = new node;
    return ptr;
}

node* search(node* head, int data_to_search){
    node* el = head;
    while((*el).data != data_to_search || el->next == NULL){
        el = (*el).next;
    }
    return el;
}

void insert(node* head, node* tail){
    int data;
    cout << "Enter the data to insert : ";
    cin >> data;
    node* element = generate();
    if(tail != NULL)tail->next = element;
    else head = element;
    (*element).next = NULL;
    (*element).prev = tail;
    tail = element;
    (*element).data = data;
}

int remove(node* head, node* tail){
    int data_to_remove;
    cout << "Enter entry to remove : ";
    cin >> data_to_remove;
    node* el = search(head, data_to_remove);
    if(el == NULL){
        cout << "Element not present.\n";
        return 0;
    }
    (*(*el).prev).next = (*el).next;
    (*(*el).next).prev = (*el).prev;
    delete(el);
    cout << "Element deleted successfully.\n";
    return 0;
}

int main(){
    node* head = NULL;
    node* tail = head;
    cout << head;
    while (true) {
        cout << "1 -> insert()\n";
        cout << "2 -> remove()\n";
        cout << "3 -> search()\n";
        cout << "4 -> exit()\n";
        cout << "Select function to perform : ";
        int response;
        cin >> response;
        switch (response)
        {
        case 1:                                         //insert
            insert(head, tail);
            break;
        case 2:                                         //remove
            remove(head, tail);
            break;
        case 3:                                         //search
            int data_to_search;
            cout << "Enter element to search : ";
            cin >> data_to_search;
            if(search(head, data_to_search) == NULL) cout << data_to_search << " is not Present.\n";
            else cout << data_to_search <<" is present.\n";
            break;
        case 4:                                         //exit program
            return 0;
            break;        
        default:
            break;
        }
    }
    return 0;
}
