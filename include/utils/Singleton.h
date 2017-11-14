#pragma once


namespace collab {
namespace utils {


/**
 * Any class that inherits from Singleton become itself a singleton.
 *
 * \remark
 * Singleton can't be copied and can't be instanciated (new).
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
template<class T>
class Singleton : private virtual Uncopyable<Singleton<T>> {
    private:
        friend T;

    private:
        Singleton() = default;
        virtual ~Singleton() = default;

    public:
        static Singleton<T> getInstance() {
            static T m_instance;
            return T;
        }
};


} // End namespace
} // End namespace
