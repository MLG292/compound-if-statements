#include <iostream>
#include <string>
using namespace std;

void thermometer() {
    string response;
    bool is_home;
    int temperature = 70;
    cout << "(yes/no)\nAre you home?" << endl;
    cin >> response;
    if(response == "yes") {
        is_home = true;
    } else if(response == "no") {
        is_home = false;
    } else {
        cout << "What?" << endl;
        thermometer();
    }
    if(is_home == false) {
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

void password() {
    string admin_username = "supergato";
    string admin_password = "1782";
    string username_input;
    string password_input;
    cout << "What is your username?" << endl;
    cin.ignore();
    getline(cin, username_input);
    cout << "What is your password?" << endl;
    getline(cin, password_input);
    if(username_input == admin_username && password_input == admin_password) {
        cout << "Access granted." << endl;
    } else {
        cout << "Incorrect username/password." << endl;
        password();
    }
}

void arcade() {
    int age;
    string current_day;
    string promotion_day = "Tuesday";
    if(promotion_day == current_day) {
        cout << "It is our promotion day! All people are given free passes.\nWelcome." << endl;
    } else {
        cout << "How old are you?" << endl;
        cin >> age;
        if(age <= 12 && age > 0) {
            cout << "You may have a free pass." << endl;
        } else if (age > 12 && age <= 120) {
            cout << "You must pay for your pass." << endl;
        } else {
            cout << "Please give a reasonable response." << endl;
            arcade();
        }
    }
}

int main()
{
    string response_a;
    string response_b;
    string response_c;
    cout << "Hello! Did you wish to manage your thermometer?" << endl;
    cin >> response_a;
    if(response_a == "Yes" || response_a == "yes") {
    thermometer();
    } else if (response_a == "No" || response_a == "no") {
        cout << "I see. Did you wish to access your account?" << endl;
        cin >> response_b;
        if(response_b == "Yes" || response_b == "yes") {
            password();
        } else if(response_b == "No" || response_b == "no") {
            cout << "Do you wish to revisit the arcade?" << endl;
            cin >> response_c;
            if(response_c == "Yes" || response_c == "yes") {
                arcade();
            } else if (response_c == "No" || response_c == "no") {
                cout << "I do not have any more prompts to give." << endl;
                return 0;
            } else {
                cout << "I do not understand." << endl;
                return 0;
            }
        }
    } else {
        cout << "I do not understand." << endl;
    }
return 0;
} 
