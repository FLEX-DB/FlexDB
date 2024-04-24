#include "rocksdb/clue_entry_set.h"

namespace ROCKSDB_NAMESPACE{

void Clue_Entry_Set::put(std::string key, std::string value){
    //printf("[DEBUG] put to ce |%d|%s|%s|\n", (int)key.size(), key.c_str(), value.c_str());
    if(value.length() == 0){
        //printf("[DEBUG] in ce set value empty\n");
    }
    else{
        ce_map.insert({key, value});
    }
    //std::lock_guard<std::mutex> lock(mutex);
    
};

std::string Clue_Entry_Set::get(std::string key){
    //printf("[DEBUG] get from ce |%s|\n", key.c_str());
    auto it = ce_map.find(key);
    //printf("[DEBUG] get value from ce |%s|\n", it->second.c_str());
    return it->second;
};

bool Clue_Entry_Set::contains(std::string key){
    return ce_map.find(key) != ce_map.end();
};

bool Clue_Entry_Set::remove(std::string key){
    size_t cnt_rm = ce_map.erase(key);
    if(cnt_rm != 1){
        printf("[DEBUG] ce_set_rm error. not removed exactly 1 ce\n");
        return false;
    }

    return true;
}

int Clue_Entry_Set::size(){
    return ce_map.size();
}

bool Clue_Entry_Set::getOnePair(std::string *key, std::string *value){
    if(ce_map.empty()){
        return false;
    }

    key->assign(ce_map.begin()->first);
    value->assign(ce_map.begin()->second);

    return true;
}


std::unordered_map<std::string, std::string> Clue_Entry_Set::map(){
    return ce_map;
}

} //end of namespace