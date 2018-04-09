#pragma once

#include <cassert>
#include <ostream>

namespace CRDT {
namespace CvRDT {


/**
 * Last-Writer-Wins Register (LWW Register).
 * CvRDT (State-based).
 *
 * Timestamps is assigned to each update and creates a total order of updates.
 *
 * \note
 * Quote from the CRDT article "A comprehensive study of CRDT":
 *
 * "
 * A Last-Writer-Wins Register (LWW-Register) creates a total order of
 * assignments by associating a timestamp with each update.
 * Timestamps are assumed unique, totally ordered, and consistent with causal
 * order; i.e., if assignment 1 happened-before assignment 2,
 * the former's timestamp is less than the latter's. This may be implemented as
 * a per-replicate counter concatenated with a unique replica identifier,
 * such as its MAC address.
 * "
 *
 * \warning
 * Timestamps must have these properties.
 * Two equal timestamps (t1 == t1 returns true) is undefined and replicated
 * may diverge. (See implementation)
 *
 *
 * \tparam T Type of element.
 * \tparam Key Timestamps key.
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template<typename T, typename Key>
class LWWRegister {
    private:
        T _reg;
        Key _timestamps = 0;


    public:

        T query() const {
            return _reg;
        }

        void set(const T value, const Key timestamps) {
            assert(timestamps > _timestamps);

            _timestamps = timestamps;
            _reg = value;
        }

        void merge(const LWWRegister& other) {
            assert(other._timestamps != _timestamps);

            if(other._timestamps > _timestamps) {
                _reg = other._reg;
                _timestamps = other._timestamps;
            }
        }

    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        friend std::ostream& operator<<(std::ostream& out,
                                        const LWWRegister& o) {
            out << "LWWRegister: " << o.query();
            return out;
        }
};


}} // End namespaces


