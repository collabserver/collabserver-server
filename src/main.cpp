#include <iostream>


#define LOG(msg) std::cout << msg << std::endl;

int main(int argc, char** argv) {

#ifdef _DEBUG
    LOG("_DEBUG")
#endif

#ifdef NDEBUG
    LOG("NDEBUG")
#endif

    return 0;
}
