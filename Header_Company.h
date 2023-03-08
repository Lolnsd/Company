#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

////////////////////////////////////////////
//               Employee                 //
////////////////////////////////////////////

class Employee{
    private:
        int salary;
        int employee_id;
        int no_clients;
        string employee_name;

        int eclient_1;
        int eclient_2;

    public:
        Employee(string employee_name, int salary, int employee_id);                           //Constructor
        ~Employee();                                                                           //Destructor
        int get_employee_id();
        int get_no_clients();
        int get_eclient_1();
        int get_eclient_2();
        void set_eclient_1(int client_id);
        void set_eclient_2(int client_id);
        void set_no_clients(int x);
        void print_employee();                                                                 //Prints employee's information
        bool if_busy();                                                                        //If worker have 2 clients already or not
        friend ostream & operator<<(ostream& out, const Employee& x);
        
        friend class Company;
        friend class Client;
};

////////////////////////////////////////////
//               Venue                    //
////////////////////////////////////////////

class Venue{
    private:
        string venue_name;
        int venue_id;
        int number_of_places;
        int price_per_guest;

        int vclient_1;
        int vclient_2;
        int vclient_3;
    public:
        Venue(string venue_name, int price_per_guest, int venue_id);                           //Constructor
        ~Venue();                                                                              //Destructor
        void print_venue();                                                                    //Print venue's information
        bool if_any_spots_left();                                                              //If there are any spots left
        int get_venue_id();
        int get_number_of_places();
        void set_number_of_places(int x);
        int get_vclient_1();
        int get_vclient_2();
        int get_vclient_3();
        void set_vclient_1(int client_id);
        void set_vclient_2(int client_id);
        void set_vclient_3(int client_id);
        friend ostream & operator<<(ostream& out, const Venue& x);

        friend class Company;
        friend class Client;
};

////////////////////////////////////////////
//               Client                   //
////////////////////////////////////////////

class Client{
    private:
        int budget;
        int number_of_guest;
        int client_id;
        int no_employees;
        int no_venues;
        int cvenue;
        int cemployee;
        
    public:
        Client(int budget, int number_of_guest, int client_id);                 //Constructor
        ~Client();                                                              //Destructor
        void print_client();                                                    //Print client's information
        int get_client_id();
        int get_no_employees();
        int get_no_venues();
        int get_cvenue();
        int get_cemployee();
        void set_no_employees(int x);
        void set_no_venues(int x);
        void set_cvenue(int venue_id);
        void set_cemployee(int employee_id);
        int get_number_of_guest();
        friend ostream & operator<<(ostream& out, const Client& x);
        
        friend class Company;
        friend class Employee;
        friend class Venue;
};

////////////////////////////////////////////
//               Company                  //
////////////////////////////////////////////

class Company{
    private:
        string company_name;
        int company_id;

        vector <Employee*> employees;
        vector <Client*> clients;
        vector <Venue*> venues;

        vector <Employee*> companys_employees;
        vector <Client*> companys_clients;
        vector <Venue*> companys_venues;

        int number_of_employees;
        int number_of_clients;
        int number_of_venues;

        int employees_count;
        int clients_count;
        int venues_count;
    
    public:
        Company(string company_name, int company_id);
        ~Company();

        int get_number_of_employees();
        int get_number_of_clients();
        int get_number_of_venues();
        int get_employees_count();
        int get_clients_count();
        int get_venues_count();

        void add_employee(string employee_name, int salary, int employee_id);   //Create an employee with given name, salary, ID
        void remove_employee(int employee_id);                                  //Remove an employee with given ID
        void hire_employee(int employee_id);                                    //Hire an employee with given ID
        void fire_employee(int employee_id);                                    //Fire an employee with given ID
        void add_venue(string venue_name, int price_per_guest, int venue_id);   //Create an venue with given name, price per guest, ID
        void remove_venue(int venue_id);                                        //Remove an venue with given ID
        void buy_venue(int venue_id);                                           //Buy a venue with given ID
        void sell_venue(int venue_id);                                          //Sell a venue with given ID
        void add_client(int budget, int number_of_guest, int client_id);        //Create an client with given budget, number of guests, ID
        void remove_client(int client_id);                                      //Remove an client with given ID

        void assign_employee (int client_id, int employee_id);                  //Assign an client with given ID to an amployee with given ID
        //void assign_venue (int client_id, int venue_id);                        //Assign an client with given ID to a venue with given ID

        void print();                                                           //Print all the data of the company
        void print_list_of_employees();                                         //Print list of employees
        void print_list_of_clients();                                           //Print list of clients
        void print_list_of_venues();                                            //Print list of venues
        void print_all();
        friend class Client;
        friend class Employee;
        friend class Venue;
};