#ifndef LINE_H
#define LINE_H
#include <vector>

#include "LinkedListTrams.h"
#include "LinkedListStations.h"
#include "NodeTram.h"
#include "NodeStation.h"



class Line
{
    public:
        Line();
        Line(LinkedListStations *LLS,LinkedListTrams *LLT);
        LinkedListStations *getLLS() const;
        LinkedListTrams *getLLT() const;
        void setLLS(LinkedListStations *A);
        void setLLT(LinkedListTrams *T);
    private:
        LinkedListStations *d_LLS;
        LinkedListTrams *d_LLT;
};

#endif // LINE_H
