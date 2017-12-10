#include <iostream>

#include <ctime>

#include <cstdlib>

#include "iotDataQueue.h"





using namespace std;

iotDataQueue sensorQueue;

int counter = 0; //counter for counting the contents of the queue

//Base class

class Sensor{



public:

    virtual int getReadings()=0;

    virtual int setReadings(int reading)=0;



    void setLowestPossibleValue(int lowest) {

        lowestPossibleValue = lowest;

    }



    void setHighestPossibleValue(int highest){

        highestPossibleValue = highest;

    }

protected:

    int lowestPossibleValue;

    int highestPossibleValue;

};

//derived class from the base class

class Temperature: public Sensor {



public:

    int getReadings(){

        srand((unsigned)time(0));

        int range = (highestPossibleValue-lowestPossibleValue)+1;

        int reading = lowestPossibleValue+int(range/(rand()%10+1));

        return reading;

    }



    int setReadings(int reading) {

        return reading;

    }



};

//derived class from the base class

class Humidity: public Sensor {



public:

    int getReadings(){



        srand((unsigned)time(0));

        int range = (highestPossibleValue-lowestPossibleValue)+1;

        int reading = lowestPossibleValue+int(range/(rand()%100+5));

        float Tc=5.0/9.0*reading;

        float Tdc=5.0/9.0*(reading+32);

        float Es=6.11*10.0*(7.5*Tc/(237.7+Tc));

        float E=6.11*10.0*(7.5*Tdc/(237.7+Tdc));

        float RH = (E/Es)*100;

        return static_cast<int>(RH);

    }



    int setReadings(int reading) {

        return reading;

    }



};

//printing contents of the queue and emptying it

void printContents(){

  cout << "Readings content: " << endl;

  while (counter >= 0)

  {

    cout << ' ' << sensorQueue.qget() << endl;

    counter --;

  }

}

//getting temperature

int getTemp() {

    Temperature temp;

    int result = 0;

    temp.setHighestPossibleValue(58);

    temp.setLowestPossibleValue(-88);

    result = temp.getReadings();

    return result;

}

//getting humidity in percent

int getHumid(){

    Humidity humid;

    int result = 0;

    humid.setHighestPossibleValue(58);

    humid.setLowestPossibleValue(-88);

    result = humid.getReadings();

    return result;

}

int main()

{

    char choice;

    int result = 0;





    do {

        cout << "Pick Action from Menu"<< endl;

        cout << "[1] Get Temperature"<< endl;

        cout << "[2] Get Humidity"<< endl;

        cout << "[3] Exit"<< endl;

        cin >> choice;



        switch (choice) {

            case '1':

                        result = getTemp();

                        if (counter < 10) {

                            sensorQueue.qput(result); //pushing value to queue

                            cout << "Storing content["<<counter+1<<"]..."<< endl;

                            cout << result << " Stored!"<< endl;

                        } else {

                            printContents();

                            return 0;

                        }

                        counter++;

                        break;

            case '2':

                        result = getHumid();

                        if (counter < 10) {

                            sensorQueue.qput(result);//pushing value to queue

                            cout << "Storing content["<<counter+1<<"]"<< endl;

                            cout << result << " Stored!"<< endl;

                        } else {

                            printContents();

                            return 0;

                        }

                        counter++;

                        break;

            case '3': return 0;

            default: cout<<"\n Invalid selection" << endl;

        }

    } while (choice != 3);



    return 0;

}

