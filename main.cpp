#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Data.h"
#include "Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
#include "BinaryTreeSearch.h"
#include <numeric>

// BINARY TREE SEARCH type Setting*
BinaryTreeSearch display;
BinaryTreeSearch sound;
BinaryTreeSearch general;

// BINARY TREE SEARCH type Setting* sort by Name
BinaryTreeSearch displayName;
BinaryTreeSearch soundName;
BinaryTreeSearch generalName;

// display mode
void displayMode(int selection);
// main interface MH-1
void mainInterface();
// menu setting MH-2
void menuSetting();
// menu display MH-3
void menuDisplay();
// change data setting display
void changeData(Node *tree, int &index, char &selection);
// menu setting display
void settingDisplay();
// menu setting sound
void settingSound();
// menu setting general
void settingGeneral();
// print display setting
void printDisplay();
// print sound setting
void printSound();
// print general setting
void printGeneral();
// read data into tree
void readDataTree(Node *displayTree, Node *soundTree, Node *generalTree);
// print information setting of car
void printAllInfor(Node *displayNode, Node *soundNode, Node *generalNode);
// print all setting
void printAll();
// column format
void printColumn();
// read data of file
void readFile();
// write data of tree to file
void writeTreeData(std::fstream &f, Node *displayTree, Node *soundTree, Node *generalTree);
// write data to file
void writeFile();
// search information of car by key
void searchKey();
// search information of car by name
void searchName();
// search information of car by name or key
void searchCar();

int main(int argc, char const *argv[])
{
    readFile();

    mainInterface();

    return 0;
}

// write data of tree to file
void writeTreeData(std::fstream &f, Node *displayTree, Node *soundTree, Node *generalTree)
{
    if (displayTree == nullptr || soundTree == nullptr || generalTree == nullptr)
        return;
    writeTreeData(f, displayTree->left, soundTree->left, generalTree->left);
    writeTreeData(f, displayTree->right, soundTree->right, generalTree->right);
    // write data of tree to file
    f << static_cast<Setting>(*displayTree->data) << ' ';
    f << *displayTree->data << ' ';
    f << *soundTree->data << ' ';
    f << *generalTree->data;
    if (displayTree != display.getRoot())
        f << '\n';
}

// write data to file
void writeFile()
{
    std::fstream file;
    file.exceptions(std::fstream::failbit | std::fstream::badbit);
    try
    {
        file.open("Setting.txt", std::ios::out | std::ios::in);
        writeTreeData(file, display.getRoot(), sound.getRoot(), general.getRoot());
    }
    catch (std::fstream::failure &e)
    {
        std::cerr << e.what() << '\n';
    }
    file.close();
}

// read data of file
void readFile()
{
    std::fstream inf;
    inf.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        inf.open("Setting.txt", std::ios::in);
        // read data of file Setting.txt
        std::string outStr;
        while (!inf.eof())
        {
            // read object Setting to file
            std::getline(inf, outStr);
            std::stringstream ss;
            ss.str(outStr);
            // ignore "Common: "
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            std::string name;
            std::getline(ss, name, ',');
            std::string mail;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            std::getline(ss, mail, ',');
            if (data::isInvalidEmail(mail))
                throw std::runtime_error("Invalid email format.");
            std::string keyPerson;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            std::getline(ss, keyPerson, ',');
            if (data::isInvalidPersonKey(keyPerson))
                throw std::runtime_error("Invalid key person.");
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            int odo;
            ss >> odo;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            int service;
            ss >> service;
            // create object Setting
            Setting s{name, mail, keyPerson, odo, service};
            // ignore "Display: "
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ':');
            // create object Display to array List<Setting*> display
            int light, screen, taplo;
            ss >> light;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            ss >> screen;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            ss >> taplo;
            Display *displayData = new Display{s, light, screen, taplo};
            display.insertByKey(displayData);
            displayName.insertByName(displayData);
            // ignore "Sound: "
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ':');
            // create object Sound to array List<Setting*> sound
            int media, call, naviga, notifi;
            ss >> media;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            ss >> call;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            ss >> naviga;
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            ss >> notifi;
            Sound *soundData = new Sound{s, media, call, naviga, notifi};
            sound.insertByKey(soundData);
            soundName.insertByName(soundData);
            // ignore "General: "
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ':');
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            // create object General to array List<Setting*> general
            std::string time;
            std::getline(ss, time, ',');
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            std::string lang;
            std::getline(ss, lang);
            General *generalData = new General{s, time, lang};
            general.insertByKey(generalData);
            generalName.insertByName(generalData);
        }
        inf.close();
    }
    catch (std::fstream::failure &e)
    {
        inf.close();
        std::cerr << "Error opening file Setting.txt.\n";
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    catch (const std::exception &e)
    {
        inf.close();
        std::cerr << "Error format data file Setting.txt.\n";
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}

// dispaly mode
void displayMode(BinaryTreeSearch &treeKey, BinaryTreeSearch &treeName, int selection)
{
    switch (selection)
    {
    // sort by name
    case 1:
        treeName.traversal();
        break;
    // sort by key person
    case 2:
        treeKey.traversal();
        break;
    default:
        std::cout << "Invaild input\n";
        break;
    }
    // data::clearConsole();
}

// column format
void printColumn()
{
    std::cout << std::setw(30) << std::right << "Ower name";
    std::cout << std::setw(30) << "Email";
    std::cout << std::setw(15) << "Key number";
    std::cout << std::setw(15) << "ODO number";
    std::cout << std::setw(20) << "Remid service (km)";
}

// print display setting
void printDisplay()
{
    data::clearConsole();
    std::cout << "\n--- SELECT DISPLAY MODE ---\n";
    std::cout << "1. Name\n";
    std::cout << "2. Key person\n";
    std::cout << "You selection: ";
    int selection{data::enterInteger(1, 2)};
    data::clearConsole();
    std::cout << "\n--- Display setting ---\n";
    printColumn();
    std::cout << std::right << std::setw(15) << "Light";
    std::cout << std::setw(15) << "Screen light";
    std::cout << std::setw(15) << "Taplo light" << std::endl;
    displayMode(display, displayName, selection);
    data::pauseConsole();
}
// print sound setting
void printSound()
{
    data::clearConsole();
    std::cout << "\n--- SELECT DISPLAY MODE ---\n";
    std::cout << "1. Name\n";
    std::cout << "2. Key person\n";
    std::cout << "You selection: ";
    int selection{data::enterInteger(1, 2)};
    data::clearConsole();
    std::cout << "\n--- Sound setting ---\n";
    printColumn();
    std::cout << std::right << std::setw(15) << "Media";
    std::cout << std::setw(15) << "Call";
    std::cout << std::setw(15) << "Navigation";
    std::cout << std::setw(15) << "Notification" << std::endl;
    displayMode(sound, soundName, selection);
    data::pauseConsole();
}
// print general setting
void printGeneral()
{
    // displayMode();
    data::clearConsole();
    std::cout << "\n--- SELECT DISPLAY MODE ---\n";
    std::cout << "1. Name\n";
    std::cout << "2. Key person\n";
    std::cout << "You selection: ";
    int selection{data::enterInteger(1, 2)};
    data::clearConsole();
    std::cout << "\n--- General setting ---\n";
    printColumn();
    std::cout << std::right << std::setw(30) << "Timezone";
    std::cout << std::setw(40) << "Language" << std::endl;
    displayMode(general, generalName, selection);
    data::pauseConsole();
}

// print information setting of car
void printAllInfor(Node *displayNode, Node *soundNode, Node *generalNode)
{
    printColumn();
    std::cout << std::endl;
    displayNode->data->Setting::printInfo();
    std::cout << std::endl;
    std::cout << std::setw(15) << "Dispaly: "
              << "\n\t" << std::setw(15) << "Light";
    std::cout << std::setw(15) << "Screen light";
    std::cout << std::setw(15) << "Taplo light"
              << "\n\t";
    displayNode->data->printInfo();
    std::cout << std::endl;

    std::cout << std::setw(15) << "Sound: "
              << "\n\t" << std::setw(15) << "Media";
    std::cout << std::setw(15) << "Call";
    std::cout << std::setw(15) << "Navigation";
    std::cout << std::setw(15) << "Notification"
              << "\n\t";
    soundNode->data->printInfo();
    std::cout << std::endl;

    std::cout << std::setw(15) << "General: "
              << "\n\t" << std::setw(30) << "Timezone";
    std::cout << std::setw(40) << "Language"
              << "\n\t";
    generalNode->data->printInfo();
    std::cout << std::endl;
    std::cout << std::endl;
}

// read data into tree
void readDataTree(Node *displayTree, Node *soundTree, Node *generalTree)
{
    if (displayTree == nullptr || soundTree == nullptr || generalTree == nullptr)
        return;
    readDataTree(displayTree->left, soundTree->left, generalTree->left);
    printAllInfor(displayTree, soundTree, generalTree);
    readDataTree(displayTree->right, soundTree->right, generalTree->right);
}

// print all setting
void printAll()
{
    // displayMode();
    data::clearConsole();
    int index{0};
    std::cout << "\n--- SELECT DISPLAY MODE ---\n";
    std::cout << "1. Name\n";
    std::cout << "2. Key person\n";
    std::cout << "You selection: ";
    int selection{data::enterInteger(1, 2)};
    data::clearConsole();

    std::cout << "\n--- All setting ---\n";
    switch (selection)
    {
    case 1:
        readDataTree(displayName.getRoot(), soundName.getRoot(), generalName.getRoot());
        break;
    case 2:
        readDataTree(display.getRoot(), display.getRoot(), display.getRoot());
        break;
    default:
        std::cerr << "Invalid input.\n";
        break;
    }
    data::pauseConsole();
}
// change data setting display
void changeData(Node *tree, int &index, char &selection)
{
    data::clearConsole();
    if (tree == nullptr || selection != 'y')
        return;

    std::cout << "--- Input Display setting -- \n";
    std::cout << "Car index: " << (index + 1) << '\n';

    tree->data->displayCommonInfo();
    tree->data->enterInfo();
    writeFile();

    std::cout << "\nWill you input for car " << (index + 1) << "(y/n): ";
    std::cin >> selection;
    data::igrone();
    ++index;

    changeData(tree->left, index, selection);
    changeData(tree->right, index, selection);
}

// menu setting display
void settingDisplay()
{
    int index{0};
    char selection{'y'};
    changeData(display.getRoot(), index, selection);
    std::cout << "RETURN MENU!!!\n";
    data::pauseConsole();
}

// menu setting sound
void settingSound()
{
    int index{0};
    char selection{'y'};
    changeData(sound.getRoot(), index, selection);
    std::cout << "RETURN MENU!!!\n";
    data::pauseConsole();
}
// menu setting general
void settingGeneral()
{
    int index{0};
    char selection{'y'};
    changeData(general.getRoot(), index, selection);
    std::cout << "RETURN MENU!!!\n";
    data::pauseConsole();
}

// search information of car by key
void searchKey()
{
    data::clearConsole();
    std::cout << "--- SEARCH ---\n";
    std::cout << "Enter person key(8 number): ";
    std::string str;
    // check input
    do
    {
        std::getline(std::cin, str);
    } while (data::isInvalidPersonKey(str));
    // search tree
    Node *displayFind = display.searchKey(str);
    Node *soundFind = sound.searchKey(str);
    Node *generalFind = general.searchKey(str);

    if (!displayFind || !soundFind || !generalFind)
    {
        std::cout << "No found person key!!!" << str << '\n';
    }
    else
    {
        printAllInfor(displayFind, soundFind, generalFind);
    }
    data::pauseConsole();
    data::clearConsole();
}

// search information of car by name
void searchName()
{
    data::clearConsole();
    std::cout << "--- SEARCH ---\n";
    std::cout << "Enter name: ";
    std::string str;
    // check input
    std::getline(std::cin, str);
    // search tree
    Node *displayFind = display.searchName(str);
    Node *soundFind = sound.searchName(str);
    Node *generalFind = general.searchName(str);

    if (!displayFind || !soundFind || !generalFind)
    {
        std::cout << "No found person key!!!" << str << '\n';
    }
    else
    {
        printAllInfor(displayFind, soundFind, generalFind);
    }
    data::pauseConsole();
    data::clearConsole();
}

// search information of car by name or key
void searchCar()
{
    data::clearConsole();
    std::cout << "--- SEARCH ---\n";
    std::cout << "1. Name\n";
    std::cout << "2. Person key\n";
    std::cout << "Your selection: ";
    int select{data::enterInteger(1, 2)};
    switch (select)
    {
    case 1:
        searchName();
        break;
    case 2:
        searchKey();
        break;
    default:
        std::cout << "Invalid input\n";
        break;
    }
}

// main interface MH-1
void mainInterface()
{
    bool loop{true};
    while (loop)
    {
        data::clearConsole();
        std::cout << "--- SELECT MENU ---\n";
        std::cout << "1. Input setting information\n";
        std::cout << "2. Print setting information\n";
        std::cout << "3. Search\n";
        std::cout << "4. Exit\n";
        std::cout << "Your selection: ";
        int select{data::enterInteger(1, 4)};
        switch (select)
        {
        case 1:
            menuSetting();
            break;
        case 2:
            menuDisplay();
            break;
        case 3:
            searchCar();
            break;
        case 4:
            loop = false;
            std::cout << "Good bye, See you again!!!\n";
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }
}

// menu setting MH-2
void menuSetting()
{
    bool loop{true};
    while (loop)
    {
        data::clearConsole();
        std::cout << "--- SELECT MENU ---\n";
        std::cout << "1. Display setting\n";
        std::cout << "2. Sound setting\n";
        std::cout << "3. General setting\n";
        std::cout << "0. Exit\n";
        std::cout << "Your selection: ";
        int select{data::enterInteger(0, 3)};
        switch (select)
        {
        case 0:
            loop = false;
            break;
        case 1:
            settingDisplay();
            break;
        case 2:
            settingSound();
            break;
        case 3:
            settingGeneral();
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }
}

// menu display MH-3
void menuDisplay()
{
    bool loop{true};
    while (loop)
    {
        data::clearConsole();
        std::cout << "\n--- SELECT MENU ---\n";
        std::cout << "1. Print Display setting information\n";
        std::cout << "2. Print Sound setting information\n";
        std::cout << "3. Print General setting information\n";
        std::cout << "4. Print all setting information\n";
        std::cout << "5. Exit\n";
        std::cout << "Your selection: ";
        int select{data::enterInteger(0, 5)};
        switch (select)
        {
        case 1:
            printDisplay();
            break;
        case 2:
            printSound();
            break;
        case 3:
            printGeneral();
            break;
        case 4:
            printAll();
            break;
        case 5:
            loop = false;
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }
}