#ifndef DEF_TIMER_H
#define DEF_TIMER_H

class Timer {
public:
	void Reset();
	void Start();

	double GetTime();
private:
	double _startTime;
};

#endif
