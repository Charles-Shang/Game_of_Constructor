#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Observer {
   public:
    // update the availability of building residence for neighbour vertices
    virtual void update();
    virtual ~Observer() = default;  // destructor
};

#endif
