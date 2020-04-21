#include <iostream>
#include <cmath>
#include <limits>

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
            first = fullName.substr(0,fullName.find(' ', 0)) - 1);
            last = fullName.substr(fullName.find(' ', 0)),fullName.length());
            std::cout << "Your first name is " << first << std::endl;
            std::cout << "Your last name is " << last << std::endl;
            // Everything is fine, continue
            inputOk = true;   
        }
    }

    return first, last;
}

std::string convertFullName(std::string first, std::string last) 
{
    std::string pigLatinFirst, pigLatinLast;

    pigLatinFirst = first.substr(1, first.find(" ")) + first.substr(0,1) + "ay";
    pigLatinLast = last.substr(1, last.find(" ")) + last.substr(0,1) + "ay";

    return pigLatinFirst, pigLatinLast;
}

int main()
{
    char ContinueAnswer;
    do
    {
        std::string first, last = getFullName();
        std::string pigLatinFirst, pigLatinLast = convertFullName(first, last);

        std::cout << "\tHello ," << first << " " << last << ",";
        std::cout << "\n\tYour Pig Latin name is: " << pigLatinFirst << " " << pigLatinLast << "." << std::endl;
        std::cout << "\nDo you want to convert another name? (Y/N)";
        std::cin >> ContinueAnswer;
        if (!(ContinueAnswer == 'Y' || ContinueAnswer == 'y'))
        {
            std::cout << "Ending program. Good bye.";
        }
    } while (ContinueAnswer == 'Y' || ContinueAnswer == 'y');
    
    return 0;
}

