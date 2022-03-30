#include "MeetingWindow.h"
#include "AnimationWindow.h"
#include "Person.h"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string& title):
        AnimationWindow(x, y, w, h, title), quitBtn{Fl_Button(w - pad- btnW, pad, btnW, btnH, "Quit")},
        personName{Fl_Input(fieldPad, pad, fieldW, fieldH, "Name")},
        personEmail{Fl_Input(fieldPad, 2*pad + fieldH, fieldW, fieldH, "Email")},
        personNewBtn{Fl_Button(fieldPad, 3*pad + 2*fieldH, btnW, btnH, "Add person")} {
            add(quitBtn);
            add(personEmail);
            add(personName);
            add(personNewBtn);
            personNewBtn.callback(cb_newPerson, this);
            quitBtn.callback(cb_quit, this);
        }

void MeetingWindow::cb_quit(Fl_Widget*, void* pw){
    static_cast<MeetingWindow*>(pw)->hide();
}

void MeetingWindow::newPerson(){
    if(personName.value() != "" && personEmail.value() != ""){
        people.emplace_back(new Person{personName.value(), personEmail.value()});
        personName.value("");
        personEmail.value("");
    }
}

void MeetingWindow::cb_newPerson(Fl_Widget*, void* pw){
    static_cast<MeetingWindow*>(pw)->newPerson();
}

void MeetingWindow::printPeople() const{
    for(auto p: people){
        std::cout << p.get()->getName() << "\n";
    }
}