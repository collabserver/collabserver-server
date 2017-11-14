#include "collabobject/History.h"


using namespace collab::collabobject;


History::History() {
}

void History::clear() {
    while(this->m_mutations.empty()) {
        this->m_mutations.pop();
    }
}
