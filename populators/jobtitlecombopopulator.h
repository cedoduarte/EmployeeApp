#ifndef JOBTITLECOMBOPOPULATOR_H
#define JOBTITLECOMBOPOPULATOR_H

#include "icombopopulator.h"

class JobTitleComboPopulator : public IComboPopulator
{
public:
    JobTitleComboPopulator();
    void populate() override;
};

#endif // JOBTITLECOMBOPOPULATOR_H
