#ifndef __BASICTEMPLATE__H__
#define __BASICTEMPLATE__H__

#pragma once

#include <utility>

namespace spi_template
{
	template<typename T1, typename T2 = T1, typename T3 = T2>
	struct trio : public std::pair<T1, T2>
	{
		typedef T3 third_type;
		third_type third;

		trio() : std::pair<T1, T2>(), third(T3()){}
		trio(const T1& t1, const T2& t2) : std::pair<T1, T2>(t1, t2), third(T3()){}
		trio(const T1& t1, const T2& t2, const T3& t3) : std::pair<T1, T2>(t1, t2), third(t3){}

		template<typename U1, typename U2>
		trio(const std::pair<U1, U2>& pr) : std::pair<T1, T2>(pr.first, pr.second), third(T3()){}
		trio(const std::pair<T1, T2>& pr) : std::pair<T1, T2>(pr.first, pr.second), third(T3()){}

		template<typename U1, typename U2, typename U3>
		trio(const trio<U1, U2, U3>& tri) : std::pair<T1, T2>(tri.first, tri.second), third(tri.third){}
		trio(const trio<T1, T2, T3>& tri) : std::pair<T1, T2>(tri.first, tri.second), third(tri.third){}

		trio& operator=(const trio<T1, T2, T3>& tri){first = tri.first, second = tri.second, third = tri.third; return *this;}
	};

	template<typename T1, typename T2, typename T3>
	inline bool operator==(const trio<T1, T2, T3>& lhs, const trio<T1, T2, T3>& rhs)
	{
		return lhs.first == rhs.first && 
			lhs.second == rhs.second && 
			lhs.third == rhs.third;
	}

	template<typename T1, typename T2, typename T3>
	inline bool operator<(const trio<T1, T2, T3>& lhs, const trio<T1, T2, T3>& rhs)
	{
		return lhs.first < rhs.first || 
			(lhs.second < rhs.second	&& !(rhs.first < lhs.first)) ||
			(lhs.third < rhs.third	&& !(rhs.second < lhs.second) && !(rhs.first < lhs.first));
	}


	template<typename T1, typename T2, typename T3>
	inline bool operator!=(const trio<T1, T2, T3>& lhs, const trio<T1, T2, T3>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T1, typename T2, typename T3>
	inline bool operator>(const trio<T1, T2, T3>& lhs, const trio<T1, T2, T3>& rhs)
	{
		return rhs < lhs;
	}

	template<typename T1, typename T2, typename T3>
	inline bool operator<=(const trio<T1, T2, T3>& lhs, const trio<T1, T2, T3>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename T1, typename T2, typename T3>
	inline bool operator>=(const trio<T1, T2, T3>& lhs, const trio<T1, T2, T3>& rhs)
	{
		return !(lhs < rhs);
	}


	template<typename T1, typename T2, typename T3>
	inline trio<T1, T2, T3> make_trio(const T1& t1, const T2& t2, const T3& t3)
	{
		return trio<T1, T2, T3>(t1, t2, t3);
	}



	template<typename T1, typename T2 = T1, typename T3 = T2, typename T4 = T3>
	struct quartet : public trio<T1, T2, T3>
	{
		typedef T4 fourth_type;
		fourth_type fourth;

		quartet() : trio<T1, T2, T3>(), fourth(T4()){}
		quartet(const T1& t1, const T2& t2) : trio<T1, T2, T3>(t1, t2), fourth(T4()){}
		quartet(const T1& t1, const T2& t2, const T3& t3) : trio<T1, T2, T3>(t1, t2, t3), fourth(T4()){}
		quartet(const T1& t1, const T2& t2, const T3& t3, const T4& t4) : trio<T1, T2, T3>(t1, t2, t3), fourth(t4){}

		template<typename U1, typename U2>
		quartet(const std::pair<U1, U2>& pr) : trio<T1, T2, T3>(std::pair<T1, T2>(pr.first, pr.second)), fourth(T4()){}
		quartet(const std::pair<T1, T2>& pr) : trio<T1, T2, T3>(std::pair<T1, T2>(pr.first, pr.second)), fourth(T4()){}

		template<typename U1, typename U2, typename U3>
		quartet(const trio<U1, U2, U3>& tri) : trio<T1, T2, T3>(tri.first, tri.second, tri.third), fourth(T4()){}
		quartet(const trio<T1, T2, T3>& tri) : trio<T1, T2, T3>(tri.first, tri.second, tri.third), fourth(T4()){}

		template<typename U1, typename U2, typename U3, typename U4>
		quartet(const quartet<U1, U2, U3, U4>& quad) : trio<T1, T2, T3>(quad.first, quad.second, quad.third), fourth(quad.fourth){}
		quartet(const quartet<T1, T2, T3, T4>& quad) : trio<T1, T2, T3>(quad.first, quad.second, quad.third), fourth(quad.fourth){}

		quartet& operator=(const quartet<T1, T2, T3, T4>& quad){first = quad.first, second = quad.second, third = quad.third, fourth = quad.fourth; return *this;}
	};

	template<typename T1, typename T2, typename T3, typename T4>
	inline bool operator==(const quartet<T1, T2, T3, T4>& lhs, const quartet<T1, T2, T3, T4>& rhs)
	{
		return lhs.first == rhs.first && 
			lhs.second == rhs.second && 
			lhs.third == rhs.third && 
			lhs.fourth == rhs.fourth;
	}

	template<typename T1, typename T2, typename T3, typename T4>
	inline bool operator<(const quartet<T1, T2, T3, T4>& lhs, const quartet<T1, T2, T3, T4>& rhs)
	{
		return lhs.first < rhs.first || 
			(lhs.second < rhs.second	&& !(rhs.first < lhs.first)) ||
			(lhs.third < rhs.third	&& !(rhs.second < lhs.second)	&& !(rhs.first < lhs.first)) ||
			(lhs.fourth < rhs.fourth	&& !(rhs.third < lhs.third)		&& !(rhs.second < lhs.second) && !(rhs.first < lhs.first));
	}


	template<typename T1, typename T2, typename T3, typename T4>
	inline bool operator!=(const quartet<T1, T2, T3, T4>& lhs, const quartet<T1, T2, T3, T4>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T1, typename T2, typename T3, typename T4>
	inline bool operator>(const quartet<T1, T2, T3, T4>& lhs, const quartet<T1, T2, T3, T4>& rhs)
	{
		return rhs < lhs;
	}

	template<typename T1, typename T2, typename T3, typename T4>
	inline bool operator<=(const quartet<T1, T2, T3, T4>& lhs, const quartet<T1, T2, T3, T4>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename T1, typename T2, typename T3, typename T4>
	inline bool operator>=(const quartet<T1, T2, T3, T4>& lhs, const quartet<T1, T2, T3, T4>& rhs)
	{
		return !(lhs < rhs);
	}


	template<typename T1, typename T2, typename T3, typename T4>
	inline quartet<T1, T2, T3, T4> make_quartet(const T1& t1, const T2& t2, const T3& t3, const T4& t4)
	{
		return quartet<T1, T2, T3, T4>(t1, t2, t3, t4);
	}



	template<typename T1, typename T2 = T1, typename T3 = T2, typename T4 = T3, typename T5 = T4>
	struct quintet : public quartet<T1, T2, T3, T4>
	{
		typedef T5 fifth_type;
		fifth_type fifth;

		quintet() : quartet<T1, T2, T3, T4>(), fifth(T5()){}
		quintet(const T1& t1, const T2& t2) : quartet<T1, T2, T3, T4>(t1, t2), fifth(T5()){}
		quintet(const T1& t1, const T2& t2, const T3& t3) : quartet<T1, T2, T3, T4>(t1, t2, t3), fifth(T5()){}
		quintet(const T1& t1, const T2& t2, const T3& t3, const T4& t4) : quartet<T1, T2, T3, T4>(t1, t2, t3, t4), fifth(T5()){}
		quintet(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5) : quartet<T1, T2, T3, T4>(t1, t2, t3, t4), fifth(t5){}

		template<typename U1, typename U2>
		quintet(const std::pair<U1, U2>& pr) : quartet<T1, T2, T3, T4>(std::pair<T1, T2>(pr.first, pr.second)), fifth(T5()){}
		quintet(const std::pair<T1, T2>& pr) : quartet<T1, T2, T3, T4>(std::pair<T1, T2>(pr.first, pr.second)), fifth(T5()){}

		template<typename U1, typename U2, typename U3>
		quintet(const trio<U1, U2, U3>& tri) : quartet<T1, T2, T3, T4>(tri.first, tri.second, tri.third), fifth(T5()){}
		quintet(const trio<T1, T2, T3>& tri) : quartet<T1, T2, T3, T4>(tri.first, tri.second, tri.third), fifth(T5()){}

		template<typename U1, typename U2, typename U3, typename U4>
		quintet(const quartet<U1, U2, U3, U4>& quad) : quartet<T1, T2, T3, T4>(quad.first, quad.second, quad.third, quad.fourth), fifth(T5()){}
		quintet(const quartet<T1, T2, T3, T4>& quad) : quartet<T1, T2, T3, T4>(quad.first, quad.second, quad.third, quad.fourth), fifth(T5()){}

		template<typename U1, typename U2, typename U3, typename U4, typename U5>
		quintet(const quintet<U1, U2, U3, U4, U5>& quint) : quartet<T1, T2, T3, T4>(quint.first, quint.second, quint.third, quint.fourth), fifth(quint.fifth){}
		quintet(const quintet<T1, T2, T3, T4, T5>& quint) : quartet<T1, T2, T3, T4>(quint.first, quint.second, quint.third, quint.fourth), fifth(quint.fifth){}

		quintet& operator=(const quintet<T1, T2, T3, T4, T5>& quint){first = quint.first, second = quint.second, third = quint.third, fourth = quint.fourth, fifth = quint.fifth; return *this;}
	};

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline bool operator==(const quintet<T1, T2, T3, T4, T5>& lhs, const quintet<T1, T2, T3, T4, T5>& rhs)
	{
		return lhs.first == rhs.first && 
			lhs.second == rhs.second && 
			lhs.third == rhs.third && 
			lhs.fourth == rhs.fourth && 
			lhs.fifth == rhs.fifth;
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline bool operator<(const quintet<T1, T2, T3, T4, T5>& lhs, const quintet<T1, T2, T3, T4, T5>& rhs)
	{
		return lhs.first < rhs.first || 
			(lhs.second < rhs.second	&& !(rhs.first < lhs.first)) ||
			(lhs.third < rhs.third	&& !(rhs.second < lhs.second)	&& !(rhs.first < lhs.first)) ||
			(lhs.fourth < rhs.fourth	&& !(rhs.third < lhs.third)		&& !(rhs.second < lhs.second)	&& !(rhs.first < lhs.first)) ||
			(lhs.fifth < rhs.fifth	&& !(rhs.fourth < lhs.fourth)	&& !(rhs.third < lhs.third)		&& !(rhs.second < lhs.second) && !(rhs.first < lhs.first));
	}


	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline bool operator!=(const quintet<T1, T2, T3, T4, T5>& lhs, const quintet<T1, T2, T3, T4, T5>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline bool operator>(const quintet<T1, T2, T3, T4, T5>& lhs, const quintet<T1, T2, T3, T4, T5>& rhs)
	{
		return rhs < lhs;
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline bool operator<=(const quintet<T1, T2, T3, T4, T5>& lhs, const quintet<T1, T2, T3, T4, T5>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline bool operator>=(const quintet<T1, T2, T3, T4, T5>& lhs, const quintet<T1, T2, T3, T4, T5>& rhs)
	{
		return !(lhs < rhs);
	}


	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline quintet<T1, T2, T3, T4, T5> make_quintet(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5)
	{
		return quintet<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5);
	}



	template<typename T1, typename T2 = T1, typename T3 = T2, typename T4 = T3, typename T5 = T4, typename T6 = T5>
	struct sextet : public quintet<T1, T2, T3, T4, T5>
	{
		typedef T6 sixth_type;
		sixth_type sixth;

		sextet() : quintet<T1, T2, T3, T4, T5>(), sixth(){}
		sextet(const T1& t1, const T2& t2) : quintet<T1, T2, T3, T4, T5>(t1, t2), sixth(){}
		sextet(const T1& t1, const T2& t2, const T3& t3) : quintet<T1, T2, T3, T4, T5>(t1, t2, t3), sixth(){}
		sextet(const T1& t1, const T2& t2, const T3& t3, const T4& t4) : quintet<T1, T2, T3, T4, T5>(t1, t2, t3, t4), sixth(){}
		sextet(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5) : quintet<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5), sixth(){}
		sextet(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6) : quintet<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5), sixth(t6){}

		template<typename U1, typename U2>
		sextet(const std::pair<U1, U2>& pr) : quintet<T1, T2, T3, T4, T5>(std::pair<T1, T2>(pr.first, pr.second)), sixth(){}
		sextet(const std::pair<T1, T2>& pr) : quintet<T1, T2, T3, T4, T5>(std::pair<T1, T2>(pr.first, pr.second)), sixth(){}

		template<typename U1, typename U2, typename U3>
		sextet(const trio<U1, U2, U3>& tri) : quintet<T1, T2, T3, T4, T5>(tri.first, tri.second, tri.third), sixth(){}
		sextet(const trio<T1, T2, T3>& tri) : quintet<T1, T2, T3, T4, T5>(tri.first, tri.second, tri.third), sixth(){}

		template<typename U1, typename U2, typename U3, typename U4>
		sextet(const quartet<U1, U2, U3, U4>& quad) : quintet<T1, T2, T3, T4, T5>(quad.first, quad.second, quad.third, quad.fourth), sixth(){}
		sextet(const quartet<T1, T2, T3, T4>& quad) : quintet<T1, T2, T3, T4, T5>(quad.first, quad.second, quad.third, quad.fourth), sixth(){}

		template<typename U1, typename U2, typename U3, typename U4, typename U5>
		sextet(const quintet<U1, U2, U3, U4, U5>& quint) : quintet<T1, T2, T3, T4, T5>(quint.first, quint.second, quint.third, quint.fourth, quint.fifth), sixth(){}
		sextet(const quintet<T1, T2, T3, T4, T5>& quint) : quintet<T1, T2, T3, T4, T5>(quint.first, quint.second, quint.third, quint.fourth, quint.fifth), sixth(){}

		template<typename U1, typename U2, typename U3, typename U4, typename U5, typename U6>
		sextet(const sextet<U1, U2, U3, U4, U5, U6>& quint) : quintet<T1, T2, T3, T4, T5>(quint.first, quint.second, quint.third, quint.fourth, quint.fifth), sixth(quint.sixth){}
		sextet(const sextet<T1, T2, T3, T4, T5, T6>& quint) : quintet<T1, T2, T3, T4, T5>(quint.first, quint.second, quint.third, quint.fourth, quint.fifth), sixth(quint.sixth){}

		sextet& operator=(const sextet<T1, T2, T3, T4, T5>& quint){first = quint.first, second = quint.second, third = quint.third, fourth = quint.fourth, fifth = quint.fifth, sixth = quint.sixth; return *this;}
	};

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	inline bool operator==(const sextet<T1, T2, T3, T4, T5, T6>& lhs, const sextet<T1, T2, T3, T4, T5, T6>& rhs)
	{
		return lhs.first == rhs.first && 
			lhs.second == rhs.second && 
			lhs.third == rhs.third && 
			lhs.fourth == rhs.fourth && 
			lhs.fifth == rhs.fifth && 
			lhs.sixth == rhs.sixth;
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	inline bool operator<(const sextet<T1, T2, T3, T4, T5, T6>& lhs, const sextet<T1, T2, T3, T4, T5, T6>& rhs)
	{
		return lhs.first < rhs.first || 
			(lhs.second < rhs.second	&& !(rhs.first < lhs.first)) ||
			(lhs.third < rhs.third	&& !(rhs.second < lhs.second)	&& !(rhs.first < lhs.first)) ||
			(lhs.fourth < rhs.fourth	&& !(rhs.third < lhs.third)		&& !(rhs.second < lhs.second)	&& !(rhs.first < lhs.first)) ||
			(lhs.fifth < rhs.fifth	&& !(rhs.fourth < lhs.fourth)	&& !(rhs.third < lhs.third)		&& !(rhs.second < lhs.second) && !(rhs.first < lhs.first)) ||
			(lhs.sixth < rhs.sixth	&& !(rhs.fifth < lhs.fifth)	&& !(rhs.fourth < lhs.fourth)	&& !(rhs.third < lhs.third)		&& !(rhs.second < lhs.second) && !(rhs.first < lhs.first));
	}


	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	inline bool operator!=(const sextet<T1, T2, T3, T4, T5, T6>& lhs, const sextet<T1, T2, T3, T4, T5, T6>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	inline bool operator>(const sextet<T1, T2, T3, T4, T5, T6>& lhs, const sextet<T1, T2, T3, T4, T5, T6>& rhs)
	{
		return rhs < lhs;
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	inline bool operator<=(const sextet<T1, T2, T3, T4, T5, T6>& lhs, const sextet<T1, T2, T3, T4, T5, T6>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	inline bool operator>=(const sextet<T1, T2, T3, T4, T5, T6>& lhs, const sextet<T1, T2, T3, T4, T5, T6>& rhs)
	{
		return !(lhs < rhs);
	}


	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	inline sextet<T1, T2, T3, T4, T5, T6> make_sextet(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6)
	{
		return sextet<T1, T2, T3, T4, T5, T6>(t1, t2, t3, t4, t5, t6);
	}



	template<typename T>
	struct couple : public std::pair<T, T>
	{
		couple() : std::pair<T, T>(){}
		couple(const T& x, const T& y) : std::pair<T, T>(x, y){}

		template<typename U1, typename U2>
		couple(const std::pair<U1, U2>& pr) : std::pair<T, T>(pr.first, pr.second){}
		couple(const couple<T>& pr) : std::pair<T, T>(pr.first, pr.second){}

		couple& operator=(const couple<T>& pr){first = pr.first, second = pr.second; return *this;}
	};

	template<typename T>
	inline couple<T> make_couple(const T& x, const T& y)
	{
		return couple<T>(x, y);
	}

	template<typename T>
	struct triple : public trio<T, T, T>
	{
		triple() : trio<T, T, T>(){}
		triple(const T& t1, const T& t2, const T& t3) : trio<T, T, T>(t1, t2, t3){}

		triple(const couple<T>& pr) : trio<T, T, T>(pr.first, pr.second){}
		triple(const triple<T>& tri) : trio<T, T, T>(tri.first, tri.second, tri.third){}

		triple& operator=(const triple<T>& tri){first = tri.first, second = tri.second, third = tri.third; return *this;}
	};

	template<typename T>
	inline triple<T> make_triple(const T& t1, const T& t2, const T& t3)
	{
		return triple<T>(t1, t2, t3);
	}

	template<typename T>
	struct quadruple : public quartet<T, T, T, T>
	{
		quadruple() : quartet<T, T, T, T>(){}
		quadruple(const T& t1, const T& t2, const T& t3, const T& t4) : quartet<T, T, T, T>(t1, t2, t3, t4){}

		quadruple(const couple<T>& pr) : quartet<T, T, T, T>(pr.first, pr.second){}
		quadruple(const triple<T>& tri) : quartet<T, T, T, T>(tri.first, tri.second, tri.third){}
		quadruple(const quadruple<T>& quad) : quartet<T, T, T, T>(quad.first, quad.second, quad.third, quad.fourth){}

		quadruple& operator=(const quadruple<T>& quad){first = quad.first, second = quad.second, third = quad.third, fourth = quad.fourth; return *this;}
	};

	template<typename T>
	inline quadruple<T> make_quadruple(const T& t1, const T& t2, const T& t3, const T& t4)
	{
		return quadruple<T>(t1, t2, t3, t4);
	}
}


#endif