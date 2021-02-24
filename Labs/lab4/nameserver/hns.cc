#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "hns.h"
#include "nameserverinterface.h"

using std::string;
using std::map;

HNS::HNS(size_t s) : size(s) {
  addresses.reserve(size);
}

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void HNS::insert(const HostName& name, const IPAddress& ip){
  auto i = std::hash<HostName>()(name) % size;
  addresses[i].push_back(std::pair<HostName, IPAddress>(name, ip));
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool HNS::remove(const HostName& name){
  auto i = std::hash<HostName>()(name) % size;
  auto it = std::remove_if(addresses[i].begin(), addresses[i].end(), [name] (const pair<HostName, IPAddress>& pairs){
    return pairs.first == name;
  });
  if(it != addresses[i].end()){
    addresses[i].erase(it);
    return true;
  }
  else{
    return false;
  }
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress HNS::lookup(const HostName& name) const{
  auto i = std::hash<HostName>()(name) % size;
  auto it = std::find_if(addresses[i].begin(), addresses[i].end(), [name] (const pair<HostName, IPAddress>& pairs){
    return pairs.first == name;
  });
  return it != addresses[i].end() ? it->second : NON_EXISTING_ADDRESS;
}
