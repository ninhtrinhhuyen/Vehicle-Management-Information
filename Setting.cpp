#include "Setting.h"

// sort name by alphabet a -> z
bool Setting::compareName(const Setting *s1, const Setting *s2)
{
    std::string name1{s1->getCarName()};
    std::string name2{s2->getCarName()};
    std::size_t sizeStr{name1.size() < name2.size() ? name1.size() : name2.size()};
    for (std::size_t index{0}; index < sizeStr; ++index)
    {
        if (name1[index] < name2[index])
            return true;
        else if (name1[index] > name2[index])
            return false;
    }
    return false;
}

// display common information
void Setting::displayCommonInfo()
{
    std::cout << "\tOwner name: " << getCarName() << '\n';
    std::cout << "\tEmail: " << getEmail() << '\n';
    std::cout << "\tKey number: " << getPersonKey() << '\n';
    std::cout << "\tODO number: " << getODO() << '\n';
    std::cout << "\tRemind service (km): " << getServiceRemind() << '\n';
}

// enter infomation of used
void Setting::enterInfo()
{
    std::cout << "Enter Ower name: ";
    std::getline(std::cin, a_car_name);
    // check person key input
    do
    {
        std::cout << "Enter person key: ";
        std::getline(std::cin, a_person_key);
    } while (data::isInvalidPersonKey(a_person_key));
    // check email input
    do
    {
        std::cout << "Enter email: ";
        std::getline(std::cin, a_email);
    } while (data::isInvalidEmail(a_email));

    std::cout << "Enter ODO number: ";
    a_odo = data::enterInteger();
    std::cout << "Enter Service Remind number: ";
    a_service_remind = data::enterInteger();
}

// print info of used
void Setting::printInfo()
{
    std::cout << std::right;
    std::cout << std::setw(30) << a_car_name << std::setw(30) << a_email << std::setw(15) << a_person_key;
    std::cout << std::setw(15) << a_odo << std::setw(20) << a_service_remind;
}

// getter function
std::string Setting::getCarName() const { return a_car_name; }
std::string Setting::getPersonKey() const { return a_person_key; }
std::string Setting::getEmail() const { return a_email; }
int Setting::getODO() const { return a_odo; }
int Setting::getServiceRemind() const { return a_service_remind; }

// setter function
void Setting::setCarName(const std::string &car_name) { a_car_name = car_name; }
void Setting::setPersonKey(const std::string &person_key) { a_person_key = person_key; }
void Setting::setEmail(const std::string &email) { a_email = email; }
void Setting::setODO(const int odo) { a_odo = odo; }
void Setting::setServiceRemind(const int service_remind) { a_service_remind = service_remind; }

// overloading operator
std::ostream &operator<<(std::ostream &out, const Setting &s)
{
    return s.identify(out);
}

bool operator<(const Setting &s1, const Setting &s2)
{
    int keyInt1{std::stoi(s1.a_person_key)};
    int keyInt2{std::stoi(s2.a_person_key)};
    return keyInt1 < keyInt2;
}

bool operator>(const Setting &s1, const Setting &s2)
{
    int keyInt1{std::stoi(s1.a_person_key)};
    int keyInt2{std::stoi(s2.a_person_key)};
    return keyInt1 > keyInt2;
}

Setting &Setting::operator=(const Setting &s)
{
    if (this == &s)
        return *this;
    a_car_name = s.a_car_name;
    a_email = s.a_email;
    a_person_key = s.a_person_key;
    a_odo = s.a_odo;
    a_service_remind = s.a_service_remind;
    return *this;
}

std::ostream &Setting::identify(std::ostream &out) const
{
    out << "Common: " << a_car_name << ", " << a_email;
    out << ", " << a_person_key << ", " << a_odo;
    out << ", " << a_service_remind;
    return out;
}

Setting::Setting(const std::string &name, const std::string &mail, const std::string &key, int odo, int service)
    : a_car_name{name}, a_email{mail}, a_person_key{key}, a_odo{odo}, a_service_remind{service}
{
}

Setting::~Setting(){};