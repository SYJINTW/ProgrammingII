#include <string>
using namespace std;

namespace oj {
    struct Node {
        int val;
        Node *lc; // left child
        Node *rc; // right child
        Node(int v) : val(v), lc(nullptr), rc(nullptr) {} // init to null when created
    };

    class BST {
        private:
            Node *root;
        
        public:
            BST(); // constructor, does what needs to be done when created
            ~BST();  // destructor, doest what needs to be done when destroyed
            void insert(int);
            void erase(int);
            string inorder(); 
    };
};  // namespace oj

