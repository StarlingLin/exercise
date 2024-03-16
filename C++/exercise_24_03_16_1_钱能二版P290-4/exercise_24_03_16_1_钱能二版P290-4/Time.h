#pragma once

#include <iostream>

enum TimeFormat
{
	FORMAT_24 = 1,
	FORMAT_12
};

class Time
{
	public:
		Time(int hour = 0, int minute = 0, int second = 0);
		~Time();
		void SetTime(int hour, int minute, int second);
		void PrintTime() const;
		void AddTime(int hour, int minute, int second);
		void SubTime(int hour, int minute, int second);
		void PrintTime(int format) const;
		void PrintCurrentTime() const;

	private:
		int hour;
		int minute;
		int second;

		void CheckTime();	//检查时间是否合法

		static int count;	//记录Time对象的个数
};