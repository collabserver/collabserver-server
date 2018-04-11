#pragma once

#include "GMap.h"

#include <ostream>

namespace CRDT {
namespace CvRDT {


/**
 * Grow-only Graph.
 * CvRDT (State-based)
 *
 * \warning
 * Data type T must work with std::max (is_arithmetic == true)
 *
 *
 * \tparam T Data type on a vertex
 * \tparam K ID type (unique for each vertex).
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template<typename K = std::string, typename T = int>
class GGraph {

    // TODO: To cleanup

    private:

        struct _Vertex {
            public:
            const K _id;
            T _content;
            GSet<K> _edges;

            friend bool operator==(const _Vertex& lhs, const _Vertex& rhs) {
                return lhs._id == rhs._id;
            }

            friend bool operator!=(const _Vertex& lhs, const _Vertex& rhs) {
                return !(lhs == rhs);
            }

            friend bool operator<(const _Vertex& lhs, const _Vertex& rhs) {
                //return lhs._content < rhs._content;
                return true; // TODO TMP
            }

            friend bool operator>(const _Vertex& lhs, const _Vertex& rhs) {
                return !(lhs < rhs);
            }
        };

        GMap<K,_Vertex> _adj;


    public:
        typedef typename GMap<K,_Vertex>::iterator          iterator;
        typedef typename GMap<K,_Vertex>::const_iterator    const_iterator;


    public:

        void addVertex(const K& id, const T& value) {
            _adj.insert({id, {id, value, {}}});
        }

        void addEdge(const K& src, const K& dest) {
            if(src == dest) {
                return;
            }
            if(_adj.count(src) == 1 && _adj.count(dest) == 1) {
                _Vertex& v = _adj[src];
                v._edges.insert(dest);
            }
        }

        void merge(const GGraph<K,T>& other) {
            // TODO
            //_adj.merge(other._adj);
        }

    public:

        friend bool operator==(const GGraph& lhs, const GGraph& rhs) {
            return lhs._adj == rhs._adj;
        }

        friend bool operator!=(const GGraph& lhs, const GGraph& rhs) {
            return !(lhs == rhs);
        }

        friend std::ostream& operator<<(std::ostream& out,
                                        const GGraph<K,T>& o) {
            out << "GGraph = {\n";
            for(const_iterator it = o._adj.cbegin(); it != o._adj.cend(); ++it) {
                _Vertex v = it->second;
                out << it->first << " (" << v._content << ") -> ";
                for(const auto& elt : v._edges) {
                    out << elt << " ";
                }
                out << "\n";
            }
            out << "}";
            return out;
        }
};


}} // End namespaces
