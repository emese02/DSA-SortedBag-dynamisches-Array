#include "SortedBag.h"
#include "SortedBagIterator.h"

// Complexity: theta(1)
SortedBag::SortedBag(Relation r) {
    //TODO - Implementation
    this->nrElems = 0;
    this->cap = 10;
    this->rel = r;
    this->elements = new std::pair<TComp, TComp>[this->cap];
}

// Best case: theta(1)   - increase frequency of first element
// Average case: theta(n)
// Worst case: theta(n)
// Complexity: O(n)
void SortedBag::add(TComp e) {
    // TODO - Implementation
    // check if it is full -> capacity must be increased (resize)

    // first check if it is already in bag or not
    if (this->nrElems == this->cap) {
        this->cap *= 2;
        auto *newElements = new std::pair <TComp, TComp> [this->cap];
        for (int index = 0; index < this->nrElems; index++)
            newElements[index] = this->elements[index];
        this->elements = newElements;
    }
    // search the correct position
    int index = 0;
    while (index < this->nrElems && this->rel(this->elements[index].first, e))
        index++;

    // if the element is already in bag, we increase frequency
    if (this->elements[index - 1].first == e)
    {
        this->elements[index - 1].second++;
    }
    // add new element to end (with frequency 1)
    else if (index == this->nrElems)
    {
        std::pair<TComp, TComp> newpair(e, 1);
        this->elements[this->nrElems] = newpair;
        this->nrElems++;
    }
    else
    {
        // make place for the new element
        for (int j = this->nrElems - 1; j >= index; j--)
            this->elements[j + 1] = this->elements[j];

        std::pair<TComp, TComp> newpair(e, 1);
        this->elements[index] = newpair;
        this->nrElems++;
    }

}

// Best case: theta(1)   - remove first element (frequency > 1)
// Average case: theta(n)
// Worst case: theta(n)
// Complexity: O(n)
bool SortedBag::remove(TComp e) {
    //TODO - Implementation

    // reduce capacity
    if (this->nrElems < this->cap/4)
    {
        this->cap /= 2;
        //allocation!!
    }

    // find correct position
    int index = 0;
    while (index < this->nrElems && this->rel(this->elements[index].first, e))
        index++;

    if (this->elements[index - 1].first == e)
    {
        // reduce frequency
        if (this->elements[index - 1].second > 1)
        {
            this->elements[index - 1].second--;
        }
        else
        // eliminate the whole pair
        {
            for (int j = index-1; j < this->nrElems - 1; j++)
                this->elements[j] = this->elements[j + 1];
            this->nrElems--;
        }
        return true;
    }
    return false;
}

// Best case: theta(1) - first element is the searched element
// Average case: theta(n)
// Worst case: theta(n)
// Complexity: O(n)
bool SortedBag::search(TComp elem) const {
    //TODO - Implementation
    // binarysearch!!
    int index = 0;
    while (index < this->nrElems && this->rel(this->elements[index].first, elem))
        index++;

    if (this->elements[index - 1].first == elem)
        return true;

    return false;
}

// Best case: theta(1)   - occurrence of first element
// Average case: theta(n)
// Worst case: theta(n)
// Complexity: O(n)
int SortedBag::nrOccurrences(TComp elem) const {
    //TODO - Implementation
    int index = 0;
    while (index < this->nrElems && this->rel(this->elements[index].first, elem))
        index++;

    if (this->elements[index - 1].first == elem)
        return this->elements[index-1].second;
    return 0;
}

// Complexity: theta(n)
int SortedBag::size() const {
    //TODO - Implementation
    int total = 0;
    for (int index = 0; index < this->nrElems; index++)
        total += this->elements[index].second;
    return total;
}

// Complexity: theta(1)
bool SortedBag::isEmpty() const {
    //TODO - Implementation
    if (this->nrElems == 0)
        return true;
    return false;
}

// Complexity: theta(1)
SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

SortedBag::~SortedBag() {
    //TODO - Implementation
    delete[] this->elements;
}

SortedBag::SortedBag(const SortedBag &sb) {
    this->cap = sb.cap;
    this->nrElems = sb.nrElems;
    this->elements = new std::pair<TComp, TComp>[this->cap];
    this->rel = sb.rel;
    for (int index = 0; index < sb.nrElems; index++)
        this->elements[index] = sb.elements[index];

}
