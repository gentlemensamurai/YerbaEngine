// VulkanSDK 1.2.135.0
// GLFW 3.3.2
// GLM 0.9.9.7

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <map>
#include <optional>
#include <set>
#include <cstdint>
#include <algorithm>
#include <fstream>

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete()
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class YerbaEngine
{
private:
    const int WIDTH {800};
    const int HEIGHT {600};
    const std::vector<const char*> VALIDATION_LAYERS { "VK_LAYER_KHRONOS_validation" };
    const std::vector<const char*> DEVICE_EXTENSIONS { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

#ifndef _DEBUG
    const bool ENABLE_VALIDATION_LAYERS {false};
#else
    const bool ENABLE_VALIDATION_LAYERS {true};
#endif

    GLFWwindow* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkQueue graphicsQueue;
    VkSurfaceKHR surface;
    VkQueue presentQueue;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    VkPipelineLayout pipelineLayout;

    static std::vector<char> readFile(const std::string& filename);
    std::vector<const char*> getRequiredExtensions();
    bool checkValidationLayersSupport();
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void createInstance();
    void setupDebugMessenger();
    bool isDeviceSuitable(VkPhysicalDevice device);
    void pickPhysicalDevice();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    void createLogicalDevice();
    void createSurface();
    void createSwapChain();
    void createImageViews();
    void createGraphicsPipeline();
    VkShaderModule createShaderModule(const std::vector<char>& code);

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

public:
    void run();
};