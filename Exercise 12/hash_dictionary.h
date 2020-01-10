#include <tuple>
#include <list>
#include <cstring>
#include <vector>
#define SIZE 256

using namespace std;

template <typename Key = string, typename V = int>
class hash_dictionary{
private:
    list<tuple<Key, V>> container[SIZE];
    size_t hash_function(const Key&)const;


public:
    void add_element(const Key&, const V&);
    void remove_element(const Key&);
    V find_element(const Key&) const;
    void change_element(const Key&);
    vector<Key> get_keys() const;
    vector<V> get_values() const;
};
