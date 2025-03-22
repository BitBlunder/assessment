# Build Instructions

## Prerequisites
Before building the project, ensure that you have the following installed:

- CMake 3.30 or higher: Required to generate the build system.

- A C++ Compiler: Compatible with your chosen IDE or build system on Windows (e.g., Visual Studio 2019/2022, MinGW).

- Development Libraries:
	- Static Libraries located in the Lib directory.
	- Vendor Headers located in the Vendors directory.
	- Configure your PATH and environment variables if necessary so that your compiler and CMake are recognized by the system.

Directory Structure
The project's directory structure is assumed to be organized as follows:

```
marine-navigation-system/
├── CMakeLists.txt
├── Source/
│   ├── main.cpp
│   ├── Private/
│   │   ├── Renderer.cpp
│   │   └── Application.cpp
│   └── Public/
│  	├── Renderer.hpp
│ 	└── Application.hpp
├── Vendors/
├── Lib/
└── README.md
```
- CMakeLists.txt: Contains the build configuration and project setup.

- Source/: Holds the main application source code, subdivided into public and private components.

- Vendors/: Contains third-party header files.

- Lib/: Contains the static libraries (.lib files) needed for linking.


## Follow these steps to build the project:

1. Clone the Repository:
Ensure that you have the complete project source available locally.

2. Create a Build Directory:
It is recommended to perform out-of-source builds to keep build artifacts separate from source files.
	```
	mkdir build
	cd build
	```

3. Run CMake to Configure the Project:
Generate the build files using CMake by pointing it to the project root.
	```
	cmake ..
	```

4. Build the Project:
Once the configuration is complete, build the project using the generated build system. For example, if you are using a Makefile-based system:
	```
	cmake --build .
	```

5. Run the Application:
After a successful build, an executable will be created in the build directory. You can run this executable directly to start the demo assessment.
