#pragma once
#include <iostream>
#include <chrono>
#include "MathLibrary.h"

namespace debug {

	class MATH_API Timer {
		static double start;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
	public:

		Timer() {
			m_startTimePoint = std::chrono::high_resolution_clock::now();
		}

		~Timer() {
			Stop();
		}

		void Stop() {
			auto endTimePoint = std::chrono::high_resolution_clock::now();

			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();

			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

			auto duration = end - start;

			double ms = duration * 0.001;

			std::cout << duration << "us (" << ms << "ms)\n";
		}
	};

}