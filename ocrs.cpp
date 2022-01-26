//Source code for my project: a car rental system.
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <unistd.h>
#include <string>

//Variables
    const std::string car[10]={"BMW", "Opel", "Nissan", "Ferrari", "Mitsubishi", "Seat", "Mercedes", "Porsche", "Tesla", "Volkswagen"};
    std::string bmw[5]={"M3","M4","M8","Z4","X5"};
    std::string opel[5]={"Corsa","Astra","Agila","Calibra","Manta"};
    std::string nissan[5]={"Versa","Sentra","Altima","GT-R","LEAF"};
    std::string ferrari[5]={"Enzo","Spider","Roma","California","599XX"};
    std::string mitsubishi[5]={"Mirage","Outlander","Outlander-Sport","Eclipse-Cross","Mirage-C4"};
    std::string seat[5]={"Ibiza","Arona","Tarraco","Mii","Leon"};
    std::string mercedes[5]={"Benz-GLA-Class","Benz-SL-Class","Benz-AMG-GT","Benz-A-Class","Benz-B-Class"};
    std::string porsche[5]={"Speedster","911","911-Turbo","Spyder","Boxster"};
    std::string tesla[5]={"Roadster","Cybertruck","Model-3","Model-S","Model-Y"};
    std::string volkswagen[5]={"Golf","Polo","Passat","Scirroco","Santana"};   
    char list_conf;
    char return_car_cont;
    int total_price;
    char menu_choice;
    int contact_choice=0,report_choice=0, return_car_cont_s;
    int total_days = 0;
    char menu_cont;
    std::string reservation_choice, reservation_model_choice;
    std::string list_choice;
    std::string fname, lname;
    bool is_rented;

      
    
//Functions

void main_menu() //Main menu function
{
    std::cout<<"1. List available cars.\n";
    std::cout<<"2. Make a reservation.\n";
    std::cout<<"3. Return a car.\n";
    std::cout<<"4. Report.\n";
    std::cout<<"5. Contact.\n";
    std::cout<<"6. Check Current Prices.\n";
    std::cout<<"7. Exit\n";
    return;
}
void contact(){ //Contact Function

    char contact_cont;
    do{
    system("cls || clear");
    std::cout<<"Please choose how you would like to contact us:\n";
    std::cout<<"Press 1 to contact us via E-Mail.\n";
    std::cout<<"Press 2 to contact us via telephone.\n";
    std::cout<<"Press 3 to contact us via mail.\n";
    std::cout<<"Press 4 to return to the main menu.\n";
    std::cin>>contact_choice;
        switch(contact_choice)
        {
            case 1:
            system("firefox mailto::ocrs@ocrs.com");
            std::cout<<"Do you want to return to the Contact menu?\n (y) for yes (n) for no\n";
            std::cin>>contact_cont;
            break;

            case 2:
            system("firefox tel:55545754484");
            std::cout<<"Do you want to return to the Contact menu?\n (y) for yes (n) for no\n";
            std::cin>>contact_cont;
            break;

            case 3:
            std::cout<<"You can send your mail at the following address: \n54124, Bleeker Streek 02, New York, USA.\n";
            std::cout<<"Do you want to return to the Contact menu?\n (y) for yes (n) for no\n";
            std::cin>>contact_cont;
            break;

            case 4:
            std::cout<<"Returning to main menu.\n";
            sleep(2);
            break;

            default:
            std::cout<<"Please choose one of the correct options.\n";
            break;

        }
    }while(contact_choice!=4 && contact_cont !='n');
}
void report(){ //Report Function
    char report_cont,report_confirm;
    std::string user_report1,user_report2,user_report3;
    do{
    system("cls || clear");
    report_choice = 0;
    std::cout<<"Thank you for reporting to us.\n";
    std::cout<<"To report a damaged car, please press 1.\nTo report a stolen car, please press 2.\nTo report anything else, please press 3.\nTo return to the main menu, please press 4.\n";
    std::cin>>report_choice;
    if(report_choice==1)
    {
        std::cout<<"Please write to us in detail, what the exact damages to the car are: \n";
        std::cin>>user_report1;
        std::cout<<"Your report is as follows: \n "<<user_report1<<"\n";
        std::cout<<"Are you sure you want to submit your report? (y) for yes (n) for no\n";
        std::cin>>report_confirm;
        if(report_confirm == 'y')
        {
            std::cout<<"Your report has been submitted.\n";
            break;
        }
        else
        {
            std::cout<<"Your report has been discarded.\n";
            break;
        }
    }
    else if(report_choice==2)
    {
        
        std::cout<<"Please write to us in detail what happened when the car was stolen, if there were witnesses etc.\n";
        std::cin>>user_report2;
        std::cout<<"Your report is as follows: \n "<<user_report2<<"\n";
        std::cout<<"Are you sure you want to submit your report? (y) for yes (n) for no\n";
        std::cin>>report_confirm;
        if(report_confirm == 'y')
        {
            std::cout<<"Your report has been submitted.\n";
            break;
        }
        else
        {
            std::cout<<"Your report has been discarded.\n";
            break;
        }

    }
    else if(report_choice==3)
    {
        std::cout<<"Please write to us in detail, anything that you want to report, that is not related to car damage and/or theft.\n";
        std::cin>>user_report3;
        std::cout<<"Your report is as follows: \n "<<user_report3<<"\n";
        std::cout<<"Are you sure you want to submit your report? (y) for yes (n) for no\n";
        std::cin>>report_confirm;
        if(report_confirm == 'y')
        {
            std::cout<<"Your report has been submitted.\n";
            break;
        }
        else
        {
            std::cout<<"Your report has been discarded.\n";
            break;
        }
    }

    } while(report_choice!=4 && report_cont !='n');
}
void list_cars(){ //List Cars Function
    std::string list_choice_num;
    std::string list_choice_quit;
    char list_cont;
    do{
    system("cls || clear");
    std::cout<<"The available car manufacturers are the following: \n\n";
    for(int i=0;i<10;i++){
        std::cout<<car[i]<<std::endl;
        
    } 
    std::cout<<"\n\n";
    std::cout<<"To list all car models from a specific car manufacturer, please type 1.\nTo go back to the main menu, please press 0.\n";
    std::cin>> list_choice_num;
    do{
    if(list_choice_num == "1"){
        std::cout<<"Please type the manufacturers name: \n";
        std::cin>>list_choice;
        if(list_choice == car[0]){
            std::string bmw[5]={"M3","M4","M8","Z4","X5"};
            for(int i=0;i<5;i++){
                std::cout<<bmw[i]<<std::endl;  
                      
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        
        }
       else if(list_choice == car[1]){
            std::string opel[5]={"Corsa","Astra","Agila","Calibra","Manta"};
            for(int i=0;i<5;i++){
                std::cout<<opel[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else if(list_choice == car[2]){
            std::string nissan[5]={"Versa","Sentra","Altima","GT-R","LEAF"};
            for(int i=0;i<5;i++){
                std::cout<<nissan[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
         else if(list_choice == car[3]){
            std::string ferrari[5]={"Enzo","Spider","Roma","California","599XX"};
            for(int i=0;i<5;i++){
                std::cout<<ferrari[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else if(list_choice == car[4]){
            std::string mitsubishi[5]={"Mirage","Outlander","Outlander-Sport","Eclipse-Cross","Mirage-C4"};
            for(int i=0;i<5;i++){
                std::cout<<mitsubishi[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else if(list_choice == car[5]){
            std::string seat[5]={"Ibiza","Arona","Tarraco","Mii","Leon"};
            for(int i=0;i<5;i++){
                std::cout<<seat[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else if(list_choice == car[6]){
            std::string mercedes[5]={"Benz-GLA-Class","Benz-SL-Class","Benz-AMG-GT","Benz-A-Class","Benz-B-Class"};
            for(int i=0;i<5;i++){
                std::cout<<mercedes[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else if(list_choice == car[7]){
            std::string porsche[5]={"Speedster","911","911-Turbo","Spyder","Boxster"};
            for(int i=0;i<5;i++){
                std::cout<<porsche[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else if(list_choice == car[8]){
            std::string tesla[5]={"Roadster","Cybertruck","Model-3","Model-S","Model-Y"};
            for(int i=0;i<5;i++){
                std::cout<<tesla[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else if(list_choice == car[9]){
            std::string volkswagen[5]={"Golf","Polo","Passat","Scirroco","Santana"};
            for(int i=0;i<5;i++){
                std::cout<<volkswagen[i]<<std::endl;         
            }
        std::cout<<"Type (r) to go back.\n";
        std::cin>>list_conf;
        }
        else{
        std::cout<<"No car manufacturer found.\n\n";
        }
        
    }
    
    else if(list_choice_num !="0"){
        system("cls || clear");
        std::cout<<"Wrong input. Please try again.\n";
        break;
        }
     
    else{
        std::cout<<"Going back to main menu.\n";
        sleep(2);
        break;
    }    
        }while(list_conf!='r');
       
    }while(list_cont!='n' && list_choice_num!="0" && list_conf != 'r');
    
}
void reservation(){ //Reservation Fucntion
    char reservation_cont;
    int reservation_confirm;
    std::string selected_car;
    
     if (is_rented == true){
        std::cout<<"You have already rented a car.\n";
        sleep(3);
        
        
    }
    else{
    do{
    
    std::cout<<"Please type in how many days you want to rent the car: \n";
    std::cin>>total_days;
    while (!total_days){
        std::cout<<"Please enter a number!\n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin>>total_days;
    }
    std::cout<<"Please select a car manufacturer from the list in option number 1. or type (r) to return: \n";
    std::cin >> reservation_choice;
    if(reservation_choice == car[0]){
        std::cout<<"You have selected: "<<car[0]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<bmw[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == bmw[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[0]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == bmw[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[0]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == bmw[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[0]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == bmw[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[0]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == bmw[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[0]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;

        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[1]){
        std::cout<<"You have selected: "<<car[1]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<opel[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == opel[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[1]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == opel[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[1]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == opel[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[1]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == opel[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[1]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == opel[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[1]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[2]){
        std::cout<<"You have selected: "<<car[2]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<nissan[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == nissan[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[2]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == nissan[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[2]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == nissan[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[2]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == nissan[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[2]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == nissan[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[2]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[3]){
        std::cout<<"You have selected: "<<car[3]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<ferrari[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == ferrari[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[3]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == ferrari[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[3]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == ferrari[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[3]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == ferrari[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[3]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == ferrari[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[3]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[4]){
        std::cout<<"You have selected: "<<car[4]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<mitsubishi[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == mitsubishi[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[4]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mitsubishi[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[4]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mitsubishi[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[4]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mitsubishi[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[4]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mitsubishi[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[4]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[5]){
        std::cout<<"You have selected: "<<car[5]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<seat[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == seat[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[5]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == seat[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[5]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == seat[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[5]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == seat[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[5]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == seat[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[5]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[6]){
        std::cout<<"You have selected: "<<car[6]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<mercedes[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == mercedes[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[6]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mercedes[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[6]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mercedes[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[6]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mercedes[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[6]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == mercedes[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[6]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[7]){
        std::cout<<"You have selected: "<<car[7]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<porsche[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == porsche[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[7]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == porsche[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[7]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == porsche[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[7]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == porsche[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[7]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == porsche[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[7]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[8]){
        std::cout<<"You have selected: "<<car[8]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<tesla[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == tesla[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[8]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == tesla[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[8]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == tesla[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[8]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == tesla[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[8]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == tesla[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[8]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == car[9]){
        std::cout<<"You have selected: "<<car[9]<<std::endl;
        std::cout <<"The available cars are: \n";
        for(int i=0; i<5; i++){
            std::cout<<volkswagen[i]<<std::endl;
        }
        std::cout<<"Please select a model: \n";
        std::cin>>reservation_model_choice;
        do{
        if(reservation_model_choice == volkswagen[0]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[9]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == volkswagen[1]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[9]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == volkswagen[2]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[9]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == volkswagen[3]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[9]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else if(reservation_model_choice == volkswagen[4]){
                std::cout<<"You have selected the "<<reservation_model_choice<<"."<<std::endl;
                std::cout<<"Are you sure you want to rent that car?: (1) to confirm (0) to return\n";
                std::cin>>reservation_confirm;
                if(reservation_confirm == 1){
                    is_rented = true;
                    std::cout<<"Congratulations, you have succesfully rented the "<<car[9]<<" "<<reservation_model_choice<<"."<<std::endl;
                }
                else{
                std::cout<<"You have aborted the renting process.\n";
                break;
                }
        }
        else{
            std::cout<<"The model you have entered is ivalid.\n";
            break;
        }
        } while(reservation_confirm !=0 && is_rented == false);
        std::cout << "Type (b) to go back to the main menu.\n";
        std::cin>>reservation_cont;
    }
    else if(reservation_choice == "r"){
        std::cout<<"Going back to main menu.\n";
        sleep(2);
        std::system("clear || cls");
        break;
    }
    else{
        std::cout<<"No such car manufacturer found.\n\nPlease use the option number 1. to list all car manufacturers.\n";
        std::cout<<"Going back to main menu.\n";
        sleep(3);
        std::system("clear || cls");
        break;
    }
 }while (reservation_cont != 'b' && reservation_choice != "r" && is_rented == false);
    
    }
}
void return_car(){ //Return Car Function


//int bmw_m3 = 0,bmw_m4 = 0,bmw_m8 = 0,bmw_z4 = 0,bmw_x5 = 0;
int bmw_p[5] = {100,200,300,400,500};
int opel_p[5] = {100,200,300,400,500};
int nissan_p[5] = {100,200,300,400,500};
int ferrari_p[5] = {100,200,300,400,500};
int mitsubishi_p[5] = {100,200,300,400,500};
int seat_p[5] = {100,200,300,400,500};
int mercedes_p[5] = {100,200,300,400,500};
int porsche_p[5] = {100,200,300,400,500};
int tesla_p[5] = {100,200,300,400,500};
int volkswagen_p[5] = {100,200,300,400,500};

    do{
        if(is_rented==true){
            if(reservation_choice == car[0]){
                if(reservation_model_choice == bmw[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * bmw_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == bmw[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * bmw_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == bmw[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * bmw_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == bmw[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * bmw_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == bmw[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * bmw_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[1]){
                if(reservation_model_choice == opel[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * opel_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == opel[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * opel_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == opel[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * opel_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == opel[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * opel_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == opel[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * opel_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[2]){
                if(reservation_model_choice == nissan[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * nissan_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == nissan[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * nissan_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == nissan[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * nissan_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == nissan[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * nissan_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == nissan[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * nissan_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[3]){
                if(reservation_model_choice == ferrari[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * ferrari_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == ferrari[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * ferrari_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == ferrari[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * ferrari_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == ferrari[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * ferrari_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == ferrari[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * ferrari_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[4]){
                if(reservation_model_choice == mitsubishi[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mitsubishi_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mitsubishi[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mitsubishi_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mitsubishi[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mitsubishi_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mitsubishi[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mitsubishi_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mitsubishi[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mitsubishi_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[5]){
                if(reservation_model_choice == seat[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * seat_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == seat[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * seat_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == seat[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * seat_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == seat[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * seat_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == seat[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * seat_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[6]){
                if(reservation_model_choice == mercedes[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mercedes_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mercedes[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mercedes_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mercedes[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mercedes_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mercedes[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mercedes_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == mercedes[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * mercedes_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[7]){
                if(reservation_model_choice == porsche[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * porsche_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == porsche[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * porsche_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == porsche[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * porsche_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == porsche[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * porsche_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == porsche[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * porsche_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[8]){
                if(reservation_model_choice == tesla[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * tesla_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == tesla[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * tesla_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == tesla[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * tesla_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == tesla[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * tesla_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == tesla[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * tesla_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
            else if(reservation_choice == car[9]){
                if(reservation_model_choice == volkswagen[0]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * volkswagen_p[0];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == volkswagen[1]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * volkswagen_p[1];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == volkswagen[2]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * volkswagen_p[2];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == volkswagen[3]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * volkswagen_p[3];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        }
                    
                }
                else if(reservation_model_choice == volkswagen[4]){
                    std::cout<<"You rented the "<<reservation_choice<< " "<<reservation_model_choice<<" "<<"for "<<total_days<<" days.\n";
                    total_price = total_days * volkswagen_p[4];
                    std::cout<<"The total price for the car is: $"<<total_price<<std::endl;
                    std::cout<<"Do you really want to return the "<<reservation_choice<<" "<<reservation_model_choice<<"?"<< " (y) for yes or (n) for no."<<std::endl;
                    std::cin>>return_car_cont;
                        if(return_car_cont == 'y'){
                            is_rented = false;
                            std::cout<<"Please wait.\n";
                            sleep(5);
                            std::cout<<"Car successfully returned.\n";
                            std::cout<<"Press 1 to return to the main menu.\n";
                            std::cin>>return_car_cont_s;
                            }
        
                        else{
                        std::cout<<"Going back to main menu."<<std::endl;
                        sleep(3);
                        break;
                        }
                    
                }
            }
        }
        else{
            std::cout<<"You have not rented a car yet.\n";
            std::cout<<"Please use the option number 2. to rent an available car.\n";
            sleep(4);
            std::system("clear || cls");
            break;
        }
    }while(return_car_cont != 'n' && return_car_cont_s != 1);
}
void prices(){ // Check Car Prices Function
    std::string prices_choice;
    int prices_cont =0; 
    while(prices_cont!=1){

        std::cout<<"Please type the car manufacturer\'s name to list the model prices: \n";
        std::cin>>prices_choice;
        

    if(prices_choice == car[0]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(10)<<"BMW: M3 = $100, "<<std::setw(5)<<"M4 = $200, "<<std::setw(5)<<"M8 = $300, "<<std::setw(5)<<"Z4 = $400, "<<std::setw(5)<<"X5 = $500.\n";
    }
    else if (prices_choice == car[1]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(10)<<"Opel: Corsa = $100, "<<std::setw(5)<<"Astra = $200, "<<std::setw(5)<<"Agila = $300, "<<std::setw(5)<<"Calibra = $400, "<<std::setw(5)<<"Manta = $500.\n";
    }
    else if(prices_choice== car[2]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(10)<<"Nissan: Versa = $100, "<<std::setw(5)<<"Sentra = $200, "<<std::setw(5)<<"Altima = $300, "<<std::setw(5)<<"GT-R = $400, "<<std::setw(5)<<"LEAF = $500.\n";
    }
    else if(prices_choice== car[3]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(5)<<"Ferrari: Enzo = $100, "<<std::setw(5)<<"Spider = $200, "<<std::setw(5)<<"Roma = $300, "<<std::setw(5)<<"California = $400, "<<std::setw(5)<<"599XX = $500.\n";
    }
    else if(prices_choice== car[4]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(5)<<"Mitsubishi: Mirage = $100, "<<std::setw(5)<<"Outlander = $200, "<<std::setw(5)<<"Outlander-Sport = $300, "<<std::setw(5)<<"Eclipse-Cross = $400, "<<std::setw(5)<<"Mirage-C4 = $500.\n";
    }
    else if(prices_choice== car[5]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(5)<<"Seat: Ibiza = $100, "<<std::setw(5)<<"Arona = $200, "<<std::setw(5)<<"Tarraco = $300, "<<std::setw(5)<<"Mii = $400, "<<std::setw(5)<<"Leon = $500.\n";
    }
    else if(prices_choice== car[6]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(5)<<"Mercedes: Benz-GLA-Class = $100, "<<std::setw(5)<<"Benz-SL-Class = $200, "<<std::setw(5)<<"Benz-AMG-GT = $300, "<<std::setw(5)<<"Benz-A-Class = $400, "<<std::setw(5)<<"Benz-B-Class = $500.\n";
    }
    else if(prices_choice== car[7]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(5)<<"Porsche: Speedster = $100, "<<std::setw(5)<<"911 = $200, "<<std::setw(5)<<"911-Turbo = $300, "<<std::setw(5)<<"Spyder = $400, "<<std::setw(5)<<"Boxster = $500.\n";
    }
    else if(prices_choice== car[8]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(5)<<"Tesla: Roadster = $100, "<<std::setw(5)<<"Cybertruck = $200, "<<std::setw(5)<<"Model-3 = $300, "<<std::setw(5)<<"Model-S = $400, "<<std::setw(5)<<"Model-Y = $500.\n";
    }
    else if(prices_choice== car[9]){
        std::cout<<"The current prices are the following: (per day)\n\n\n";
        std::cout<<std::setw(5)<<"Volkswagen: Golf = $100, "<<std::setw(5)<<"Polo = $200, "<<std::setw(5)<<"Passat = $300, "<<std::setw(5)<<"Scirroco = $400, "<<std::setw(5)<<"Santana = $500.\n";
    }
    else{
        std::cout<<"Wrong manufacturer name.\n";


    }
    
    std::cout<<"\n\nPress 1 to go back to the main menu, or 0 to check the prices again.\n";
    std::cin>>prices_cont;
    }
}




//Start of main program

int main(){
    std::cout<<"\n\n"<<R"( __  __ __  __
/  \/  |__)(_ 
\__/\__| \ __))"<<"\n\n\n\n";
    std::cout<<"Welcome to the Odelia Car Renting System!- OCRS\n\n";

    std::cout<<"Please type your name: \n\n";
    std::cin>>fname;
    do{
    std::cout<<"Welcome " << fname << ".\n" << std::endl;
    std::cout<<"Please choose one of the following options. \n";
    
    main_menu();

    std::cin>>menu_choice;
    
        
    switch (menu_choice)
    {
    case '1':
        list_cars();
        break;
    case '2':
        reservation();
        break;

    case '3':
        return_car();
        break;
    case '4':
        report();
        break;
    
    case '5':
        contact();
        break;
    
    case '6':
        prices();
        break;

    case '7':
        std::cout<<"Thank you for using OCRS!\n";
        std::cout<<"\nWe hope to see you again!\n";
        break;

    default:
        std::cout<<"Please choose one of the correct options!\n";
        system("cls || clear");
        break;
        
        
    }
    
        
     }while(menu_choice!=7 && menu_cont !='n' && return_car_cont_s !=2);    
    
}