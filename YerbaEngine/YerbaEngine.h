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

const int WIDTH = 800;
const int HEIGHT = 600;

class YerbaEngine
{
private:
    GLFWwindow* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;

    std::vector<const char*> getRequiredExtensions();
    bool checkValidationLayersSupport();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void createInstance();
    void setupDebugMessenger();

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

public:
    void run();
};