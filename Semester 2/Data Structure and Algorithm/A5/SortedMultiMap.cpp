#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
    this->root = nullptr;
    this->_size = 0;
    this->relation = r;
}

//O(depth)
void SortedMultiMap::add(TKey c, TValue v) {
    ++this->_size;
    Node* newNode = new Node;
    newNode->elem = std::make_pair(c,v);
	if(this->_size == 1){
        this->root = newNode;
    } else {
        auto current = this->root;
        Node* prev;
        while(true) {
            prev = current;
            if (this->relation(c, current->elem.first)) {
                current = current->left;
                if(current == nullptr){
                    prev->left = newNode;
                    break;
                }
            } else {
                current = current->right;
                if(current == nullptr){
                    prev->right = newNode;
                    break;
                }
            }
        }
    }
}

//O(depth)
vector<TValue> SortedMultiMap::search(TKey c) const {
    std::vector<TValue> result;
    auto current = this->root;
    while(current != nullptr){
        if(current->elem.first == c){
            while(current->elem.first == c){
                result.push_back(current->elem.second);
                current = current->left;
                if(current == nullptr)
                    return result;
            }
            return result;
        } else if (this->relation(c, current->elem.first)) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return result;
}

//O(depth)
bool SortedMultiMap::remove(TKey c, TValue v) {
    if(this->_size == 0)
        return false;
    --this->_size;
    if(this->root->elem.first == c && this->root->elem.second == v){
        Node* current;
        if(this->root->right != nullptr){
            current = this->root->right;
            Node* addLeftPart = this->root->right;
            while(addLeftPart->left != nullptr)
                addLeftPart = addLeftPart->left;
            addLeftPart->left = this->root->left;
        }
        else
            current = this->root->left;
        delete this->root;
        this->root = current;
    } else{
        auto current = this->root;
        Node* prev;
        while(current->elem.first != c || current->elem.second != v){
            prev = current;
            if (this->relation(c, current->elem.first)){
                current = current->left;
            }
            else{
                current = current->right;
            }
            if(current == nullptr){
                ++this->_size;
                return false;
            }
        }
        if(current->left == current->right){
            if(prev->left->elem.first == current->elem.first)
                prev->left = nullptr;
            else
                prev->right = nullptr;
            delete current;
        }
        else if(current->left != nullptr && current->right != nullptr){
            auto nodeToDelete = current;
            current = current->right;
            while(current->left != nullptr)
                current = current->left;
            if(prev->left->elem.first == nodeToDelete->elem.first)
                prev->left = nodeToDelete->right;
            else
                prev->right = nodeToDelete->right;
            current->left = nodeToDelete->left;
            delete nodeToDelete;
        }
        else{
            if(prev->left->elem.first == current->elem.first){
                if(current->left == nullptr)
                    prev->left = current->right;
                else
                    prev->left = current->left;
            }
            else{
                prev->right = nullptr;
                if(current->left == nullptr)
                    prev->right = current->right;
                else
                    prev->right = current->left;
            }
            delete current;
        }
    }
    return true;
}

//O(depth)
void SortedMultiMap::replace(TKey k, TValue oldValue, TValue newValue) {
    if (this->search(k).empty())
        return;
    auto current = this->root;
    while(current != nullptr){
        if(current->elem.first == k){
            while(current != nullptr){
                if(current->elem.second == oldValue)
                    current->elem.second = newValue;
                current = current->left;
            }
            break;
        }
        if (this->relation(k, current->elem.first)){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
}

//Tetha(1)
int SortedMultiMap::size() const {
	return this->_size;
}
//Tetha(1)
bool SortedMultiMap::isEmpty() const {
	return this->_size == 0;
}

//Tetha(1)
SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

//Tetha(size)
SortedMultiMap::~SortedMultiMap() {
    auto it = this->iterator();
    while(it.valid()){
        auto prev = it;
        it.next();
        delete prev.current;
    }
}
