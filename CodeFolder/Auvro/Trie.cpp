//Trie:
typedef struct Node{
    Node* next[26];
    bool endmark;
    Node(){
        endmark = false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
} Node;

class Trie{
private:
    Node* root;

public:
    Trie(){ root = new Node(); }

    void insert(string word){
        Node* node = root;
        for(int i=0; i < word.size(); i++){
            if(node->next[word[i] - 'a'] == NULL){
                node->next[word[i] - 'a'] = new Node();
            }
            node = node->next[word[i] - 'a'];
        }
        node->endmark = true;
    }

    bool search(string word) {
        Node* node = root;
        for(int i=0; i < word.size(); i++){
            if(node->next[word[i] - 'a'] == NULL){
                return false;
            }
            node = node->next[word[i] - 'a'];
        }
        return node->endmark == true;
    }

    Node* startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i < prefix.size(); i++){
            if(node->next[prefix[i] - 'a'] == NULL){
                return NULL;
            }
            node = node->next[prefix[i] - 'a'];
        }
        return node;
    }

    void display(Node* curr, string prefix) {
        if(curr->endmark == true){
            cout<<prefix<<" ";
        }

        for(int i=0; i<26; i++){
            if(curr->next[i] != NULL){
                char nextChar = i + 'a';
                display(curr->next[i], prefix+nextChar);
            }
        }
    }

    void displayAll() { display(root, ""); }

    void destroyTrie(Node* curr){
        for(int i=0; i<26; i++){
            if(curr->next[i])
                destroyTrie(curr->next[i]);
        }

        delete(curr);
    }
};
