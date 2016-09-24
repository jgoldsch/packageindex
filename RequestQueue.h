#include <queue>
#include <mutex>
#include <condition_variable>
 

class RequestQueue {

  std::queue<int> m_queue;
  std::mutex m_mutex;
  std::condition_variable m_cond;

 public:

  RequestQueue() {}

  ~RequestQueue() {}

  int pop()
  {
    std::unique_lock<std::mutex> lk(m_mutex);
    while (m_queue.empty())
      {
	m_cond.wait(lk);
      }
    int item = m_queue.front();
    m_queue.pop();
    return item;
  }
 
  void push(const int& item)
  {
    std::unique_lock<std::mutex> lk(m_mutex);
    m_queue.push(item);
    lk.unlock();
    m_cond.notify_one();
  }
};
