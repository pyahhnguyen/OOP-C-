
   
#include <iostream>
#include <ntsid.h>


using namespace std;

struct Node {
    string text;
    Node * next;
};

uint hashfunc(string txt) {
    unsigned int sum = 0;
    for(int i = 0; i < txt.size(); i++) {
        sum += txt[i]<<(i%4)*8;
    }
    return sum;


void add_to_hashtable(Node** hashtable, int n, string &txt) {
    
    int hash = hashfunc(txt)%n;

    Node * tmp = new Node;
    tmp -> text = txt;
    tmp -> next = nullptr;

    if(hashtable[hash] == nullptr) {
        hashtable[hash] = tmp;
        return;
    }

    Node * p = hashtable[hash];
    while(p -> next != nullptr)
        p = p -> next;

    p -> next = tmp;

}

bool check_if_exists(Node** hashtable, int n, string txt) {
   

    int hash = hashfunc(txt)%n;
    Node * p = hashtable[hash];
    while(p != nullptr && p -> text != txt)
        p = p -> next;

    return (p != nullptr);
}

void free_memory(Node** hashtable, int n) {
    Node *ptr, *nxt;
    for (int i = 0; i < n; i++) {
        ptr = hashtable[i];
        while (ptr != nullptr) {
           
            nxt = ptr -> next;
            ptr -> next = nullptr;
            delete ptr;
            ptr = nxt;
        }
    }
    delete[](hashtable);
}

void debug_print_hashtable(Node** hashtable, int n) {
//#ifdef DEBUG
    Node* ptr;
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            ptr = hashtable[i];
            while (ptr != NULL) {
                cout << ptr->text << " | ";
                ptr = ptr->next;
            }
            cout << endl;
        }

}

int main() {
    ios::sync_with_stdio(false);
    int Z;
    cin >> Z;

    while (Z--) {
        int n, k;
        string tmp;

        cin >> n;
        cin >> k;

        Node** hashtable = new Node*[n]();

        for (int i = 0; i < n; i++)
            hashtable[i] = nullptr;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            add_to_hashtable(hashtable, n, tmp);
        }

        for (int i = 0; i < k; i++) {
            cin >> tmp;
            if (check_if_exists(hashtable, n, tmp)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        free_memory(hashtable, n);
    }

}
