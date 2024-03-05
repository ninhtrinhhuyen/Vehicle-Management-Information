#ifndef SETTING_H_
#define SETTING_H_

#include "Data.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>


class Setting
{
public:
    Setting() = delete;
    Setting(const std::string& name, const std::string& mail, const std::string& key, int odo, int service);
    virtual ~Setting();
    // print info of used
    virtual void printInfo();
    // enter infomation of used
    virtual void enterInfo();

    std::string getCarName() const;
    std::string getPersonKey() const;
    std::string getEmail() const;
    int getODO() const;
    int getServiceRemind() const;

    // display common information
    void displayCommonInfo();

    // sort name by alphabet a -> z
    static bool compareName(const Setting *s1, const Setting *s2);


    friend std::ostream& operator<<(std::ostream& out, const Setting& s);
    Setting& operator=(const Setting& s);
    friend bool operator<(const Setting& s1, const Setting& s2);
    friend bool operator>(const Setting& s1, const Setting& s2);
    virtual std::ostream& identify(std::ostream& out) const;

protected:    
    void setCarName(const std::string& car_name);
    void setPersonKey(const std::string& person_key);
    void setEmail(const std::string& email);
    void setODO(const int odo);
    void setServiceRemind(const int service_remind);
private:
    std::string a_car_name;
    std::string a_person_key;   // chuoi co 8 chu so
    std::string a_email;        // format abc@xyz.com
    int a_odo;
    int a_service_remind;
};

#endif // SETTING_H_