#pragma once

#include <cassert>


namespace CRDT {
namespace CmRDT {


/**
 * Last-Writer-Wins Register (LWW Register).
 * CmRDT (Operation-based).
 *
 * Timestamp is assigned to each update and creates a total order of updates.
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
 * Timestamps must have a total order.
 * Two equal timestamps (t1 == t1 returns true) is undefined and replicated
 * may diverge. (See implementation).
 * (Ex: use a mix of datetime + user id for instance).
 *
 *
 * \tparam T    Type of element.
 * \tparam Key  Timestamps key.
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
template<typename T, typename Key>
class LWWRegister {
    private:
        T   _reg;
        Key _timestamp = 0;

    public:
        /**
         * Get a copy of the current register value.
         *
         * \return Copy of the register content.
         */
        T query() const {
            return _reg;
        }

        /**
         * Get a reference to the current register value.
         *
         * \return Reference to the register content.
         */
        T& query() {
            return _reg;
        }

        /**
         * Change the local register value. (Downstream update).
         * Do nothing if given stamp is less or equal to the current timestamps.
         * (There are no preconditions, so update always returns true).
         *
         * \param value New value for this register.
         * \param stamp Associated timestamp
         * \return True if precondition was true, otherwise, returns false.
         */
        bool update(const T& value, const Key& stamp) {
            assert(stamp != _timestamp);

            if(stamp > _timestamp) {
                _reg = value;
                _timestamp = stamp;
                return true;
            }
            return true; // Because no pre-condition
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        /**
         * Check if two registers are equal.
         * Register data and timestamp must be equal for registers to be equal.
         *
         * \return True if equal, otherwise, return false.
         */
        friend bool operator==(const LWWRegister& lhs, const LWWRegister& rhs) {
            return (lhs._reg == rhs._reg) && (lhs._timestamp == rhs._timestamp);
        }

        /**
         * Check if two registers are different.
         * See operator== for equality meaning.
         *
         * \return True if not equal, otherwise, return false.
         */
        friend bool operator!=(const LWWRegister& lhs, const LWWRegister& rhs) {
            return !(lhs == rhs);
        }

        /**
         * Display the register value.
         * This is mainly for debug print purpose.
         */
        friend std::ostream& operator<<(std::ostream& out,
                                        const LWWRegister& o) {
            out << "CmRDT::LWWRegister: " << o.query();
            return out;
        }
};


}} // End namespaces


