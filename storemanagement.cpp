//LIBRARIES :


// for commands like "cout" and "cin"
// istream for cin
// ostream for cout
#include<iostream>

//fstream deal with files that can one can write to and read from.
//there are two types of fstream files, one is ifstream, which is used to read from a file
//the other is ofstream ,which is used to write in a file
//both will be used later in the code
//the fstream library has both the functions
//iostream library cannot store the data permanently, so we use fstream to store data inputted by the user for later use
#include<fstream>

//generating random numbers/ using the system ("cls | clear") command
#include<stdlib.h>

using namespace std;



//GLOBAL VARIABLES
int yesorno;



// FUNCTION LIST

//this function is just to show the main page of the program as an introduction
void firstpage();

//this is to access the main menu of login programe
void loginmainpage();

/* the login function will take input from the user for his/her username and password and check in the text file "database.txt that if it is present
in it, if present the user will login*/
void login();

/* the register function will take input from the user for his/her username and password and save them into the text file */
void registr();

//this will be used to add items to the inventory
void additems();

//before going into the add items function, this function will check if the user is an owner or not
void ownerornot();

//shows the itemlist to the customer
void itemlist();



//MAIN FUNCTION

int main()
{

    //the first page void function is called to display the introductory page
    firstpage();


}

//This is the register function as declared above

void firstpage()
{
    cout << "                            WELCOME TO OUT SHOP                     "<<endl<<endl<<endl;
    cout<< "If you want membership, press 1 to go to our login page " << endl <<"and sign up for membership for a 20% discount on all items bought! " <<endl;
    cout<< "If you do not want membership, press 2 to go to the items list! "<<endl << "Thank you!" <<endl;

    int firstchoice;
    cout<< "enter your choice here : ";
    cin >> firstchoice;

    if( firstchoice == 1)
    {
        loginmainpage();
    }

    else if ( firstchoice == 2)
    {
        ownerornot();
    }

}

void loginmainpage()
{

    //clearing screen for neatness
    system("cls | clear ");

    // an integer variable named "answer" is declared so that the input can be taken afterwards for what the user wants to do
    int answer;

    //cout statement prints output on the screen
    cout<< "                         LOGIN PAGE                          "<<endl<<endl<<endl;
    cout<< "enter 1 to login : "<<endl <<endl;
    cout<< "enter 2 to register : "<<endl<<endl;
    cout<< "enter the numbers 1 or 2 here : ";

    //cin will take in input for the variable "choice"
    cin >>answer;

    // if the choice is 1, the code will enter the login function
    if( answer == 1 )
    {
        //the login function is of type "void" , and void functions do not need to be passed parameters , hence the empty brackets.
        login();
    }

    //if the choice is not one, the code will check if it is 2, if it is 2, the registr funtion will be called
    else if( answer == 2)
    {
        registr();
    }

    //if it is not any from 1,2 the user has probably entered wrong input and they will be made to enter input again
    else
    {
        cout<< "please enter correct input! "<<endl;
        main();
    }
}

void registr()
{
    //Two variables, namely username and password are generated of datatype "string"
    string username , password;

    //the input screen is cleared so the program is neat
    system ("cls | clear");

    //inputs for username and password are taken
    cout<< "enter username : ";
    cin >> username;
    cout<< "enter password : ";
    cin >> password;


    //ofstream is used as we want to write on a file / output on the file
    //the name of the file object is "reg", a file object is an "access" to the file
    //any time the name "reg" is used it means you want to access the database.txt file
    //it will store the data in a file named database.txt
    ofstream reg("database.txt");
    //the program checks whether a file named "database.txt" exists in the folder where the source code exists,
    //if it doesnt, the program will create a file named "database.txt"  itself


    reg << username << " " << password << endl; // this is the syntax for inputting data from the user to store the data in the file
    //this data will be permanently written in the file hence permanently stored for the program , unlike the data achieved by cin
    //The data will stored as :  one user will be assigned one line and the start of line will have the username, followed by a space
    //after the space there will be a password


    //the code below is to check whether the code for accessing the file is working or not
    /*
    if(!reg)
    {
        cout<< "not able to open the file" <<endl;
    }
    else
    {
        cout<< "file opened" <<endl;
    }
    */


    //screen is cleared again for clarity
    system( "cls | clear ");

    //message to ensure that registeration was successful
    cout<< "registeration successful! Thank you! "<<endl <<endl;

    cout<< "do you want to go to the items list or do you want to leave ? "<<endl <<"press 1 for going to items list, and press 2 for going back to the first page";
    int press1or2;
        cin>>press1or2;

        if(press1or2 == 1)
        {
            itemlist();
        }
        else if( press1or2 == 2 )
        {
            firstpage();
        }
}

//Below is the login function as declared above

void login()
{
    //A boolean valiable is created so that we can check if the details exist or not, set initially to false
    bool details_exist = false;

    // four string variables are created
    // the names of the variables themselves tell their use
    string username_by_user, password_by_user , username_in_databse , password_in_database;

    system("cls|clear");

    cout<< "enter username : ";
    cin >>username_by_user;

    cout<< "enter password : ";
    cin >> password_by_user;

    //ifstream will extract data from the file to the program
    ifstream input ("database.txt");

    //the program will input the usernames in databse and the passwords in database (all of them can be accessed through using a loop)
    while( input  >>  username_in_databse  >>  password_in_database )//the loop runs through all the usernames and passwords
    {
        if ( username_in_databse == username_by_user && password_in_database == password_by_user )
        {
            details_exist = true;// if one of the set matches, the boolean variable "details exist" is set to true
            break;//the loop is exited as it is no longer needed anymore. and this is beneficial as we can use the bool variable in descision statements ahead
        }
    }

    input.close();

    // if the bool is set to true, this if statement is accessed and the program tells that login was successful
    if ( details_exist == true )
    {
        //if details_exist is true, and user presses 1, he will be taken to the items list
        cout << "login is successful "<<endl;
        cout << "press 1 to go to the items list!" <<endl;

        cin>>yesorno;

        if(yesorno == 1)
        {
            itemlist();
        }
    }

    else
    {
        cout<<"login unsuccessful. try again " <<endl;
        cout << "press 1 to try logging in again" <<endl;

        cin>>yesorno;
        //the user is given another chance to login by calling the login function again in this if block;
        if(yesorno == 1)
        {
           login();
        }
    }
}

void ownerornot()
{

    system("cls | clear");
    cout << "Are you a certified owner for this shop?" <<endl << "If you are, enter 1, if you are not, enter 2" <<endl;

    cin >> yesorno;
    if(yesorno == 1)
    {
        additems();
    }
    else if (yesorno == 2)
    {
        itemlist();
    }
}


int number_of_items_needed;
int quantity;
double price;


void additems()
{
    system("cls | clear");
    cout<< "this page is to enter items. must only be used by the owner "<<endl <<endl;
    string item_name;

    cout<< "how many items do you want to add? "<<endl;
    //int number_of_items_needed;
    cin>> number_of_items_needed;

    ofstream items("items.txt");
    for ( int i = 1 ; i <= number_of_items_needed ; i++)
    {
        cout<< "enter item name : ";
        cin >> item_name;

        cout<< "enter its quantity : ";
        cin >> quantity;

        cout<< "enter its price : ";
        cin >> price;

        items << i << " - " << item_name << " " << quantity << " " << price <<endl;
        cout<< endl;
    }
    items.close();
    itemlist();
}

void itemlist()
{
    system("cls|clear");
    cout << "                   WELCOME TO THE ITEMS LIST                   "<<endl;

    ifstream items("items.txt");

    if (items.is_open())
        cout << items.rdbuf();
    items.close();

    cout<< "enter the serial number of the items you want to buy : ";

}



