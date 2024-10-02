#ifndef SALARYLINEEDITPREPARATOR_H
#define SALARYLINEEDITPREPARATOR_H

#include "ilineeditpreparator.h"

class SalaryLineEditPreparator : public ILineEditPreparator
{
public:
    SalaryLineEditPreparator();
    void prepare() override;
};

#endif // SALARYLINEEDITPREPARATOR_H
