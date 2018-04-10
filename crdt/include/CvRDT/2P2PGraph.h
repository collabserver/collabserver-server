#pragma once

#include "2PSet.h"

#include <utility> // std::pair

namespace CRDT {
namespace CvRDT {


template<typename T, typename K>
class TwoPTwoPGraph {
    private:
        class Node {
            K id;
            T content;
            TwoPSet<K> _edges;
        };

        TwoPSet<Node> _vertices;


        //TwoPSet<std::pair<K,T>> _vertices;
        //TwoPSet<std::pair<K,K>> _edges;


    public:
        typedef typename std::set<T>::iterator              iterator;
        typedef typename std::set<T>::const_iterator        const_iterator;


    public:
        /*
        T query_vertex(const K& vertexID) {
            //TODO
            std::set<T> it = _vertices.find(vertexID);
        }
        */
};


}} // End namespaces
