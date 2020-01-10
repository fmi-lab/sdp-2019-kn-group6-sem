#include "hash_dictionary.h"
#include<iostream>

template <typename Key, typename V>
size_t hash_dictionary<Key, V>::hash_function(const Key& key)const{
    size_t position = 0;
    for(char c : key){
        position += (int)c;
    }
    position %= 256;
    return position;
}

template <typename Key, typename V>
void hash_dictionary<Key, V>::add_element(const Key& key, const V& value){
    size_t position = hash_function(key);
    container[position].push_back(tuple<Key, V>(key, value));
}

template <typename Key, typename V>
V hash_dictionary<Key, V>::find_element(const Key& key) const{
    size_t position = hash_function(key);
    typename list<tuple<Key, V>>::const_iterator i = container[position].begin();
    while(i != container[position].end()){
        if(get<0>(*i) == key){
            return get<1>(*i);
        }
    i++;
    }
    cout<<"No such element.\n";
}

template <typename Key, typename V>
void hash_dictionary<Key, V>::remove_element(const Key& key){
    size_t position = hash_function(key);
    typename list<tuple<Key, V>>::iterator i = container[position].begin();
    while(i != container[position].end()){
        if(get<0>(*i) == key){
            container[position].erase(i);
            return;
        }
    i++;
    }
    cout<<"No such element.\n";
}

template <typename Key, typename V>
vector<Key> hash_dictionary<Key, V>::get_keys() const{
    vector<Key> keys;
    for(size_t i = 0; i < SIZE; i++){
        for(typename list<tuple<Key, V>>::const_iterator it = container[i].begin(); it != container[i].end(); it++){
            keys.push_back(get<0>(*it));
        }
    }
    return keys;
}

template <typename Key, typename V>
vector<V> hash_dictionary<Key, V>::get_values() const{
    vector<V> values;
    for(size_t i = 0; i < SIZE; i++){
        for(typename list<tuple<Key, V>>::const_iterator it = container[i].begin(); it != container[i].end(); it++){
            values.push_back(get<1>(*it));
        }
    }
    return values;
}

int main(){
    hash_dictionary<> hash_d;
    hash_d.add_element("abc", 123);
    hash_d.add_element("cba", 321);
    hash_d.add_element("ab", 12);
    hash_d.add_element("ac", 13);
    hash_d.add_element("c", 3);
    cout<<hash_d.find_element("abc")<<endl;
    cout<<hash_d.find_element("cba")<<endl;
    cout<<hash_d.find_element("c")<<endl;
    hash_d.remove_element("ab");
    vector<string> keys = hash_d.get_keys();

    for(string key : keys){
        cout<<key<<endl;
    }

    cout<<"---------------\n";
    hash_d.remove_element("cba");

    vector<string> keys2 = hash_d.get_keys();

    for(string key : keys2){
        cout<<key<<endl;
    }

    cout<<"---------------\n";

    vector<int> values = hash_d.get_values();

    for(int value : values){
        cout<<value<<endl;
    }

}

