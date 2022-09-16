#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
    if(this->map.isEmpty()){
        this->current = nullptr;
        return;
    }
    this->current = this->map.root;
    while(current->left != nullptr){
        this->stack.push(this->current);
        this->current = this->current->left;
    }
}

void SMMIterator::first(){
    while(!stack.empty())
        stack.pop();
    if(this->map.isEmpty()){
        this->current = nullptr;
        return;
    }
    this->current = this->map.root;
    while(current->left != nullptr){
        this->stack.push(this->current);
        this->current = this->current->left;
    }
}

void SMMIterator::next(){
	if(!this->valid()){
        throw std::exception();
    }
    if(this->current->right != nullptr){
        this->current = this->current->right;
        while(current->left != nullptr){
            this->stack.push(this->current);
            this->current = this->current->left;
        }
    }
    else if(this->stack.empty())
        this->current = nullptr;
    else{
        this->current = this->stack.top();
        this->stack.pop();
    }
}

bool SMMIterator::valid() const{
	return this->current != nullptr;
}

TElem SMMIterator::getCurrent() const{
    if (this->valid())
        return this->current->elem;
    throw std::exception();
}


