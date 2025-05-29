/*
Program Title: Birthday Paradox
Program Summary: This program gets the probability of at least two people sharing the same birthday
in groups defined by the user's input and checks if any records in birthdays.csv share the same birthday.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int main()
{
    //Create a struct to store information from the file

    struct Person {
        std::string name;
        int month;
        int day;

    };

    // Gather group size from input

    int group_size;

    std::cout << "Enter group size: \n";
    std::cin >> group_size;

    std::cout<< "For group size: "<< group_size << "\n";

    //Now calculate probability using the formula for the birthday paradox
    double probability = 1.0;

    for (int i = 0; i < group_size; i++){
        probability = probability * ((365.0 - i) / 365.0);

    }

    probability = 1.0 - probability;

    if (group_size == 23){
        std::cout << "Probability of 1 Pair Sharing Birthday: "<<std::fixed << std::setprecision(0)<< (probability*100) << "%\n";

    }else{
        std::cout << "Probability of 1 Pair Sharing Birthday: "<< int(probability*100) << "%\n";
    }

    std::ifstream in;
    in.open("birthdates.csv");
    if (!in){

        std::cout<< "Error opening file for reading\n";
        return 1;
    }

    //read the file and store in vector people
    std::vector <Person> people;
    std::string line;

    while(std::getline(in,line)){

        //Create a stream to parse through each line 
        std::istringstream iss(line);
        std::string name, month, day;

        //parse through the values using getline
        std::getline(iss,name,',');
        std::getline(iss,month,',');
        std::getline(iss,day);

        //Using the initial struct to define a Person, create a person object and add to the vector
        Person p;
        p.name = name;
        p.month = std::stoi(month);
        p.day = std::stoi(day);

        people.push_back(p); // add the person to the vector
    }
    in.close(); // close the file

    //Check for matching birthdays

    bool found_match = false;

    //iterate through each element of the vector people

    for(size_t i = 0; i < people.size();i++){
        for(size_t j = i+1; j < people.size(); j++){
            //now check if they have the same birthday
            if (people[i].month == people[j].month && people[i].day == people[j].day){

                std::cout<<"Match: "<<std::right <<std::setw(9) << people[i].name << " & " << std::left << std::setw(9) <<  people[j].name << std::right << " "<< people[i].month << "/" << people[i].day <<std::endl;

                found_match = true;
            }
        }
    }

    std::cout << std::endl;
    if (found_match) {
        std::cout << "Birthday Paradox is true.\n";
    }else{
        std::cout << "No Birthday Paradox for this group occured.\n";
    }
    return 0;

}

