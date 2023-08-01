/////////////////////////////////////////////////////////////////////////////
// Name:        daemonLinkedList.hpp
// Purpose:     daemon linked list implementation
// Author:      Lukas Jackson
// Modified by:
// Created:     6/7/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
/*
Linked list which will contain the daemon history.

In the future a feature will be added to log the history to a file(.txt)

*/

#ifndef DAEMONLINKEDLIST_HPP_
#define DAEMONLINKEDLIST_HPP_

//System includes
#include<stdio.h>
#include<iostream>

template <class T>
class Node{
    public:
    typedef T value_type;
    typedef T& reference_type;
    typedef T const& const_reference_type;
    typedef T* pointer_type;
    typedef T const* const_pointer_type;

    Node():m_next(nullptr){
        m_value = value_type();
    }

    Node(value_type value){
        this->m_value = value;
        this->m_next = nullptr;
    }

    public:
    value_type m_value;
    Node* m_next;
};

template <class T>
class List: public Node<T>
{
    public:
    
    typedef Node<T> node_type;
    typedef node_type* pointer_type;

        typedef typename node_type::value_type value_type;
        typedef typename node_type::reference_type reference_type;
        typedef typename node_type::const_reference_type const_reference_type;
        //typedef typename node_type::pointer_type pointer_type;
        
        pointer_type head;

        pointer_type getHead(){
            return head;
        }
        
        List():head(nullptr){}

        void add(pointer_type data){
            pointer_type newNode = new node_type(data);
            if(head == nullptr){
                head = newNode;
            }
            else{
                pointer_type current = head;
                while(current->m_next != nullptr){
                    current = current->m_next;
                }
                current->m_next = newNode;
            }
        }

        void add(reference_type data){
            pointer_type newNode = new node_type(data);
            if(head==nullptr){
                head = newNode;
            }
            else{
                pointer_type current = head;
                while(current->m_next!=nullptr){
                    current = current->m_next;
                }
                current->m_next = newNode;
            }
        }

        [[nodiscard]] bool empty()const noexcept{
            pointer_type head;
            if(head->m_next == head) return true;
            else return false;
        }

        void printHistory(List& list) noexcept{
            pointer_type current = head = list.getHead();
            while(current!=nullptr){
                std::cout<<current->m_value<<"\n";
                current = current->m_next;
                std::cout<<"";
            }
            printf("\n");
        }//Add printAllhistory function that prints everything including commands used.
};
#endif //DAEMONLINKEDLIST_H_
