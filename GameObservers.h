#ifndef GAME_GAMEOBSERVERS_H
#define GAME_GAMEOBSERVERS_H

class Subject{
private:
    std::vector<Observer *> obs;
  	int *state;

public:
    void attach(Observer *o);
    void detach(Observer *o);
    virtual void notifyAllObservers();
  	int getState();
    void setState(int i);
};

class Observer {
protected:
		Subject *subject;  
public:
    virtual void update();
};

class GameStateObserver : public Observer{

  public:
    GameStateObserver(Subject *subject);
  	virtual void update() update;
};
/*
 * Place Tile Observer (notifies game state observer when a tile is placed on gb)
 */
class PlaceTileObserver : public Observer {

public:
    PlaceTileObserver(Subject *subject);

    virtual void update() override;
};

class PlaceBuildingObserver : public Observer {

public:
    PlaceBuildingObserver(Subject *subject);

    virtual void update() override;
};

class DrawObserver : public Observer {

public:
    DrawObserver(Subject *subject);

    virtual void update() override;
};

class ResetObserver : public Observer {

public:
    ResetObserver(Subject *subject);

    virtual void update() override;
};

class ComputeScoreObserver : public Observer{
public:
  ComputeScoreObserver(Subject *subject);
  
  virtual void update() override;
}
#endif //GAME_GAMEOBSERVERS_H

