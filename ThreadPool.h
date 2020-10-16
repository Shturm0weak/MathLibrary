#pragma once
#include <thread>
#include <vector>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <future>

using Task = std::function<void()>;
class ThreadPool {
private:
	static ThreadPool* thread_pool;
	std::vector<std::thread> m_Threads;
	std::mutex m_mutex;
	std::thread::id main = std::this_thread::get_id();
	std::condition_variable m_condition_var;
	std::queue <Task> m_Tasks;
	
	void Infinite_loop_function();
	bool m_stopping = false;
	static bool initialized;
public:
	int num_Threads = 0;
	ThreadPool(int n);
	~ThreadPool();
	void Shutdown()noexcept;
	static ThreadPool* Instance() { return thread_pool; }
	void enqueue(Task task);
	static void Init();
};

bool ThreadPool::initialized = false; 
ThreadPool* ThreadPool::thread_pool; thread_pool