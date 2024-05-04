#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

class Double;
class Presidential;
class Villa;
class Customer;

int calcD(Customer &c, Double d[]);
int calcP(Customer &c, Presidential p[]);
int calcV(Customer &c, Villa v[]);

void roomBookedForReceipt(Customer *c, Double d[], Presidential p[], Villa v[]);
int checkNightD(Customer *c, Double d[]);
int checkNightP(Customer *c, Presidential p[]);
int checkNightV(Customer *c, Villa v[]);
float totalD(Customer *c, Double d[]);
float totalP(Customer *c, Presidential p[]);
float totalV(Customer *c, Villa v[]);
float totalAmount(Customer *c, Double d[], Presidential p[], Villa v[]);


// This is the function to print the receipt. It is broken down into multiple small parts to make it easier to read.
void print_receipt_func(Customer *c, Double d[], Presidential p[], Villa v[]){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(10000, 99999);
    int invoiceNum = dis(gen);

    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&currentTime);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    cout << "                                            ------------------------------------------------------------------------------  " << endl;
    cout << "                                           |               _               ___             _      _      _                | " << endl;
    cout << "                                           |              | |             | '_ \\          (_)    (_)    | |               | " << endl;
    cout << "                                           |              | |     ___     | |_) |_ __ __ _ _ _ __ _  ___| |               | " << endl;
    cout << "                                           |              | |    / _ \\    | ._ /| '__/ _` | | '__| |/ _ \\ |               | " << endl;
    cout << "                                           |              | |___|  __/    | |   | | | (_| | | |  | |  __/ |               | " << endl;
    cout << "                                           |              |_____|\\___|    |_|   |_|  \\__,_|_|_|  |_|\\___|_|               | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                         Multimedia University Sdn.Bhd                        | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                             Persiaran Multimedia                             | " << endl;
    cout << "                                           |                                63100 Cyberjaya                               | " << endl;
    cout << "                                           |                                   Selangor.                                  | " << endl;
    cout << "                                           |                                 1-300-80-0668                                | " << endl;
    cout << "                                           |                                www.mmu.edu.my                                | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |==============================================================================| " << endl;
    cout << "                                           |                                    Invoice                                   | " << endl;
    cout << "                                           |==============================================================================| " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |  Invoice Number : " << invoiceNum << "                                                      | " << endl;
    cout << "                                           |  Date           : " << day << "/" << month << "/" << year << "                                                  | " << endl;
    cout << "                                           |  BILL TO        : " << setw(30) << left << c -> getName() << "                             | " << endl;
    cout << "                                           |  IC             : " << setw(30) << left << c -> getIC() << "                             | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |==============================================================================| " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                                  DESCRIPTION                                 | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           | ";
    roomBookedForReceipt(c, d, p, v);
    cout << "                                           |------------------------------------------------------------------------------| " << endl;
    cout << "                                           |" << "   Total Payment : RM " << setw(53) << right << totalAmount(c, d, p, v) << "   | " << endl;
    cout << "                                           |------------------------------------------------------------------------------| " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                     Thanks for choosing our LA PRAIRIEL!                     | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                        We hope you enjoy your holiday!                       | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |      ___       ________  ___      ___ _______           ___  ___             | " << endl;     
    cout << "                                           |     |\\  \\     |\\   __  \\|\\  \\    /  /|\\  ___ \\         |\\  \\|\\  \\            | " << endl;   
    cout << "                                           |     \\ \\  \\    \\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|        \\ \\  \\ \\  \\           | " << endl;   
    cout << "                                           |      \\ \\  \\    \\ \\  \\ \\  \\ \\  \\/  / / \\ \\  \\_|/__       \\ \\  \\ \\  \\          | " << endl;  
    cout << "                                           |       \\ \\  \\____\\ \\  \\_\\  \\ \\    / /   \\ \\  \\_|\\ \\       \\ \\  \\_\\  \\         | " << endl; 
    cout << "                                           |        \\ \\_______\\ \\_______\\ \\__/ /     \\ \\_______\\       \\ \\_______\\        | " << endl;
    cout << "                                           |         \\|_______|\\|_______|\\|__|/       \\|_______|        \\|_______|        | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                            ------------------------------------------------------------------------------  " << endl;
    cout << endl;
    c->setPrice(totalAmount(c, d, p, v));
}

void roomBookedForReceipt(Customer *c, Double d[], Presidential p[], Villa v[]){
    cout <<" Rooms that you've booked                                                    |" << endl;
    cout << "                                           |                                                                              | " << endl;
    cout << "                                           | " << setw(20) << left << "  Type of rooms" << setw(22) << right << "Number of Room" << setw(16) << right << "Night(s)" << setw(18) << right << "Amount(RM)" << " | " << endl;
    cout << "                                           |------------------------------------------------------------------------------| " << endl;
    cout << "                                           | " << setw(20) << left << "  Double Room" << left << setw(15) << right << calcD(*c, d) << setw(19) << right << checkNightD(c, d) << setw(20) << right << totalD(c, d) << "   | " << endl;
    cout << "                                           | " << setw(20) << left << "  Presidential Room" << left << setw(15) << right <<  calcP(*c, p) << setw(19) << right << checkNightD(c, p) << setw(20) << right << totalP(c, p) << "   | " << endl;
    cout << "                                           | " << setw(20) << left << "  Villa" << left << setw(15) << right << calcV(*c, v) << setw(19) << right << checkNightD(c, v) << setw(20) << right << totalV(c, v) << "   | " << endl;
}

int checkNightD(Customer *c, Double d[]){
    int numNights=0;

    for (int i = 0; i < 10; i++){
        if (d[i].getCustomer() == c->getIC()){
            numNights = d[i].getNights();
        }
    }

    return numNights;
}

int checkNightP(Customer *c, Presidential p[]){
    int numNights=0;

    for (int i = 0; i < 10; i++){
        if (p[i].getCustomer() == c->getIC()){
            numNights = p[i].getNights();
        }
    }

    return numNights;
}

int checkNightV(Customer *c, Villa v[]){
    int numNights=0;

    for (int i = 0; i < 10; i++){
        if (v[i].getCustomer() == c->getIC()){
            numNights = v[i].getNights();
        }
    }

    return numNights;
}

float totalD(Customer *c, Double d[]){
    float price =10000;
    float numRooms = calcD(*c, d);
    float night2 = checkNightD(c, d);

    return price * numRooms * night2;
}

float totalP(Customer *c, Presidential p[]){
    float price =25000;
    float numRooms = calcP(*c, p);
    float night2 = checkNightP(c, p);

    return price * numRooms * night2;
}

float totalV(Customer *c, Villa v[]){
    float price =50000;
    float numRooms = calcV(*c, v);
    float night2 = checkNightV(c, v);
    
    return price * numRooms * night2;
}

float totalAmount(Customer *c, Double d[], Presidential p[], Villa v[]){
    float result1 = totalD( c, d);
    float result2 = totalP( c, p);
    float result3 = totalV( c, v);

    return result1 + result2 + result3;
}