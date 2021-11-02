#include "mylog.h"

void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h,
        const std::string& s){
    *this << TIME::Evt1jDur(d,s,h,TIME::Duree(0));
}

void MyLog::displayLog(std::ostream& f) const{
    for(Agenda::const_iterator it=begin(); it!=end(); ++it)
        f<<dynamic_cast<const TIME::Evt1jDur&>(*it).getDate()<<" - "<<
            dynamic_cast<const TIME::Evt1jDur&>(*it).getHoraire()<<":"<<(*it).getDescription()<<"\n";
}

