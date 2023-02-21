cmake_minimum_required(VERSION 3.0)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(cmake-text)			# Название проекта

set(SOURCE_EXE main.cpp)		# Установка переменной со списком исходников для исполняемого файла

#set(SOURCE_LIB a.cpp)			# Тоже самое, но для библиотеки
#add_library(a STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo STATIC -> SHARED to switch lib to dll

include_directories(sub-directory-lib)			# Расположение заголовочных файлов

add_subdirectory(sub-directory-lib)				# Добавление подпроекта, указывается имя дирректории

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(main a)		# Линковка программы с библиотекой
