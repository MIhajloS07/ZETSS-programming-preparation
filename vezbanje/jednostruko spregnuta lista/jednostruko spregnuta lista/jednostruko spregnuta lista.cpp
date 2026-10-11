#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void dodajNaPocetak(Node*& head, int vrednost) {
    Node* novi = new Node;
    novi->data = vrednost;
    novi->next = head;
    head = novi;
}

void dodajNaKraj(Node*& head, int vrednost) {
    Node* novi = new Node;
    novi->data = vrednost;
    novi->next = nullptr; // zadnji element kao NULL
    if (head == nullptr) {
        head = novi; return; }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = novi;
}

void obrisiListu(Node*& head) {
    // Dok ne dodje do zadnjeg elementa, brise trenutni
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void ispisi(Node* head) {
    // Dok ne dodje do zadnjeg elementa, ispisuje
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;
    dodajNaPocetak(head, 10);
    dodajNaPocetak(head, 20);
    dodajNaPocetak(head, 30);
    ispisi(head);
    obrisiListu(head);
    return 0;
}
