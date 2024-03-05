#ifndef SOUND_H_
#define SOUND_H_

#include "Setting.h"

class Sound : public Setting
{
    public:
        Sound() = delete;
        Sound(const Setting& s, int media, int call, int navigation, int notification);
        ~Sound();
        int getMediaVolumeLevel() const;
        int getCallVolumeLevel() const;
        int getNavigationVolumeLevel() const;
        int getNotificationVolumeLevel() const;
        void setMediaVolumeLevel(const int media_level);
        void setCallVolumeLevel(const int call_level);
        void setNavigationVolumeLevel(const int navigation_level);
        void setNotificationVolumeLevel(const int notification_level);
        // print info of used
        void printInfo() final;
        // enter infomation of used
        void enterInfo() final;
        std::ostream& identify(std::ostream& out) const final;
    private:
        int a_media_level;
        int a_call_level;
        int a_navigation_level;
        int a_notification_level;
        bool isAlready{false}; // non-already existed
};

#endif // SOUND_H_