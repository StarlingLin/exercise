#define _CRT_SECURE_NO_WARNINGS

#include "Time.h"

int Time::count = 0;

Time::Time(int hour, int minute, int second)
{
	SetTime(hour, minute, second);
	count++;
}

Time::~Time()
{
	count--;
}

void Time::SetTime(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	CheckTime();
}

void Time::PrintTime() const
{
	std::cout << hour << ":" << minute << ":" << second << std::endl;
}

void Time::AddTime(int hour, int minute, int second)
{
	this->hour += hour;
	this->minute += minute;
	this->second += second;
	CheckTime();
}

void Time::SubTime(int hour, int minute, int second)
{
	this->hour -= hour;
	this->minute -= minute;
	this->second -= second;
	CheckTime();
}

void Time::PrintTime(int format) const
{
	switch (format)
	{
		case FORMAT_24:
			std::cout << hour << ":" << minute << ":" << second << std::endl;
			break;
		case FORMAT_12:
			if (hour >= 12)
			{
				std::cout << hour - 12 << ":" << minute << ":" << second << " PM" << std::endl;
			}
			else
			{
				std::cout << hour << ":" << minute << ":" << second << " AM" << std::endl;
			}
	}
}

void Time::PrintCurrentTime() const
{
	time_t t = time(0);
	tm* local = localtime(&t);
	std::cout << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << std::endl;
}

void Time::CheckTime()
{
	if (second >= 60)
	{
		minute += second / 60;
		second %= 60;
	}
	if (minute >= 60)
	{
		hour += minute / 60;
		minute %= 60;
	}
	if (hour >= 24)
	{
		hour %= 24;
	}
}