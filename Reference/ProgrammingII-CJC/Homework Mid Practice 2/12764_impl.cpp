#include "12764.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using namespace oj;

namespace oj {
    class Circle : public Shape {
    public: 
        void setArea(double datas[]) {
            area = datas[0] * datas[0] * datas[1];
        }

        void print() {
            cout.setf(std::ios_base::fixed);
            cout.precision(2);
            cout << "Circle(" << getArea() << ")\n";
        }
    };

    class Square : public Shape {
    public: 
        void setArea(double datas[]) {
            area = datas[0] * datas[0];
        }

        void print() {
            cout.setf(std::ios_base::fixed);
            cout.precision(2);
            cout << "Square(" << getArea() << ")\n";
        }
    };
}


void BST::insertNode(std::string& str) {
    Node* newNode = new Node();

    vector<string> splitStr;
    istringstream iss(str);
    for(string s; iss >> s; ){
        splitStr.push_back(s);
    }

    Shape* m_shape ; // factory return this Shape
    if(splitStr[0] == "Square"){
        m_shape = new Square();

        double tempArray[1] = {stod(splitStr[1])};
        m_shape->setArea(tempArray);
    } else if (splitStr[0] == "Circle") {
        m_shape = new Circle();

        double tempArray[2] = {stod(splitStr[1]), stod(splitStr[2])};
        m_shape->setArea(tempArray);
    }
    // end of factory
    newNode->data = m_shape;
    bool done = false;

    if(root == nullptr) {
        root = newNode;
    } else {
        Node* temp = root;
        while(!done) {
            if(temp->data->getArea() > m_shape->getArea()) {
                if(temp->left == nullptr) {
                    temp->left = newNode;
                    done = true;
                } else {
                    temp = temp->left;
                }
            } else if (temp->data->getArea() < m_shape->getArea()) {
                if(temp->right == nullptr) {
                    temp->right = newNode;
                    done = true;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
}

