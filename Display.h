#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "Setting.h"
class Display : public Setting
{
    public:
        Display() = delete;
        Display(const Setting& s, int light, int screen, int taplo);
        ~Display();
        int getLightLevel() const;
        int getScreenLevel() const;
        int getTaploLightLevel() const;
        void setLightLevel(const int light_level);
        void setScreenLevel(const int screen_level);
        void setTaploLightLevel(const int taplo_light_level);
        std::ostream& identify(std::ostream& out) const final;
        // print info of used
        void printInfo() final;
        // enter infomation of used
        void enterInfo() final;
    private:
        int a_light_level;
        int a_screen_level;
        int a_taplo_light_level;
        bool isAlready{false}; // non-already existed
};
#endif // DISPLAY_H_