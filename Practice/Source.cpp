#include<iostream>
#include<unordered_set>
using namespace std;
struct Node {
	int data;
	int priority = 9000;
	Node* next;
};
class LinkedList {
	Node* head;
public:
	LinkedList() {
		head = NULL;
	}
	Node* getLastNode(){
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		return current;
	}
	void priorityEnqueue() {
		Node* temp = new Node;
		cout << "Enter Data of New Node: ";
		cin >> temp->data;
		cin.ignore();
		cout << "Enter Priority: ";
		cin >> temp->priority;
		cin.ignore();
		if (head->priority > temp->priority) {
			temp->next = head;
			head = temp;
		}
		else {
			Node* current = head;
			while (current->next != NULL && current->next->priority<temp->priority) {
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
	}
	void insertAtEnd() {
		Node* temp = new Node;
		cout << "Enter Data of New Node: ";
		cin >> temp->data;
		cin.ignore();
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
		}
		else {
			Node* current = getLastNode();
			current->next = temp;
		}
	}
	void insertAtStart() {
		Node* temp = new Node;
		cout << "Enter Data of New Node: ";
		cin >> temp->data;
		cin.ignore();
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}
	void insertAfterNumber() {
		if (head == NULL) {
			cout << "List is Empty\n";
			return;
		}
		cout << "Enter Number: ";
		int number;
		cin >> number;
		cin.ignore();
		Node* current = head;
		Node* temp = new Node;
		cout << "Enter new Node data: ";
		cin >> temp->data;
		cin.ignore();
		temp->next = NULL;
		while (current != NULL) {
			if (current->data == number) {
				break;
			}
			else {
				current = current->next;
			}
		}
		if (current != NULL) {
			temp->next = current->next;
			current->next = temp;
		}
		else {
			cout << "Number Not Found\n";
		}
	}
	void insertBeforeNumber() {
		if (head == NULL) {
			cout << "List is Emtpy\n";
			return;
		}
		cout << "Enter Number: ";
		int number;
		cin >> number;
		cin.ignore();
		Node* current = head;
		Node* previous = head;
		Node* temp = new Node;
		cout << "Enter New Data: ";
		cin >> temp->data;
		cin.ignore();
		temp->next = NULL;
		while (current != NULL) {
			if (current->data == number) {
				break;
			}
			else {
				previous = current;
				current = current->next;
			}
		}
		if (current != NULL) {
			if (current== head) {
				temp->next = head;
				head = temp;
			}
			else {
				temp->next = current;
				previous->next = temp;
			}
		}
		else {
			cout << "Number Not Found\n";
		}
	}
	void deleteAtEnd() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else if (head->next == NULL) {
			delete (head->next);
			head = NULL;
		}
		else {
			Node* current = head;
			while (current->next->next != NULL) {
				current = current->next;
			}
			delete (current->next);
			current->next = NULL;
		}
	}
	void deleteAtStart() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else if (head->next == NULL) {
			delete (head->next);
			head = NULL;
		}
		else {
			Node* current = head;
			head = head->next;
			delete (current);
		}
	}
	void deleteAfterNumber() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else {
			cout << "Enter Number: ";
			int number;
			cin >> number;
			cin.ignore();
			Node* current = head;
			while (current != NULL) {
				if (current->data == number)
					break;
				else current = current->next;
			}
			if (current != NULL) {
				if (current->next == NULL) {
					cout << "Next Number Does not Exist\n";
				}
				else {
					Node* temp = current->next;
					current->next = temp->next;
					delete (temp);
				}
			}
			else cout << "Number Not Found\n";
		}
	}
	void deleteBeforeNumber() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else {
			cout << "Enter Number: ";
			int number;
			cin >> number;
			cin.ignore();
			Node* current = head;
			Node* previous = head;
			while (current != NULL) {
				if (current->data == number) {
					break;
				}
				else if (current->next->data == number) {
					current = current->next;
					break;
				}
				previous = current;
				current = current->next;
			}
			if (current!= NULL) {
				if (current == head) {
					cout << "Cannot Delete Before head\n";
				}
				else if (previous == head) {
					head = previous->next;
					delete (previous);
				}
				else {
					Node* temp = previous->next;
					previous->next = current;
					delete (temp);
				}
			}
			else cout << "Number Not Found\n";
		}
	}
	void RemoveDuplicate() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else {
			unordered_set<int>list;
			Node* current = head;
			Node* previous = head;
			while (current != NULL) {
				if (list.find(current->data) != list.end()) {
					previous->next = current->next;
					delete (current);
				}
				else {
					list.insert(current->data);
					previous = current;
				}
				current = previous->next;
			}
		}
	}
	void replaceNode(Node* toBeReplaced, Node* AfterNode) {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else {
			Node* current = head;
			while (current->next != toBeReplaced) {
				current = current->next;
			}
			current->next = toBeReplaced->next;
			toBeReplaced->next = NULL;
			Node* temp = head;
			if (AfterNode->next != NULL) {
				toBeReplaced->next = AfterNode->next;
				AfterNode->next = toBeReplaced;
			}
			else {
				AfterNode->next = toBeReplaced;
			}
		}
	}
	Node* getHead() {
		return head;
	}
	void display() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else {
			Node* current = head;
			while (current != NULL) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << "\n";
		}
	}
	void displayMiddle() {
		if (head == NULL) {
			cout << "List is Emtpy\n";
		}
		else {
			Node* current = head;
			Node* previous = head;
			while (current->next != NULL) {
				current = current->next->next;
				previous = previous->next;
			}
			cout << "Middle Value: " << previous->data << "\n";
		}
	}
	Node* getNode(int number) {
		Node* current = head;
		int counter = 0;
		while (current != NULL) {
			counter++;
			if (counter == number) {
				break;
			}
			current = current->next;
		}
		return current;
	}
	void midtermFunction() {
		if (head != NULL) {
			Node* curr = head;
			Node* prev=NULL;
			Node* temp=NULL;
			while (curr != NULL) {
				temp = curr->next;
				curr->next = prev;
				prev = curr;
				curr = temp;
			}
			head = prev;
		}
	}
	void sortNodes() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else {
			for (Node *current=head; current->next != NULL; current = current->next) {
				for (Node* j = current->next; j != NULL; j = j->next) {
					if (current->data > j->data) {
						Node* temp = new Node;
						temp->data = current->data;
						current->data = j->data;
						j->data = temp->data;
					}
				}
			}
		}
	}
	void createEvenOdd() {
		if (head == NULL) {
			cout << "List is Empty\n";
		}
		else {
			Node* list1 = NULL;
			Node* list2 = NULL;
			Node* current = head;
			while (current != NULL) {
				Node* saperate = new Node;
				saperate->data = current->data;
				saperate->next = NULL;
				if (current->data % 2 == 0) {
					if (list1 == NULL) {
						list1 = saperate;
					}
					else {
						Node* temp = list1;
						while (temp->next != NULL) {
							temp = temp->next;
						}
						temp->next = saperate;
					}
				}
				else {
					if (list2 == NULL) {
						list2 = saperate;
					}
					else {
						Node* temp = list2;
						while (temp->next != NULL) {
							temp = temp->next;
						}
						temp->next = saperate;
					}
				}
				current = current->next;
			}
			Node* currentList1 = list1;
			Node* currentList2 = list2;
			cout << "List 1: ";
			while (currentList1 != NULL) {
				cout << currentList1->data << " ";
				currentList1= currentList1->next;
			}
			cout << "\nList 2: ";
			while (currentList2 != NULL) {
				cout << currentList2->data << " ";
				currentList2= currentList2->next;
			}
		}
	}
};
void main() {
	Node* toBeReplaced, * AfterNode;
	int number;
	bool isRunning = true;
	LinkedList obj;
	do {
		bool user_choice;
		do {
			user_choice = true;
			cout << "\nPress [E] to Insert at End\n";
			cout << "Press [S] to Insert at Start\n";
			cout << "Press [T] to Insert After Number\n";
			cout << "Press [R] to Insert Before Number\n";
			cout << "Press [I] to Priority Enqueue\n";
			cout << "Press [W] to Delete End\n";
			cout << "Press [Q] to Delete Start\n";
			cout << "Press [P] to Delete After Number\n";
			cout << "Press [O] to Delete Before Number\n";
			cout << "Press [M] to Remove Duplicate\n";
			cout << "Press [K] to Replace a Node After Another Node\n";
			cout << "Press [Z] to Sort\n";
			cout << "Press [C] to Create Even & Odd\n";
			cout << "Press [D] to Display List\n";
			cout << "Press [J] to Call Midterm\n";
			cout << "Press [N] to Display Middle Value\n";
			cout << "Press [X] to Exit\n";
			cout << "\nChoose your Option: ";
			char choice;
			cin >> choice;
			cin.ignore();
			choice = tolower(choice);
			switch (choice) {
			case 'e':obj.insertAtEnd();
				break;
			case 's':obj.insertAtStart();
				break;
			case 't':obj.insertAfterNumber();
				break;
			case 'r':obj.insertBeforeNumber();
				break;
			case 'i':obj.priorityEnqueue();
				break;
			case 'w':obj.deleteAtEnd();
				break;
			case 'q':obj.deleteAtStart();
				break;
			case 'p':obj.deleteAfterNumber();
				break;
			case 'o':obj.deleteBeforeNumber();
				break;
			case 'm':obj.RemoveDuplicate();
				break;
			case 'k':obj.display();
				cout << "Enter Number: ";
				cin >> number;
				cin.ignore();
				toBeReplaced = obj.getNode(number);
				cout << "Enter Number of Node to insert the previous after that: ";
				cin >> number;
				cin.ignore();
				AfterNode = obj.getNode(number);
				obj.replaceNode(toBeReplaced, AfterNode);
				break;
			case 'd':obj.display();
				break;
			case 'c':obj.createEvenOdd();
				break;
			case'j':obj.midtermFunction();
				break;
			case 'z':obj.sortNodes();
				break;
			case 'n':obj.displayMiddle();
				break;
			case 'x':isRunning = false;
				break;
			default:
				cout << "Invalid Choice Try Again\n";
				user_choice = false;
			}
		} while (user_choice == false);
	} while (isRunning);
}