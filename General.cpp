#include "General.h"

// timezone data list
std::vector<CommonInfo> g_time_zone_list{data::downloadData("timezones.txt")};
// languge data list
std::vector<CommonInfo> g_language_list{data::downloadData("languages.txt")};

// sort time zone
void sortTimeZone()
{
    std::cout << "\n--- SELECT DISPALY MODE ---\n";
    std::cout << "1. Name\n";
    std::cout << "2. UTC\n";
    std::cout << "You selection: ";
    int selection{data::enterInteger(1, 2)};
    switch (selection)
    {
    // sort by name
    case 1:
        std::sort(g_time_zone_list.begin(), g_time_zone_list.end(),
            [](const CommonInfo& c1, const CommonInfo& c2)
            {
                return data::compareAlphabet(c1.getName(), c2.getName());
            }
        );
        break;
    // sort by utc
    case 2:
        std::sort(g_time_zone_list.begin(), g_time_zone_list.end(),
            [](const CommonInfo& c1, const CommonInfo& c2)
            {
                int num1{std::stoi(c1.getNumber().substr(4, 3))};
                if(num1 < 0)
                    num1 = num1 * 100 - std::stoi(c1.getNumber().substr(8));
                else
                    num1 = num1 * 100 + std::stoi(c1.getNumber().substr(8));
                int num2{std::stoi(c2.getNumber().substr(4, 3))};
                if(num2 < 0)
                    num2 = num2 * 100 - std::stoi(c2.getNumber().substr(8));
                else
                    num2 = num2 * 100 + std::stoi(c2.getNumber().substr(8));
                return num1 < num2;
            }
        );
        break;
    default:
        std::cout << "Invaild input\n";
        break;
    }
}

// sort languages
void sortLanguage()
{
    std::cout << "\n--- SELECT DISPALY MODE ---\n";
    std::cout << "1. Name\n";
    std::cout << "2. Index\n";
    std::cout << "You selection: ";
    int selection{data::enterInteger(1, 2)};
    switch (selection)
    {
    //sort by name
    case 1:
        std::sort(g_language_list.begin(), g_language_list.end(),
            [](const CommonInfo& c1, const CommonInfo& c2)
            {
                return data::compareAlphabet(c1.getName(), c2.getName());
            }
        );
        break;
    // sort by index
    case 2:
        std::sort(g_language_list.begin(), g_language_list.end(),
            [](const CommonInfo& c1, const CommonInfo& c2)
            {
                return std::stoi(c1.getNumber()) < std::stoi(c2.getNumber());
            }
        );
        break;
    default:
        std::cout << "Invaild input\n";
        break;
    }
}

General::General(const Setting& s, const std::string& time = "", const std::string& lang = "")
                : Setting{s}, a_time_zone{time}, a_language{lang}
{

}

General::~General()
{
}
// getter function
std::string General::getTimeZone() const  {return a_time_zone;}
std::string General::getLanguage() const  {return a_language;}
// setter function
void General::setTimeZone(const std::string& time_zone) {a_time_zone = time_zone;}
void General::setLanguage(const std::string& language)  {a_language = language;}
// print info of used
void General::printInfo()
{
    std::cout << std::right << std::setw(30) << a_time_zone;
    int lang{std::stoi(a_language) - 1};
    std::cout << std::setw(40) << g_language_list[lang].getName();
}

// select Time Zone
void General::selectionTimeZone()
{
    std::cout << "\n--- SELECT TIMEZONE DATA ---\n";
    sortTimeZone();
    int i{0};
    for(const auto& element : g_time_zone_list)
    {
        std::cout << ++i << ": " << element << '\n';
    }
    std::cout << "YOUR SELECTION: ";
    // enter and check selection of uesd
    int choose{data::enterInteger(1, g_time_zone_list.size()) - 1};
    // get time_zone string from vector<string>. fomat GTM hh::mm
    a_time_zone = g_time_zone_list[choose].getNumber();
}

// selection Language
void General::selectionLanguage()
{
    std::cout << "\n--- SELECT LANGUAGE DATA ---\n";
    sortLanguage();
    for(int i{0}; i < g_language_list.size(); ++i)
    {
        std::cout << (i+1) << ": " << g_language_list[i].getName() << '\n';
    }
    std::cout << "YOUR SELECTION: ";
    // enter and check selection of uesd
    int choose{data::enterInteger(1, g_language_list.size()) - 1};
    // get language string from vector<string>. fomat abcd
    a_language = g_language_list[choose].getNumber();
}

// enter infomation of used
void General::enterInfo()
{
    if(isAlready == false)
    {
        std::cout << "\t->This is car, data will be appened to your list\n";
        // this car already existed
        isAlready = true;
    }
    else
    {
        std::cout << "\t->This car already existed, data will be overriten\n";
    }
    selectionTimeZone();
    selectionLanguage();
}

std::ostream& General::identify(std::ostream& out) const
{
    out << " General: " << a_time_zone << ", " << a_language;
    return out;
}