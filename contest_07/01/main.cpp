#include <iostream>

struct Time{
    short hours;
    short minutes;
    short seconds;
    
    void addSeconds(short count){
        seconds += count;
        if (seconds >= 60){
            count = seconds / 60;
            seconds %= 60;
        } else return;
        
        minutes += count;
        if (minutes >= 60){
            count = minutes / 60;
            minutes %= 60;
        } else return;
        
        hours += count;
        if (hours >= 60)
            hours = minutes = seconds = 0;
    }
};

bool operator==(const Time& lhs, const Time& rhs){
    return lhs.hours == rhs.hours &&
           lhs.minutes == rhs.minutes &&
           lhs.seconds == rhs.seconds;
}

bool operator!=(const Time& lhs, const Time& rhs){
    return not (lhs == rhs);
}

bool operator<(const Time& lhs, const Time& rhs){
    return lhs.hours * 3600 + lhs.hours * 60 + lhs.seconds < rhs.hours * 3600 + rhs.hours * 60 + rhs.seconds;
}

class IRunnable{
public:
    virtual void run() = 0;
};

class IClock{
public:
    virtual void add(IRunnable* client, Time time) = 0;
    virtual bool next() = 0;
};

// Ваш код здесь
#include <vector>
#include <string>

class OSUpdater : public IRunnable {
public:
    void run() {
        std::cout << "OSUpdater" << std::endl;
    }
};

class Alarm : public IRunnable {
public:
    void run() {
        std::cout << "Alarm" << std::endl;
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() {
        std::cout << "ActivityChecker" << std::endl;
    }
};

class Clock : public IClock, public IRunnable {
private:
    struct Event {
        IRunnable* client;
        Time time;
    };

    std::vector<Event> events;
public:
    void add(IRunnable* client, Time time) {
        Event event;
        event.client = client;
        event.time = time;
        events.push_back(event);
    }

    std::string AddZero(short number) {
        if (number < 10) {
            return "0" + std::to_string(number);
        }
        else {
            return std::to_string(number);
        }
    }

    bool next() {
        if (events.empty()) {
            return false;
        }

        int nextIndex = 0;
        Time nextTime = events[0].time;
        for (int i = 1; i < events.size(); i++) {
            if (events[i].time < nextTime) {
               nextIndex = i;
               nextTime = events[i].time;
           }
        }
    
        std::cout << AddZero(nextTime.hours) << ":" << AddZero(nextTime.minutes) << ":" << AddZero(nextTime.seconds) << " ";
        events[nextIndex].client->run();
        events.erase(events.begin() + nextIndex);

        return true;
    }

    void run() {
        while (next()) {
    
        }
    }
};
//Конец вашего кода
int main(){
    int monentum;
    std::cin >> monentum;
    srand(monentum);  // Фиксируем случайность
    
    IClock* clock = new Clock;
    IRunnable* timer = (Clock*)clock;
    
    Time t = {0, 0, 0}, midnight = {0, 0, 0};
    
    do{
        int type = rand() % 3;
        if (type == 0) clock->add(new OSUpdater, t);
        else if (type == 1) clock->add(new Alarm, t);
        else if (type == 2) clock->add(new ActivityChecker, t);
        t.addSeconds(3600 + rand() % 3600);
    }while(t != midnight);
    
    timer->run();
}
