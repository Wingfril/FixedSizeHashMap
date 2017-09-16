//
//  linked.cpp
//

//
//  Created by Ziyan Mo on 9/6/17.
//
// NEED ABS

#include "linked.hpp"

using namespace std;

hashMap::hashMap(long nsize)
{
    //
    array = new hashCell * [nsize];
    size = nsize;
    fullEmpty = new bool [nsize];
    
    for(int i = 0; i<size; i++)
    {
        fullEmpty[i] = false;
        array[i] = NULL;
    }
    
}

bool hashMap::set(string key, void* value)
{
    long hashint = hashstr(key);
    hashint %= size;
    hashint = abs(hashint);
    if(cursize == size)
    {
       return false;
    }
    hashCell * temp = array[hashint];
    hashCell * pair = new hashCell;
    if (temp == NULL)
    {
        pair->key = key;
        pair->value = value;
        array[hashint] = pair;
        fullEmpty[hashint]= true;
        pair->next = NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        pair->key = key;
        pair->value = value;
        temp->next = pair;
        pair->next = NULL;
    }
    cursize ++;
    return true;
    
}

void * hashMap::get(string key)
{
    long hashint = hashstr(key);
    hashint %= size;
    hashint = abs(hashint);
    if (fullEmpty[hashint] == false)
    {
        return 0;
    }
    
    hashCell * temp = array[hashint];
    while(temp->next != NULL)
    {
        if(temp->key != key)
        {
            temp = temp->next;
        }
        else
        {
            return temp->value;
        }
    }
    if (temp->key == key)
    {
        return temp->value;
    }
    return NULL;
}

void hashMap::deleted(string key)
{
    // Create a hashcode. However, depending on the
    // size of the array it is very possible
    // for collisions to occur.
    // We also have to make sure the hashint is
    // positive to not access negative values.
    long hashint = hashstr(key);
    hashint %= size;
    hashint = abs(hashint);
    hashCell * temp = array[hashint];
    hashCell * correctPair;
    while(temp->next != NULL)
    {
        if(temp->next->key == key)
        {
            correctPair = temp->next;
            if(correctPair->next != NULL)
            {
                temp->next = correctPair->next;
            }
            else
            {
                temp->next = NULL;
            }
            cursize --;
            delete correctPair;
            return;
        }
        temp = temp->next;
    }
    temp = NULL;
    fullEmpty[hashint] = false;
    cursize --;
}

float hashMap::load()
{
    return (float)cursize/size;
}
