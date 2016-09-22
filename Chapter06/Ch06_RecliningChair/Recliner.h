// File: recliner.h - Recliner class definition
//
#ifndef RECLINER_H
#define RECLINER_H

class Recliner
{
private:
	int seatbackAngle;

public:
	Recliner();
	Recliner(int anAngle);
	~Recliner();
	void setAngle(int anAngle);
	int angle();
	void reset();
};

#endif
