#include <bits/stdc++.h>

using namespace std;

int main() {

    //declare variables
    int odoStart, odoEnd, rentDays, startMonth;
    string custName, lux;

    //get input from user
    cout << "Odometer at start: ";
    cin >> odoStart;
    cout << "Odometer at end: ";
    cin >> odoEnd;
    cout << "Rental days: ";
    cin >> rentDays;

    cin.ignore(10000, '\n');

    cout << "Customer name: ";
    getline(cin, custName);

    cout << "Luxury car? (y/n): ";
    getline(cin, lux);

    cout << "Starting month (1=Jan, 2=Feb, etc.): ";
    cin >> startMonth;

    cout << "---" << endl;

    //printing results

    //if there was a user error in the input
    if(odoStart < 0) cout << "The starting odometer reading must not be negative." << endl;
    else if(odoEnd < odoStart) cout << "The ending odometer reading must be at least as large as the starting reading." << endl;
    else if(rentDays <= 0) cout << "The number of rental days must be positive." << endl;
    else if(custName.size() == 0) cout << "You must enter a customer name." << endl;
    else if(lux != "y" && lux != "n") cout << "You must enter y or n." << endl;
    else if(startMonth < 1 || startMonth > 12) cout << "The month number must be in the range 1 through 12." << endl;
    else{
        //calculating rental charge
        cout << "The rental charge for " << custName << " is $";
        double charge = 45*rentDays;
        if(lux == "y") charge += 30*rentDays;
        
        int odoDiff = odoEnd - odoStart;
        //first <=100 miles
        if(odoDiff <= 100){
            charge += (0.33)*(odoDiff);
            cout << charge << endl;
            return 0;
        }
        
        charge += 33;
        odoDiff -= 100;

        //next 500 miles
        int sub = min(odoDiff, 500);
        if(startMonth <= 3 || startMonth == 12){
            charge += (0.33)*(sub);
        }
        else{
            charge += (0.27)*(sub);
        }
        
        //above 600 miles
        odoDiff -= sub;
        charge += (0.21)*(odoDiff);

        cout << charge << endl;

    }
}