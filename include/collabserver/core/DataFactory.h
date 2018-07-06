#pragma once

#include <cassert>

#include "collabdata/custom/SimpleGraph.h"

namespace collab {


/**
 * \brief
 * Factory to create any collab data supported by the server.
 */
class DataFactory {
    public:

        /** List all supported data for this server. */
        enum DataTypeID : int {
            DEFAULT_DATA = 1,
            SIMPLE_GRAPH
        };

    private:
        DataFactory() = delete;
        DataFactory(const DataFactory& other) = delete;
        DataFactory& operator=(const DataFactory& other) = delete;

    public:

        /**
         * Create a new CollabData according to given ID.
         * Data is created on the heap (new).
         * You must release the memory later.
         *
         * \param id The ID of CollabData to create.
         * \return Pointer to the created data or nullptr if error.
         */
        static CollabData* newDataByID(const int id) {
            switch(id) {
                case DEFAULT_DATA:
                case SIMPLE_GRAPH:
                    return new SimpleGraph();

                default:
                    return nullptr;
            }
        }

        /**
         * Release the memory used by data.
         * This basically free the data pointer, don't use it anymore.
         *
         * \param data CollabData pointer to free.
         */
        static void releaseData(CollabData* data) {
            assert(data != nullptr);
            if(data != nullptr) {
                delete data;
            }
        }
};


} // End namespace


