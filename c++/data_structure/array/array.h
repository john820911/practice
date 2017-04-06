#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using std::cout;
using std::endl;

namespace std {

template<class T>
class Array {

public:
	Array(T* data = new T[0], const size_t& size = 0, const size_t& capacity = 0): _data(data), _size(size), _capacity(capacity) {}
	~Array() {}
	class iterator {
	public:
		iterator(T* element = NULL): _element(element) {}
		~iterator() {}
		const T& operator*() const { return *(this -> _element); }
		iterator& operator=(const iterator& it) { this -> _element = it._element; return *this; }
		bool operator==(const iterator& it) const { return this -> _element == it._element; }
		bool operator!=(const iterator& it) const { return this -> _element != it._element; }
		iterator& operator++() { ++(this -> _element); return *this; }
		iterator operator++(int) { iterator old_it = *this; ++(this -> _element); return old_it; }
		iterator operator+(int i) const { return iterator(this -> _element + i); }
		iterator& operator+=(int i) { this -> _element += i; return *this; }
		iterator& operator--() { --(this -> _element); return *this; }
		iterator operator--(int) { iterator old_it = *this; --(this -> _element); return old_it; }
		iterator operator-(int i) const { return iterator(this -> _element - i); }
		iterator& operator-=(int i) { this -> _element -= i; return *this; }

	private:
		T* _element;
	};
	iterator begin() const {
		return iterator(_data);
	}
	iterator end() const {
		return iterator(_data + _size);
	}
	const T& operator[](size_t i) const {
		return _data[i];
	}
	bool insert(const T& data) {
		int lower_bound = 0, upper_bound = _size - 1, mid_point = (lower_bound + upper_bound) / 2;
		while(lower_bound <= upper_bound) {
			if(data == _data[mid_point]) {
				return false;
			}
			else if(data < _data[mid_point]) {
				upper_bound = mid_point - 1;
			}
			else {
				lower_bound = mid_point + 1;
			}
			mid_point = (lower_bound + upper_bound) / 2;
		}
		++_size;
		if(_size > _capacity) {
			_capacity = (!_capacity)? 1:_capacity*2;
			T* new_data = new T[_capacity];
			for(int i = 0; i < lower_bound; ++i) {
				new_data[i] = _data[i];
			}
			new_data[lower_bound] = data;
			for(int i = lower_bound + 1; i < _size; ++i) {
				new_data[i] = _data[i - 1];
			}
			delete [] _data;
			_data = new_data;
		}
		else {
			for(int i = _size - 1; i > lower_bound; --i) {
				_data[i] = _data[i - 1];
			}
			_data[lower_bound] = data;
		}
		return true;
	}
	bool erase(const T& data) {
		int lower_bound = 0, upper_bound = _size - 1, mid_point = (lower_bound + upper_bound) / 2;
		bool ret = false;
		while(lower_bound <= upper_bound) {
			if(data == _data[mid_point]) {
				ret = true;
				break;
			}
			else if(data < _data[mid_point]) {
				upper_bound = mid_point - 1;
			}
			else {
				lower_bound = mid_point + 1;
			}
			mid_point = (lower_bound + upper_bound) / 2;
		}
		if(ret) {
			-- _size;
			if(_size == _capacity / 2) {
				_capacity /= 2;
				T* new_data = new T[_capacity];
				for(int i = 0; i < mid_point; ++i) {
					new_data[i] = _data[i];
				}
				for(int i = mid_point; i < _size; ++i) {
					new_data[i] = _data[i + 1];
				}
				delete [] _data;
				_data = new_data;
			}
			else {
				for(int i = mid_point; i < _size; ++i) {
					_data[i] = _data[i + 1];
				}
			}
		}
		return ret;
	}
	bool erase(const iterator& pos) {
		if(begin() == end()) {
			return false;
		}
		else {
			--_size;
			if(_size == _capacity / 2) {
				_capacity /= 2;
				T* new_data = new T[_capacity];
				iterator it = begin(); int i = 0;
				while(it != pos) {
					new_data[i] = *it;
					++it; ++i;
				}
				while(it != end()) {
					new_data[i] = *(it + 1);
					++it; ++i;
				}
				delete [] _data;
				_data = new_data;
			}
			else {
				iterator it = begin(); int i = 0;
				while(it != pos) {
					_data[i] = *it;
					++it; ++i;
				}
				while(it != end()) {
					_data[i] = *(it + 1);
					++it; ++i;
				}
			}
			return true;
		}
	}
	bool pop_front() {
		if(begin() == end()) {
			return false;
		}
		else {		
			--_size;
			if(_size == _capacity / 2) {
				_capacity /= 2;
				T* new_data = new T[_capacity];
				iterator it = begin(); int i = 0;
				while(it != end()) {
					new_data[i] = *(it + 1);
				}
				delete [] _data;
				_data = new_data;
			}
			else {
				iterator it = begin(); int i = 0;
				while(it != end()) {
					_data[i] = *(it + 1);
				}
			}
			return true;
		}
	}
	bool pop_back() {
		if(begin() == end()) {
			return false;
		}
		else {
			--_size;
			if(_size == _capacity / 2) {
				_capacity /= 2;
				T* new_data = new T[_capacity];
				iterator it = begin(); int i = 0;
				while(it != end()) {
					new_data[i] = *it;
					++it; ++i;
				}
				delete [] _data;
				_data = new_data;
			}
			return true;
		}
	}
	void clear() {
		delete [] _data;
		_data = new T[0];
		_size = 0;
		_capacity = 0;
	}
	size_t size() const {
		return _size;
	}
	bool empty() const {
		return _size == 0;
	}

private:
	T* _data;
	size_t _size;
	size_t _capacity;

};

};

#endif