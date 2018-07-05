#pragma once

namespace collab {


/***
 * \brief
 * Information and config for a storage service.
 */
class StorageConfig {
    public:
        enum Mode {
            /**
             * In this mode, all operation applied on the CRDT CollabServer data
             * are also sent to the Storage. From the storage place, you will
             * receive operations that are valid in CRDT point of view, but
             * should be applied straight inside the database. (You may receive
             * delete X before create X).
             * This mode may be used if a CRDT replicate runs also on the
             * Storage program side. (Example: file storage that re-write the
             * whole file with the new data content after each operations).
             */
            CRDT_OPERATIONS,

            /**
             * In this mode, only valid operation are sent to the storage.
             * You don't need to run a CRDT replicate on the storage side.
             * You may simple apply each operation you receive on the database.
             */
            LINEAR_OPERATIONS
        };


    public:
        Mode mode;
};


} // End namespace


