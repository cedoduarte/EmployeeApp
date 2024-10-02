#ifndef EMAILLINEEDITPREPARATOR_H
#define EMAILLINEEDITPREPARATOR_H

#include "ilineeditpreparator.h"

class EmailLineEditPreparator : public ILineEditPreparator
{
public:
    EmailLineEditPreparator();
    void prepare() override;
};

#endif // EMAILLINEEDITPREPARATOR_H
