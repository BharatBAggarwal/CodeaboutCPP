// File: irecliner.h
// IRecliner class definition

#ifndef IRECLINE_H
#define IRECLINE_H

class IRecline
{
public:
	virtual void    setRecline(int anAngle) = 0;   // recline the seatback
	virtual int     recline() = 0;                 // get recline angle
};

#endif
