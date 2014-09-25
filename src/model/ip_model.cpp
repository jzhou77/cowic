/* Cowic is a C++ library to compress formatted log like Apache access log.
 *
 * Cowic is released under the New BSD license (see LICENSE.txt). Go to the
 * project home page for more info:
 *
 * HOMEPAGE_URL
 */
//ip_model.cpp

#include "ip.h"
#include "ip_model.h"

IPModel::IPModel() : AbstractNumberModel(){
}

IPModel::IPModel(const shared_ptr<DictionaryModel>& dictModelPtrVal) 
    : AbstractNumberModel(dictModelPtrVal){
    }

shared_ptr<AbstractNumber> IPModel::parseColumnStr(const string& columnStr){
    IP ip = IP::parse(columnStr);
    return shared_ptr<AbstractNumber>(new IP(ip));
}

string IPModel::toPlainStr(unsigned int num, const string& before, const string& after) const{
    return IP(num, before, after).to_plain_str();
}
    
string IPModel::getModelName() const{
    return "IP";
}
