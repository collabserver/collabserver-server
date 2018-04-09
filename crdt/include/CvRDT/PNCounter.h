#pragma once

#include "GCounter.h"

#include <iostream>

namespace CRDT {
namespace CvRDT {


/**
 * Increment / Decrement Counter.
 * CvRDT (State based object)
 *
 * \note
 * Internally, uses two Grow Only counters. (Positive / Negative).
 *
 * \tparam T Type of counter. (Default int)
 * \tparam ID Type of the id used to identify each replicated. (Each unique).
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template <typename T = int, typename Key = std::string>
class PNCounter {
    private:
        GCounter<T, Key> _positive; // Positive counter
        GCounter<T, Key> _negative; // Negative counter

    public:
        PNCounter(const Key id) : _positive(id), _negative(id) {}


    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------

    public:

        T query() const {
            return _positive.query() - _negative.query();
        }

        void increment() {
            _positive.increment();
        }

        void decrement() {
            _negative.increment();
        }

        void merge(const PNCounter& other) {
            _positive.merge(other._positive);
            _negative.merge(other._negative);
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        friend std::ostream& operator<<(std::ostream& out, const PNCounter& o) {
            out << "PNCounter: " << o.query();
            out << " (" << o._positive << "), (" << o._negative << ")";
            return out;
        }
};


}} // End namespaces


