//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// uva12100
namespace uva12100 {
    struct Point {
        int priority;
        int status;
        int flag;

        Point(int priority = 0, int status = 0, int flag = 0) {
            this->priority = priority;
            this->status = status;
            this->flag = flag;
        }
    };

    int PrintQueue() {
        int n;
        cin >> n;
        while (n--) {
            int quantity, top;
            cin >> quantity >> top;
            vector<Point> points;
            priority_queue<int> maxPriority;
            for (int i = 0; i < quantity; i++) {
                int priority;
                cin >> priority;
                points.emplace_back(priority);
                maxPriority.push(priority);
            }
            points[top].flag = 1;

            int pointer = 0;
            int times = 0;
            while (true) {
                if (points[pointer].status == 0 && points[pointer].priority == maxPriority.top()) {
                    points[pointer].status = 1;
                    maxPriority.pop();
                    times++;
                    if (points[pointer].flag)
                        break;
                }
                pointer = (pointer + 1) % points.size();
            }
            cout << times << endl;
        }
        return 0;
    }
}
