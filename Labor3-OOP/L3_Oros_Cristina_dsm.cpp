#include "L3_Oros_Cristina_DSM.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include<cmath>
using namespace std;

//constructor
DSM::DSM(int elementCount)
{
    this->elementCount = elementCount;
    this->weight_matrix = new int *[elementCount];
    this->element_names.resize(this->elementCount, "");
    for (int i=0; i<elementCount; i++)
        this->weight_matrix[i] = new int [this->elementCount];
   
    for (int i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            this->weight_matrix[i][j] = 0;

    if (elementCount <= 0 || elementCount == 1)
        throw exception();
}

//constructor
DSM::DSM(vector<string> element_names)
{
    //this->elementCount = elementCount;
    this->element_names = element_names;
    this->element_names.resize(this->elementCount, "");
    this->elementCount = element_names.size();
    this->weight_matrix = new int *[elementCount];
}

//copy-constructor
DSM::DSM(const DSM &other)
{
    elementCount = other.elementCount;
    weight_matrix = new int *[other.elementCount];
    element_names = other.element_names;
    for (int i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            weight_matrix[i][j] = other.weight_matrix[i][j];
}

//destructor
DSM::~DSM()
{
    delete[] weight_matrix;
}

//setter
void DSM::set_element_name(int index, string name)
{
    this->element_names[index] = name;
    if (index == this->elementCount || index < 0)
        throw exception();
}


//getter
string DSM::get_name(int index)
{
    return this->element_names[index];
    if (index == this->elementCount || index < 0)
        throw exception();
}

//method that finds the index of an element
int DSM::find_index(string element)
{
    int i;
    for (int i = 0; i < elementCount; i++)
        if (element_names[i] == element)
            return i;
    return -1;
}
//returns the size of the matrix
int DSM::size()
{
    return elementCount;
}

//method that adds a link between two elements
void DSM::add_link(string from_element, string to_element, int weight)
{
    int from_index = find_index(from_element);
    int to_index = find_index(to_element);

    if (from_index != -1 && to_index != -1)
        
    {
        this->weight_matrix[from_index][to_index] = weight;
    }

    else 
    {
        throw exception();
    }
}
//method that deletes a link between two elements
void DSM::delete_link(string from_element, string to_element)
{
    int from_index = find_index(from_element);
    int to_index = find_index(to_element);
    if (from_index != -1 && to_index != -1)
        
        this->weight_matrix[from_index][to_index] = 0;

    else
    {
        throw exception();
    }
}


//method that counts all to links
int DSM::count_to_links(string element_name)
{
    int to_index = find_index(element_name);
    int counter = 0;
    for (int i = 0; i < this->elementCount; i++)
    
        if (this->weight_matrix[i][to_index] != 0)
            counter++;
    
       
    return counter;
}

//method that counts all from links
int DSM::count_from_links(string element_name)
{
    int from_index = find_index(element_name);
    int counter = 0;
    for (int i = 0; i < this->elementCount; i++)
        if (this->weight_matrix[from_index][i] != 0)
            counter++;
    return counter;
}

//method that verifies if a link exists
bool DSM::habe_link(string from_element, string to_link)
{
    int from_index = find_index(from_element);
    int to_index = find_index(to_link);
    if (this->weight_matrix[from_index][to_index] != 0)
        return true;
    return false;
}

//method that returns the weight
int DSM::link_weight(string from_element, string to_link)
{
    int from_index = find_index(from_element);
    int to_index = find_index(to_link);
    if (from_index != -1 && to_index != -1)
        return this->weight_matrix[from_index][to_index];
    else
    {
        throw exception();
    }
}

//counts all links
int DSM::count_all_links()
{
    int counter = 0;
    for (int i = 0; i < this->elementCount; i++)
        for (int j = 0; j < this->elementCount; j++)
            if (this->weight_matrix[i][j] != 0)
                counter++;
    return counter;
}
//returns the matrix density
double DSM::calculate_matrix_density()
{
    double total_links;
    double density;
    total_links = count_all_links();
    density = total_links / (this->elementCount * this->elementCount);
    density=floor(density*100)/100;
    return density;
}