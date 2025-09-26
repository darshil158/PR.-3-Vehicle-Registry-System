#include <iostream>
using namespace std;

class Vehicle {
    private:
        int vehicleID;
        char manufacturer[20];
        char model[20];
        int year;
        static int totalVehicles;

    public:
        Vehicle() {
            vehicleID = 0;
            manufacturer[0] = '\0';
            model[0] = '\0';
            year = 0;
        }

        void setData(int id, const char man[], const char mod[], int y) {
            vehicleID = id;
            int i;
            for (i = 0; man[i] != '\0'; i++) manufacturer[i] = man[i];
            manufacturer[i] = '\0';

            for (i = 0; mod[i] != '\0'; i++) model[i] = mod[i];
            model[i] = '\0';

            year = y;
            totalVehicles++;
        }

        ~Vehicle() { 
            --totalVehicles; 
        }

        void setVehicleID(int id) { vehicleID = id; }
        int getVehicleID() { return vehicleID; }


        void setManufacturer(char man[20]) { manufacturer[20] = man[20]; }
        char getManufacturer() { return manufacturer[20]; }


        void setModel(char mod[20]) { model[20] = mod[20]; }
        char getModel() { return model[20]; }


        void setYear(int y) { year = y; }
        int getYear() { return year; }


        static int getTotalVehicles() { 
            return totalVehicles; 
        }

        void showData() {
            cout << "ID :- " << vehicleID
                << "   Manufacturer :- " << manufacturer
                << "   Model :- " << model
                << "   Year :- " << year << endl;
        }

        static void showTotal() {
            cout << "Total Vehicles Registered: " << totalVehicles << endl;
        }
        int getID() { return vehicleID; }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
    private :
        char fuelType[20];

    public :
        void setCar(int id, const char man[], const char mod[], int yr, const char fuel[]) {
            setData(id, man, mod, yr);

            int i;
            for (i = 0; fuel[i] != '\0'; i++) fuelType[i] = fuel[i];
            fuelType[i] = '\0';
        }

        void showCar() {
            showData();
            cout << "Fuel Type: " << fuelType << endl;
        }
};

class VehicleRegistry {
    private:
        Vehicle* vehicles[20];
        int totalVehicles;

    public:
        VehicleRegistry() {
            totalVehicles = 0;
        }

        void addVehicle() {
            if (totalVehicles < 20) {
                int id, year;
                char man[20], mod[20], fuel[20];

                cout << "Enter Vehicle ID: ";
                cin >> id;
                cout << "Enter Manufacturer: ";
                cin >> man;
                cout << "Enter Model: ";
                cin >> mod;
                cout << "Enter Year: ";
                cin >> year;
                cout << "Enter Fuel Type: ";
                cin >> fuel;

                Car* c = new Car();
                c->setCar(id, man, mod, year, fuel);

                vehicles[totalVehicles] = c;
                totalVehicles++;

                cout << "Vehicle added successfully!\n";
            }
            else {
                cout << "Registry full!\n";
            }
        }

        void showAll() {
            for (int i = 0; i < totalVehicles; i++) {
                vehicles[i]->showData();
            }
        }

        void searchVehicleByNumber(int number) {
            bool found = false;
            for (int i = 0; i < totalVehicles; i++) {
                if (vehicles[i]->getID() == number) {   // use -> instead of .
                    vehicles[i]->showData();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Vehicle with ID " << number << " not found." << endl;
            }
        }
};

int main() {
    VehicleRegistry registry;
    int choice,searchNumber;

    do {
        cout << endl << "---- Vehicle Registry System ----" << endl << endl;
        cout << "1> Add a vehicle (of a different type)" << endl;
        cout << "2> View all vehicles" << endl;
        cout << "3> Search vehicles by Id" << endl;
        cout << "4> Exit" << endl << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter your choice :- ";
        cin >> choice;
        cout << "-----------------------------------------" << endl;

        switch (choice) {
        case 1: 
            registry.addVehicle();
            break;
        case 2:
            registry.showAll();
            break;

        case 3 : // Search vehicles by Number
            cout << "Enter vehicle Number to search :- ";
            cin >> searchNumber;
            registry.searchVehicleByNumber(searchNumber);
            break;
        case 4 : // Exit
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default : // Invalid choice
            cout << "Invalid choice !!! Try again " << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
