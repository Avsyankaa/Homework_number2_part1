#include <iostream>
#include <string>
using namespace std;
struct Node {
  int znach;
  Node *next;
};
struct List {
  Node *head;
};
void zapoln(List &list, int integer1, Node *&last) {
  Node *curr = new Node{integer1, nullptr};
  if (list.head == nullptr)
    list.head = curr;
  else {
    if (list.head->next == nullptr) list.head->next = curr;
    if (last != nullptr) last->next = curr;
    last = curr;
  }
}
void vivod(Node *&curr) {
  do {
    if (curr->next == nullptr)
      cout<< curr->znach<< endl;
    else
      cout<< curr->znach << "->";
    curr = curr->next;
  } while (curr != nullptr);
}
int main(int argc, char *argv[]) {
  Node *last = nullptr;
  int flag = 1;
  List list;
  list.head = nullptr;
  if (argc == 1)
    flag = 0;
  else {
    if (argc == 2) {
      int k = 0;
      string Main;
      Main = argv[1];
      string integer;
      int integer1;
      while (true) {
        for (int i = k; i < Main.length(); i++) {
          if (Main[i] == ',') {
            k++;
            break;
          }
          integer = integer + Main[i];
          k++;
        }
        if (integer == "") break;
        integer1 = atoi(integer.c_str());
        zapoln(list, integer1, last);
        integer = "";
      }
    } else {
      int integer2;
      int n = 1;
      while (n < argc) {
        integer2 = atoi(argv[n]);
        zapoln(list, integer2, last);
        n++;
      }
    }
  }
  int flag1 = 0;
  while (flag1 != 7) {
    cout<< "Select one of the operations:"<< endl;
    cout<< "1.Print the list"<< endl;
    cout<< "2.Add items to the list"<< endl;
    cout<< "3.Delete item"<< endl;
    cout<< "4.Find positions of iteams"<< endl;
    cout<< "5.Replace the item on the other" << endl;
    cout<< "6.Sort the list items" << endl;
    cout<< "7.Сomplete the program"<< endl;
    cin>> flag1;
    switch (flag1) {
      case 1:
        if (flag == 0)
          cout << "List is empty"<< endl;
        else {
          Node *curr = nullptr;
          curr = list.head;

          vivod(curr);
        }
        break;
    }
  }
}
