#include "mylog.h"

using namespace TIME;

void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h,const std::string& s){
    evts << TIME::Evt1jDur(d,s,h,TIME::Duree(0));
}
void MyLog::displayLog(std::ostream& f) const{
    for(Agenda::iterator it=evts.begin(); it!=evts.end(); ++it)
        f << dynamic_cast<const TIME::Evt1jDur&>(*it).
                getHoraire()<<":"<<(*it).getDescription()<<"\n";
}
