#include "lve_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>
namespace lve {
	LvePipeline::LvePipeline(
		LveDevice& device,
		const std::string& vertFilepath,
		const std::string& fragFilepath,
		const PipelineConfigInfo& configInfo):lveDevice{device}
	{
		createGraphicsPipeline(vertFilepath, fragFilepath,configInfo);
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

	void LvePipeline::createGraphicsPipeline(
		const std::string& vertFilepath, 
		const std::string& fragFilepath,
		const PipelineConfigInfo& configInfo)
	{
		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex size:" << vertCode.size() << '\n';
		std::cout << "frag size:" << fragCode.size() << '\n';

	}
	void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data()); //for c

		if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create shader module!");
		}
	}

	PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
		PipelineConfigInfo configInfo{};

		return configInfo;
	}
} //namespace lve