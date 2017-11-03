#include <iostream>
#include <string>
using namespace std;
struct Node {
  int value;
  Node *next;
};
struct List {
  Node *head;
};
void fill(List &list, int integer1, Node *&last) {
  Node *curr = new Node{integer1, nullptr};
  if (list.head == nullptr)
    list.head = curr;
  else {
    if (list.head->next == nullptr) list.head->next = curr;
    if (last != nullptr) last->next = curr;
    last = curr;
  }
}
void outputting(Node *&curr) {
  do {
    if (curr->next == nullptr)
      cout << curr->value << endl;
    else
      cout << curr->value << "->";
    curr = curr->next;
  } while (curr != nullptr);
}
void Menu(int &choise, void outputting(Node *&), int flag, List &list) {
  while (choise != 7) {
    cout << "Select one of the operations:" << endl;
    cout << "1.Print the list" << endl;
    cout << "2.Add items to the list" << endl;
    cout << "3.Delete item" << endl;
    cout << "4.Find positions of iteams" << endl;
    cout << "5.Replace the item on the other" << endl;
    cout << "6.Sort the list items" << endl;
    cout << "7.Сomplete the program" << endl;
    cin >> choise;
    switch (choise) {
      case 1:
        if (flag == 0)
          cout << "List is empty" << endl;
        else {
          Node *curr = nullptr;
          curr = list.head;
          outputting(curr);
        }
        break;
    }
  }
}
int main(int argc, char *argv[]) {
  Node *last = nullptr;
  int flag = 1;
  int integer1;
  List list;
  list.head = nullptr;
  if (argc == 1)
    flag = 0;
  else {
    if (argc == 2) {
      int k = 0;
      string number_array;
      number_array = argv[1];
      string integer_str;
      while (true) {
        for (int i = k; i < number_array.length(); i++) {
          if (number_array[i] == ',') {
            k++;
            break;
          }
          integer_str = integer_str + number_array[i];
          k++;
        }
        if (integer_str == "") break;
        integer1 = atoi(integer_str.c_str());
        fill(list, integer1, last);
        integer_str = "";
      }
    } else {
      int n = 1;
      while (n < argc) {
        integer1 = atoi(argv[n]);
        fill(list, integer1, last);
        n++;
      }
    }
  }
  int choise = 0;
  Menu(choise, outputting, flag, list);
}
