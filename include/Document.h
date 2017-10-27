#pragma once

#include "Entity.h"


namespace collab {


class Document {
    private:
        Entity* m_entity = nullptr;

    public:
        Document() = default;
        ~Document() = default;
};


} // End namespace
