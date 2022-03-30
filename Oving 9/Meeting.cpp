#include "Meeting.h"
#include "Person.h"
#include <iostream>
#include <vector>


std::ostream& operator<<(std::ostream& os, const Campus& c){
switch (c){
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        
        case Campus::Aalesund:
            os << "Aalesund";
            break;
        
        case Campus::Gjovik:
            os << "Gjovik";
            break;
        
        default:
            os << "Ikke gyldig campus";
    }
    return os;
}

void Meeting::addParticipant(std::shared_ptr<Person> newParticipant){
    participants.push_back(newParticipant);
}

std::vector<std::string> Meeting::getParticipantsList() const{
    std::vector<std::string> participantsList;
    for(auto p: participants){
        std::string name = p.get()->getName();
        participantsList.push_back(name);
    }
    return participantsList;
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting m) const{
    std::vector<std::shared_ptr<Person>> potentialCos;
    if(abs(m.getStartTime() - startTime) < 1 && abs(m.getEndTime() - endTime) < 1 && m.day == day
    && m.location == location){
        for(auto p: m.participants){
            if(p.get()->hasAvailableSeats()){
                potentialCos.push_back(p);
            }
        }
    }
    return potentialCos;
}

std::ostream& operator<<(std::ostream& os, const Meeting& m){
    os << "Subject: " << m.getSubject() << "\n";
    os << "Location: " << m.getLocation() << "\n";
    os << "Start time: " << m.getStartTime() << "\n";
    os << "End time: " << m.getEndTime() << "\n";
    os << "Leader: " << m.getLeader().get()->getName() << "\n";
    os << "Participants: ";
    for(std::string p: m.getParticipantsList()){
        os << p << ", ";
    }
    return os;
}