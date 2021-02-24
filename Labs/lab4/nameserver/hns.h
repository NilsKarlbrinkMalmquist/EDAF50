#ifndef HNS_H
#define HNS_H

#include <iostream>
#include <string>
#include <vector>
#include "nameserverinterface.h"

using std::string;
using std::vector;
using std::pair;
using std::size_t;

class HNS: public NameServerInterface {
public:
  HNS(size_t s);
  void insert(const HostName& name, const IPAddress& ip) override;
  bool remove(const HostName& name) override;
  IPAddress lookup(const HostName& name) const override;
private:
  size_t size;
  vector<vector<pair<HostName, IPAddress>>> addresses;
};

#endif
