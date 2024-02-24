#include <stdio.h>
#include <stdlib.h>

struct KeyValuePair {
    int key;
    int value;
};

struct Node {
    struct KeyValuePair* data;
    size_t size;  // current size of the array
    size_t capacity;  // maximum capacity of the array
};

int hashfunction(int key, int table_size) {
    return key % table_size;
}

void initializeHashtable(struct Node* hash[], int tablesize) {
    for (int i = 0; i < tablesize; i++) {
        hash[i] = NULL;
    }
}

void insert(struct Node* hash[], int key, int value, int tablesize) {
    int index = hashfunction(key, tablesize);

    if (hash[index] == NULL) {
        // Initialize a new dynamic array (list) for the key-value pairs
        hash[index] = (struct Node*)malloc(sizeof(struct Node));
        hash[index]->data = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair) * 2); // initial capacity is 2
        hash[index]->size = 0;
        hash[index]->capacity = 2;
    }

    // Check if the array is full and resize if needed
    if (hash[index]->size == hash[index]->capacity) {
        hash[index]->capacity *= 2;
        hash[index]->data =(struct KeyValuePair*) realloc(hash[index]->data, sizeof(struct KeyValuePair) * hash[index]->capacity);
    }

    // Add the new key-value pair to the array
    hash[index]->data[hash[index]->size].key = key;
    hash[index]->data[hash[index]->size].value = value;
    hash[index]->size++;
}

int search(struct Node* hash[], int key, int tablesize) {
    int index = hashfunction(key, tablesize);
    struct Node* current = hash[index];
    if (current == NULL) {
        return -1;  // Return -1 if key not found
    }

    for (size_t i = 0; i < current->size; i++) {
        if (current->data[i].key == key) {
            return current->data[i].value;
        }
    }
    return -1; // Return -1 if key not found
}

int main() {
    const int tablesize = 100;
    struct Node* hash[tablesize];

    // Example usage:
    // Initializing the hash table
    initializeHashtable(hash, tablesize);

    // Inserting key-value pairs
    insert(hash, 5, 42, tablesize);
    insert(hash, 105, 99, tablesize);

    // Searching for a key
    int result = search(hash, 5, tablesize);
    if (result != -1) {
        printf("Value for key 5: %d\n", result);
    } else {
        printf("Key 5 not found.\n");
    }

    result = search(hash, 105, tablesize);
    if (result != -1) {
        printf("Value for key 105: %d\n", result);
    } else {
        printf("Key 105 not found.\n");
    }

    // Free allocated memory
    for (int i = 0; i < tablesize; i++) {
        if (hash[i] != NULL) {
            free(hash[i]->data);
            free(hash[i]);
        }
    }

    return 0;
}
