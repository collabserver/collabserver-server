#pragma once

namespace collab {
namespace utils {


/**
 * Any class that inherits from Uncopyable cannot be copied anymore.
 *
 * \remark
 * In order to disable totally object copy,
 * Copy constructor and copy operator are disabled.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
template<class T>
class Uncopyable {
    public:
        Uncopyable() = default;
        virtual ~Uncopyable() = default;
    private:
        Uncopyable(const Uncopyable<t> &) = delete;
        Uncopyable<T>& operator=(const Uncopyable<T> &) = delete;

};


} // End namespace 1
} // End namespace 2
