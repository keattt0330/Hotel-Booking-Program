#include<iostream>
#include<iomanip>

using namespace std;

class Presidential;
class Villa;
class Double;

void noCustomer();
void icNotFound();

// The customer class using linked list method
class Customer{
	int roomType[3] = {0, 0, 0};
	string ic;
	string name;
	float price;
	Customer *next;
	int room;

	public:
		Customer(){
			cout << "\n                                                                                 Enter name : ";
			getline(cin, name);
			cout << "\n                                                                            Enter IC number : ";
			getline(cin, ic);
			next = NULL;
		}
		void setData(){
			cout << "\n                                                                                 Enter name : ";
			getline(cin, name);
			cout << "\n                                                                            Enter IC number : ";
			getline(cin, ic);
		}

		Customer(string i, string n, float p, int r) : ic(i), name(n), price(p), room(r), next(nullptr) {}

		void setNext(Customer * n){
			next = n;
		}

		void setPrice(float p){
			price = p;
		}
		void setName(string n){
			name = n;
		}
		void setIC(string c){
			ic = c;
		}

		string getName(){
			return name;
		}

		string getIC(){
			return ic;
		}

		Customer * getNext(){
			return next;
		}
		float getPrice(){
			return price;
		}
		void getroomType(int r){
			room = r;
		}

		int getroom(){
			return room;
		}

		void setRoomtype(int type){
			roomType[type] = 1;
		}

		void setRoomtype(int d, int p, int v){
			roomType[0] = d;
			roomType[1] = p;
			roomType[2] = v;
		}

		int * getRoomtype(){
			return roomType;
		}

		~Customer(){
			cout << endl;
			cout << "                                                                                 " << name << " is deleted!! " << endl;		
		}
		
		// friend void addCustomer(Customer &c, Double d[], Presidential p[], Villa v[]); // friend function
		friend void get_hotel_room_preferences(Customer &c, Double d[], Presidential p[], Villa v[]);
		friend void editRoom(Customer &c, Double d[], Presidential p[], Villa v[]);
		friend void editCustomer(Customer *c, Double d[], Presidential p[], Villa v[]);
};

// Function to print out the names of the customers in the list
void printList(Customer *head){
	if (head == NULL)
	{
		noCustomer();
	}
	
	while (head->getNext() != NULL){
		cout << "\n                                                                                       " << head->getName() << endl;
		head = head->getNext();
	}
	cout << "\n                                                                                       " << head->getName() << endl;
}

// Function to print the customer purchase information
void printSellList(Customer* head) {
    if (head == nullptr) {
        noCustomer();
        return;
    }
    cout << "\t\t\t\t\t+=================================================================================================+\n";
    cout << "\t\t\t\t\t|                                    Customer Purchase Information                                |\n";
    cout << "\t\t\t\t\t+=================================================================================================+\n";

    // Print customer information
    Customer* current = head;
    while (current != nullptr) {
        cout << "\t\t\t\t\t IC: " << left << setw(10) << current->getIC() << " | ";
        cout << "Name: " << left << setw(10) << current->getName() << " | ";
        cout << "Price: RM" << left << setw(10) << fixed << setprecision(2) << current->getPrice() << " | ";
        cout << "RoomType: " ;

        // Print room types directly inside the loop
        bool isFirstRoomType = true;
        for (int i = 0; i < 3; ++i) {
            if (current->getRoomtype()[i] > 0) {
                if (!isFirstRoomType) {
                    cout << ", ";
                }
                isFirstRoomType = false;

                if (i == 0) {
                    cout << "Double";
                } else if (i == 1) {
                    cout << "Presidential";
                } else if (i == 2) {
                    cout << "Villa";
                }
            }
        }
        cout << endl;
        cout << "\t\t\t\t\t+-------------------------------------------------------------------------------------------------+\n";
        current = current->getNext();
    }
}




void printRoomList(Customer* head, int s) {
    if (head == NULL) {
        noCustomer();
        return;
    }
	string roomType;
	if (s == 1){
		roomType = "Double";
	}
	else if (s == 2){
		roomType = "Presidential";
	}
	else if (s == 3){
		roomType = "Villa";
	}


    // Header
	cout << endl;
    cout << "\t\t\t\t\t\t\t+=================================================================+\n";
    cout << "\t\t\t\t\t\t\t                      Room " << roomType << " Customer List                        \n";
    cout << "\t\t\t\t\t\t\t+=================================================================+\n";

    // Print customer information
    Customer* current = head;
    int found = 0;

    while (current != NULL) {
        if (current->getRoomtype()[s-1] > 0) {
            found = 1;
            cout << "\t\t\t\t\t\t\t  IC: " << left << setw(10) << current->getIC() << " | ";
            cout << "Name: " << left << setw(10) << current->getName() << " | ";
            cout << "Price: RM" << left << setw(10) << fixed << setprecision(2) << current->getPrice() << " \n";
            cout << "\t\t\t\t\t\t\t+-----------------------------------------------------------------+\n\n";
        }
        current = current->getNext();
    }

    // If no customer is found for the specified room type, display a message
    if (!found) {
        cout << "\t\t\t\t\t\t\t|                   No customers found for Room " << s << "                 |\n";
        cout << "\t\t\t\t\t\t\t+-----------------------------------------------------------------+\n\n";
    }
}




Customer* insertCustomer(Customer* head, string id, string name, float price, int room) {
    // Check if the customer with the given IC already exists
    Customer* current = head;
    while (current != nullptr) {
        if (current->getIC() == id) {
            return head; // Customer already exists, return the head of the list
        }
        current = current->getNext();
    }

    // Insert the new customer at the beginning of the list
    Customer* newCustomer = new Customer(id, name, price, room);
    newCustomer->setNext(head);
    return newCustomer;
}

// Use bubble sort to amount spent by customer in ascending order
void price_ascendingOrder(Customer* head) {
	int sorted = 0;
	string tempName;
	string tempIC;
	float tempPrice;

    if (head == NULL) {
        noCustomer();
        return;
    }
	else if (head->getNext() == NULL){
		return;
	}

    while (!sorted) {
        Customer* current = head;
        Customer* next = head->getNext();
        sorted = 1;

        while (next != NULL) {
            if (current->getPrice() > next->getPrice()) {
                // Swap the elements
                tempName = current->getName();
                tempIC = current->getIC();
           		tempPrice = current->getPrice();

                current->setName(next->getName());
                current->setIC(next->getIC());
                current->setPrice(next->getPrice());

                next->setName(tempName);
                next->setIC(tempIC);
                next->setPrice(tempPrice);

                sorted = 0;
            }

            current = next;
            next = next->getNext();
		}
	}
}

//  Sorting the amount spent by the customer in descending order
void price_descendingOrder (Customer* head) {
	int sorted = 0;
	string tempName;
	string tempIC;
	float tempPrice;

    if (head == NULL) {
        noCustomer();
        return;
    }
	else if (head->getNext() == NULL){
		return;
	}
	

    while (!sorted) {
        Customer* current = head;
        Customer* next = head->getNext();
        sorted = 1;

        while (next != NULL) {
            if (current->getPrice() < next->getPrice()) {
                // Swap the elements
                tempName = current->getName();
                tempIC = current->getIC();
                tempPrice = current->getPrice();

                current->setName(next->getName());
                current->setIC(next->getIC());
                current->setPrice(next->getPrice());

                next->setName(tempName);
                next->setIC(tempIC);
                next->setPrice(tempPrice);

                sorted = 0;
            }

            current = next;
            next = next->getNext();
		}
	}
}

// Function to free up the memory
void freeList(Customer *head){
	if (head == NULL)
	{
		return;
	}
	while(head->getNext() != NULL){
		Customer *tmp = head;
		head = head->getNext();
		delete tmp;
	}
	delete head;
	return;
}

// Function to check which pointer is free to add the customer in the list
void checkNull(Customer *head, Customer *n){
	while(head->getNext() != NULL){
		head = head->getNext();
	}
	head->setNext(n);
}

// Function to delete the customer out from the list
void delCus(Customer *head, Customer **head2, Double d[], Presidential p[], Villa v[]){
	if (head == NULL){
		noCustomer();
		return;
	}
		string ic;
		cout << "\n                                     Enter customer IC number that you would like to delete : ";
		cin >> ic;
		for(int i = 0; i < 10; i++){
			if(d[i].getCustomer() == ic){
				d[i].reset();
			}
			if(p[i].getCustomer() == ic){
				p[i].reset();
			}
			if(v[i].getCustomer() == ic){
				v[i].reset();
			}
		}
		if (head->getIC() == ic){
			if(head->getNext() == NULL){
				head->setNext(NULL);
				delete head;
				*head2 = NULL;
				return;
			}
			Customer *tmp = head->getNext();
			delete head;
			*head2 = tmp;
			return;
		}
		if(head->getNext() == NULL){
				icNotFound();
				return;
			}
		while(head->getNext()->getIC() != ic){
			head = head->getNext();
			if(head->getNext() == NULL){
				icNotFound();
				return;
			}
		}
		Customer *tmp = head->getNext();
		head->setNext(head->getNext()->getNext());
		delete tmp;
}

// This is the function to find the location of the customer in the list stored in the memory.
Customer *findCus(Customer *head){
	if (head == NULL){
		noCustomer();
		return NULL;
	}
	string ic;
	cout << "\n                                                                       Enter your IC number : ";
	getline(cin, ic);
	while(head->getIC() != ic){
		head = head->getNext();
		if(head == NULL){
			icNotFound();
			return NULL;
		}
	}
	return head;
	
}

void noCustomer()
{
	cout << "                                                                     _______________________________________ " << endl;
    cout << "                                                                    !                                       !" << endl;
    cout << "                                                                    !           No customer yet!!           !" << endl;
    cout << "                                                                    !_______________________________________!" << endl;
}

void icNotFound()
{
	cout << endl;
	cout << "                                                                     _______________________________________ " << endl;
    cout << "                                                                    !                                       !" << endl;
    cout << "                                                                    !   No customer with that IC number!!   !" << endl;
    cout << "                                                                    !_______________________________________!" << endl;
}

