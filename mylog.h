#ifndef CPP_2021_MYLOG_H
#define CPP_2021_MYLOG_H



#include "log.h"
#include "evenement.h"
class MyLog : public Log, private TIME::Agenda {
public:
    void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s);
    void displayLog(std::ostream& f) const;
};


class LogError : public std::exception {
    std::string info;
public:
    LogError(const char* s) noexcept:info(s){}
    const char* what() const noexcept { return info.c_str(); }
};




#endif //CPP_2021_MYLOG_H
