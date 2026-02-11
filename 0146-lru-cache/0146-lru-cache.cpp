class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int size;
    int capacity;
    unordered_map<int, Node*> mp;
    Node* latest = nullptr;  
    Node* oldest = nullptr; 

    void remove(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;
        prev->next = next;
        next->prev = prev;
    }

    void add(Node* node) {
        Node* prev = latest->prev;
        prev->next = node;
        node->prev = prev;
        node->next = latest;
        latest->prev = node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;

        oldest = new Node(0, 0); 
        latest = new Node(0, 0); 

        oldest->next = latest;
        latest->prev = oldest;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        add(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            remove(node);
            add(node);
        } else {
            Node* node = new Node(key, value);
            mp[key] = node;
            add(node);
            size++;

            if (size > capacity) {
                Node* lru = oldest->next;

                remove(lru);
                mp.erase(lru->key);
                delete lru;
                size--;
            }
        }
    }
};
