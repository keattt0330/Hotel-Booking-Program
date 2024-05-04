#include <iostream>
#include <iomanip>
using namespace std;

class Double;
class Presidential;
class Villa;
class Customer;

//ui function 
void booking_menu(Double d[], Presidential p[], Villa v[]);
void printThanks();
void getChoice();
void editMenu();
void editMenu2();
void noRoom();
void noEnough();
void re_enter();

int availableD(Double room[]);
int availableP(Presidential room[]);
int availableV(Villa room[]);
void roomBooked(Customer &c, Double d[], Presidential p[], Villa v[]);

int calcD(Customer &c, Double d[]);
int calcP(Customer &c, Presidential p[]);
int calcV(Customer &c, Villa v[]);

void get_hotel_room_preferences(Customer &c, Double d[], Presidential p[], Villa v[]){
    int roomtype, numNights, numRooms, choice, roomType;
    string roomtypeCopy, startDate;

    do{
        booking_menu(d, p, v);
        cout<<endl<<"\n                                                                     Please enter your choice(1-3) : ";
        cin>>roomtype;

        if(roomtype > 3 || roomtype < 1){
            re_enter();
            choice = 2;
            continue ;
        }

        cout<<"\n                                   Please enter number of rooms that you needed for this room type : ";
        cin>>numRooms;

        
        cout<<"\n                                          Please enter number of night(s) you are planning to stay : ";
        cin>>numNights;

        cout<<"\n                                                        Please enter your check-in date [DD-MM-YY] : ";
        cin>>startDate;

        switch (roomtype){
            case 1:
                roomtypeCopy = "Double Room";
                if (availableD(d) == 0)
                {
                    noRoom();
                    continue;
                }
                else if (availableD(d) < numRooms)
                {
                    noEnough();
                    continue;
                }
                else{
                    for (int i = 0; i < numRooms; ++i){
                        for (int j = 0; j < 10; ++j)
                        {
                            if (d[j].customer == "")
                            {
                                d[j].customer = c.ic;
                                d[j].nights = numNights;
                                d[j].startDate = startDate;
                                c.setRoomtype(roomtype - 1);
                                break;
                            }
                        }
                        
                    }
                }
                break;
                
            case 2:
                roomtypeCopy = "Presidential Room";
                if (availableP(p) == 0)
                {
                    noRoom();
                    continue;
                }
                else if (availableP(p) < numRooms)
                {
                    noEnough();
                    continue;
                }
                else{
                    for (int i = 0; i < numRooms; ++i){
                        for (int j = 0; j < 10; ++j)
                        {
                            if (p[j].customer == "")
                            {
                                p[j].customer = c.ic;
                                p[j].nights = numNights;
                                p[j].startDate = startDate;
                                c.setRoomtype(roomtype - 1);
                                break;
                            }
                        }
                    }
                }
                break;

            case 3:
                roomtypeCopy = "Villa";
                if (availableV(v) == 0)
                {
                    noRoom();
                    continue;
                }
                else if (availableV(v) < numRooms)
                {
                    noEnough();
                    continue;
                }
                else{
                    for (int i = 0; i < numRooms; ++i){
                        for (int j = 0; j < 10; ++j)
                        {
                            if (v[j].customer == "")
                            {
                                v[j].customer = c.ic;
                                v[j].nights = numNights;
                                v[j].startDate = startDate;
                                c.setRoomtype(roomtype - 1);
                                break;
                            }
                        }
                    }
                }
                break;
        }
        
        printThanks();
        getChoice();
        cin>>choice;

    } while (choice == 2);

    roomBooked(c, d, p, v);
}





void editRoom(Customer &c, Double d[], Presidential p[], Villa v[]){
    int choice, roomtype, numNights, numRooms, curRoom;
    string date;
    do{
        editMenu();
        cout << endl << "                                                                            Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            roomBooked(c, d, p, v);
            editMenu2();
            cout << endl << "                                                                             Enter your choice : ";
            cin >> roomtype;
            switch (roomtype)
            {
                case 1:
                    cout << "\n                                                                   Enter new number of room(s) : ";
                    cin >> numRooms;
                    cout << "\n                                                                      Enter number of night(s) : ";
                    cin >> numNights;
                    cout << "\n                                                          Enter start check-in date [DD-MM-YY] : ";
                    cin >> date;
                    cout << endl;
                    curRoom = calcD(c, d);
                    if (curRoom < numRooms){
                        if (availableD(d) == 0)
                        {
                            noRoom();
                            continue;
                        }
                        else if (availableD(d) < numRooms - curRoom)
                        {
                            noEnough();
                            continue;
                        }
                        else{
                            for (int i = 0; i < numRooms - curRoom; ++i){
                                for (int j = 0; j < 10; ++j)
                                {
                                    if (d[j].customer == "")
                                    {
                                        d[j].customer = c.ic;
                                        d[j].nights = numNights;
                                        break;
                                    }
                                }
                            }
                        }
                        continue;
                    }
                    else if (curRoom > numRooms){
                        for (int i = 0; i < curRoom - numRooms; ++i){
                            for (int j = 0; j < 10; ++j)
                            {
                                if (d[j].customer == c.ic)
                                {
                                    d[j].reset();
                                    break;
                                }
                            }
                        }
                    }
                    break;
                    
                case 2:
                    cout << "\n                                                                   Enter new number of room(s) : ";
                    cin >> numRooms;
                    cout << "\n                                                                      Enter number of night(s) : ";
                    cin >> numNights;
                    cout << "\n                                                          Enter start check-in date [DD-MM-YY] : ";
                    cin >> date;
                    cout << endl;
                    curRoom = calcP(c, p);
                    if (curRoom < numRooms){
                        if (availableP(p) == 0)
                        {
                            noRoom();
                            continue;
                        }
                        else if (availableP(p) < numRooms - curRoom)
                        {
                            noEnough();
                            continue;
                        }
                        else{
                            for (int i = 0; i < numRooms - curRoom; ++i){
                                for (int j = 0; j < 10; ++j)
                                {
                                    if (p[j].customer == "")
                                    {
                                        p[j].customer = c.ic;
                                        p[j].nights = numNights;
                                        break;
                                    }
                                }
                            }
                        }
                        continue;
                    }
                    else if (curRoom > numRooms){
                        for (int i = 0; i < curRoom - numRooms; ++i){
                            for (int j = 0; j < 10; ++j)
                            {
                                if (p[j].customer == c.ic)
                                {
                                    p[j].reset();
                                    break;
                                }
                            }
                        }
                    }
                    break;

                case 3:
                    cout << "\n                                                                   Enter new number of room(s) : ";
                    cin >> numRooms;
                    cout << "\n                                                                      Enter number of night(s) : ";
                    cin >> numNights;
                    cout << "\n                                                          Enter start check-in date [DD-MM-YY] : ";
                    cin >> date;
                    cout << endl;
                    curRoom = calcV(c, v);
                    if (curRoom < numRooms){
                        if (availableV(v) == 0)
                        {
                            noRoom();
                            continue;
                        }
                        else if (availableV(v) < numRooms - curRoom)
                        {
                            noEnough();
                            continue;
                        }
                        else{
                            for (int i = 0; i < numRooms - curRoom; ++i){
                                for (int j = 0; j < 10; ++j)
                                {
                                    if (v[j].customer == "")
                                    {
                                        v[j].customer = c.ic;
                                        v[j].nights = numNights;
                                        break;
                                    }
                                }
                            }
                        }
                        continue;
                    }
                    else if (curRoom > numRooms){
                        for (int i = 0; i < curRoom - numRooms; ++i){
                            for (int j = 0; j < 10; ++j)
                            {
                                if (v[j].customer == c.ic)
                                {
                                    v[j].reset();
                                    break;
                                }
                            }
                        }
                    }
            }
            break;
        
        case 2:
            roomBooked(c, d, p, v);
            editMenu2();
            cout << endl << "                                                                          Enter your choice : ";
            cin >> roomtype;
            cout << "\n                                                               Enter new number of night(s) : ";
            cin >> numNights;
            switch (roomtype)
            {
            case 1:
                for (int i = 0; i < 10; ++i){
                    if (d[i].customer == c.ic){
                        d[i].nights = numNights;
                    }
                }
                break;
            
            case 2:
                for (int i = 0; i < 10; ++i){
                    if (p[i].customer == c.ic){
                        p[i].nights = numNights;
                    }
                }
                break;
            
            case 3:
                for (int i = 0; i < 10; ++i){
                    if (v[i].customer == c.ic){
                        v[i].nights = numNights;
                    }
                }
                break;
            }
            break;
        case 3:
            editCustomer(&c, d, p, v);
            break;
        }
    }while (choice != 4);
}

void editCustomer(Customer *c, Double d[], Presidential p[], Villa v[]){
    int choice;
    string ic;
    cout << "\n                                                Enter 1 to change IC Number, 2 to change Name : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\n                                                                          Enter new IC Number : ";    
        cin >> ic;
        for (int i = 0; i < 10; ++i){
            if (d[i].customer == c->ic){
                d[i].customer = ic;
            }
            if (p[i].getCustomer() == c->ic){
                p[i].customer = ic;
            }
            if (v[i].getCustomer() == c->ic){
                v[i].customer = ic;
            }
        }
        c->ic = ic;
        break;
    case 2:
        string name;
        cout << "\n                                                                               Enter new Name : ";
        cin.ignore();
        getline(cin, name);
        c->name = name;
        break;
    }
}


void roomBooked(Customer &c, Double d[], Presidential p[], Villa v[]){

    system("cls");
    cout << "\n\n";
    cout << "                                                      .--------------------------------------------------------------------." << endl;
    cout << "                                                      | .----------------------------------------------------------------. |" << endl;
    cout << "                                                      | |                                                                | |" << endl;
    cout << "                                                      | |                    + ===================== +                   | |" << endl;
    cout << "                                                      | |                    | Rooms that you booked |                   | |" << endl;
    cout << "                                                      | |                    + ===================== +                   | |" << endl;
    cout << "                                                      | |                                                                | |" << endl;
    cout << "                                                      | |                        Double Room : " << calcD(c, d) << "                         | |" << endl;
    cout << "                                                      | |                                                                | |" << endl;
    cout << "                                                      | |                  Presidential Room : " << calcP(c, p) << "                         | |" << endl;
    cout << "                                                      | |                                                                | |" << endl;
    cout << "                                                      | |                              Villa : " << calcV(c, v) << "                         | |" << endl;
    cout << "                                                      | |________________________________________________________________| |" << endl;
    cout << "                                                      |____________________________________________________________________|" << endl;
    cout << endl;
}




int calcD(Customer &c, Double d[]){
    int total = 0;
    for (int i = 0; i < 10; ++i){
        if (d[i].getCustomer() == c.getIC()){
            total++;
        }
    }
    return total;
}

int calcP(Customer &c, Presidential p[]){
    int total = 0;
    for (int i = 0; i < 10; ++i){
        if (p[i].getCustomer() == c.getIC()){
            total++;
        }
    }
    return total;
}

int calcV(Customer &c, Villa v[]){
    int total = 0;
    for (int i = 0; i < 10; ++i){
        if (v[i].getCustomer() == c.getIC()){
            total++;
        }
    }
    return total;
}

void booking_menu(Double d[], Presidential p[], Villa v[])
{
    cout << "\n";
    cout << "                                                                                ______________________________________________________________________________________________   " << endl; 
    cout << "                                                                               /\\                                                                                             \\" << endl;
    cout << "                                                                               \\_|                                       + DESCRIPTION +                                       |" << endl;
    cout << "                                                                                 |  =========================================================================================  | " << endl;
    cout << "                                                                                 |                                                                                             | " << endl;
    cout << "                                                                                 |                                       < Double room >                                       | " << endl; 
    cout << "                                                                                 |                                                                                             | " << endl;
    cout << "                                                                                 |                             A standard hotel room for a couple.                             | " << endl;
    cout << "                                                                                 |                          This package includes one king-size bed.                           | " << endl;
    cout << "                                                                                 |                                                                                             | " << endl;
    cout << "             __________________________   __________________________             |  -----------------------------------------------------------------------------------------  | " << endl;
    cout << "         .-/|                          \\ /                          |\\-.         |                                                                                             | " << endl;
    cout << "         ||||                                                       ||||         |                                    < Presidential Room >                                    | " << endl;
    cout << "         ||||               < Room booking Systems >                ||||         |                                                                                             | " << endl;
    cout << "         ||||                                                       ||||         |              A luxurious and exclusive accommodation reserved for VIP guests.               | " << endl;
    cout << "         ||||        Please choose your preferably room type:       ||||         |          It features two king-size beds, and breakfast is included in this package.         | " << endl;
    cout << "         ||||                                                       ||||         |                                                                                             | " << endl;
    cout << "         ||||                                                       ||||         |  -----------------------------------------------------------------------------------------  | " << endl;
    cout << "         ||||" << setw(28) << left << "     1. Double room " << setw(3) << left << availableD(d) << " room(s) available" << "      ||||         |                                                                                             | " << endl;
    cout << "         ||||                                                       ||||         |                                          < Villa >                                          | " << endl;
    cout << "         ||||" << setw(28) << left << "     2. Presidential Room " << setw(3) << left << availableP(p) << " room(s) available" << "      ||||         |                                                                                             | " << endl;
    cout << "         ||||                                                       ||||         |                                  A necessity, not a luxury.                                 | " << endl;
    cout << "         ||||" << setw(28) << left << "     3. Villa " << setw(3) << left << availableV(v) << " room(s) available" << "      ||||         |                    Furnished balcony with a sea view, two king-size beds.                   | " << endl;
    cout << "         ||||                                                       ||||         |                Gordon Ramsay will be your personal chef to serve your meals.                | " << endl;
    cout << "         ||||__________________________   __________________________||||         |                                                                                             | " << endl;
    cout << "         ||/===========================\\|/===========================\\||         |   __________________________________________________________________________________________|_" << endl;
    cout << "          `---------------------------~___~---------------------------''          \\_/___________________________________________________________________________________________/" << endl;
}

void printThanks()
{
    cout << "\n" << endl;
    cout << "                                            __^__                                                                                   __^__" << endl;
    cout << "                                           ( ___ )---------------------------------------------------------------------------------( ___ )" << endl;
    cout << "                                            | / |                                                                                   | \\ |" << endl;
    cout << "                                            | / |                       Thanks for providing your preferences.                      | \\ |" << endl;
    cout << "                                            | / |                                                                                   | \\ |" << endl;
    cout << "                                            | / |     Do you wish to continue or wish to stay to add more preferably room type?     | \\ |" << endl;
    cout << "                                            |___|                                                                                   |___|" << endl;
    cout << "                                           (_____)---------------------------------------------------------------------------------(_____)" << endl;
    cout << "\n";

    return;
}

void getChoice()
{
    cout << "                                                                       ___________________________________" << endl;
    cout << "                                                                      /                                   \\" << endl;
    cout << "                                                                     |   1. Stop booking                   |" << endl;
    cout << "                                                                     |   2. Add more preferably room type  |" << endl;
    cout << "                                                                      \\___________________________________/\n" << endl;
    cout << "                                                                              Enter you choice : ";
}

void editMenu()
{
    cout << "\n" << endl;
    cout << "                                                                   ===========================================" << endl;
    cout << "                                                                   |                                         |" << endl;
    cout << "                                                                   |     < What would you like to edit? >    |" << endl;
    cout << "                                                                   |                                         |" << endl;
    cout << "                                                                   |       1.  Edit numbers of room(s)       |" << endl;
    cout << "                                                                   |                                         |" << endl;
    cout << "                                                                   |       2.  Edit numbers of night(s)      |" << endl;
    cout << "                                                                   |                                         |" << endl;
    cout << "                                                                   |       3.  Edit customer details         |" << endl;
    cout << "                                                                   |                                         |" << endl;
    cout << "                                                                   |       4.  Exit                          |" << endl;
    cout << "                                                                   |                                         |" << endl;
    cout << "                                                                   ===========================================" << endl;
}  

void editMenu2()
{
    cout << endl;
    cout << "                                                                   > > > > > > > > > > > > > > > > > > > > > >" << endl;
    cout << "                                                                   ^                                         ^" << endl;
    cout << "                                                                   ^     < What would you like to edit? >    ^" << endl;
    cout << "                                                                   ^                                         ^" << endl;
    cout << "                                                                   ^       1.  Edit for Double Room          ^" << endl;
    cout << "                                                                   ^                                         ^" << endl;
    cout << "                                                                   ^       2.  Edit for Presidential Room    ^" << endl;
    cout << "                                                                   ^                                         ^" << endl;
    cout << "                                                                   ^       3.  Edit for Villa                ^" << endl;
    cout << "                                                                   ^                                         ^" << endl;
    cout << "                                                                   > > > > > > > > > > > > > > > > > > > > > >" << endl;
}

void noRoom()
{
    cout << endl;
    cout << "                                                                     _______________________________________ " << endl;
    cout << "                                                                    !                                       !" << endl;
    cout << "                                                                    !          No room available!!          !" << endl;
    cout << "                                                                    !_______________________________________!" << endl;
}

void noEnough()
{
    cout << endl;
    cout << "                                                                     _______________________________________ " << endl;
    cout << "                                                                    !                                       !" << endl;
    cout << "                                                                    !      Not enough room available!!      !" << endl;
    cout << "                                                                    !_______________________________________!" << endl;
}

void re_enter()
{
	cout << endl;
	cout << "                                                                     ___________________________________________ " << endl;
    cout << "                                                                    !                                           !" << endl;
    cout << "                                                                    !   Invalid input. Please re-enter again.   !" << endl;
    cout << "                                                                    !___________________________________________!" << endl;
}