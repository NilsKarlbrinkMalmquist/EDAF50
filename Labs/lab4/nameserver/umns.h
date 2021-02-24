#ifndef UMNS_H
#define UMNS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "nameserverinterface.h"

using std::string;
using std::unordered_map;

class UMNS: public NameServerInterface {
public:
  void insert(const HostName& name, const IPAddress& ip) override;
  bool remove(const HostName& name) override;
  IPAddress lookup(const HostName& name) const override;
private:
  unordered_map<HostName, IPAddress> addresses;
};

#endif
