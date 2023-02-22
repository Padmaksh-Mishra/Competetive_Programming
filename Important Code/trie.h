const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    int count;
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
        isEndOfWord = false;
        count = 0;
    }
};

// trie data structure
class Trie {
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    // insert a word into the trie
    void insert(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
            pCrawl->count++;
        }
        pCrawl->isEndOfWord = true;
    }

    // search for a word in the trie
    bool search(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }
    ll lcs(string word) {
        TrieNode *pCrawl = root;
        ll ans = 0;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return ans;
            pCrawl = pCrawl->children[index];
            if(pCrawl->count<2){
            	return ans;
            }else ans++;
        }
        return ans;
    }
};