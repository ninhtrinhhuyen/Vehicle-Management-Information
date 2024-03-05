#include "Display.h"

Display::Display(const Setting& s, int light = 0, int screen = 0, int taplo = 0)
                :Setting{s}, a_light_level{light}, a_screen_level{screen}
                , a_taplo_light_level{taplo}
{

}

Display::~Display(){}
// getter function
int Display::getLightLevel() const         {return a_light_level;}
int Display::getScreenLevel() const         {return a_screen_level;}
int Display::getTaploLightLevel() const    {return a_taplo_light_level;}
// setter function
void Display::setLightLevel(const int light_level)             {a_light_level = light_level;}
void Display::setScreenLevel(const int screen_level)            {a_screen_level = screen_level;}
void Display::setTaploLightLevel(const int taplo_light_level)  {a_taplo_light_level = taplo_light_level;}


// print info of used
void Display::printInfo()
{
    std::cout << std::right;
    std::cout << std::setw(15) << a_light_level << std::setw(15)  << a_screen_level << std::setw(15)  << a_taplo_light_level;
}
// enter infomation of used
void Display::enterInfo()
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
    std::cout << "Enter light level: ";
    a_light_level = data::enterInteger(data::k_min_level, data::k_max_level);
    std::cout << "Enter screen level: ";
    a_screen_level = data::enterInteger(data::k_min_level, data::k_max_level);
    std::cout << "Enter taplo light level: ";
    a_taplo_light_level = data::enterInteger(data::k_min_level, data::k_max_level);
}

std::ostream& Display::identify(std::ostream& out) const
{
    out << " Display: " << a_light_level;
    out << ", " << a_screen_level << ", " << a_taplo_light_level;
    return out;
}