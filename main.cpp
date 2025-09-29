/*
Mason Gross
9/29/25
Nest if statements
Created lots of nested if statements for an output for each option
*/

#include <iostream>
#include <string>
using namespace std;

void thermometer() { //The thermometer option
    string response;
    bool is_home;
    int temperature = 70;
    cout << "(yes/no)\nAre you home?" << endl; //Asking for the boolean
    cin >> response;
    if(response == "yes") { //Sets the boolean depending on the input
        is_home = true;
    } else if(response == "no") {
        is_home = false;
    } else {
        cout << "What?" << endl; //If an answer isn't yes or no
        thermometer();
    }
    if(is_home == false) { //Checks what the temperature is or if the person is home to then respond accordingly
        cout << "System idle. No one is home." << endl;
    } else if(temperature > 75) {
        cout << "The temperature is: " << temperature << " degrees." << endl;
        cout << "Activating cooling system..." << endl;
    } else if(temperature < 65) {
        cout << "The temperatures is: " << temperature << " degrees." << endl;
        cout << "Activating heating system..." << endl;
    } else if(is_home == true){
        cout << "The temperature is: " << temperature << " degrees." << endl;
        cout << "Temperature is stable. System standby." << endl;
    } else {
        cout << "Unknown input." << endl;
    }
}

void password() { //The sign in access
    string admin_username = "supergato";
    string admin_password = "1782";
    string username_input;
    string password_input;
    cout << "What is your username?" << endl; //Getting username and password
    cin.ignore();
    getline(cin, username_input);
    cout << "What is your password?" << endl;
    getline(cin, password_input);
    //Checking username and password to the admin account
    if(username_input == admin_username && password_input == admin_password) {
        cout << "Access granted." << endl;
    } else {
        cout << "Incorrect username/password." << endl;
        password();
    }
}

void arcade() { //The arcade option
    int age;
    string current_day;
    string promotion_day = "Tuesday";
    if(promotion_day == current_day) { //If its promotion day, do this
        cout << "It is our promotion day! All people are given free passes.\nWelcome." << endl;
    } else {
        cout << "How old are you?" << endl;
        cin >> age;
        if(age <= 12 && age > 0) { //If 12 or older, free pass otherwise, no
            cout << "You may have a free pass." << endl;
        } else if (age > 12 && age <= 120) {
            cout << "You must pay for your pass." << endl;
        } else {
            cout << "Please give a reasonable response." << endl; //If answer isn't a reasonable value
            arcade();
        }
    }
}

int main()
{
    string response_a;
    string response_b;
    string response_c;
    cout << "Hello! Did you wish to manage your thermometer?" << endl; //Checks if user wants to manage thermometer
    cin >> response_a;
    if(response_a == "Yes" || response_a == "yes") {
    thermometer();
    } else if (response_a == "No" || response_a == "no") {
        cout << "I see. Did you wish to access your account?" << endl;
        cin >> response_b;
        if(response_b == "Yes" || response_b == "yes") { //Checks if user wants to check admin account
            password();
        } else if(response_b == "No" || response_b == "no") {
            cout << "Do you wish to revisit the arcade?" << endl;
            cin >> response_c;
            if(response_c == "Yes" || response_c == "yes") { //Checks if user wants to go to arcade
                arcade();
            } else if (response_c == "No" || response_c == "no") {
                cout << "I do not have any more prompts to give." << endl;
                return 0;
            } else {
                cout << "I do not understand." << endl; //If answers do not make sense
                return 0;
            }
        }
    } else {
        cout << "I do not understand." << endl; //If answers do not make sense
    }
return 0;
} 
