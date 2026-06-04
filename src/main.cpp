#include <iostream>
#include <vector>

using namespace std;


vector<vector<patient>> specialization_array(20 , vector<patient>(5));

struct patient {

    string name;
    bool status;

};

void add_new_patient() {
    int specialization_number;
    string name;
    bool status;

    cin >> specialization_number >> name >> status;

    patient new_patient;

    new_patient.name = name;
    new_patient.status = status;


    if (specialization_array[specialization_number] < 5) {
        
        if (status == true) {
            specialization_array[specialization_number].insert(
                specialization_array[specialization_number].begin(), new_patient);
                cout << "Urgent patient has added to the begin of the list in specialization "
                << specialization_number << "\n";
            }

    }
    
    
}

void start() {
    int choise;
    
    while (true) {
        
        cin >> choise;

        cout << "Enter your choise: \n";
        cout << "1) Add new patient \n";
        cout << "2) Print all patients \n";
        cout << "3) Get the next patient \n";
        cout << "4) Exit \n";

        /* switch (choise) {
            case 1 :

                break;
            case 2 : 

                break;
            case 3 :

                break;

            case 4 :

                break;
            default :

                break;
        }
         */

    }

}

int main() {




    return 0;
}