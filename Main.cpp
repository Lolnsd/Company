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

int main(){
    
    //First scenario   (Testing operations on non-existing objects and creating objects with the wrong values)
    cout<<"Company A"<<endl;
    Company A = Company ("A", 1111);
    A.remove_employee(101);               //error: cannot remove an employee that does not exist
    A.hire_employee(102);                 //error: cannot hire an employee that does not exist
    A.fire_employee(103);                 //error: cannot fire an employee that does not exist
    A.buy_venue(302);                     //error: cannot buy a venue that does not exist
    A.sell_venue(303);                    //error: cannot sell a venue that does not exist
    A.remove_venue(301);                  //error: cannot remove a venue that does not exist
    A.remove_client(201);                 //error: cannot remove a client that does not exist
    A.add_client(3000, 21, 999);          //error: the client cannot have more than 20 guest
    A.add_venue("Lillies", 200, 999);     //error: the venue cannot charge more than 100 per guest
    A.print();
    cout<<"\n"<<endl;
    cout<<"\n"<<endl;



    //Second scenario  (Printing lists for an empty company)
    cout<<"Company B"<<endl;
    Company B = Company ("B", 2222);
    B.print();                            //output: no employees, no clients, no venues
    B.print_list_of_employees();          //output: no employees
    B.print_list_of_clients();            //output: no clients
    B.print_list_of_venues();             //output: no venues
    cout<<"\n"<<endl;
    cout<<"\n"<<endl;



    //Third scenario   (Testing the errors for assigning an existing to a non-existing object)
    cout<<"Company C"<<endl;
    Company C = Company ("C", 3333);
    C.add_employee("John", 100, 111);      //add John with salary = 100 and id = 111
    C.add_client(1500, 15, 222);           //add client with budget = 1500, number of guests = 15 and id = 222
    C.add_venue("Pollis", 55, 333);        //add venue with name = Pollis, price per guest = 55 and id = 333
    C.hire_employee(111);
    C.buy_venue(333);
    C.print();
    cout<<"\n"<<endl;
    cout<<"\n"<<endl;



    //Fourth scenario   (Testing all the operations in the correct way)
    cout<<"Company D"<<endl;
    Company D = Company ("D", 4444);
    D.add_employee("Jill", 1000, 191);    //add Jill with salary = 1000 and id = 191
    D.add_client(1500, 15, 292);          //add client with budget = 1500, number of guests = 15 and id = 292
    D.add_venue("Jackies", 100, 393);     //add venue with name = Jackies, price per guest = 100 and id = 393
    D.hire_employee(191);                 //hire Jill
    D.buy_venue(393);                     //buy Jackies
    D.print();
    D.remove_employee(191);
    D.fire_employee(191);                 //fire Jill
    D.remove_venue(393);
    D.sell_venue(393);
    D.remove_venue(393);                  //sell Jackies
    D.remove_client(292);                 //remove client with ID 292
    D.remove_employee(191);               //remove Jill    
    D.print();
    cout<<"\n"<<endl;
    cout<<"\n"<<endl;

    //Test scenario
    cout<<"Company T"<<endl;
    Company *test = new Company ("test", 5555);
    test -> add_employee("Bill", 111, 156);       //add Bill with salary = 111 and id = 156
    test -> add_employee("Gill", 222, 157);       //add Gill with salary = 222 and id = 157
    test -> add_employee("Mill", 333, 158);       //add Mill with salary = 333 and id = 158
    test -> add_employee("Kill", 444, 159);       //add Kill with salary = 444 and id = 159
    test -> add_venue("Billies", 11, 356);        //add venue with name = Billies, price per guest = 11 and id = 356
    test -> add_venue("Gillies", 22, 357);        //add venue with name = Gillies, price per guest = 22 and id = 357
    test -> add_venue("Millies", 33, 358);        //add venue with name = Millies, price per guest = 33 and id = 358
    test -> add_client(2000, 15, 256);            //add client with budget = 2000, number of guests = 15 and id = 256
    test -> add_client(2000, 15, 257);            
    test -> add_client(2000, 15, 258);            
    test -> add_client(2000, 15, 259);            
    test -> hire_employee(156);                         
    test -> buy_venue(356);   
    test -> print();
    delete test;


    //Fifth scenario   (Testing the limits)
    cout<<"Company E"<<endl;
    Company E = Company ("E", 5555);
    E.add_employee("Bill", 111, 156);       //add Bill with salary = 111 and id = 156
    E.add_employee("Gill", 222, 157);       //add Gill with salary = 222 and id = 157
    E.add_employee("Mill", 333, 158);       //add Mill with salary = 333 and id = 158
    E.add_employee("Kill", 444, 159);       //add Kill with salary = 444 and id = 159
    E.add_venue("Billies", 11, 356);        //add venue with name = Billies, price per guest = 11 and id = 356
    E.add_venue("Gillies", 22, 357);        //add venue with name = Gillies, price per guest = 22 and id = 357
    E.add_venue("Millies", 33, 358);        //add venue with name = Millies, price per guest = 33 and id = 358
    E.add_client(2000, 15, 256);            //add client with budget = 2000, number of guests = 15 and id = 256
    E.add_client(2000, 15, 257);            //add client with budget = 2000, number of guests = 15 and id = 257
    E.add_client(2000, 15, 258);            //add client with budget = 2000, number of guests = 15 and id = 258
    E.add_client(2000, 15, 259);            //add client with budget = 2000, number of guests = 15 and id = 259
    E.hire_employee(156);                   //hire Bill
    E.hire_employee(157);                   //hire Gill
    E.hire_employee(158);                   //hire Mill
    E.hire_employee(159);                   //error: the company cannot have more than 3 employees
    E.print_list_of_employees();
    E.buy_venue(356);                       //buy Billies
    E.buy_venue(357);                       //buy Gillies
    E.buy_venue(358);                       //error: the company cannot have more than 2 venues
    E.print_list_of_venues();
    cout<<"\n"<<endl;
    cout<<"\n"<<endl;

    E.assign_employee(256, 156);          //assign client with ID 256 to Bill
    E.assign_employee(256, 157);          //error: client cannot work with more than 1 employee at once
    E.assign_employee(257, 156);          //assign client with ID 257 to Bill
    E.assign_employee(258, 156);          //error: employee cannot work with more than 2 clients at once
    E.assign_employee(259, 157);          //assign client with ID 259 to Gill
    E.assign_employee(258, 157);          //error: the company cannot have more than 3 cliets at once

    E.print_list_of_clients();


    cout<<"End"<<endl;

    E.remove_client(256);
    E.remove_client(257);
    E.remove_client(258);
    
    E.print_list_of_clients();

    

}