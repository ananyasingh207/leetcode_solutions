class LRUCache {
public:

    struct Node {
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

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head; // dummy head
    Node* tail; // dummy tail

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head = MRU
    void insertFront(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove node from wherever it is
    void remove(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move to front = MRU
        remove(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // Make it MRU
            remove(node);
            insertFront(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;

        // New node = MRU
        insertFront(node);

        // Capacity exceeded
        if(mp.size() > capacity) {

            // Node before dummy tail = LRU
            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */