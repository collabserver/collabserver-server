#pragma once

#include "Uncopyable.h"


namespace collab {


/**
 * Singleton interface.
 * Any class that inherits from Singleton is not more instanciable.
 * Singleton can't be copied nor instanciated (ex: new).
 *
 * \note
 * Example to implement a singleton class A:
 *
 * \code{.cpp}
 * class A : private Singleton<A> {
 *     private:
 *         friend Singleton<A>;
 *         A() = default;
 *
 *      public:
 *          using Singleton<A>::getInstance;
 *          void initialize() override;
 *          void destroy() override;
 * };
 * \endcode
 *
 *
 * \author  Constantin Masson
 * \since   0.1.0
 * \date    Nov 2017
 */
template <class T>
class Singleton : private Uncopyable<Singleton<T>> {
    private:
        friend T;
        Singleton() = default;
        virtual ~Singleton() = default;

    public:
        static T& getInstance() {
            static T m_instance;
            return m_instance;
        }
};


} // End namespace
