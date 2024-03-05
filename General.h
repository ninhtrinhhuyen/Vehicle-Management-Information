#ifndef GENERAL_H_
#define GENERAL_H_

#include "Setting.h"
#include "Data.h"
#include <algorithm>
#include <vector>

// sort time zone
void sortTimeZone();
// sort language
void sortLanguage();

class General : public Setting
{
    public:
        General() = delete;
        General(const Setting& s, const std::string& time, const std::string& lang);
        ~General();
        std::string getTimeZone() const;
        std::string getLanguage() const;
        void setTimeZone(const std::string& time_zone);
        void setLanguage(const std::string& language);
        // print info of used
        void printInfo() final;
        // enter infomation of used
        void enterInfo() final;
        // selection Time Zone
        void selectionTimeZone();
        // selection Language
        void selectionLanguage();
        
        std::ostream& identify(std::ostream& out) const final;
    private:
        std::string a_time_zone;
        std::string a_language;
        bool isAlready{false}; // non-already existed
};

#endif // GENERAL_H_