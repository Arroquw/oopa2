#include "NodeFactory.h"
#include <cassert>
#include "Node.h"


NodeFactory::NodeFactory() {
}


NodeFactory::~NodeFactory() {
}

void NodeFactory::assign(const char* szID, Node *base) {
    auto& cmap = GetMap();
    assert(szID != nullptr);
    assert(*szID != '\0');
    assert(cmap.find(szID) == cmap.end());
    cmap[szID] = base;
}

NodeFactory::node_map& NodeFactory::GetMap() {
    static node_map cMap;
    return cMap;
}

Node* NodeFactory::create(const char* szID) {
    auto& cmap = GetMap();
    const node_map::const_iterator iFind = cmap.find(szID);
    if (iFind == cmap.end()) {
        return nullptr;
    }
    return iFind->second->clone();
}
