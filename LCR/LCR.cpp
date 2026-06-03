#include <iostream>
#include "Libraries.h"
#include "Person.h"
#include "Organizer.h"
#include "Organization.h"
#include "Volunteer.h"
#include "Building.h"
#include "Road.h"
#include "Hygiene.h"
#include "Tool.h"
#include "Tasks.h"

template<typename T>
void createOrganizersFile(const vector<T>& vec) {
    string organizersFileName;
    cin >> organizersFileName;
    organizersFileName += ".txt";

    fstream organizersFile;
    organizersFile.open(organizersFileName, ios::out);

    if (organizersFile.is_open()) {
        organizersFile << "List of organizers:" << endl;
        for (size_t i = 0; i < vec.size(); i++) {
            organizersFile << endl;
            vec[i].Output(organizersFile);
            vec[i].getAddress(organizersFile);
            vec[i].getMoney(organizersFile);
        }
    }
}

template<typename T>
void createVolunteersFile(const vector<T>& vec) {
    string volunteersFileName;
    cin >> volunteersFileName;
    volunteersFileName += ".txt";

    fstream volunteersFile;
    volunteersFile.open(volunteersFileName, ios::out);

    if (volunteersFile.is_open()) {
        volunteersFile << "List of volunteers:" << endl;
        for (size_t i = 0; i < vec.size(); i++) {
            volunteersFile << endl;
            vec[i].Output(volunteersFile);
            vec[i].getDonation(volunteersFile);
        }
    }
}

template<typename T>
void createGenericFile(const vector<T>& vec, string typeName) {
    string fileName;
    cin >> fileName;
    fileName += ".txt";

    fstream file;
    file.open(fileName, ios::out);
    if (file.is_open()) {
        file << "List of " << typeName << ":" << endl;
        for (size_t i = 0; i < vec.size(); i++) {
            file << endl;
            vec[i].Output(file);
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

    vector<Building> buildingVector;
    vector<Road> roadVector;

    vector<Hygiene> hygieneVector;
    vector<Tool> toolVector;

    while (true) {
        if (menu == 1) {
            system("cls");
            cout << "=== Main Menu ===" << endl;
            cout << "1. Manage Platform (People / Targets / Resources)" << endl;
            cout << "2. View & Save Data (Console / Files)" << endl;
            cout << "3. Execute Restoration Task Simulation" << endl;
            cout << "4. Exit" << endl;

            cin >> choice;
            if (choice == 1)      menu = 2;
            else if (choice == 2) menu = 3;
            else if (choice == 3) menu = 6;
            else if (choice == 4) break;
        }
        else if (menu == 2) {
            system("cls");
            cout << "=== Create & Add Elements ===" << endl;
            cout << "1. Add Organizer / Organization" << endl;
            cout << "2. Add Volunteer" << endl;
            cout << "3. Add Repair Target: Building" << endl;
            cout << "4. Add Repair Target: Road" << endl;
            cout << "5. Add Resource: Hygiene Material" << endl;
            cout << "6. Add Resource: Construction Tool" << endl;
            cout << "7. Back to Main Menu" << endl;

            cin >> choice;
            if (choice == 1)      menu = 4;
            else if (choice == 2) menu = 5;
            else if (choice == 3) {
                Building b;
                b.Input(cin);
                buildingVector.push_back(b);
            }
            else if (choice == 4) {
                Road r;
                r.Input(cin);
                roadVector.push_back(r);
            }
            else if (choice == 5) {
                Hygiene h;
                h.Input(cin);
                hygieneVector.push_back(h);
            }
            else if (choice == 6) {
                Tool t;
                t.Input(cin);
                toolVector.push_back(t);
            }
            else if (choice == 7) menu = 1;

            organizationObjectExists = false;
            volunteerObjectExists = false;
        }
        else if (menu == 3) {
            system("cls");
            cout << "=== Display & Save System Records ===" << endl;
            cout << "1. Save data to Text Files (.txt)" << endl;
            cout << "2. Print People to Console" << endl;
            cout << "3. Print Targets (Buildings & Roads) to Console" << endl;
            cout << "4. Print Resources (Hygiene & Tools) to Console" << endl;
            cout << "5. Back to Main Menu" << endl;

            cin >> choice;
            if (choice == 1) {
                system("cls");
                cout << "Choose what to save:\n1. Organizers\n2. Volunteers\n3. Buildings\n4. Roads\n5. Hygiene\n6. Tools\n";
                int fileChoice; cin >> fileChoice;
                cout << "Enter file name (without extension): ";
                if (fileChoice == 1) createOrganizersFile(organizationVector);
                if (fileChoice == 2) createVolunteersFile(volunteerVector);
                if (fileChoice == 3) createGenericFile(buildingVector, "Buildings");
                if (fileChoice == 4) createGenericFile(roadVector, "Roads");
                if (fileChoice == 5) createGenericFile(hygieneVector, "Hygiene");
                if (fileChoice == 6) createGenericFile(toolVector, "Tools");
            }
            else if (choice == 2) {
                cout << "\n--- List of Organizers ---" << endl;
                for (size_t i = 0; i < organizationVector.size(); i++) {
                    organizationVector[i].Output(cout);
                    organizationVector[i].getAddress(cout);
                    organizationVector[i].getMoney(cout);
                }
                cout << "\n--- List of Volunteers ---" << endl;
                for (size_t i = 0; i < volunteerVector.size(); i++) {
                    volunteerVector[i].Output(cout);
                    volunteerVector[i].getDonation(cout);
                    cout << "Task Points: " << volunteerVector[i].getPoints() << "\n";
                }
                cout << "\nPress Enter to continue...";
                cin.ignore(); cin.get();
            }
            else if (choice == 3) {
                cout << "\n--- Buildings ---" << endl;
                for (size_t i = 0; i < buildingVector.size(); i++) buildingVector[i].Output(cout);
                cout << "\n--- Roads ---" << endl;
                for (size_t i = 0; i < roadVector.size(); i++) roadVector[i].Output(cout);
                cout << "\nPress Enter to continue...";
                cin.ignore(); cin.get();
            }
            else if (choice == 4) {
                cout << "\n--- Hygiene Resources ---" << endl;
                for (size_t i = 0; i < hygieneVector.size(); i++) hygieneVector[i].Output(cout);
                cout << "\n--- Tool Resources ---" << endl;
                for (size_t i = 0; i < toolVector.size(); i++) toolVector[i].Output(cout);
                cout << "\nPress Enter to continue...";
                cin.ignore(); cin.get();
            }
            else if (choice == 5) menu = 1;
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
            cout << "=== Organization Details ===" << endl;
            cout << "1. Set Address" << endl;
            cout << "2. Set Needed money" << endl;
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
            else if (choice == 3) menu = 2;
            else if (choice == 4) break;
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
            cout << "=== Volunteering Details ===" << endl;
            cout << "1. Record Donation" << endl;
            cout << "2. Back" << endl;
            cout << "3. Exit" << endl;

            cin >> choice;
            if (choice == 1) {
                cout << "Enter donation: ";
                volunteerVector.back().setDonation();
            }
            else if (choice == 2) menu = 2;
            else if (choice == 3) break;
        }
        else if (menu == 6) {
            system("cls");
            cout << "=== Execute Restoration Task ===" << endl;

            if (volunteerVector.empty() || (buildingVector.empty() && roadVector.empty()) || (hygieneVector.empty() && toolVector.empty())) {
                cout << "ERROR: You need at least 1 Volunteer, 1 Target, and 1 Resource to run a task!\n";
                cout << "Press Enter to return...";
                cin.ignore(); cin.get();
                menu = 1;
                continue;
            }

            cout << "Select Target Type for the task:\n1. Repair a Building\n2. Repair a Road\n";
            int targetType; cin >> targetType;

            cout << "Select Resource Type to use:\n1. Hygiene Materials\n2. Tools\n";
            int resType; cin >> resType;

            cout << "Enter quantity of resource needed: ";
            int neededQty; cin >> neededQty;

            try {
                if (targetType == 1 && resType == 1) {
                    RestorationTask<Building> task(&buildingVector.back(), &volunteerVector.back(), &hygieneVector.back(), neededQty);
                    task.execute();
                }
                else if (targetType == 1 && resType == 2) {
                    RestorationTask<Building> task(&buildingVector.back(), &volunteerVector.back(), &toolVector.back(), neededQty);
                    task.execute();
                }
                else if (targetType == 2 && resType == 1) {
                    RestorationTask<Road> task(&roadVector.back(), &volunteerVector.back(), &hygieneVector.back(), neededQty);
                    task.execute();
                }
                else if (targetType == 2 && resType == 2) {
                    RestorationTask<Road> task(&roadVector.back(), &volunteerVector.back(), &toolVector.back(), neededQty);
                    task.execute();
                }

                cout << "\n[SUCCESS]: Task executed successfully! Volunteer earned 50 points.\n";
            }
            catch (const runtime_error& e) {
                cout << "\n[TASK FAILED]: " << e.what() << endl;
            }

            cout << "Press Enter to return to Main Menu...";
            cin.ignore(); cin.get();
            menu = 1;
        }
    }
    return 0;
}