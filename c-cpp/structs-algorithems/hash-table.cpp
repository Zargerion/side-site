#include <vector>
#include <list>
#include <iostream>

template<typename K, typename V>
class HashTable {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    size_t size;

    size_t hash(K key) {
        return std::hash<K>{}(key) % table.size();
    }

public:
    HashTable(size_t initialSize = 10) : table(initialSize), size(0) {}

    void insert(K key, V value) {
        size_t index = hash(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
        ++size;
    }

    bool contains(K key) const {
        size_t index = hash(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                return true;
            }
        }
        return false;
    }

    V& operator[](K key) {
        size_t index = hash(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        table[index].emplace_back(key, V{});
        ++size;
        return table[index].back().second;
    }

    size_t getSize() const {
        return size;
    }

    void remove(K key) {
        size_t index = hash(key);
        table[index].remove_if([key](auto& kv) { return kv.first == key; });
    }
};

const int TABLE_SIZE = 100;

class HashTable2 {
public:
    HashTable2() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable2() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void put(const std::string& key, const std::string& value) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    std::string get(const std::string& key) const {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return "";
    }

private:
    struct Node {
        std::string key;
        std::string value;
        Node* next;

        Node(const std::string& key, const std::string& value)
            : key(key), value(value), next(nullptr) {}
    };

    Node* table[TABLE_SIZE];

    int hashFunction(const std::string& key) const {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % TABLE_SIZE;
    }
};

int main ()
{
    HashTable<int, float> table1;
    table1.insert(1, 1.11f);
    std::cout << "table 1 " << table1[1] << "\n";
    
    HashTable2 table2;
    std::string k = "Hi, key!";
    std::string v = "Hi, value!";
    table2.put(k, v);
    std::cout << "table 2 " << table2.get(k) << "\n";
}

