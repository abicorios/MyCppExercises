

#include "boost/date_time/gregorian/gregorian.hpp"
//#include <iostream>
//#include <map>
//#include <string>

int main()
{
	std::map<std::string, int> ma{ { "bday",28 },{ "bmonth",2 },{ "byear",1970 },{ "addday",1 },{ "addmonth",20 },{ "addyear",8 } };
	for (auto it : ma) std::cout << it.first << "=" << it.second << std::endl;
	boost::gregorian::date d(ma["byear"], ma["bmonth"], ma["bday"]);
	std::cout << d << std::endl;
	d += boost::gregorian::date_duration(ma["addday"]);
	std::cout << d << std::endl;
	d += boost::gregorian::months(ma["addmonth"]);
	std::cout << d << std::endl;
	d += boost::gregorian::years(ma["addyear"]);
	std::cout << d << std::endl;
	boost::gregorian::date u(1970, 1, 1);
	boost::gregorian::date d1(1971, 1, 1);
	std::cout << d1 - u << std::endl;
}

