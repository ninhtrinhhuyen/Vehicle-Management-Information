#include "Data.h"

// compare string by alphabet a -> z
bool data::compareAlphabet(const std::string& s1, const std::string& s2)
{
    std::size_t sizeStr{s1.size() < s2.size() ? s1.size() : s2.size()};
    for(std::size_t index{0}; index < sizeStr; ++index)
    {
        if(s1[index] < s2[index])
            return true;
        else if(s1[index] > s2[index])
            return false;
    }
    return true;
}

// pause console
void data::pauseConsole()
{
    std::string dummy;
    std::cout << "Enter to continue...";
    std::getline(std::cin, dummy);
}
// clear console ubuntu
void data::clearConsole()
{
    std::system("clear");
}

// download data from file to vector
std::vector<CommonInfo> data::downloadData(const std::string& file_name)
{
    std::vector<CommonInfo> v;
    std::ifstream inf;
    inf.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        inf.open(file_name);
        while (!inf.eof())
        {
            std::string strNumber;
            std::string strName;
            std::getline(inf, strNumber, ' ');
            //ignore ' / '
            std::string strIgnore;
            std::getline(inf, strIgnore, ' ');
            std::getline(inf, strName);
            if(!strNumber.empty() && !strName.empty())
            {
                if(strNumber.size() < 2)
                    strNumber.insert(0,"0");
                // delete char \r
                if(strName[strName.size() - 1] == '\r')
                {
                    strName.erase(strName.size() - 1);
                }
                CommonInfo comon{strNumber, strName};
                v.push_back(comon);
            }
        }
    }
    catch(std::ifstream::failure e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Error openning file.\n";
        v.clear();
    }
    inf.close();
    return v;
}
// igrone characters from the input stream
void data::igrone()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// enter and check a number integer >= 0
int data::enterInteger()
{
    while (true)
    {
        int num;
        std::cin >> num;
        // neu nhap vao la 1 so nguyen >= 0 thi tra ve so nguyen
        if(!std::cin.fail() && num >= 0)
        {
            data::igrone();
            return num;
        }
        std::cin.clear();
        data::igrone();
        std::cout << "Enter a integer, try again: ";
    }
}

// enter and check a number integer between min to max
int data::enterInteger(int min, int max)
{
    while (true)
    {
        int num;
        std::cin >> num;
        // neu nhap vao la 1 so nguyen >= 0 thi tra ve so nguyen
        if(!std::cin.fail() && num >= min && num <= max)
        {
            data::igrone();
            return num;
        }
        std::cin.clear();
        data::igrone();
        std::cout << "Enter a integer from " << min << " to " << max << ", try again: ";
    }
}

// check email format abc@xyz.def
bool data::isInvalidEmail(const std::string& email)
{

        // check format abc@xyz.def
        std::size_t found_a{email.find('@')};
        std::size_t found_space{email.find(' ')};
        if(found_a != std::string::npos && found_a != 0 && found_space == std::string::npos)
        {
            std::size_t found_dot{email.find('.', (found_a + 2))};
            // kiem tra chi co 1 ky tu @
            found_a = email.find('@', (found_a + 1));
            // kiem tra co dau cham va dau cham khong nam o cuoi string
            if(found_a == std::string::npos && found_dot != std::string::npos && found_dot < (email.length() - 1))
            {
                return false;
            }
        }
        std::cout << "Invald email format abc@xyz.def, try again.\n";
        return true;
}

// enter anh check person key have 8 char
bool data::isInvalidPersonKey(const std::string& person_key)
{
    if(person_key.length() != 8) 
    {
        std::cout << "Enter a person key have 8 number, try again.\n";
        return true;
    }
    for(auto it{person_key.begin()}; it != person_key.end(); ++it)
    {
        if(!isdigit(*it))
        {
            std::cout << "Enter a person key have 8 number, try again.\n";
            return true;
        }
    }
    return false;
}