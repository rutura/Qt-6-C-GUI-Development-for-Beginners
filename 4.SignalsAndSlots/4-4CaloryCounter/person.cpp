#include "person.h"

void Person::setWeight(double weight)
{
    if (m_weight != weight) {
        m_weight = weight;
        emit weightChanged();
    }
}
