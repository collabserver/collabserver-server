#include "collabobject/History.h"

using namespace collab;

void History::clear() {
    while(this->m_mutations.empty()) {
        this->m_mutations.pop();
    }
}
