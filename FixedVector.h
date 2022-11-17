#pragma once
#ifndef FIXEDVECTOR_H
#define FIXEDVECTOR_H


#include <vector>


template <class T>
class FixedVector{
private:
	std::vector<T> mVec;

public:
	FixedVector(int _spacesToAllocate);
	void insertElement(T _element);
	void insertElementInPlace(T _element, int _index);
	void insertElementUnique(T _element);
	int findElement(T _element);
	std::vector<T>* const getInternalVector();
};

template<class T>
FixedVector<T>::FixedVector(int _spacesToAllocate) {
	mVec.reserve(_spacesToAllocate);
}

template<class T>
void FixedVector<T>::insertElement(T _element)
{
	if (mVec.size() != mVec.capacity()) {
		mVec.push_back(_element);

	}

	else if (mVec.size() == mVec.capacity()) {
		mVec.erase(mVec.begin());
		mVec.insert(mVec.end(), _element);

	}
}

template<class T>
void FixedVector<T>::insertElementInPlace(T _element, int _index) {
	if (_index < mVec.capacity()) {
		mVec.insert(mVec.begin() + _index, _element);
	}
}

template<class T>
void FixedVector<T>::insertElementUnique(T _element) {
	bool foundElement = false;
	for (int i = 0; i < mVec.size(); i++) {
		if (mVec[i] == _element) {
			if (mVec.size() != mVec.capacity()) {
				mVec.push_back(_element);

			}

			else if (mVec.size() == mVec.capacity()) {
				mVec.erase(mVec.begin());
				mVec.insert(mVec.end(), _element);

			}
			break;
		}
	}
}

template<class T>
int FixedVector<T>::findElement(T _element) {
	for (int i = 0; i < mVec.size; i++) {
		if (_element == mVec[i]) {
			return i;
			break;
		}
	}
}

template<class T>
std::vector<T>* const FixedVector<T>::getInternalVector()
{
	return &mVec;
}
#endif // !FIXEDVECTOR_H