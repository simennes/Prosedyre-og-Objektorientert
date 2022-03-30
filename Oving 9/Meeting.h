#pragma once
#include <iostream>
#include <vector>
#include "Person.h"

enum class Campus {Trondheim, Aalesund, Gjovik};

std::ostream& operator<<(std::ostream& os, const Campus& c);

class Meeting{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        std::string subject;
        const std::shared_ptr<Person> leader;
        std::vector<std::shared_ptr<Person>> participants;
    public:
        Meeting(int d, int ti, int tf, Campus loc, std::string sub, const std::shared_ptr<Person> lead):
        day{d}, startTime{ti}, endTime{tf}, location{loc}, subject{sub}, leader{lead} 
        {addParticipant(lead);};
        int getDay() const{return day;}
        int getStartTime() const{return startTime;}
        int getEndTime() const{return endTime;}
        Campus getLocation() const{return location;}
        std::string getSubject() const{return subject;}
        const std::shared_ptr<Person> getLeader() const{return leader;}

        void addParticipant(std::shared_ptr<Person> newParticipants);
        std::vector<std::string> getParticipantsList() const;
        std::vector<std::shared_ptr<Person>> findPotentialCoDriving(Meeting m) const;
};

std::ostream& operator<<(std::ostream& os, const Meeting& m);