#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct patient {

    string name;
    bool status;

};



vector<vector<patient>> specialization_array(21);


void add_new_patient() {
    int specialization_number;
    string name;
    bool status;


    cout << "Please enter specialization, name, status \n";
    cin >> specialization_number >> name >> status;

    if (specialization_number > 20 || specialization_number < 0) {
        cout << "please enter specialization between 0 and 20 \n";
        return;
    }

    patient new_patient;

    new_patient.name = name;
    new_patient.status = status;


    if (specialization_array[specialization_number].size() < 5) {
        
        if (status == true) {
            specialization_array[specialization_number].insert(
                specialization_array[specialization_number].begin(), new_patient);
                cout << "Urgent patient has added to the begin of the list in specialization "
                << specialization_number << "\n";
        } else {
            specialization_array[specialization_number].push_back(new_patient);
            cout << "New patient has added to the end of queue in specialization "<<
            specialization_number << "\n";
        }

    } else {
        cout << "sorry, this spectializtion is full \n";
    }   
}

void print_all_patients() {
    for (int i =0; i < 21; ++i) {
        if (!specialization_array[i].empty()) {
            cout << "*********************************** \n";
            cout << "There are " << specialization_array[i].size() <<
            " in specialization " << i << " \n";
            
            for (int j =0; j < specialization_array[i].size(); ++j ) {
                cout << specialization_array[i][j].name << "\n";
            }
        }
    }
}

void get_next_patient() {
    int sepcialization_num;

    cout << "Enter Specialization : ";
    cin >> sepcialization_num;
    if (sepcialization_num < 0 || sepcialization_num > 20) {
        cout << "Invalid specialization number!\n";
        return;
    }

    cout << "\n";
    if(specialization_array[sepcialization_num].empty()) {
        cout << "There is no patients at the moment, take a rest dr.\n";
    } else {
        cout << specialization_array[sepcialization_num].front().name 
        << " please go to the dr \n";
        specialization_array[sepcialization_num].erase(specialization_array[sepcialization_num].begin());
    }
}




void start() {

    bool system_running = true;

    while (system_running) {

        int choise;
        cout << "Enter your choise: \n";
        cout << "1) Add new patient \n";
        cout << "2) Print all patients \n";
        cout << "3) Get the next patient \n";
        cout << "4) Exit \n";
        cin >> choise;


        switch (choise) {
            case 1 :
                add_new_patient();
                break;
            case 2 : 
                print_all_patients();
                break;
            case 3 :
                get_next_patient();
                break;

            case 4 :
                cout << "Exiting... \n";
                system_running = false;
                break;
            default :
                cout << "Invalid choice!\n";
                cout << "You can choose only from 1 to 4 \n";
                break;
        }
    }
}

int main() {

    start();

    return 0;
}