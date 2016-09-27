#include <iostream>
#include "iotDataQueue.h"

using namespace std;

iotDataQueue::iotDataQueue()
{
    //ctor
}

iotDataQueue::~iotDataQueue()
{
    //dtor
}

void iotDataQueue::init()
{
    rloc = sloc = 0;
}

//initialise the queue
void iotDataQueue::qput(int i)
{
    if(sloc==100){
        cout << "queue is full. \n";
        return;
    }
    sloc++;
    q[sloc] = i;
}

//get an integer from the queue
int iotDataQueue::qget()
{
    if(rloc == sloc){
        cout << "queue underflow. \n";
        return 0;
    }
    rloc++;
    return q[rloc];
}

