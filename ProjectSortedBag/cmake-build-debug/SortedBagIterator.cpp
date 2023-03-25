#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
    this->index = 0;
}

TComp SortedBagIterator::getCurrent() {
	//TODO - Implementation
	return NULL_TCOMP;
}

bool SortedBagIterator::valid() {
	//TODO - Implementation
    // return this->index >=0  and this->index < this->bag.nrElems;
	return false;
}

void SortedBagIterator::next() {
	//TODO - Implementation
    if (this->index < this->bag.nrElems-1)
        this->index ++;
    else
        throw exception();
}

void SortedBagIterator::first() {
	//TODO - Implementation
    this->index = 0;
}

