#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#include "Header_Company.h"

using namespace std;

////////////////////////////////////////////
//               Employee                 //
////////////////////////////////////////////

Employee :: Employee(string employee_name, int salary, int employee_id){
    this -> employee_name = employee_name;
    this -> salary = salary;
    this -> employee_id = employee_id;
    this -> no_clients = 0;
    this -> eclient_1 = 0;
    this -> eclient_2 = 0;
}


Employee :: ~Employee(){

}


int Employee :: get_employee_id(){
    return this -> employee_id;
}


int Employee :: get_no_clients(){
    return this -> no_clients;
}


int Employee :: get_eclient_1(){
    return this -> eclient_1;
}


int Employee :: get_eclient_2(){
    return this -> eclient_2;
}


void Employee :: print_employee(){
    cout << " Name : " << employee_name << endl;
    cout << " Salary : " << salary << endl;
    cout << " ID : " << employee_id << endl;
    cout << '\n';
    cout << '\n';
}

bool Employee :: if_busy(){
    if(this -> no_clients != 2){
        return false;
    }
    else{
        return true;
    }
}


ostream & operator<<(ostream& out, const Employee& x){
    out << " Name : " << x.employee_name << endl;
    out << " Salary : " << x.salary << endl;
    out << " ID : " << x.employee_id << endl;
    out << '\n';
    out << '\n';
    return out;
}


void Employee :: set_eclient_1(int client_id){
    this -> eclient_1 = client_id;
}


void Employee :: set_eclient_2(int client_id){
    this -> eclient_2 = client_id;
}

void Employee :: set_no_clients(int x){
    this -> no_clients = x;
}

////////////////////////////////////////////
//               Client                   //
////////////////////////////////////////////

Client :: Client(int budget, int number_of_guest, int client_id){
    this -> budget = budget;
    this -> number_of_guest = number_of_guest;
    this -> client_id = client_id;
    this -> no_employees = 0;
    this -> no_venues = 0;
    this -> cvenue = 0;
    this -> cemployee = 0;
}


Client :: ~Client(){

}


void Client :: print_client(){
    cout << " Budget : " << budget << endl;
    cout << " Number of guests : " << number_of_guest << endl;
    cout << " ID : " << client_id << endl;
    cout << '\n';
    cout << '\n';
}


int Client :: get_client_id(){
    return this -> client_id;
}


int Client :: get_no_employees(){
    return this -> no_employees;
}


int Client :: get_no_venues(){
    return this -> no_venues;
}


int Client :: get_cvenue(){
    return this -> cvenue;
}


int Client :: get_cemployee(){
    return this -> cemployee;
}


int Client :: get_number_of_guest(){
    return this -> number_of_guest;
}


ostream & operator<<(ostream& out, const Client& x){
    out << " Budget : " << x.budget << endl;
    out << " Number of guests : " << x.number_of_guest << endl;
    out << " ID : " << x.client_id << endl;
    out << '\n';
    out << '\n';
    return out;
}


void Client :: set_cvenue(int venue_id){
    this ->  cvenue = venue_id;
}


void Client :: set_cemployee(int employee_id){
    this -> cemployee = employee_id;
}

void Client :: set_no_employees(int x){
    this -> no_employees = x;
}


void Client :: set_no_venues(int x){
    this -> no_venues = x;
}



////////////////////////////////////////////
//               Venue                    //
////////////////////////////////////////////

Venue :: Venue(string venue_name, int price_per_guest, int venue_id){
    this -> venue_name = venue_name;
    this -> price_per_guest = price_per_guest;
    this -> venue_id = venue_id;
    this -> vclient_1 = 0;
    this -> vclient_2 = 0;
    this -> vclient_3 = 0;
    this -> number_of_places = 0;
}


Venue :: ~Venue(){

}


void Venue :: print_venue(){
    cout << " Name : " << venue_name << endl;
    cout << " Price per guest : " << price_per_guest << endl;
    cout << " ID : " << venue_id << endl;
    cout << '\n';
    cout << '\n';
}


bool Venue :: if_any_spots_left(){
    if(this -> number_of_places < 40){
        return true;
    }
    else{
        return false;
    }
}


int Venue :: get_venue_id(){
    return this -> venue_id;
}


int Venue :: get_number_of_places(){
    return this -> number_of_places;
}


int Venue :: get_vclient_1(){
    return this -> vclient_1;
}


int Venue :: get_vclient_2(){
    return this -> vclient_2;
}


int Venue :: get_vclient_3(){
    return this -> vclient_3;
}


ostream & operator<<(ostream& out, const Venue& x){
    out << " Name : " << x.venue_name << endl;
    out << " Price per guest : " << x.price_per_guest << endl;
    out << " ID : " << x.venue_id << endl;
    out << '\n';
    out << '\n';
    return out;
}

void Venue :: set_vclient_1(int client_id){
    this -> vclient_1 = client_id;
}


void Venue :: set_vclient_2(int client_id){
    this -> vclient_2 = client_id;
}


void Venue :: set_vclient_3(int client_id){
    this -> vclient_3 = client_id;
}

void Venue :: set_number_of_places(int x){
    this -> number_of_places = x;
}
////////////////////////////////////////////
//               Company                  //
////////////////////////////////////////////

Company :: Company(string company_name, int company_id){
    this -> company_id = company_id;
    this -> company_name = company_name;
    this -> number_of_employees = 0;
    this -> number_of_clients = 0;
    this -> number_of_venues = 0;
    this -> employees_count = 0;
    this -> clients_count = 0;
    this -> venues_count = 0;
}


Company :: ~Company(){
    for ( int i = 0; i < employees.size(); i++ ){       
        delete employees[i];    
    }    
    employees.clear();

    for ( int l = 0; l < employees.size(); l++ ){       
        delete clients[l];    
    } 
    clients.clear();

    for ( int k = 0; k < employees.size(); k++ ){       
        delete venues[k];    
    } 
    venues.clear();
    
    companys_employees.clear();
    companys_clients.clear();
    companys_venues.clear();
}


int Company :: get_number_of_employees(){
    return this -> number_of_employees;
}


int Company :: get_number_of_clients(){
    return this -> number_of_clients;
}


int Company :: get_number_of_venues(){
    return this -> number_of_venues;
}


int Company :: get_employees_count(){
    return this -> employees_count;
}


int Company :: get_clients_count(){
    return this -> clients_count;
}


int Company :: get_venues_count(){
    return this -> venues_count;
}


void Company :: add_employee(string employee_name, int salary, int employee_id){
    if(this -> employees_count ==0){
        Employee *cr = nullptr;
        cr = new Employee(employee_name, salary, employee_id);
        employees.push_back(cr);
        this -> employees_count++;
    }
    else{
        for(int y = 0; y < employees.size(); y++){
            if (employee_id != employees[y] -> get_employee_id()){
                Employee *cr = nullptr;
                cr = new Employee(employee_name, salary, employee_id);
                employees.push_back(cr);
                this -> employees_count++;
            }
            break;
        }
    }
}



void Company :: remove_employee(int employee_id){
    if(this -> employees_count == 0){
        cout<<"error: cannot remove an employee that does not exist"<<endl;
    }
    else{
        for( int y = 0 ; y < this -> employees.size(); y++){

            for( int y = 0 ; y < companys_employees.size(); y++){
            if(companys_employees[y] -> get_employee_id() == employee_id){
                this -> number_of_employees--;
                companys_employees.erase(companys_employees.begin() + y);
                break;
            }
            else if (y == companys_employees.size() - 1){
                break;
            }
        }

            if(employees[y] -> get_employee_id() == employee_id){
                employees.erase(employees.begin() + y);
                this -> employees_count--;
                break;
            }
            else if (y == this -> employees.size() - 1){
                cout<<"error: cannot remove an employee that does not exist"<<endl;
                break;
            }
        }
    }
}


void Company :: hire_employee(int employee_id){
    if(this -> employees_count == 0){
        cout<<"error: cannot hire an employee that does not exist"<<endl;
    }
    else{
        for( int y = 0 ; y < employees.size(); y++){
            if(employees[y] -> get_employee_id() == employee_id){
                if(this -> number_of_employees == 3){
                    cout<<"error: the company cannot have more than 3 employees"<<endl;
                    break;
                }
                else{
                    this -> number_of_employees++;
                    Employee *ar = nullptr;
                    ar = employees[y];
                    companys_employees.push_back(ar);
                    break;
                }
            }
            else if (y == employees.size() - 1){
                cout<<"error: cannot hire an employee that does not exist"<<endl;
                break;
            }
        }
    }
}


void Company :: fire_employee(int employee_id){
    if(this -> number_of_employees == 0){
        cout<<"error: cannot fire an employee that does not exist"<<endl;
    }
    else{
        for( int y = 0 ; y < companys_employees.size(); y++){
            if(companys_employees[y] -> get_employee_id() == employee_id){
                this -> number_of_employees--;
                companys_employees.erase(companys_employees.begin() + y);
                break;
            }
            else if (y == companys_employees.size() - 1){
                cout<<"error: cannot fire an employee that does not exist"<<endl;
                break;
            }
        }
    }
}


void Company :: add_venue(string venue_name, int price_per_guest, int venue_id){
    if(price_per_guest < 101){
       if(this -> venues_count ==0){
        Venue *cs = nullptr;
        cs = new Venue(venue_name, price_per_guest, venue_id);
        venues.push_back(cs);
        this -> venues_count++;
        }
        else{
            for(int y = 0; y < venues.size(); y++){
                if (venue_id != venues[y] -> get_venue_id()){
                    Venue *cs = nullptr;
                    cs = new Venue(venue_name, price_per_guest, venue_id);
                    venues.push_back(cs);
                    this -> venues_count++;
                }
                break;
            }
        }
    }
    else{
        cout<<"error: the venue cannot charge more than 100 per guest"<<endl;
    }   
}



void Company :: remove_venue(int venue_id){
    if(this -> venues_count == 0){
        cout<<"error: cannot remove a venue that does not exist"<<endl;
    }
    else{

        for( int y = 0 ; y < companys_venues.size(); y++){
            if(companys_venues[y] -> get_venue_id() == venue_id){
                this -> number_of_venues--;
                companys_venues.erase(companys_venues.begin() + y);
                break;
            }
            else if (y == companys_venues.size() - 1){
                cout<<"error: cannot sell a venue that does not exist"<<endl;
                break;
            }
        }
        
        for( int y=0 ; y < this -> venues.size(); y++){
            if(venues[y] -> get_venue_id() == venue_id){
                venues.erase(venues.begin() + y);
                this -> venues_count--;
                break;
            }
            else if (y == this -> venues.size() - 1){
                cout<<"error: cannot remove a venue that does not exist"<<endl;
                break;
            }
        }
    }
}


void Company :: buy_venue(int venue_id){
    if(this -> venues_count == 0){
        cout<<"error: cannot buy a venue that does not exist"<<endl;
    }
    else{
        for( int y = 0 ; y < venues.size(); y++){
            if(venues[y] -> get_venue_id() == venue_id){
                if(this -> number_of_venues == 2){
                    cout<<"error: the company cannot have more than 2 venues"<<endl;
                    break;
                }
                else{
                    this -> number_of_venues++;
                    Venue *as = nullptr;
                    as = venues[y];
                    companys_venues.push_back(as);
                    break;
                }
            }
            else if (y == venues.size() - 1){
                cout<<"error: cannot buy a venue that does not exist"<<endl;
                break;
            }
        }
    }
}


void Company :: sell_venue(int venue_id){
    if(this -> number_of_venues == 0){
        cout<<"error: cannot sell a venue that does not exist"<<endl;
    }
    else{
        for( int y = 0 ; y < companys_venues.size(); y++){
            if(companys_venues[y] -> get_venue_id() == venue_id){
                this -> number_of_venues--;
                companys_venues.erase(companys_venues.begin() + y);
                break;
            }
            else if (y == companys_venues.size() - 1){
                cout<<"error: cannot sell a venue that does not exist"<<endl;
                break;
            }
        }
    }
}



void Company :: add_client(int budget, int number_of_guest, int client_id){
    if(number_of_guest < 21){
        if(this -> clients_count == 0){
            Client *cf = nullptr;
            cf = new Client(budget, number_of_guest, client_id);
            clients.push_back(cf);
            this -> clients_count++;
        }
        else{
            for(int y = 0; y < clients.size(); y++){
                if (client_id != clients[y] -> get_client_id()){
                    Client *cf = nullptr;
                    cf = new Client(budget, number_of_guest, client_id);
                    clients.push_back(cf);
                    this -> clients_count++;
                }
                break;
            }
        }
    }
    else{
        cout<<"error: the client cannot have more than 20 guest"<<endl;
    }
}



void Company :: remove_client(int client_id){
    if(this -> clients_count == 0){
        cout<<"error: cannot remove a client that does not exist"<<endl;
    }
    else{

        for( int y = 0 ; y < companys_clients.size(); y++){
            if(companys_clients[y] -> get_client_id() == client_id){
                this -> number_of_clients--;
                companys_clients.erase(companys_clients.begin() + y);
                break;
            }
            else if (y == companys_clients.size() - 1){
                break;
            }
        }

        for( int y=0 ; y < this -> clients.size(); y++){
            if(clients[y] -> get_client_id() == client_id){
                clients.erase(clients.begin() + y);
                clients_count--;
                break;
            }
            else if (y == this -> clients.size() - 1){
                cout<<"error: cannot remove a client that does not exist"<<endl;
                break;
            }
        }
    }
}

/*
void Company :: assign_employee (int client_id, int employee_id){
    Employee* employee=nullptr;
    Client* client=nullptr;
    for(int i=0;i<companys_employees.size();i++) {
        if(companys_employees[i]->get_employee_id()==employee_id)
        employee=companys_employees[i];
    }
    if(employee==nullptr)
    cout<<"employee not found";
    for(int i=0;i<clients.size();i++) {
        if(clients[i]->get_client_id()==client_id)
    client=clients[i];
    }
    if(client==nullptr)
    cout<<"client not found";
    if(client->no_employees==0) {
        client->set_cemployee(employee_id);
        client->set_no_employees(1);
        
    }
    else{
        cout<<"error: client cannot work with more than 1 employee at once"<<endl;
    }
    if(employee->no_clients<3){
        if(employee->eclient_1==0){
            employee->set_eclient_1(client_id);
            employee->set_no_clients(employee->get_no_clients()+1);
            companys_clients.push_back(client);
        }
        else if(employee->eclient_2==0){
            employee->set_eclient_2(client_id);
            employee->set_no_clients(employee->get_no_clients()+1);
            companys_clients.push_back(client);
        }
    }
    else {
        cout<<"error: employee cannot work with more than 2 clients at once"<<endl;
    }
}
*/





void Company :: assign_employee (int client_id, int employee_id){
    for( int y = 0 ; y < clients.size(); y++){
        if(clients[y] -> get_client_id() == client_id){

            for( int i = 0 ; i < companys_employees.size(); i++){
                if(companys_employees[i] -> get_employee_id() == employee_id){

                    if(clients[y] -> get_no_employees() != 1){
                        if(companys_employees[i] -> get_no_clients() != 2){

                            if(companys_employees[i] -> get_eclient_1() == 0){

                                if(this -> number_of_clients == 3){
                                    cout<<"error: the company cannot have more than 3 cliets at once";
                                }
                                else{
                                    int u = companys_employees[i] -> get_no_clients();
                                    u += 1;
                                    companys_employees[i] -> set_no_clients(u);

                                    int v = clients[y] -> get_no_employees();
                                    v += 1;
                                    clients[y] -> set_no_employees(v);

                                    clients[y] -> set_cemployee(companys_employees[i] -> get_employee_id());
                                    companys_employees[i] ->  set_eclient_1(clients[y] -> get_client_id());

                                    Client *ch = nullptr;
                                    ch = clients[y];
                                    companys_clients.push_back(ch);
                                    this -> number_of_clients++;
                                }
                            }
                            else{
                                if(this -> number_of_clients == 3){
                                    cout<<"error: the company cannot have more than 3 cliets at once";
                                }
                                else{
                                    int u = companys_employees[i] -> get_no_clients();
                                    u += 1;
                                    companys_employees[i] -> set_no_clients(u);

                                    int v = clients[y] -> get_no_employees();
                                    v += 1;
                                    clients[y] -> set_no_employees(v);

                                    clients[y] -> set_cemployee(companys_employees[i] -> get_employee_id());
                                    companys_employees[i] ->  set_eclient_2(clients[y] -> get_client_id());

                                    Client *ch = nullptr;
                                    ch = clients[y];
                                    companys_clients.push_back(ch);
                                    this -> number_of_clients++;
                                }
                            }
                        }
                        else{
                            cout<<"error: employee cannot work with more than 2 clients at once"<<endl;
                        }
                    }
                    else{
                        cout<<"error: client cannot work with more than 1 employee at once"<<endl;
                    }
                }
                else if (i == this -> companys_employees.size() ){
                    cout<<"error: employee with give ID does not exist"<<endl;
                    break;
                }
            }
        }
        else if (y == this -> companys_clients.size() ){
            cout<<"error: client with given ID does not exist"<<endl;
            break;
        }
    }
}

void Company :: print_list_of_employees(){
    if(this -> number_of_employees == 0){
        cout << "no employees" << endl;
        cout << '\n';
    }
    else{
        for (int i = 0; i < companys_employees.size() ; i++) {
        cout << " Name : " << companys_employees[i] -> employee_name << endl;
        cout << " Salary : " << companys_employees[i] -> salary << endl;
        cout << " ID : " << companys_employees[i] -> employee_id << endl;
        cout << '\n';
        cout << '\n';
        }
    }
}


void Company :: print_list_of_clients(){


        for (int i = 0; i < companys_clients.size() ; i++) {
        cout << " Budget : " << companys_clients[i] -> budget << endl;
        cout << " Number of guests : " << companys_clients[i] -> number_of_guest << endl;
        cout << " ID : " << companys_clients[i] -> client_id << endl;
        cout << '\n';
        cout << '\n';
        }
    
}


void Company :: print_list_of_venues(){
    if(this -> number_of_venues == 0){
        cout << "no venues" << endl;
        cout << '\n';
    }
    else{
        for (int i = 0; i < companys_venues.size() ; i++) {
        cout << " Name : " << companys_venues[i] -> venue_name << endl;
        cout << " Price per guest : " << companys_venues[i] -> price_per_guest << endl;
        cout << " ID : " << companys_venues[i] -> venue_id << endl;
        cout << '\n';
        cout << '\n';
        }
    }
}


void Company :: print(){
    print_list_of_employees();
    print_list_of_clients();
    print_list_of_venues();
}