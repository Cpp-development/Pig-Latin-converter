#include <iostream>
#include <cmath>
#include <limits>
#include <tuple>

struct getFirstAndLast {
    std::string First;
    std::string Last;
};

getFirstAndLast firstAndLastName(std::string fullName) {
    getFirstAndLast result;
    result.First = fullName.substr(0,fullName.find(' ', 0) - 1);
    result.Last = fullName.substr(fullName.find(' ', 0),fullName.length());
    return result;
}

std::string getFullName() 
{
    std::string fullName;
    std::string first, last;
    bool inputOk = false;
    
    while (!inputOk)
    {
        
        // Get the full name from the user
        std::cout << "Please provide your full name and press enter: ";
        //std::cin >> fullName;
        std::getline (std::cin, fullName);
        std::cout << fullName.find(' ', 0);

        // Check if the full name is logical, if not throw an error
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
            std::cout <<  "Your full name must be a string! Try again: " << std::endl;
            continue;
        }
        else if (!(fullName.find(' ', 0) == 0))
        {
            std::cout << "It seems you did not provide a first and lastname combination. Try again: " << std::endl;
            continue;
        }
        else
        {
            // Everything is fine, continue
            inputOk = true;   
        }
    }

    return fullName;
}


std::string convertFullName(std::string first, std::string last) 
{
    std::string pigLatinFirst, pigLatinLast, fullPigLatinName;
    //Converting input to lower case
    first[0] = tolower(first[0]);
    last[0] = tolower(last[0]);

    pigLatinFirst = first.substr(1, first.find(" ")) + first.substr(0,1) + "ay";
    pigLatinLast = last.substr(1, last.find(" ")) + last.substr(0,1) + "ay";

    pigLatinFirst[0] = toupper(pigLatinFirst[0]);
    pigLatinLast[0] = toupper(pigLatinLast[0]);

    fullPigLatinName = pigLatinFirst + " " + pigLatinLast;
    return fullPigLatinName;
}

int main()
{
    char ContinueAnswer;
    do
    {
        
        std::string fullName = getFullName();
        //first = fullName.substr(0,fullName.find(' ', 0) - 1);
        //last = fullName.substr(fullName.find(' ', 0),fullName.length());
        getFirstAndLast firstAndLast = firstAndLastName(fullName);
        std::cout << "Your first name is " << firstAndLast.First << std::endl;
        std::cout << "Your last name is " << firstAndLast.Last << std::endl;

        std::string pigLatinFirstAndPigLatinLast = convertFullName(firstAndLast.First, firstAndLast.Last);

        std::cout << "\tHello " << firstAndLast.First << " " << firstAndLast.Last << ",";
        std::cout << "\n\tYour Pig Latin name is: " << pigLatinFirstAndPigLatinLast << "." << std::endl;
        std::cout << "\nDo you want to translate another name? (Y/N)";
        std::cin >> ContinueAnswer;
        if (!(ContinueAnswer == 'Y' || ContinueAnswer == 'y'))
        {
            std::cout << "Ending program. Good bye.";
        }
    } while (ContinueAnswer == 'Y' || ContinueAnswer == 'y');
    
    return 0;
}

