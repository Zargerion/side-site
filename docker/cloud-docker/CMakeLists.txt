cmake_minimum_required(VERSION 3.0)

project(cloud-docker)

#cmake -B . -S . -DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake

# Установка пути к файлу скрипта инструмента сборки
set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_INCLUDE_DIR "C:/dev/vcpkg/installed/x64-windows/include")
# Поиск и подключение библиотеки Boost
find_package(Boost REQUIRED)
message("Y")
if(Boost_FOUND)
message("N")
endif()

include_directories(${Boost_INCLUDE_DIRS})

# Добавление исполняемого файла
add_executable(out-exe main.cpp)

# Линковка с библиотекой Boost
target_link_libraries(out-exe PRIVATE Boost::boost) 
#target_include_directories(out-exe PRIVATE ${Boost_INCLUDE_DIRS})
