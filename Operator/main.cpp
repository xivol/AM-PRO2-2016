#include "point.h"
#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        point start, finish;
        cout << "¬ведите начальную точку: ";        
        cin >> start;
        cout << "¬ведите конечную точку: ";        
        cin >> finish;

        double v, a;
        cout << "¬ведите начальную скорость: ";        
        cin >> v;
        cout << "¬ведите ускорение: ";        
        cin >> a;

        vector vel(start, finish), acc(start, finish);
        vel.normalize();
        vel = vel*v;
        acc.normalize();
        acc = acc*a;

        double t  = 10;
        double time = 0;
        point cur = start;
        point next = start;
        while(start.distance_to(next) < start.distance_to(finish))
        {
            cur = next;
            cout<< time << ":" <<cur <<" "<<start.distance_to(cur)<<" "<< vel.length() << endl;            
            next = cur + vel;
            vel = vel + acc * t;
            time += t;           
        }
        time -= t;
        vel = vel - acc * t;
        // at^2 + 2vt + 2s = 0
        double s = cur.distance_to(finish);
        v = vel.length();
        double d = 4*v*v + 8 * a * s;

        if (d >= 0) 
            t = (-2*v+ sqrt(d))/2/a;
        time += t;
        cout<< time<<endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    system("pause");
    return 0;
}