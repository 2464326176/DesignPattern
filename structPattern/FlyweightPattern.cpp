
#include <iostream>

using namespace std;
#include <ctime>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> g_colors = {"red", "blur", "green", "black", "white", "yellow"};
class Shape {
    void draw();
};

time_t g_t;

class Circle : public Shape {
public:
    Circle(string color) {
        m_color = color;
    }

    void setX(int x) {
        m_x = x;
    }

    void setY(int y) {
        m_y = y;
    }

    void setR(int r) {
        m_radius = r;
    }

    void draw() {
        cout << "circle: color: " << m_color << " x: " << m_x << " y: " << m_y << " r: " << m_radius << endl;
    }

public:
    int m_x;
    int m_y;
    int m_radius;
    string m_color;
};

class ShapeFactory {
public:

    static Circle* getCircle(string color) {
        map<string, Circle*>::iterator mapCircle = m_circleMap.find(color);
        if (mapCircle == m_circleMap.end()) {
            Circle* circle = new Circle(color);
            m_circleMap.insert(pair<string, Circle*>(color, circle));
            cout << "system create circle of color:" << color << endl;
            return circle;
        }
        return mapCircle->second;
    }
public:
    static map<string, Circle*> m_circleMap;
};

int getRandX() {
    return int(rand() % 50);
}

int getRandY() {
    return int(rand() % 50);
}

int getRandColor() {
    return int(rand() % g_colors.size());
}
map<string, Circle*> ShapeFactory::m_circleMap;

int main() {
    srand((unsigned) time(&g_t));

    for (int i = 0; i < 20; ++i) {
        Circle* circle = ShapeFactory::getCircle(g_colors[getRandColor()]);
        circle->setX(getRandX());
        circle->setY(getRandY());
        circle->draw();
    }
    /*
    for (auto circleMap : ShapeFactory::m_circleMap) {
        cout << circleMap.second->m_color << endl;
    }*/

    return 0;
}