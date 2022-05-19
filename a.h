struct HashTable* create();
unsigned int hash(const char* key);
bool add(struct HashTable* table, const char* key, int value);
struct Binding* find(struct HashTable* table, const char* key);
bool remover(struct HashTable* table, const char* key);
void delete_table(struct HashTable* table);
