#ifndef BORDER_
#define BORDER_

#include "Entity.h"



class Border : public Entity
{
public:
    Border();
    ~Border();

    void update(double deltaT) override;

};

#endif // BORDER_
