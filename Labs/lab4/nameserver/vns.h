#ifndef VNS_H
#define VNS_H

#include <iostream>
#include <string>
#include <vector>
#include "nameserverinterface.h"

using std::string;
using std::vector;
using std::pair;

class VNS: public NameServerInterface {
public:
  void insert(const HostName& name, const IPAddress& ip) override;
  bool remove(const HostName& name) override;
  IPAddress lookup(const HostName& name) const override;
private:
  vector<pair<HostName, IPAddress>> addresses;
};

#endif
