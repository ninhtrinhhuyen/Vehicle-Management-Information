#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <string>

class CommonInfo
{
    public:
        CommonInfo() = delete;
        CommonInfo(const std::string& number, const std::string& name)
        : a_number{number}, a_name{name}
        {

        }
        ~CommonInfo(){};
        std::string getNumber() const {return a_number;}
	
        std::string getName()   const {return a_name;}
        
        void setNumber(const std::string& number)
        {
            a_number = number;	
        }
        
        void setName(std::string& name)
        {
            a_name = name;
        }

        friend std::ostream& operator<<(std::ostream& out, const CommonInfo& c);
    private:
        std::string a_number;
        std::string a_name;
};

inline std::ostream& operator<<(std::ostream& out, const CommonInfo& c)
{
    out << c.a_number << ' ' << c.a_name;
    return out;
}

#endif // COMMON_H_