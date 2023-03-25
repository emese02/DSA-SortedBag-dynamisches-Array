#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

// Complexity: theta(1)
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
    this->index = 0;
    this->freq = 1;
}

// Complexity: theta(1)
TComp SortedBagIterator::getCurrent() {
	//TODO - Implementation
    // check if iterator is correct and return element
    if (SortedBagIterator::valid())
        return this->bag.elements[this->index].first;
    else
    {
        exception E;
        throw E;
    }
}

// Complexity: theta(1)
bool SortedBagIterator::valid() {
	//TODO - Implementation
    return this->index < this->bag.nrElems;
}

// Complexity: theta(1)
void SortedBagIterator::next() {
	//TODO - Implementation
    if (SortedBagIterator::valid())
    {
     if (this->freq < this->bag.elements[this->index].second)
         this->freq ++;
     else
     {
         // the first appearance of the next element
         this->index++;
         this->freq = 1;
     }
    }
    else
    {
        exception E;
        throw E;
    }
}

// Complexity: theta(1)
void SortedBagIterator::first() {
	//TODO - Implementation
    this->index = 0;
    this->freq = 1;
}

