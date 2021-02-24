#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "mns.h"
#include "nameserverinterface.h"

using std::string;
using std::map;

/*
 * Insert a name/address pair. Does not check if the name
 * or address already exists.
 */
void MNS::insert(const HostName& name, const IPAddress& ip){
  addresses.insert({name, ip});
  //addresses.insert(std::pair<HostName, IPAddress>(name, ip));
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool MNS::remove(const HostName& name){
  auto it = addresses.find(name);
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
IPAddress MNS::lookup(const HostName& name) const{
  auto it = addresses.find(name);
  return it != addresses.end() ? it->second : NON_EXISTING_ADDRESS;
}
