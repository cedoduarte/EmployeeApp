#ifndef DEPARTMENTCOMBOPOPULATOR_H
#define DEPARTMENTCOMBOPOPULATOR_H

#include "icombopopulator.h"

class DepartmentComboPopulator : public IComboPopulator
{
public:
    DepartmentComboPopulator();
    void populate() override;
};

#endif // DEPARTMENTCOMBOPOPULATOR_H
