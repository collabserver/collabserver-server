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
 * \warning
 * Data type T must work with std::max. (is_arithmetic == true)
 *
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

        /**
         * Query a copy of the counter value.
         */
        T query() const {
            return _positive.query() - _negative.query();
        }

        /**
         * Increment counter by one.
         */
        void increment() {
            _positive.increment();
        }

        /**
         * Increment counter by specific amount.
         *
         * \warning
         * Positive number expected.
         * See GSet doc for further information.
         *
         * \see GSet::increment(const T& value)
         */
        void increment(const T& value) {
            _positive.increment(value);
        }

        /**
         * Decrement counter by one.
         */
        void decrement() {
            _negative.increment();
        }

        /**
         * Increment counter by specific amount.
         *
         * \warning
         * Positive number expected.
         * See GSet doc for further information.
         *
         * \see GSet::increment(const T& value)
         */
        void decrement(const T& value) {
            _negative.increment(value);
        }

        /**
         * Merge with another counter.
         */
        void merge(const PNCounter& other) {
            _positive.merge(other._positive);
            _negative.merge(other._negative);
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        bool operator==(const PNCounter& lhs) const {
            return (this->_positive == lhs._positive)
                && (this->_negative == lhs._negative);
        }

        bool operator!=(const PNCounter& lhs) const {
            return !(*this == lhs);
        }

        friend std::ostream& operator<<(std::ostream& out, const PNCounter& o) {
            out << "PNCounter = " << o.query();
            out << " (" << o._positive << "), (" << o._negative << ")";
            return out;
        }
};


}} // End namespaces


