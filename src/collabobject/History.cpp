#include "collabobject/History.h"


using namespace collab::collabobject;


History::History(CollabObject const& obj) {
    this->m_dataObject = obj;
}

void History::clear() {
    while(this->m_mutations.empty()) {
        this->m_mutations.pop();
    }
}
