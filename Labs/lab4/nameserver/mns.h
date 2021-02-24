#ifndef MNS_H
#define MNS_H

#include <iostream>
#include <string>
#include <map>
#include "nameserverinterface.h"

using std::string;
using std::map;

class MNS: public NameServerInterface {
public:
  void insert(const HostName& name, const IPAddress& ip) override;
  bool remove(const HostName& name) override;
  IPAddress lookup(const HostName& name) const override;
private:
  map<HostName, IPAddress> addresses;
};

#endif
