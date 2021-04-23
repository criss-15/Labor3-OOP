#include <iostream>
using namespace std;
#include <string>
#include <vector>

class DSM
{


private:
    int elementCount;
    vector<string> element_names;
    int** weight_matrix;
    
        
public:
    //constructor
    DSM(int elementCount);
    DSM(vector<string> element_names);
    DSM(const DSM& other);
    ~DSM();

    //methoden
    int size();//done
    void set_element_name(int index, string name);
    string get_name(int index);
    void add_link(string from_element, string to_element, int weight);

    void delete_link(string from_element, string to_element);
    int find_index(string name);
    //Analyse-methoden
    bool habe_link(string from_element, string to_link);
    int link_weight(string from_element, string to_link);
    int count_to_links(string element_name);
    int count_from_links(string element_name);

    //Bestimmung von Eigenschaften
    int count_all_links();
    double calculate_matrix_density();



};