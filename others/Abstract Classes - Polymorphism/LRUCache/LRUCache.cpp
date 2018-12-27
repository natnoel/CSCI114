#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
	LRUCache(int cap) {
		cp = cap;
	};

	void set(int k, int v) {
		if (head == NULL) { //If nothing in cache
			cout << "Entered head == NULL\n";
			head = new Node(k, v);
			tail = head;
			mp.insert(make_pair(k, head));
		}
		else {
			map<int, Node*>::iterator it = mp.find(k);

			if (it == mp.end()) {    //If not in cache, add head
				Node* n = new Node(NULL, head, k, v);
				head->prev = n;
				head = n;
				mp.insert(make_pair(k, n));

				if (mp.size() > cp) {    //If exceed capacity, remove tail
					mp.erase(tail->key);
					Node *dN = tail;
					tail = tail->prev;
					tail->next = NULL;
					delete dN;
				}
			}
			else {   //If already in cache, change position to head
				Node *n = it->second;

				//Take care or before and after nodes pointing to it
				n->prev->next = n->next;
				if (n != tail)
					n->next->prev = n->prev;

				//Take care of n and head pointers
				n->next = head;
				head->prev = n;
				n->prev = NULL;
				head = n;
			}
		}
		cout << "Size is now " << mp.size() << endl;
		//printNodes();
		printMap();
		//printNodesReverse();
	}

	int get(int k) {
		map<int, Node *>::iterator it = mp.find(k);
		if (it == mp.end())
			return -1;
		else
			return it->second->value;
	}

	void printNodes()
	{
		Node *n = head;
		while (n != NULL) {
			cout << "(" << n->key << "," << n->value << ") ";
			n = n->next;
		}
		cout << endl;
	}

	void printNodesReverse()
	{
		Node *n = tail;
		while (n != NULL) {
			cout << "(" << n->key << "," << n->value << ") ";
			n = n->prev;
		}
		cout << endl;
	}

	void printMap() {
		for (map<int,Node*>::iterator it = mp.begin(); it != mp.end(); it++)
			cout << "(" << it->first << "," << it->second->value << ") ";
		cout << endl;
	}
};

int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}
