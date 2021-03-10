#ifndef __DISPLAYTEXT_H__
#define __DISPLAYTEXT_H__

enum colors {WHITE = 0, GREEN, RED, PURPLE, BLUE, YELLOW};

class DisplayText {

    private:


    public:
        DisplayText();
        virtual ~DisplayText();

        /* Accessors */

        /* Functions */
        void print(std::string text, std::string color);
        void print(std::string text, int color);
};

#endif
