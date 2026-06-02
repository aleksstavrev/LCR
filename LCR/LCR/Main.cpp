#include <iostream>
#include "Libraries.h"
#include "Person.h"
#include "Organizer.h"
#include "Organization.h"
#include "Volunteer.h"

template<typename T>
void createOrganizersFile(vector<T> vector) {
    string organizersFileName;
    cin >> organizersFileName;
    organizersFileName += ".txt";

    fstream organizersFile;

    organizersFile.open(organizersFileName, ios::out);

    if (organizersFile.is_open()) {
        organizersFile << "List of organizers:" << endl;

        for (int i = 0; i < vector.size(); i++) {
            organizersFile << endl;
            vector[i].Output(organizersFile);
            vector[i].getAddress(organizersFile);
            vector[i].getMoney(organizersFile);
        }
    }
}

template<typename T>
void createVolunteersFile(vector<T> vector) {
    string volunteersFileName;
    cin >> volunteersFileName;
    volunteersFileName += ".txt";

    fstream volunteersFile;

    volunteersFile.open(volunteersFileName, ios::out);

    if (volunteersFile.is_open()) {
        volunteersFile << "List of volunteers:" << endl;

        for (int i = 0; i < vector.size(); i++) {
            volunteersFile << endl;
            vector[i].Output(volunteersFile);
            vector[i].getDonation(volunteersFile);
        }
    }
}

int main() {
    int choice;
    int menu = 1;

    vector<Organization> organizationVector;
    bool organizationObjectExists = false;

    vector<Volunteer> volunteerVector;
    bool volunteerObjectExists = false;

    while (true) {
        if (menu == 1) {
            system("cls");

            cout << "=== Main Menu ===" << endl;
            cout << "1. Choose position" << endl;
            cout << "2. List people" << endl;
            cout << "3. Exit" << endl;

            cin >> choice;

            if (choice == 1) {
                menu = 2;
            }
            else if (choice == 2) {
                menu = 3;
            }
            else if (choice == 3) {
                break;
            }
        }
        else if (menu == 2) {
            system("cls");

            cout << "=== Choose Position ===" << endl;
            cout << "1. Organizer" << endl;
            cout << "2. Volunteer" << endl;
            cout << "3. Back" << endl;
            cout << "4. Exit" << endl;

            cin >> choice;

            if (choice == 1) {
                menu = 4;
            }
            else if (choice == 2) {
                menu = 5;
            }
            else if (choice == 3) {
                menu = 1;
            }
            else if (choice == 4) {
                break;
            }

            organizationObjectExists = false;
            volunteerObjectExists = false;
        }
        else if (menu == 3) {
            system("cls");

            cout << "=== List people ===" << endl;
            cout << "1. Save organizers to file" << endl;
            cout << "2. Save volunteers to file" << endl;
            cout << "3. Print organizers to console" << endl;
            cout << "4. Print volunteers to console" << endl;
            cout << "5. Back" << endl;
            cout << "6. Exit" << endl;

            cin >> choice;

            if (choice == 1) {
                cout << "Enter file name: ";

                createOrganizersFile(organizationVector);
            }
            else if (choice == 2) {
                cout << "Enter file name: ";

                createVolunteersFile(volunteerVector);

            }
            else if (choice == 3) {
                cout << "List of organizers:" << endl;

                for (int i = 0; i < organizationVector.size(); i++) {
                    cout << endl;
                    organizationVector[i].Output(cout);
                    organizationVector[i].getAddress(cout);
                    organizationVector[i].getMoney(cout);
                }

                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }
            else if (choice == 4) {
                cout << "List of volunteers:" << endl;

                for (int i = 0; i < volunteerVector.size(); i++) {
                    cout << endl;
                    volunteerVector[i].Output(cout);
                    volunteerVector[i].getDonation(cout);
                }

                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }
            else if (choice == 5) {
                menu = 1;
            }
            else if (choice == 6) {
                break;
            }
        }
        else if (menu == 4) {
            system("cls");

            if (!organizationObjectExists) {
                Organization organizationObject;

                organizationObject.Input(cin);

                organizationVector.push_back(organizationObject);

                organizationObjectExists = true;
            }

            system("cls");

            cout << "=== Organization ===" << endl;
            cout << "1. Address" << endl;
            cout << "2. Needed money" << endl;
            cout << "3. Back" << endl;
            cout << "4. Exit" << endl;

            cin >> choice;

            if (choice == 1) {
                cout << "Enter address: ";
                organizationVector.back().setAddress();
            }
            else if (choice == 2) {
                cout << "Enter needed money: ";
                organizationVector.back().setMoney();
            }
            else if (choice == 3) {
                menu = 2;
            }
            else if (choice == 4) {
                break;
            }
        }
        else if (menu == 5) {
            system("cls");

            if (!volunteerObjectExists) {
                Volunteer volunteerObject;

                volunteerObject.Input(cin);

                volunteerVector.push_back(volunteerObject);

                volunteerObjectExists = true;
            }

            system("cls");

            cout << "=== Volunteering ===" << endl;
            cout << "1. Donate" << endl;
            cout << "2. Back" << endl;
            cout << "3. Exit" << endl;

            cin >> choice;

            if (choice == 1) {
                cout << "Enter donation: ";
                volunteerVector.back().setDonation();
            }
            else if (choice == 2) {
                menu = 2;
            }
            else if (choice == 3) {
                break;
            }
        }
    }
}