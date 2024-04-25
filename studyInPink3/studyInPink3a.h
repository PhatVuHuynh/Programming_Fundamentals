/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	};
	string toString() const {
		stringstream ss;
		string m, n;
		ss << this->x;
		ss >> m;
		ss.clear();
		ss << this->y;
		ss >> n;
		string r = "<Point[" + m + ',' + n + "]>";
		return r;
	};

	int distanceTo(const Point& otherPoint) const {
		int d = ceil(sqrt(pow(otherPoint.x - this->x, 2) + pow(otherPoint.y - this->y, 2)));
		return d;
	};
};
class Node {
private:
	Point point;
	Node* next;

	friend class Path;
	friend class Point;

public:
	Node(const Point& point = Point(), Node* next = NULL) {
		this->point = point;
		this->next = next;
	};
	string toString() const {
		string s = "<Node[" + this->point.toString() + "]>";
		return s;
	};
};
class Path {
private:
	Node* head;
	Node* tail;
	int count;
	int length;

public:
	Path() {
		this->head = nullptr;
		this->tail = nullptr;
		this->count = 0;
		this->length = -1;
	};
	~Path() {
		Node* ptr = head;
		Node* n = nullptr;
		while (ptr != nullptr) {
			n = ptr->next;
			delete ptr;
			ptr = n;
		}
		head = nullptr;
		tail = nullptr;
	};

	void addPoint(int x, int y) {
		Node dN(Point(x, y));
		Node* pN = new Node(dN);
		if (head == nullptr) {
			head = pN;
			tail = pN;
		}
		else {
			tail->next = pN;
			tail = pN;
		}
		Node* pre = head;
		for (int i = 1; i < this->count && pre != nullptr; i++) {
			pre = pre->next;
		}
		(this->count)++;
		if (this->count == 1) this->length = 0;
		else if (this->count > 1) this->length += ceil(dN.point.distanceTo(pre->point));
	};
	string toString() const {
		Node* temp = this->head;
		string s = "";
		for (int i = 1; i <= this->count; i++) {
			s = s + temp->toString();
			if (i < this->count) s = s + ',';
			temp = temp->next;
		}
		stringstream ss;
		string a, b;
		ss << this->count;
		ss >> a;
		ss.clear();
		ss << this->length;
		ss >> b;
		string t = "<Path[count:" + a + ",length:" + b + ",[" + s + "]]>";
		return t;
	};
	Point getLastPoint() const {
		Point nP = tail->point;
		return nP;
	};
	int getLength() {
		return this->length;
	}
};
class Character {
private:
	string name;
	Path* path;

public:
	Character(const string& name = "") {
		this->name = name;
		Path* p1 = new Path();
		this->path = p1;
	};
	~Character() {
		delete this->path;
	};

	string getName() const {
		return this->name;
	};
	void setName(const string& name) {
		this->name = name;
	};

	void moveToPoint(int x, int y) {
		this->path->addPoint(x, y);
	};
	Point getCurrentPosition() const {
		return path->getLastPoint();
	}
	int lengthPathofChar() const {
		return this->path->getLength();
	}
	string toString() const {
		string s = "<Character[name:" + this->name + ",path:" + this->path->toString() + "]>";
		return s;
	};
};
bool rescueSherlock(
	const Character& chMurderer,
	const Character& chWatson,
	int maxLength,
	int maxDistance,
	int& outDistance
) {
	int l1 = chWatson.lengthPathofChar();
	int l2 = chMurderer.lengthPathofChar();
	Point v = chWatson.getCurrentPosition();
	Point c = chMurderer.getCurrentPosition();
	if (l1 - l2 <= maxLength) {
		outDistance = v.distanceTo(c);
		if (outDistance <= maxDistance) return 1;
	}
	else outDistance = -1;
	return 0;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */