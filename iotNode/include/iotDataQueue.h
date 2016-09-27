#ifndef IOTDATAQUEUE_H
#define IOTDATAQUEUE_H


class iotDataQueue
{
    public:
        iotDataQueue();
        virtual ~iotDataQueue();
        void init();
        void qput(int i);
        int qget();

    protected:

    private:
        int q[10];
        int sloc, rloc;
};

#endif // IOTDATAQUEUE_H
