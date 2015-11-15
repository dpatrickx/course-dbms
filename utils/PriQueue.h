#ifndef PRIQUEUE_H
#define PRIQUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class PriQueue {
public:
	int _capa; // max of elements
	int _size; // number of elements
	T* _elem;

	PriQueue (int n = 1) {
		_size = 0;
		_capa = n;
		_elem = new T[n];
	}

	int insert (T ele) {
		if (_size == _capa-1)
			expand();
		_elem[_size] = ele;
		int i = _size;
		for (int j = _size-1;j >= 0;j--) {
			if (ele < _elem[j]) {
				T temp = _elem[j];
				_elem[j] = ele;
				_elem[i] = temp;
				i = j;
			} else {
				break;
			}
		}
		_size++;
	}

	int select (T ele) {
		for (int i = 0;i < _size;i++)
			if (_elem[i] == ele)
				return i;
		return -1;
	}

	int remove (T ele) {
		int pos = select(ele);
		if (pos == -1)
			return -1;
		for (int i = pos;i < _size-1;i++) {
			_elem[i] = _elem[i+1];
		}
		_size--;
		return 1;
	}

	void expand() {
		_capa *= 2;
		T* temp = _elem;
		_elem = new T[_capa];
		for (int i = 0;i < _size;i++)
			_elem[i] = temp[i];
	}
};

#endif