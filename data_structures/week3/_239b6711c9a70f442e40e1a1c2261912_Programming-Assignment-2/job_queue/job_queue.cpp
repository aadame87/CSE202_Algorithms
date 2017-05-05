#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

using std::swap;

struct Process
{
  Process(): priority( 0 ), job_num( 0 )
  {}

  Process( int p, int w ): priority( p ), job_num( w )
  {}

  long long priority;
  int job_num;

  friend bool operator<( const Process &proc1, const Process &proc2 );

  friend bool operator==( const Process &proc1, const Process &proc2 );

  friend bool operator>( const Process &proc1, const Process &proc2 );

  friend bool operator!=( const Process &proc1, const Process &proc2 );
};

bool operator<( const Process &proc1, const Process &proc2 )
{
  if ( proc1.priority < proc2.priority )
    return true;
  else if ( proc1.priority == proc2.priority )
  {
    if ( proc1.job_num < proc2.job_num )
      return true;
    else
      return false;
  }
  return false;
}

bool operator==( const Process &proc1, const Process &proc2 )
                {return proc1.priority == proc2.priority;}

bool operator>( const Process &proc1, const Process &proc2 )
                {return !( proc1 < proc2 ) && !( proc1 == proc2 );}

bool operator!=( const Process &proc1, const Process &proc2 )
                {return !( proc1 == proc2 );}

class Heap
{
public:
  explicit Heap( int size )
    : size_( size )
    , maxSize_( size + 10 )
    , data_( maxSize_ )
  {
    for ( int i = 0; i < size_; ++i )
    {
      data_[ i ] = Process( 0, i );
    }
  }

private:
  int size_;
  int maxSize_;
  vector< Process > data_;

  int LeftChild( int i ) { return 2 * i + 1; }

  int RightChild( int i ) { return 2 * i + 2; }

  int Parent( int i )
  {
    if ( i == 0 )
      return 0;
    else
      return ( i - 1 ) / 2;
  }

  void SiftUp( int i )
  {
    int c = i;

    while ( c > 0 && data_[ Parent( c ) ] > data_[ c ] )
    {
      swap( data_[ Parent( c ) ], data_[ c ] );
      c = Parent( c );
    }
  }

  void SiftDown( int i )
  {
    int maxIndex = i;
    int left = LeftChild( i );
    if ( left < size_ && data_[ left ] < data_[ maxIndex ] )
    {
      maxIndex = left;
    }

    int right = RightChild( i );
    if ( right < size_ && data_[ right ] < data_[ maxIndex ] )
    {
      maxIndex = right;
    }

    if ( i != maxIndex )
    {
      swap( data_[ i ], data_[ maxIndex ] );
      SiftDown( maxIndex );
    }
  }

public:
  void BuildHeap()
  {
    int mid = size_ / 2;
    for ( int i = mid; i >= 0; --i )
    {
      SiftDown( i );
    }
  }

  Process GetMax()
  {
    const Process &r = data_[ 0 ];
    return r;
  }

  void ChangePriority( int i, long long priority )
  {
    Process &r = data_[ i ];
    long long prev_priority = r.priority;
    r.priority = priority;
    if ( priority > prev_priority )
      SiftDown( i );
    else
      SiftUp( i );
  }

  void Insert( const Process &n )
  {
    size_ += 1;
    data_[ size_ - 1 ] = n;
    SiftUp( size_ - 1 );
  }
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }
/*
  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }*/

  void AssignJobs()
{
  assigned_workers_.resize( jobs_.size() );
  start_times_.resize( jobs_.size() );
  vector< long long > next_free_time( num_workers_, 0 );
  Heap heap( num_workers_ );
  int duration;
  for ( size_t i = 0; i < jobs_.size(); ++i )
  {
    duration = jobs_[ i ];
    Process Process = heap.GetMax();
    assigned_workers_[ i ] = Process.job_num;
    start_times_[ i ] = next_free_time[ Process.job_num ];
    next_free_time[ Process.job_num ] += duration;
    heap.ChangePriority( 0, Process.priority + ( long long )duration );
  }
}

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
