#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r, int capacity) {
	//TODO - Implementation
    if (capacity <= 0)
        throw exception();

    this->nrElems = 0;
    this->cap = capacity;
    this->rel = r;
    this->elements = new std::pair <TComp,TComp> [capacity];
}

void SortedBag::add(TComp e) {
	// TODO - Implementation
    // check if it is full
    if (this->nrElems == this->cap)
        throw exception();

    int index = 0;
    int count = 0;
    while (index < this->nrElems && this->rel(e,this->elements[index].first))
        index ++;

    // check if the element is yet not in bag -> new pair to the correct position with frequency 1
    if (index == this->nrElems)
    {
        TComp f=1;
        TElem newpair(e,f);
        this->elements[this->nrElems] = newpair;
        this->nrElems ++;
    }
    // if the element is already in bag, we increase frequency
    else if (this->elements[index].first == e)
    {
        this->elements[index].second++;
    }
    else
    {
        for (int i=this->nrElems-1; i>= index; i--)
            this->elements[i+1] = this->elements[i];

        TComp f=1;
        TElem newpair(e,f);
        this->elements[index] = newpair;
        this->nrElems ++;
    }
}


bool SortedBag::remove(TComp e) {
	//TODO - Implementation
    // if frequency == 1 -> pair elimination
    for (int index = 0; index < this->nrElems; index++) {
        if (this->elements[index].first == e) {
            if (this->elements[index].second > 1)
                this->elements[index].second--;
            else {
                for (int j = index; j < this->nrElems - 1; j++)
                    this->elements[j] = this->elements[j + 1];
                this->nrElems--;
            }
            return true;
        }
    }
        return false;
}


bool SortedBag::search(TComp elem) const {
	//TODO - Implementation
    for (int index = 0; index < this->nrElems; index++)
        if (this->elements[index].first == elem)
            return true;
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
	//TODO - Implementation
    for (int index = 0; index < this->nrElems; index++)
        if (this->elements[index].first == elem)
            return this->elements[index].second;
	return 0;
}


int SortedBag::size() const {
	//TODO - Implementation
    return this->nrElems;
	return 0;
}


bool SortedBag::isEmpty() const {
	//TODO - Implementation
    if (size() == 0)
        return true;
	return false;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	//TODO - Implementation
    delete[] this->elements;
}
