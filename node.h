#ifndef NODE_H
#define NODE_H


template<typename T>
struct node
{
    T data;
    node<T>* right;
    node<T>* left;
    node();
    node(T data);
    ~node();

};



template<typename T>
node<T>::node()
{
    left = right = nullptr;
}

template<typename T>
node<T>::~node()
{

}

template<typename T>
node<T>::node(T data)
{
    this->data = data;
    left=right=nullptr;
}


#endif

