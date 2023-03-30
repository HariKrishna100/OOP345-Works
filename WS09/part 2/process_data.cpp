// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

#include <numeric>
#include "process_data.h"

namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = std::accumulate(arr + size, arr + divisor, 0.0) / (divisor - size);
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = std::accumulate(arr + size, arr + divisor, 0.0,
			[avg](double acc, int x) { return acc + (x - avg) * (x - avg); }) / (divisor - size);
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.

		std::ifstream file(filename);
		if (file) {
			file.read(reinterpret_cast<char*>(&total_items), sizeof(total_items));
			data = new int[total_items];
			file.read(reinterpret_cast<char*>(data), sizeof(int) * total_items);
		}
		else {
			total_items = 0;
			data = nullptr;
		}

		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.




	int ProcessData::operator()(std::string fname_target, double& avg, double& var)
	{
		// TODO: divide data into a number of parts equal to the number of threads

		// Compute average factors for each part of the data in parallel
		std::vector<double> avg_factors(num_threads);
		std::vector<std::thread> avg_threads;
		for (int i = 0; i < num_threads; ++i)
		{
			avg_threads.emplace_back(
				computeAvgFactor, std::ref(data), i * total_items / num_threads,
				(i + 1) * total_items / num_threads, std::ref(avg_factors[i]));
		}
		for (auto& thread : avg_threads)
		{
			thread.join();
		}

		// Compute total average
		double total_avg = 0;
		for (auto& factor : avg_factors)
		{
			total_avg += factor;
		}
		total_avg /= num_threads;

		// Compute variance factors for each part of the data in parallel
		std::vector<double> var_factors(num_threads);
		std::vector<std::thread> var_threads;
		for (int i = 0; i < num_threads; ++i)
		{
			var_threads.emplace_back(
				computeVarFactor, std::ref(data), i * total_items / num_threads,
				(i + 1) * total_items / num_threads, total_avg, std::ref(var_factors[i]));
		}
		for (auto& thread : var_threads)
		{
			thread.join();
		}

		// Compute total variance
		double total_var = 0;
		for (auto& factor : var_factors)
		{
			total_var += factor;
		}

		// Update output arguments
		avg = total_avg;
		var = total_var;

		// Save data to file
		std::ofstream out(fname_target);
		if (!out) return -1;

		out.write(reinterpret_cast<const char*>(&total_items), sizeof(total_items));
		out.write(reinterpret_cast<const char*>(data), sizeof(int) * total_items);

		out.close();
		return 0;
	}

}