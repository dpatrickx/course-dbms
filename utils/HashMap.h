#ifndef HASHMAP_H
#define HASHMAP_H

#include "../db/para.h"
#include <string>
using namespace std;

#define SIZE 90211

struct HashNode {
public:
	HashNode() : val(""), next(0) {}
	string val;
	HashNode* next;
	HashNode(string v) : val(v), next(0) {}
};

class HashLink {
public:
	HashLink() : head(0), tail(0) {}
	bool empty;
	HashNode* head;
	HashNode* tail;
	void add(HashNode* n) {
		if (head == 0) {
			head = n;
			tail = n;
		} else if(head->next == 0) {
			head->next = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
	}
	void remove(string v) {
		HashNode* node = head;
		HashNode* befo = 0;
		while(node != 0) {
			if (node->val == v) {
				if (befo != 0) {
					befo->next = node->next;
					if (node == tail)
						tail = befo;
				} else
					head = node->next;
				delete node;
				break;
			}
			befo = node;
			node = node->next;
		}
	}
	bool check(string v) {
		bool res = false;
		HashNode* node = head;
		while(node != 0) {
			if (node->val == v)
				res = true;
			node = node->next;
		}
		return res;
	}
};

class HashMap {
private:
	HashLink dict[SIZE];
public:
	HashMap() {}
	bool check(string v) {
		int rank = 0;
		for (int i = 0; i < v.size(); i++) {
			int dist = v[i] - '0';
			if (dist < 0)
				dist = -dist;
			rank += 13*(i+1)*dist;
		}
		rank %= SIZE;
		return dict[rank].check(v);
	}
	bool insert(string v) {
		int rank = 0;
		for (int i = 0; i < v.size(); i++) {
			int dist = v[i] - '0';
			if (dist < 0)
				dist = -dist;
			rank += 13*(i+1)*dist;
		}
		rank %= SIZE;
		HashNode* node = new HashNode(v);
		dict[rank].add(node);
	}
	void remove(string v) {
		int rank = 0;
		for (int i = 0; i < v.size(); i++) {
			int dist = v[i] - '0';
			if (dist < 0)
				dist = -dist;
			rank += 13*(i+1)*dist;
		}
		rank %= SIZE;
		dict[rank].remove(v);
	}
};

#endif