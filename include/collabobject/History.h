#pragma once

//class CollabObject;
//class Mutation;

#include "Mutation.h"
#include <stack>


namespace collab {
namespace collabobject {

    class CollabObject;

class History {
    private:
        CollabObject const& m_dataObject;
        //std::stack<collab::collabobject::Mutation> m_mutations;

    public:
        History(CollabObject const& obj);
        ~History() = default;

    public:
        void clear();
};


} // End namespace
} // End namespace
