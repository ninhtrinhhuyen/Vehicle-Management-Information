#include "Sound.h"

Sound::Sound(const Setting& s, int media = 0, int call = 0, int navigation = 0, int notification = 0)
            : Setting{s}, a_media_level{media}, a_call_level{call}
            , a_navigation_level{navigation}, a_notification_level{notification}
{

}

Sound::~Sound()
{
}
// setter function
int Sound::getMediaVolumeLevel() const         {return a_media_level;}
int Sound::getCallVolumeLevel() const          {return a_call_level;}
int Sound::getNavigationVolumeLevel() const    {return a_navigation_level;}
int Sound::getNotificationVolumeLevel() const  {return a_notification_level;}
// getter function
void Sound::setMediaVolumeLevel(const int media_level)
{
    a_media_level = media_level;
}
void Sound::setCallVolumeLevel(const int call_level)
{
    a_call_level = call_level;
}
void Sound::setNavigationVolumeLevel(const int navigation_level)
{
    a_navigation_level = navigation_level;
}
void Sound::setNotificationVolumeLevel(const int notification_level)
{
    a_notification_level = notification_level;
}
// print info of used
void Sound::printInfo()
{
    std::cout << std::right << std::setw(15)  << a_media_level << std::setw(15)  << a_call_level;
    std::cout << std::setw(15)  << a_navigation_level << std::setw(15)  << a_notification_level;
}
// enter infomation of used
void Sound::enterInfo()
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
    std::cout << "Enter media volume level: ";
    a_media_level = data::enterInteger(data::k_min_level, data::k_max_level);
    std::cout << "Enter call volume level: ";
    a_call_level = data::enterInteger(data::k_min_level, data::k_max_level);
    std::cout << "Enter navigation volume level: ";
    a_navigation_level = data::enterInteger(data::k_min_level, data::k_max_level);
    std::cout << "Enter notification volume level: ";
    a_notification_level = data::enterInteger(data::k_min_level, data::k_max_level);
}

std::ostream& Sound::identify(std::ostream& out) const
{
    out << " Sound: " << a_media_level << ", " << a_call_level;
    out << ", " << a_navigation_level << ", " << a_notification_level;
    return out;
}