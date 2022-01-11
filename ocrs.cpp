//Source code for my project: a car rental system.
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <unistd.h>
   
//Variables
    const std::string car[10]={"BMW", "Opel", "Nissan", "Ferrari", "Mitsubishi", "Seat", "Mercedes", "Porsche", "Tesla", "Volkswagen"};
    int menu_choice=0, contact_choice=0,report_choice=0;
    char menu_cont;
    std::string list_choice;
    std::string fname, lname;
//Functions

void main_menu() //Main menu function
{
    std::cout<<"1. List available cars.\n";
    std::cout<<"2. Search for a specific car.\n";
    std::cout<<"3. Make a reservation.\n";
    std::cout<<"4. Return a car.\n";
    std::cout<<"5. Report.\n";
    std::cout<<"6. Contact.\n";
    std::cout<<"7. Exit\n";

    return;
}
void contact() //Contact Function
{
    char contact_cont;
    do
    {
    std::cout<<"Please choose how you would like to contact us:\n";
    std::cout<<"Press 1 to contact us via E-Mail at lazy_titan94@protonmail.com\n";
    std::cout<<"Press 2 to contact us via telephone.\n";
    std::cout<<"Press 3 to contact us via mail.\n";
    std::cout<<"Press 4 to return to the main menu.\n";
    std::cin>>contact_choice;
        switch(contact_choice)
        {
            case 1:
            system("firefox mailto::lazy_titan94@protonmail.com");
            std::cout<<"Do you want to continue?\n (y) for yes (n) for no\n";
            std::cin>>contact_cont;
            break;

            case 2:
            system("firefox tel:55545754484");
            std::cout<<"Do you want to continue?\n (y) for yes (n) for no\n";
            std::cin>>contact_cont;
            break;

            case 3:
            std::cout<<"You can send your mail at the following address: \n54124, Bleeker Streek 02, New York, USA.\n";
            std::cout<<"Do you want to continue?\n (y) for yes (n) for no\n";
            std::cin>>contact_cont;
            break;

            case 4:
            break;

            default:
            std::cout<<"Please choose one of the correct options.\n";
            break;

        }
    }while(contact_choice!=4 && contact_cont !='n');
}
void report() //Report Function
{
    char report_cont,report_confirm;
    std::string user_report1,user_report2,user_report3;
    do
    {
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
void list_cars(){
    int i,list_choice_num = 0;
    char list_cont;
    do{
    std::cout<<"The available car manufacturers are the following: \n";
    for(i=0;i<10;i++){
        std::cout<<car[i]<<std::endl;
    } 
    
    std::cout<<"To list all car models from a specific car manufacturer, please type 1.\nTo go back to the main menu, please press 0.\n";
    std::cin>> list_choice_num;
    char list_conf;
    do{
    if(list_choice_num==1){
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
            std::string mitsubishi[5]={"Mirage","Outlander","Outlander Sport","Eclipse Cross","Mirage C4"};
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
            std::string mercedes[5]={"Benz GLA Class","Benz SL Class","Benz AMG GT","Benz A Class","Benz B Class"};
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
            std::string tesla[5]={"Roadster","Cybertruck","Model 3","Model S","Model Y"};
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
    }while(list_cont!='n' && list_choice_num != 0 && list_conf != 'r');
    }while(list_cont!='n'&& list_choice_num!=0);
    
}


//Start of main program

int main()
{
    std::cout<<"\n\n"<<R"( __  __ __  __
/  \/  |__)(_ 
\__/\__| \ __))"<<"\n\n\n\n";
    std::cout<<"Welcome to the Odelia Car Renting System!- OCRS\n\n";

    std::cout<<"Please type your name: \n";
    std::cin>>fname;
    do
    {
    std::cout<<"Welcome " << fname << "\n" << std::endl;
    std::cout<<"Please choose one of the following options. \n";

    main_menu();

    std::cin>>menu_choice;
    switch (menu_choice)
    {
    case 1:
        list_cars();
        break;
    case 2:

        break;

    case 3:

        break;
    case 4:
        
        break;
    case 5:
        report();
        break;
    case 6:
        contact();
        break;
    case 7:
        std::cout<<"Thank you for using OCRS!\n";
        std::cout<<"\nWe hope to see you again!\n";
        break;
    default:
        std::cout<<"Please choose of the correct options.\n";
        sleep(3);
        break;
    }
    } while(menu_choice!=7 && menu_cont !='n');    
}