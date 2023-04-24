#include "../headers/Line.h"

Line::Line(LinkedListStations *LLS,LinkedListTrams *LLT): d_LLS{LLS},d_LLT{LLT}
{

}

Line::Line(): d_LLS{nullptr} , d_LLT{nullptr}
{

}

LinkedListStations *Line::getLLS() const
{
    return d_LLS;
}
LinkedListTrams *Line::getLLT() const
{
    return d_LLT;
}

void Line::setLLS(LinkedListStations *A)
{
   d_LLS=A;
}

void Line::setLLT(LinkedListTrams *T)
{
    d_LLT=T;
}

