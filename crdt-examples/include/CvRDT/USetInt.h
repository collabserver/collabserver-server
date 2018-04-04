#pragma once

#include <set>
#include <iterator>
#include <cassert>
#include <stdio.h>

namespace CRDT {
namespace CvRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

/**
 * Grow Only Add / Remove Set Integer. (2P Set)
 *
 * Elements are added only once and removed only if already added.
 * Once removed, an element cannot be re-added.
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
struct USetInt {
    std::set<int> _mAdd; // Set of added elt
    std::set<int> _mDel; // Set of removed elt (tombstone)
};


// -----------------------------------------------------------------------------
// Data Methods
// -----------------------------------------------------------------------------

int USetInt_find(const USetInt& data, const int value) {
    auto itAdd = data._mAdd.find(value);
    auto itDel = data._mDel.find(value);

    bool containsAdd = itAdd != data._mAdd.end();
    bool containsDel = itDel != data._mDel.end();

    if(containsAdd && !containsDel) {
        return *itAdd;
    }
    return -1;
}

void USetInt_add(USetInt& data, const int value) {
    data._mAdd.insert(value); // Do nothing if already in set
}

void USetInt_remove(USetInt& data, const int value) {
    std::set<int>::iterator itAdd = data._mAdd.find(value);
    bool containsAdd = itAdd != data._mAdd.end();
    if(containsAdd) {
        data._mDel.insert(value);
    }
}

void USetInt_merge(USetInt& ours, const USetInt& theirs) {
    for(auto it = theirs._mAdd.begin(); it != theirs._mAdd.end(); ++it) {
        ours._mAdd.insert(*it);
    }
    for(auto it = theirs._mDel.begin(); it != theirs._mDel.end(); ++it) {
        ours._mDel.insert(*it);
    }
}

void USetInt_print(const USetInt& data) {
    char separator = ' ';
    fprintf(stdout, "CvRDT USetInt: [");

    for(auto it = data._mAdd.begin(); it != data._mAdd.end(); ++it) {
        bool contains = (data._mDel.find(*it) != data._mDel.end());
        if(!contains) {
            fprintf(stdout, "%c%d", separator, *it);
            separator = ',';
        }
    }

    fprintf(stdout, "]\n");
}


}} // End namespace
