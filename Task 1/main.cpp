#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double COMPONENT_PRICE = 200.00;

// Define item codes, descriptions, and prices
string caseCodes[] = {"A1", "A2"};
string caseDescriptions[] = {"Compact", "Tower"};
double casePrices[] = {75.00, 150.00};

string ramCodes[] = {"B1", "B2", "B3"};
string ramDescriptions[] = {"8 GB", "16 GB", "32 GB"};
double ramPrices[] = {79.99, 149.99, 299.99};

string hddCodes[] = {"C1", "C2", "C3"};
string hddDescriptions[] = {"1 TB HDD", "2 TB HDD", "4 TB HDD"};
double hddPrices[] = {49.99, 89.99, 129.99};

int displayOptions(string category, string itemCodes[], string itemDescriptions[], double itemPrices[], int size) {
    cout << "*******************************************************" << endl;
    cout << " category\t" << "itemCodes\t"  << "Descriptions\t" << "  Price: $\t" << endl;
     cout << "-----------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout <<  category << "\t\t" << itemCodes[i]<< "\t\t" << itemDescriptions[i]<<"\t\t\t"<< itemPrices[i]<<"\t\t" << endl;
    }
cout << "-----------------------------------------------------------------------" << endl<<endl;
cout << "Choose " << category << " for your system (or 0 to skip):" ;
    string choice;
    cin >> choice;

    if (choice == "0") {
        return -1; // Skip item
    }

    for (int i = 0; i < size; i++) {
        if (choice == itemCodes[i]) {
            return i;
        }
    }

    return -2; // Invalid choice
}

int main() {
    // Task 1 - Setting up the system and ordering main items
    cout << "Welcome to the Online Computer Shop!" << endl;
    char CustomerName;
    string OrderId;
    int caseChoice = displayOptions("CASE", caseCodes, caseDescriptions, casePrices, 2);
    int ramChoice = displayOptions("RAM", ramCodes, ramDescriptions, ramPrices, 3);
    int hddChoice = displayOptions("Main Hard Disk Drive", hddCodes, hddDescriptions, hddPrices, 3);

    if (caseChoice == -2 || ramChoice == -2 || hddChoice == -2) {
        cout << "Invalid choice. Exiting program." << endl;
        return 0;
    }

    // Calculate total price
    double total = COMPONENT_PRICE;
    if (caseChoice >= 0) total += casePrices[caseChoice];
    if (ramChoice >= 0) total += ramPrices[ramChoice];
    if (hddChoice >= 0) total += hddPrices[hddChoice];

    // Output chosen items and total price
    cout << "\nOrder Summary" << endl;
    cout<<"=================="<<endl<<endl;
    //cout<<"Customer Name:";
    //cin>>CustomerName;
    //cout<<"Order Id:";
    //cin>>OrderId;
    cout << " category\t" << "itemCodes\t" << "Descriptions\t" << "  Price: $\t" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    if (caseChoice >= 0) cout <<"CASE" <<"\t\t" <<caseCodes[caseChoice] <<"\t\t" << caseDescriptions[caseChoice] << "\t\t" << casePrices[caseChoice] << endl;
    if (ramChoice >= 0) cout << "RAM" << "\t\t" << ramCodes[ramChoice] << "\t\t" << ramDescriptions[ramChoice] << " \t\t" << ramPrices[ramChoice] << endl;
    if (hddChoice >= 0) cout <<"MAIN HARD DISK DRIVE"<< "\t\t" << hddCodes[hddChoice] << "\t\t" <<  hddDescriptions[hddChoice] << " \t\t" << hddPrices[hddChoice] << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tTotal Price: $" << total << endl;

    if (caseChoice >= 0 || ramChoice >= 0 || hddChoice >= 0) {
        cout << "Great choice!" << endl;
    }

    // Task 2 - Ordering additional items
    cout << "\nDo you want to add additional items? (y/n): ";
    char additionalChoice;
    cin >> additionalChoice;

    double additionalPrice = 0.0;
    int additionalItems = 0;

    if (additionalChoice == 'y' || additionalChoice == 'Y') {
        string ssdCodes[] = {"D1", "D2"};
        string ssdDescriptions[] = {"240 GB SSD", "480 GB SSD"};
        double ssdPrices[] = {59.99, 119.99};

        string secondHddCodes[] = {"E1", "E2", "E3"};
        string secondHddDescriptions[] = {"1 TB HDD", "2 TB HDD", "4 TB HDD"};
        double secondHddPrices[] = {49.99, 89.99, 129.99};

        string opticalDriveCodes[] = {"F1", "F2"};
        string opticalDriveDescriptions[] = {"DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer"};
        double opticalDrivePrices[] = {50.00, 100.00};

        string osCodes[] = {"G1", "G2"};
        string osDescriptions[] = {"Standard Version", "Professional Version"};
        double osPrices[] = {100.00, 175.00};

        int ssdChoice = displayOptions("Solid State Drive", ssdCodes, ssdDescriptions, ssdPrices, 2);
        int secondHddChoice = displayOptions("Second Hard Disk Drive", secondHddCodes, secondHddDescriptions, secondHddPrices, 3);
        int opticalDriveChoice = displayOptions("Optical Drive", opticalDriveCodes, opticalDriveDescriptions, opticalDrivePrices, 2);
        int osChoice = displayOptions("Operating System", osCodes, osDescriptions, osPrices, 2);

        if (ssdChoice >= 0) {
            additionalPrice += ssdPrices[ssdChoice];
            additionalItems++;
        }
        if (secondHddChoice >= 0) {
            additionalPrice += secondHddPrices[secondHddChoice];
            additionalItems++;
        }
        if (opticalDriveChoice >= 0) {
            additionalPrice += opticalDrivePrices[opticalDriveChoice];
            additionalItems++;
        }
        if (osChoice >= 0) {
            additionalPrice += osPrices[osChoice];
            additionalItems++;
        }

        total += additionalPrice;

        // Output additional items and updated total price
        cout << "\nAdditional items:" << endl;
        cout << " category\t\t" << "itemCodes\t" << "Descriptions\t" << "  Price: $\t" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        if (ssdChoice >= 0) cout << "Solid State Drive " << "\t" <<  ssdCodes[ssdChoice] << "\t\t" << ssdDescriptions[ssdChoice] << "\t\t" << ssdPrices[ssdChoice] << endl;
        if (secondHddChoice >= 0) cout << "Second Hard Disk Drive " << "\t" <<  secondHddCodes[secondHddChoice] << "\t\t" << secondHddDescriptions[secondHddChoice] << " \t\t" << secondHddPrices[secondHddChoice] << endl;
        if (opticalDriveChoice >= 0) cout << "Optical Drive " <<  "\t" << opticalDriveCodes[opticalDriveChoice] << "\t\t" << opticalDriveDescriptions[opticalDriveChoice] << " \t\t" << opticalDrivePrices[opticalDriveChoice] << endl;
        if (osChoice >= 0) cout << "Operating System " <<  "\t" <<  osCodes[osChoice] << "\t\t" << osDescriptions[osChoice] << "\t\t" << osPrices[osChoice] << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t\tUpdated Total Price: $" << total << endl;
    }

    // Task 3 - Offering discounts
    if (additionalItems == 1) {
        double discount = 0.05 * total;
        total -= discount;

        // Output discount information and final total price
        cout << "\nDiscount Applied: $" << discount << " (5%)" << endl;
        cout << "Amount Saved: $" << discount << endl;
    } else if (additionalItems >= 2) {
        double discount = 0.10 * total;
        total -= discount;

        // Output discount information and final total price
        cout << "\nDiscount Applied: $" << discount << " (10%)" << endl;
        cout << "Amount Saved: $" << discount << endl;
    }

    cout << "\nThanks for shopping at the Online Computer Shop!" << endl;

    return 0;
}
