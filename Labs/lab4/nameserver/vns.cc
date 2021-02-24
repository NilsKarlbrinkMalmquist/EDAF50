#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "vns.h"
#include "nameserverinterface.h"

using std::vector;
using std::string;
using std::pair;

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void VNS::insert(const HostName& name, const IPAddress& ip){
  addresses.push_back(make_pair(name, ip));
  //addresses.emplace_back(name, ip);
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool VNS::remove(const HostName& name){
  auto it = std::remove_if(addresses.begin(), addresses.end(), [name] (const pair<HostName, IPAddress>& pairs){
    return pairs.first == name;
  });
  if(it != addresses.end()){
    addresses.erase(it);
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
IPAddress VNS::lookup(const HostName& name) const{
  auto it = std::find_if(addresses.begin(), addresses.end(), [name] (const pair<HostName, IPAddress>& pairs){
    return pairs.first == name;
  });
  return it != addresses.end() ? it->second : NON_EXISTING_ADDRESS;
}
