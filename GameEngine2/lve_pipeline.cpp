#include "lve_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>
namespace lve {
	LvePipeline::LvePipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
		createGraphicsPipeline(vertFilepath, fragFilepath);
	}

	std::vector<char> LvePipeline::readFile(const std::string& filepath) {
		std::ifstream file(filepath, std::ios::ate | std::ios::binary); //got to the end and read as binary

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg()); //take file size
		std::vector<char> buffer(fileSize); // char buffer con file size

		file.seekg(0); // go to start of the file
		file.read(buffer.data(), fileSize);//read the data of the file and safe in buffer, read till fileSize

		file.close();
		return buffer;
	}

	void LvePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex size:" << vertCode.size() << '\n';
		std::cout << "frag size:" << fragCode.size() << '\n';

	}

} //namespace lve