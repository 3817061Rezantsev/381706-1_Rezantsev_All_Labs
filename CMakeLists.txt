cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Rezantsev_All_Labs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта
set (SList SList)
set (ListLib ListLib)
set (SListLib SListLib)
set (test test)
set (Exception Exception)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)
add_subdirectory(test)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SListLib)
add_subdirectory(SList)
add_subdirectory(SListLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(ListLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)


#target_link_libraries(${SList} ${SListLib} )#Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}

#target_link_libraries(${SList} ${ListLib} )
