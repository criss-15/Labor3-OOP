#include "L3_Oros_Cristina_DSM.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    DSM dsm = DSM(6); //create a matrix with 6 rows and columns

    cout << "Setter started" << endl;
    //sets the elements to a position
    dsm.set_element_name(0, "Apfel");
    dsm.set_element_name(1, "Banane");
    dsm.set_element_name(2, "Erdbeeren");
    dsm.set_element_name(3, "Orange");
    dsm.set_element_name(4, "Birnen");
    dsm.set_element_name(5, "Kirschen");

    cout << "Size function started" << endl;
    assert(dsm.size() == 6);

    cout << "Getter started" << endl;
    //returns the fruit from a position
    assert(dsm.get_name(1) == "Banane");
    assert(dsm.get_name(2) == "Erdbeeren");
    assert(dsm.get_name(0) == "Apfel");

    cout << "Find index started" << endl;
    //tests find_index function
    assert(dsm.find_index("Birnen") == 4);
    assert(dsm.find_index("Kirschen") == 5);
    assert(dsm.find_index("Apfel") == 0);
    assert(dsm.find_index("Banane") == 1);

    cout << "Add link started" << endl;
    //tests add_link function
    dsm.add_link("Apfel", "Orange", 1); //delete
    dsm.add_link("Birnen", "Kirschen", 2);
    dsm.add_link("Banane", "Kirschen", 3);
    dsm.add_link("Birnen", "Erdbeeren", 2); //delete
    dsm.add_link("Apfel", "Kirschen", 2);
    dsm.add_link("Apfel", "Banane", 3);
    dsm.add_link("Orange", "Banane", 4); //delete


    cout << "Count_to_links started" << endl;
    assert(dsm.count_to_links("Birnen") == 0);
    assert(dsm.count_to_links("Kirschen") == 3);
    assert(dsm.count_to_links("Banane") == 2);

    cout << "Count_from_links" << endl;
    assert(dsm.count_from_links("Apfel") == 3);
    assert(dsm.count_from_links("Banane") == 1);
    assert(dsm.count_from_links("Birnen") == 2);

    cout << "Habe_link" << endl;
    assert(dsm.habe_link("Apfel", "Orange") == true);
    assert(dsm.habe_link("Apfel", "Kirschen") == true);
    assert(dsm.habe_link("Orange", "Banane") == true);

    assert(dsm.habe_link("Banane", "Orange") == false);
    assert(dsm.habe_link("Apfel", "Birnen") == false);
    assert(dsm.habe_link("Orange", "Apfel") == false);

    cout << "Link_weight started" << endl;
    assert(dsm.link_weight("Apfel", "Orange") == 1);
    assert(dsm.link_weight("Birnen", "Kirschen") == 2);
    assert(dsm.link_weight("Banane", "Kirschen") == 3);
    assert(dsm.link_weight("Orange", "Banane") == 4);
    assert(dsm.link_weight("Apfel", "Banane") == 3);

    cout << "Count_all_links started" << endl;
    assert(dsm.count_all_links() == 7);

    cout << "Calculate_matrix_density started" << endl;
    assert(dsm.calculate_matrix_density() == 0.19);

    //tests delete_link function
    cout << "Delete function started" << endl;
    dsm.delete_link("Apfel", "Orange");
    dsm.delete_link("Birnen", "Erdbeeren");
    dsm.delete_link("Orange", "Banane");

    assert(dsm.count_to_links("Kirschen") == 3);
    assert(dsm.count_to_links("Erdbeeren") == 0);
    assert(dsm.count_to_links("Banane") == 1);

    assert(dsm.count_from_links("Kirschen") == 0);
    assert(dsm.count_from_links("Erdbeeren") == 0);
    assert(dsm.count_from_links("Banane") == 1);

    assert(dsm.habe_link("Birnen", "Kirschen") == true);
    assert(dsm.habe_link("Apfel", "Kirschen") == true);
    assert(dsm.habe_link("Apfel", "Banane") == true);

    assert(dsm.habe_link("Birnen", "Erdbeeren") == false);
    assert(dsm.habe_link("Apfel", "Orange") == false);
    assert(dsm.habe_link("Orange", "Banane") == false);

    assert(dsm.link_weight("Birnen", "Kirschen") == 2);
    assert(dsm.link_weight("Banane", "Kirschen") == 3);
    assert(dsm.link_weight("Apfel", "Kirschen") == 2);
    assert(dsm.link_weight("Apfel", "Banane") == 3);

    assert(dsm.count_all_links() == 4);

    assert(dsm.calculate_matrix_density() == 0.11);

    dsm.delete_link("Birnen", "Kirschen");

    assert(dsm.count_all_links() == 3);

    assert(dsm.calculate_matrix_density() == 0.08);

    return 0;
}
