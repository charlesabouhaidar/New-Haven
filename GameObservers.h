#ifndef GAME_GAMEOBSERVERS_H
#define GAME_GAMEOBSERVERS_H
#include <list>

using std::list;

class Observer{
public:
    ~Observer();
    virtual void Update() = 0;
protected:
    Observer();
};

class Subject{
public:
    virtual void Attach(Observer* o);
    virtual void Detach(Observer* o);
    virtual void Notify();
    Subject();
    ~Subject();
private:
    list<Observer*> *_observers;
};

class TurnSubject : public Subject{

};

class TurnObserver : public Observer{

};

class StatSubject : public Subject{

};

class StatObserver : public Observer{

};

#endif //GAME_GAMEOBSERVERS_H
