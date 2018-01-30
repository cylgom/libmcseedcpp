#ifndef LIBMCSEEDCPP_SEED_H
#define LIBMCSEEDCPP_SEED_H

#include "java.hpp"
#include <string>

class Seed
{
	public:
		Seed(const std::string&);
		Seed(const std::u16string&);
		void set(const std::string&);
		void set(const std::u16string&);
		jlong get();

	private:
		std::u16string seed;
};

#endif /* LIBMCSEEDCPP_SEED_H */
