#include "mylog.h"

void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h,
        const std::string& s){
    if (begin()!=end()){
        const TIME::Evt1jDur* lastEvent=dynamic_cast<const TIME::Evt1jDur*>(*(--end()));
        if (d<lastEvent->getDate() || (d==lastEvent->getDate()&&h<lastEvent->getHoraire()))
            throw LogError("Addition of a posterior event");
    }
    TIME::Evt1jDur e(d,s,h,TIME::Duree(0));
    *this << e;
}

void MyLog::displayLog(std::ostream& f) const{
    for(Agenda::const_iterator it=begin(); it!=end(); ++it)
        f<<dynamic_cast<const TIME::Evt1jDur&>(*it).getDate()<<" - "<<
            dynamic_cast<const TIME::Evt1jDur&>(*it).getHoraire()<<":"<<(*it).getDescription()<<"\n";
}

