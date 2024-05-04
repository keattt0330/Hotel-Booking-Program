#include <iostream>
using namespace std;

class Customer;
class Presidential;
class Villa;

// This is the class of Double room, which is the parent class of Presidential and Villa.
class Double
{
    protected:
        int roomNum;
        string customer;
        int nights;
        float price;
        char choice;
        string startDate;

    public:
        Double()
        {
            price = 10000;
            nights = 0;
            customer = "";
        }

        void setRoomNum(int rn)
        {   
            roomNum = rn;
        }

        void changeDetails()
        {
            customer = "";
        }

        int get_roomNum()
        {   
            return roomNum;
        }

        void reset(){
            customer = "";
            nights = 0;
            startDate = "";
        }

        string getCustomer()
        {
            return customer;
        }

        int getNights(){
            return nights;
        }

        float getPrice(){
            return price;
        }

        friend void get_hotel_room_preferences(Customer &c, Double d[], Presidential p[], Villa v[]);
        friend void editRoom(Customer &c, Double d[], Presidential p[], Villa v[]);
        friend void editCustomer(Customer *c, Double d[], Presidential p[], Villa v[]);
        
};

class Presidential : public Double
{
    public:
        Presidential()
        {
            price = 25000;
            customer = "";
        }

        friend void get_hotel_room_preferences(Customer &c, Double d[], Presidential p[], Villa v[]);
        friend void editRoom(Customer &c, Double d[], Presidential p[], Villa v[]);
        friend void editCustomer(Customer *c, Double d[], Presidential p[], Villa v[]);
};


// This is the class of Villa room, which is the child class of Double.
// Constructor initializes the price of the room.
class Villa : public Double
{
    public:
        Villa()
        {
            price = 50000;
            customer = "";
        }

        friend void get_hotel_room_preferences(Customer &c, Double d[], Presidential p[], Villa v[]);
        friend void editRoom(Customer &c, Double d[], Presidential p[], Villa v[]);
        friend void editCustomer(Customer *c, Double d[], Presidential p[], Villa v[]);
};
