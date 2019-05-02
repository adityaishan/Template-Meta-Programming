#include"bits/stdc++.h"
//------------------CP stuff---------------------------------------------------------
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//-----------------------------------------------------------------------------------
#define ll long long int
#define llu unsigned long long int
#define db long double
using namespace std;
#define PI 3.1415926535897932
const db eps=1e-6;
const ll MOD=1e9+7;
const int MAX=1e9+5;
using namespace std;

template<typename T, typename U>
T maxx1(T x, U y){
   return max(x, y);
}

template<typename T, typename U>
T max1(T x, U y){
   //cout<<1<<"\n";
   return (x.compare(y) < 0) ? y : x;
}

//Explicit instantiation
template string max1(string x, string y);

//Explicit Specialization
// no need to write: template<> T func_name<T>();
template<> const char* max1(const char* x, const char* y){
   //cout<<2<<"\n";
   return (strcmp(x, y) < 0) ? y : x;
}

template<int T>
void print(){
   cout << T << "\n";
}

template<typename T>
T Sum(T *parr, int size){
  T sum{};//uniform initialization of modern C++, same as T sum = 0;
  for(int i = 0; i != size; ++i){
	  sum += parr[i];
	}
  return sum;
}

template<typename T>
void print1(initializer_list<T> args){
   for(const auto& x : args){
	  cout << x << " ";
   }
   cout<<"\n";	  
}

//Base Case for variadic template
void print2(){
  cout << "\n";
}

//Variadic Templates
//template parameter pack
template<typename T, typename... Params>
//function parameter pack
void print2(T&& a, Params&&... args){
  cout << a;
  if(sizeof... (args)) cout << ",";
  print2(std::forward<Params>(args)... );
}

template<typename T, int size>
class Stack
{
private:
  T m_Buffer[size];
  int m_Top{-1};

public:
  void Push(const T& elem){
    m_Buffer[++m_Top] = elem;
  }
  
  void Pop();
  
  const T& Top() const{
	return m_Buffer[m_Top];
  }

  bool IsEmpty(){
   return m_Top == -1;
 }
};

template<typename T, int size>
void Stack<T, size>::Pop(){
  --m_Top;
}

template<typename T>
class Printer{
public:
  Printer(T* data) : m_pdata(data) {}

  void Print(){
	cout << *m_pdata << "\n";
  }

private:
  T *m_pdata;
};

template<>
void Printer<std::vector<int>>::Print(){
  for(auto x : *m_pdata)   
     cout << x << " ";
  cout << "\n";
}

//instead of specializing the whole 
//class specialized the function only

// template<>
// class Printer<std::vector<int>>{
	
// 	private:
// 		std::vector<int> *m_pdata;

// 	public:
// 		Printer(std::vector<int> *data) : m_pdata(data) {} 

// 		void Print(){
// 			for(auto x : *m_pdata)
// 				std::cout << x << " ";
// 			std::cout << "\n";
// 		}
// };

int main()
{
 //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

 cout << maxx1(10, 3) << "\n";
 //cout<<max1(-1,2,3)<<"\n";
 string a = "a";
 string b = "b";
 cout << max1(a, b) << "\n";

 cout << max1("A", "B") << "\n";

 const int i = 3;
 print<sizeof(i)>();

 int arr[]{1,2,3,4};
 int sum = Sum(arr, 4);
 cout << sum << "\n";

 print1({1,2,3,4});

 for(auto x : {1,2,3})
 	cout << x << " ";
 cout << "\n";

 print2(1, 2.5, 3, "4");

 Stack<int, 4> s;
 s.Push(3);
 s.Push(1);
 s.Push(6);
 s.Push(9);

 while(!s.IsEmpty()){
 	cout << s.Top() << " ";
 	s.Pop();
 }

 cout << "\n";

 int data = 5;
 double f = 8.2f;

 Printer<int> p1(&data);
 p1.Print();
 Printer<double> p2(&f);
 p2.Print();

 std::vector<int>v{1,2,3,4};
 Printer<std::vector<int>> pv(&v);
 pv.Print();
	
 return 0;
}
