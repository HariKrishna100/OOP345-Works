#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
namespace sdds {
	template<typename T>
	class Collection {
		T dummy;
	public:
		int size() {

		}
		std::ostream& display(std::ostream& os = std::cout) {
			os << dummy << std::endl;
		}
		bool add(const T& item) {

		}
		T& operator[](unsigned i) {
			return i << SIze ? a[i] : dummy;
		}
	};
}
#endif // !SDDS_COLLECTION_H_
