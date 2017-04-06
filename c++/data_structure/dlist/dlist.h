#ifndef DLIST_H
#define DLIST_H

#include <iostream>

using std::cout;
using std::endl;

namespace std {

template<class T>
class DListNode {

public:
	DListNode(const T& data, DListNode<T>* prev = NULL, DListNode<T>* next = NULL): _data(data), _prev(prev), _next(next) {}
	~DListNode() {}
	inline void setPrev(DListNode<T>* prev) { _prev = prev; }
	inline void setNext(DListNode<T>* next) { _next = next; }
	inline const T& getData() const { return _data; }
	inline DListNode<T>* getPrev() const { return _prev; }
	inline DListNode<T>* getNext() const { return _next; }

private:
	T _data;
	DListNode<T>* _prev;
	DListNode<T>* _next;

};

template<class T>
class DList {

public:
	DList(DListNode<T>* head = new DListNode<T>(T())): _head(head) { _head -> setPrev(_head); _head -> setNext(_head); }
	~DList() {}
	inline void setHead(DListNode<T>* head) { _head = head; }
	class iterator {

	public:
		iterator(DListNode<T>* node = NULL): _node(node) {}
		~iterator() {}
		inline DListNode<T>* getNode() { return _node; }
		const T& operator*() { return this -> _node -> getData(); }
		iterator& operator=(const iterator& it) { this -> _node = it._node; return *this; }
		bool operator==(const iterator& it) const { return this -> _node == it._node; }
		bool operator!=(const iterator& it) const { return this -> _node != it._node; }
		iterator& operator++() { this -> _node = this -> _node -> getNext(); return *this; }
		iterator operator++(int) { iterator old_it = *this; this -> _node = this -> _node -> getNext(); return old_it; }
		iterator operator+(int i) { DListNode<T>* new_node = this -> _node; for(int count = 0; count < i; ++count) { new_node = new_node -> getNext(); } return iterator(new_node); }
		iterator& operator+=(int i) { for(int count = 0; count < i; ++count) { this -> _node = this -> _node -> getNext(); } return *this; }
		iterator& operator--() { this -> _node = this -> _node -> getPrev(); return *this; }
		iterator operator--(int) { iterator old_it = *this; this -> _node = this -> _node -> getPrev(); return old_it; }
		iterator operator-(int i) { DListNode<T>* new_node = this -> _node; for(int count = 0; count < i; ++count) { new_node = new_node -> getPrev(); } return iterator(new_node); }
		iterator& operator-=(int i) { for(int count = 0; count < i; ++count) { this -> _node = this -> _node -> getPrev(); } return *this; }

	private:
		DListNode<T>* _node;

	};
	iterator begin() const {
		return iterator(_head);
	}
	iterator end() const {
		return iterator(_head -> getPrev());
	}
	const T& operator[](size_t i) const {
		DListNode<T>* ptr = _head;
		for(int count = 0; count < i; ++count) {
			ptr = ptr -> getNext();
		}
		return ptr -> getData();
	}
	bool insert(const T& data) {
		DListNode<T>* cur = _head;
		while(cur -> getNext() != _head) {
			if(cur -> getData() == data) {
				return false;
			}
			else if(cur == _head && data < cur -> getData()) {
				DListNode<T>* new_cur = new DListNode<T>(data, cur -> getPrev(), cur);
				cur -> getPrev() -> setNext(new_cur);
				cur -> setPrev(new_cur);
				setHead(new_cur);
				return true;
			}
			else if(cur -> getNext() == _head -> getPrev()) {
				DListNode<T>* new_cur = new DListNode<T>(data, cur, cur -> getNext());
				cur -> getNext() -> setPrev(new_cur);
				cur -> setNext(new_cur);
				return true;
			}
			else if(cur -> getData() < data && data < cur -> getNext() -> getData()){
				DListNode<T>* new_cur = new DListNode<T>(data, cur, cur -> getNext());
				cur -> getNext() -> setPrev(new_cur);
				cur -> setNext(new_cur);
				return true;
			}
			else {
				cur = cur -> getNext();
			}
		}
		DListNode<T>* new_cur = new DListNode<T>(data, cur, cur);
		cur -> setPrev(new_cur);
		cur -> setNext(new_cur);
		setHead(new_cur);
		return true;
	}
	bool erase(const T& data) {
		DListNode<T>* cur = _head;
		while(cur -> getNext() != _head) {
			if(cur -> getData() == data) {
				if(cur == _head) {
					setHead(cur -> getNext());
				}
				cur -> getNext() -> setPrev(cur -> getPrev());
				cur -> getPrev() -> setNext(cur -> getNext());
				delete cur;
				return true;
			}
			cur = cur -> getNext();
		}
		return false;
	}
	bool erase(const iterator& pos) {
		if(_head == _head -> getNext()) {
			return false;
		}
		else {
			iterator it = begin();
			while(it != end()) {
				if(it == pos) {
					if(it == begin()) {
						setHead(it.getNode() -> getNext());
					}
					it.getNode() -> getNext() -> setPrev(it.getNode() -> getPrev());
					it.getNode() -> getPrev() -> setNext(it.getNode() -> getNext());
					delete it.getNode();
					return true;
				}
				++it;
			}
		}
		return false;
	}
	bool pop_front() {
		if(_head == _head -> getNext()) {
			return false;
		}
		else {
			iterator it = begin();
			it.getNode() -> getNext() -> setPrev(it.getNode() -> getPrev());
			it.getNode() -> getPrev() -> setNext(it.getNode() -> getNext());
			setHead(it.getNode() -> getNext());
			delete it.getNode();
			return true;
		}
	}
	bool pop_back() {
		if(_head == _head -> getNext()) {
			return false;
		}
		else {
			iterator it = end() - 1;
			it.getNode() -> getNext() -> setPrev(it.getNode() -> getPrev());
			it.getNode() -> getPrev() -> setNext(it.getNode() -> getNext());
			delete it.getNode();
			return true;
		}
	}
	void clear() {
		while(pop_front()) {

		}
	}
	size_t size() const {
		DListNode<T>* ptr = _head; size_t count = 0;
		while(ptr -> getNext() != _head) {
			ptr = ptr -> getNext(); ++count;
		}
		return count;
	}
	bool empty() const {
		return _head == _head -> getNext();
	}

private:
	DListNode<T>* _head;

};

};

#endif
