#pragma once

#include <map>
#include <utility> // std::pair

namespace CRDT {
namespace CmRDT {


/**
 * Last-Writer-Wins Map (LWW Map).
 * CmRDT (Operation-based)
 *
 *
 * \tparam T    Type of element.
 * \tparam Key  Type of key.
 * \tparam U    Type of timestamp.
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
template<typename Key, typename T, typename U>
class LWWMap {
    private:
        /*
         * This map only keep metadata about each element in map
         */
        std::map<Key,std::pair<U,bool>> _meta; // bool=true if removed
        std::map<Key,T> _map;

    public:
        typedef typename std::map<Key,T>::const_iterator  const_iterator;
        typedef typename std::map<Key,T>::size_type       size_type;
        typedef typename std::map<Key,T>::value_type      value_type;


    // -------------------------------------------------------------------------
    // Modifier
    // -------------------------------------------------------------------------

    public:

        /**
         * Inserts element into the container, if the container
         * doesn't already contain an element with an equivalent key.
         *
         * \param value {key, data} to add.
         */
        void insert(const value_type& value, const U& stamp) {
            //TODO get elt
            // if no elt
            //      add
            // else
            //      if stamp > current -> add
            //      else -> nothing
            //
            //_map.insert(value);
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        /**
         * Check if lhs and rhs are equals.
         * Two LWWMap are equal if their internal map are equal.
         *
         * \return True if equal, otherwise, return false.
         */
        friend bool operator==(const LWWMap& lhs, const LWWMap& rhs) {
            return lhs._map == rhs._map;
        }

        /**
         * Check if lhs and rhs are not equals.
         * See operator == for further information about equality meaning.
         *
         * \return True if not equal, otherwise, return false.
         */
        friend bool operator!=(const LWWMap& lhs, const LWWMap& rhs) {
            return !(lhs._map == rhs._map);
        }

        /**
         * Display the internal map content.
         * This is mainly for debug print purpose.
         */
        friend std::ostream& operator<<(std::ostream& out, const LWWMap<Key,T,U>& o) {
            out << "CmRDT::LWWMap = Not Implemented Yet";
            /*
             * TODO
             *
            for(const std::pair<Key,T>& elt : o._map) {
                out << "(" << elt.first << "," << elt.second << ") ";
            }
            */
            return out;
        }
};


}} // End namespace


