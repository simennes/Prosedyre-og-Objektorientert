#pragma once
#include "AnimationWindow.h"
#include <iostream>
#include "Person.h"
#include <vector>

class MeetingWindow : public AnimationWindow{

    private:
        static constexpr int pad = 10;
        static constexpr int btnW = 80;
        static constexpr int btnH = 40;
        static constexpr int fieldW = 200;
        static constexpr int fieldH = 25;
        static constexpr int fieldPad = 50;
        Fl_Button quitBtn;
        Fl_Input personName;
        Fl_Input personEmail;
        Fl_Button personNewBtn;
        std::vector<std::shared_ptr<Person>> people;

    public:
        MeetingWindow(int x, int y, int w, int h, const std::string& title);
        static void cb_quit(Fl_Widget*, void* pw);
        static void cb_newPerson(Fl_Widget*, void* pw);
        void newPerson();
        void printPeople() const;
};