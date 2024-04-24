#pragma once

#include "rocksdb/rocksdb_namespace.h"
#include "rocksdb/slice.h"

#include <unordered_map>
#include <mutex>

namespace ROCKSDB_NAMESPACE {

class Clue_Entry_Set{
public:
    void put(std::string key, std::string value);
    std::string get(std::string key);
    bool contains(std::string key);
    bool remove(std::string key); //returns true if removed 1 ce;
    bool getOnePair(std::string *key, std::string *value);

    //for debug
    int size();

    std::unordered_map<std::string, std::string> map(void);

    bool rollback = false;

private:
    std::unordered_map<std::string, std::string> ce_map;
    std::mutex mutex;
};

} //end of namespace